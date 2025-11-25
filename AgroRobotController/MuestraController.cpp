#include "MuestraController.h"
#include "GestorNutricionalController.h"

using namespace System::Runtime::Serialization::Formatters::Binary;
using namespace AgroRobotController;
using namespace System::IO;

MuestraController::MuestraController() {
    this->listaMuestras = gcnew List<Muestra^>();
    try {
        // Paso1: Establecer la conexion
        abrirConexion();
        // Paso2: Crear el comando SQL
        String^ sSqlDiagnostico = "SELECT IdMuestra, Tipo, FechaToma, Consistencia, ColorHeces, Olor, Parasistos, CantidadExtraida, ColorSangre, Coagulos, Contaminacion ";
        sSqlDiagnostico += " FROM Muestras ";
        // Paso3: Crear el SqlCommand, donde le paso la sentencia SQL y la conexion
        SqlCommand^ comando = gcnew SqlCommand(sSqlDiagnostico, getObjConexion());
        // Paso4: Ahora para ejecutar voy a utilizar ExecuteReader cuando la sentencia es SELECT
        // Para recuperar la informacion que me devuelve un select, utilizo SqlDataReader
        SqlDataReader^ objData = comando->ExecuteReader();
        // Paso5: Leer los registros de la tabla
        while (objData->Read()) {
			int idMuestra = objData->GetInt32(0); // IdMuestra
			String^ tipo = objData->GetString(1); // Tipo
			String^ fechaToma = objData->GetString(2); // FechaToma
			String^ consistencia = objData->GetString(3); // Consistencia
			String^ colorHeces = objData->GetString(4); // ColorHeces
			String^ olor = objData->GetString(5); // Olor
			String^ parasitos = objData->GetString(6); // Parasistos
			int cantidadExtraida = objData->GetInt32(7); // CantidadExtraida
			String^ colorSangre = objData->GetString(8); // ColorSangre
			String^ coagulos = objData->GetString(9); // Coagulos
            String^ contaminacion = objData->GetString(10); // Contaminacion
            Muestra^ muestra = gcnew Muestra(
                idMuestra, tipo, fechaToma,
                consistencia, colorHeces, olor, parasitos,
                cantidadExtraida, coagulos, contaminacion,
                colorSangre, nullptr // Animal se asigna después
            );
			this->listaMuestras->Add(muestra);
        }
        // Paso6: Cerrar el DataReader y la conexion
        objData->Close();
        cerrarConexion();
    }
    catch (Exception^ ex) {
        Console::WriteLine("Error al conectar a la base de datos: " + ex->Message);
        // En caso de cualquier error, crear lista vacía
        this->listaMuestras = gcnew List<Muestra^>();
    }
}

// Leer todas las muestras desde archivo
List<Muestra^>^ MuestraController::buscarTodasMuestrasArchivo(GestorNutricionalController^ gestor) {
    List<Muestra^>^ listaMuestras = gcnew List<Muestra^>();
    if (!File::Exists("muestras.txt")) return listaMuestras;

    array<String^>^ lineas = File::ReadAllLines("muestras.txt");
    for each (String ^ linea in lineas) {
        if (String::IsNullOrWhiteSpace(linea)) continue;

        array<String^>^ campos = linea->Split(';');
        if (campos->Length < 13) continue; // siempre deben ser 13 columnas

        // Trim de cada campo
        for (int i = 0; i < campos->Length; i++) {
            campos[i] = campos[i]->Trim();
        }

        int idMuestra;
        if (!Int32::TryParse(campos[0], idMuestra)) continue;

        String^ tipo = campos[1];
        String^ fechaToma = campos[2];

        // Campos de heces
        String^ consistencia = campos[3];
        String^ colorHeces = campos[4];
        String^ olor = campos[5];
        String^ parasitos = campos[6];

        // Campos de sangre
        int cantidadExtraida;
        if (!Int32::TryParse(campos[7], cantidadExtraida)) continue;
        String^ coagulos = campos[8];
        String^ contaminacion = campos[9];
        String^ colorSangre = campos[10];

        // Animal
        int idAnimal;
        if (!Int32::TryParse(campos[11], idAnimal)) continue;
        String^ especie = campos[12];

        Animal^ animal = nullptr;
        if (gestor != nullptr) {
            animal = gestor->consultarAnimalporId(idAnimal);
        }
        if (animal == nullptr) {
            //ahora usamos el constructor básico
            animal = gcnew Animal(idAnimal, especie);
        }

        // Crear la muestra
        Muestra^ muestra = gcnew Muestra(
            idMuestra, tipo, fechaToma,
            consistencia, colorHeces, olor, parasitos,
            cantidadExtraida, coagulos, contaminacion, colorSangre,
            animal
        );

        listaMuestras->Add(muestra);
    }
    return listaMuestras;
}



// Buscar muestra por ID
Muestra^ MuestraController::buscarMuestraPorIdArchivo(int idMuestra, GestorNutricionalController^ gestor) {
    List<Muestra^>^ lista = buscarTodasMuestrasArchivo(gestor);
    for each (Muestra ^ m in lista) {
        if (m->getIdMuestra() == idMuestra)
            return m;
    }
    return nullptr;
}

// Buscar muestras por ID de animal
List<Muestra^>^ MuestraController::buscarMuestrasPorAnimalArchivo(int idAnimal, GestorNutricionalController^ gestor) {
    List<Muestra^>^ lista = buscarTodasMuestrasArchivo(gestor);
    List<Muestra^>^ resultado = gcnew List<Muestra^>();
    for each (Muestra ^ m in lista) {
        if (m->getAnimal() != nullptr && m->getAnimal()->IdAnimal == idAnimal) {
            resultado->Add(m);
        }
    }
    return resultado;
}

List<Muestra^>^ MuestraController::buscarMuestrasPorEspecieArchivo(String^ especie, GestorNutricionalController^ gestor) {
    
    List<Muestra^>^ todas = this->buscarTodasMuestrasArchivo(gestor);
    List<Muestra^>^ filtradas = gcnew List<Muestra^>();
    for each (Muestra ^ m in todas) {
        if (m->getAnimal() != nullptr &&
            m->getAnimal()->Especie->Equals(especie, StringComparison::OrdinalIgnoreCase)) {
            filtradas->Add(m);
        }
    }
    return filtradas;
}


// Agregar nueva muestra
void MuestraController::agregarMuestraArchivo(Muestra^ nuevaMuestra, GestorNutricionalController^ gestor) {
    // Validar que la muestra tenga un animal asociado
    Animal^ animal = nuevaMuestra->getAnimal();
    if (animal == nullptr) {
        return;
    }
    // Validar existencia del animal en animales.txt usando GestorNutricionalController
    if (!gestor->existeAnimal(animal->IdAnimal)) {
        return;
    }
    // Si pasa la validación, agregar la muestra
    List<Muestra^>^ lista = buscarTodasMuestrasArchivo(gestor);
    lista->Add(nuevaMuestra);
    escribirArchivo(lista);
}

// Editar muestra existente
void MuestraController::editarMuestraArchivo(int idMuestra, Muestra^ muestraEditada) {
    List<Muestra^>^ lista = buscarTodasMuestrasArchivo(nullptr);
    for (int i = 0; i < lista->Count; i++) {
        if (lista[i]->getIdMuestra() == idMuestra) {

            lista[i]->setTipo(muestraEditada->getTipo());
            lista[i]->setFechaToma(muestraEditada->getFechaToma());

            lista[i]->setConsistencia(muestraEditada->getConsistencia());
            lista[i]->setColorHeces(muestraEditada->getColorHeces());
            lista[i]->setOlor(muestraEditada->getOlor());
            lista[i]->setParasitos(muestraEditada->getParasitos());

            lista[i]->setCantidadExtraida(muestraEditada->getCantidadExtraida());
            lista[i]->setCoagulos(muestraEditada->getCoagulos());
            lista[i]->setContaminacion(muestraEditada->getContaminacion());
            lista[i]->setColorSangre(muestraEditada->getColorSangre());
            break;
        }
    }
    escribirArchivo(lista);
}

// Eliminar muestra por ID
void MuestraController::eliminarMuestraArchivo(int idMuestra) {
    List<Muestra^>^ lista = buscarTodasMuestrasArchivo(nullptr);
    for (int i = 0; i < lista->Count; i++) {
        if (lista[i]->getIdMuestra() == idMuestra) {
            lista->RemoveAt(i);
            break;
        }
    }
    escribirArchivo(lista);
}

int MuestraController::generarNuevoId() {
    List<Muestra^>^ lista = buscarTodasMuestrasArchivo(nullptr); // O readTxt() si usas ese nombre
    int maxId = 0;
    for each (Muestra ^ muestra in lista) {
        if (muestra->getIdMuestra() > maxId) {
            maxId = muestra->getIdMuestra();
        }
    }
    return maxId + 1;
}

// Guardar lista completa en archivo
void MuestraController::escribirArchivo(List<Muestra^>^ listaMuestras) {
    array<String^>^ lineas = gcnew array<String^>(listaMuestras->Count);
    for (int i = 0; i < listaMuestras->Count; i++) {
        Muestra^ m = listaMuestras[i];
        Animal^ a = m->getAnimal();
        String^ idAnimalStr = a != nullptr ? a->IdAnimal.ToString() : "0";
        String^ especieStr = a != nullptr ? a->Especie : "null";

        lineas[i] = m->getIdMuestra() + ";" + m->getTipo() + ";" + m->getFechaToma() + ";" +
            m->getConsistencia() + ";" + m->getColorHeces() + ";" + m->getOlor() + ";" + m->getParasitos() + ";" +
            m->getCantidadExtraida() + ";" + m->getCoagulos() + ";" + m->getContaminacion() + ";" + m->getColorSangre() + ";" +
            idAnimalStr + ";" + especieStr;
    }
    File::WriteAllLines("muestras.txt", lineas);
}

void MuestraController::escribirArchivoBINMuestras() {
    //Creamos el archivo
    Stream^ stream = File::Open(this->archivo, FileMode::Create);
    BinaryFormatter^ formateador = gcnew BinaryFormatter();
    formateador->Serialize(stream, this->listaMuestras);
    stream->Close();
}