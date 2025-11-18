#include "DiagnosticoController.h"

using namespace AgroRobotController;
using namespace System::IO;

DiagnosticoController::DiagnosticoController() {}

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
    List<Diagnostico^>^ lista = gcnew List<Diagnostico^>();
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

    return lista;
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

Diagnostico^ DiagnosticoController::generarDiagnosticoParaAnimal(
    int idAnimal,
    MuestraController^ muestraController,
    GestorNutricionalController^ gestor
) {
    List<Muestra^>^ muestras = muestraController->buscarMuestrasPorAnimalArchivo(idAnimal, gestor);

    if (muestras == nullptr || muestras->Count == 0) {
        return nullptr; // No hay muestras, no se genera diagnóstico
    }

    String^ resultadoHeces = "No";
    String^ resultadoSangre = "No";
    String^ especie = "";

    for each (Muestra ^ m in muestras) {
        if (m->getAnimal() != nullptr) {
            especie = m->getAnimal()->Especie;
        }

        if (m->getTipo()->Equals("Heces") && m->getParasitos()->Equals("Sí")) {
            resultadoHeces = "Sí";
        }

        if (m->getTipo()->Equals("Sangre") && m->getContaminacion()->Equals("Sí")) {
            resultadoSangre = "Sí";
        }
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
