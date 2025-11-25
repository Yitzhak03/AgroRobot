#include "DiagnosticoController.h"

using namespace System::Runtime::Serialization::Formatters::Binary;
using namespace AgroRobotController;
using namespace System::IO;
using namespace System::Collections::Generic;
using namespace System::Globalization;

DiagnosticoController::DiagnosticoController() {
	this->listaDiagnosticos = gcnew List<Diagnostico^>();
    try {
        // Paso1: Establecer la conexion
        abrirConexion();
        // Paso2: Crear el comando SQL
		String^ sSqlDiagnostico = "SELECT IdDiagnostico, IdAnimal, Especie, ResultadoHeces, ResultadoSangre, EstadoSalud, Observaciones ";
        sSqlDiagnostico += " FROM Diagnosticos ";
        // Paso3: Crear el SqlCommand, donde le paso la sentencia SQL y la conexion
        SqlCommand^ comando = gcnew SqlCommand(sSqlDiagnostico, getObjConexion());
        // Paso4: Ahora para ejecutar voy a utilizar ExecuteReader cuando la sentencia es SELECT
        // Para recuperar la informacion que me devuelve un select, utilizo SqlDataReader
        SqlDataReader^ objData = comando->ExecuteReader();
        // Paso5: Leer los registros de la tabla
        while (objData->Read()) {
			int idDiagnostico = objData->GetInt32(0); // IdDiagnostico
			int idAnimal = objData->GetInt32(1); // IdAnimal
			String^ especie = objData->GetString(2); // Especie
			String^ resultadoHeces = objData->GetString(3); // ResultadoHeces
			String^ resultadoSangre = objData->GetString(4); // ResultadoSangre
			String^ estadoSalud = objData->GetString(5); // EstadoSalud
			String^ observaciones = objData->GetString(6); // Observaciones
            Diagnostico^ diagnostico = gcnew Diagnostico(idDiagnostico, idAnimal, especie, resultadoHeces, resultadoSangre, estadoSalud, observaciones);
            this->listaDiagnosticos->Add(diagnostico);
        }
        // Paso6: Cerrar el DataReader y la conexion
        objData->Close();
        cerrarConexion();
    }
    catch (Exception^ ex) {
        Console::WriteLine("Error al conectar a la base de datos: " + ex->Message);
        // En caso de cualquier error, crear lista vacía
        this->listaDiagnosticos = gcnew List<Diagnostico^>();
    }
}

int DiagnosticoController::generarNuevoId() {
    List<Diagnostico^>^ lista = buscarTodosDiagnosticosArchivo();
    int maxId = 0;
    for each (Diagnostico ^ d in lista) {
        if (d->IdDiagnostico > maxId) {
            maxId = d->IdDiagnostico;
        }
    }
    return maxId + 1;
}

List<Diagnostico^>^ DiagnosticoController::buscarTodosDiagnosticosArchivo() {
    /*List<Diagnostico^>^ lista = gcnew List<Diagnostico^>();
    if (!File::Exists("diagnosticos.txt")) return lista;

    array<String^>^ lineas = File::ReadAllLines("diagnosticos.txt");
    for each (String ^ linea in lineas) {
        if (String::IsNullOrWhiteSpace(linea)) continue;

        array<String^>^ campos = linea->Split(';');
        if (campos->Length < 7) continue;

        int idDiagnostico, idAnimal;
        if (!Int32::TryParse(campos[0], idDiagnostico)) continue;
        if (!Int32::TryParse(campos[1], idAnimal)) continue;

        Diagnostico^ d = gcnew Diagnostico(
            idDiagnostico,
            idAnimal,
            campos[2]->Trim(),
            campos[3]->Trim(),
            campos[4]->Trim(),
            campos[5]->Trim(),
            campos[6]->Trim()
        );

        lista->Add(d);
    }

    return lista;*/
    return this->listaDiagnosticos;
}

Diagnostico^ DiagnosticoController::buscarDiagnosticoPorIdArchivo(int idDiagnostico) {
    List<Diagnostico^>^ lista = buscarTodosDiagnosticosArchivo();
    for each (Diagnostico ^ d in lista) {
        if (d->IdDiagnostico == idDiagnostico) {
            return d;
        }
    }
    return nullptr;
}

List<Diagnostico^>^ DiagnosticoController::buscarDiagnosticosPorAnimalArchivo(int idAnimal) {
    List<Diagnostico^>^ lista = buscarTodosDiagnosticosArchivo();
    List<Diagnostico^>^ resultado = gcnew List<Diagnostico^>();
    for each (Diagnostico ^ d in lista) {
        if (d->IdAnimal == idAnimal) {
            resultado->Add(d);
        }
    }
    return resultado;
}

List<Diagnostico^>^ DiagnosticoController::buscarDiagnosticosPorEspecieArchivo(String^ especie) {
    List<Diagnostico^>^ todos = this->buscarTodosDiagnosticosArchivo();
    List<Diagnostico^>^ filtrados = gcnew List<Diagnostico^>();

    for each (Diagnostico ^ d in todos) {
        if (!String::IsNullOrEmpty(d->Especie) &&
            d->Especie->Equals(especie, StringComparison::OrdinalIgnoreCase)) {
            filtrados->Add(d);
        }
    }
    return filtrados;
}

void DiagnosticoController::escribirArchivo(List<Diagnostico^>^ listaDiagnosticos) {
    array<String^>^ lineas = gcnew array<String^>(listaDiagnosticos->Count);
    for (int i = 0; i < listaDiagnosticos->Count; i++) {
        Diagnostico^ d = listaDiagnosticos[i];
        lineas[i] = d->IdDiagnostico + ";" + d->IdAnimal + ";" + d->Especie + ";" +
            d->ResultadoHeces + ";" + d->ResultadoSangre + ";" +
            d->EstadoSalud + ";" + d->Observaciones;
    }
    File::WriteAllLines("diagnosticos.txt", lineas);
}

void DiagnosticoController::guardarDiagnosticoArchivo(Diagnostico^ diagnostico) {
    List<Diagnostico^>^ lista = buscarTodosDiagnosticosArchivo();
    lista->Add(diagnostico);
    escribirArchivo(lista);
}

Diagnostico^ DiagnosticoController::generarDiagnosticoParaAnimal(int idAnimal, MuestraController^ muestraController, GestorNutricionalController^ gestor) {
    List<Muestra^>^ muestras = muestraController->buscarMuestrasPorAnimalArchivo(idAnimal, gestor);

    if (muestras == nullptr || muestras->Count == 0) {
        return nullptr; // No hay muestras, no se genera diagnóstico
    }

    String^ resultadoHeces = "No";
    String^ resultadoSangre = "No";
    String^ especie = "";

    bool tieneHeces = false;
    bool tieneSangre = false;

    for each (Muestra ^ m in muestras) {
        if (m->getAnimal() != nullptr) {
            especie = m->getAnimal()->Especie;
        }

        if (m->getTipo()->Equals("Heces")) {
            tieneHeces = true;
            if (m->getParasitos()->Equals("Sí")) {
                resultadoHeces = "Sí";
            }
        }

        if (m->getTipo()->Equals("Sangre")) {
            tieneSangre = true;
            if (m->getContaminacion()->Equals("Sí")) {
                resultadoSangre = "Sí";
            }
        }
    }

    // Validación: si falta alguna muestra, no generar diagnóstico
    if (!tieneHeces || !tieneSangre) {
        return nullptr;
    }

    String^ estadoSalud;
    String^ observaciones;

    // Nueva lógica con casos intermedios
    if (resultadoHeces->Equals("Sí") && resultadoSangre->Equals("Sí")) {
        estadoSalud = "Enfermo";
        observaciones = "Atención urgente";
    }
    else if (resultadoHeces->Equals("Sí") && resultadoSangre->Equals("No")) {
        estadoSalud = "En observación";
        observaciones = "Parásitos detectados";
    }
    else if (resultadoHeces->Equals("No") && resultadoSangre->Equals("Sí")) {
        estadoSalud = "En observación";
        observaciones = "Sangre contaminada";
    }
    else {
        estadoSalud = "Saludable";
        observaciones = "Sin problemas";
    }

    int nuevoId = generarNuevoId();

    Diagnostico^ diag = gcnew Diagnostico(
        nuevoId,
        idAnimal,
        especie,
        resultadoHeces,
        resultadoSangre,
        estadoSalud,
        observaciones
    );

    return diag;
}

void DiagnosticoController::eliminarDiagnosticoArchivo(int idDiagnostico) {
    List<Diagnostico^>^ lista = buscarTodosDiagnosticosArchivo();
    for (int i = 0; i < lista->Count; i++) {
        if (lista[i]->IdDiagnostico == idDiagnostico) {
            lista->RemoveAt(i);
            break;
        }
    }
    escribirArchivo(lista); 
}

void DiagnosticoController::escribirArchivoBINDiagnosticos() {
    //Creamos el archivo
    Stream^ stream = File::Open(this->archivo, FileMode::Create);
    BinaryFormatter^ formateador = gcnew BinaryFormatter();
    formateador->Serialize(stream, this->listaDiagnosticos);
    stream->Close();
}