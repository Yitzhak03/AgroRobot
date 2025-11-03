#include "DiagnosticoController.h"

using namespace AgroRobotController;
using namespace System::IO;

DiagnosticoController::DiagnosticoController() {}

void DiagnosticoController::agregarDiagnosticoArchivo(Diagnostico^ nuevoDiagnostico) {
    List<Diagnostico^>^ lista = buscarTodosDiagnosticosArchivo();
    lista->Add(nuevoDiagnostico);
    escribirArchivo(lista);
}

void DiagnosticoController::editarDiagnosticoArchivo(int idDiagnostico, Diagnostico^ diagnosticoEditado) {
    List<Diagnostico^>^ lista = buscarTodosDiagnosticosArchivo();
    for (int i = 0; i < lista->Count; i++) {
        if (lista[i]->getIdDiagnostico() == idDiagnostico) {
            lista[i] = diagnosticoEditado;
            break;
        }
    }
    escribirArchivo(lista);
}

void DiagnosticoController::eliminarDiagnosticoArchivo(int idDiagnostico) {
    List<Diagnostico^>^ lista = buscarTodosDiagnosticosArchivo();
    for (int i = 0; i < lista->Count; i++) {
        if (lista[i]->getIdDiagnostico() == idDiagnostico) {
            lista->RemoveAt(i);
            break;
        }
    }
    escribirArchivo(lista);
}

int DiagnosticoController::generarNuevoId() {
    List<Diagnostico^>^ lista = buscarTodosDiagnosticosArchivo();
    int maxId = 0;
    for each (Diagnostico ^ d in lista) {
        if (d->getIdDiagnostico() > maxId)
            maxId = d->getIdDiagnostico();
    }
    return maxId + 1;
}

List<Diagnostico^>^ DiagnosticoController::buscarTodosDiagnosticosArchivo() {
    List<Diagnostico^>^ lista = gcnew List<Diagnostico^>();
    if (!File::Exists("diagnostico.txt")) return lista;

    array<String^>^ lineas = File::ReadAllLines("diagnostico.txt");
    String^ separador = ";";

    for each (String ^ linea in lineas) {
        array<String^>^ campos = linea->Split(separador->ToCharArray());

        int idDiagnostico = Convert::ToInt32(campos[0]);
        int idAnimal = Convert::ToInt32(campos[1]);
        String^ especie = campos[2];
        String^ resultadoHeces = campos[3];
        String^ resultadoSangre = campos[4];
        String^ estadoSalud = campos[5];
        String^ observaciones = campos[6];
        String^ fecha = campos[7];

        Diagnostico^ d = gcnew Diagnostico(idDiagnostico, idAnimal, especie, resultadoHeces, resultadoSangre, estadoSalud, observaciones, fecha);
        lista->Add(d);
    }
    return lista;
}

Diagnostico^ DiagnosticoController::buscarDiagnosticoPorIdArchivo(int idDiagnostico) {
    List<Diagnostico^>^ lista = buscarTodosDiagnosticosArchivo();
    for each (Diagnostico ^ d in lista) {
        if (d->getIdDiagnostico() == idDiagnostico)
            return d;
    }
    return nullptr;
}

List<Diagnostico^>^ DiagnosticoController::buscarDiagnosticosPorAnimalArchivo(int idAnimal) {
    List<Diagnostico^>^ lista = buscarTodosDiagnosticosArchivo();
    List<Diagnostico^>^ filtrados = gcnew List<Diagnostico^>();
    for each (Diagnostico ^ d in lista) {
        if (d->getIdAnimal() == idAnimal)
            filtrados->Add(d);
    }
    return filtrados;
}

void DiagnosticoController::escribirArchivo(List<Diagnostico^>^ listaDiagnosticos) {
    array<String^>^ lineas = gcnew array<String^>(listaDiagnosticos->Count);
    for (int i = 0; i < listaDiagnosticos->Count; i++) {
        Diagnostico^ d = listaDiagnosticos[i];
        lineas[i] = d->getIdDiagnostico() + ";" + d->getIdAnimal() + ";" + d->getEspecie() + ";" +
            d->getResultadoHeces() + ";" + d->getResultadoSangre() + ";" + d->getEstadoSalud() + ";" +
            d->getObservaciones() + ";" + d->getFecha();
    }
    File::WriteAllLines("diagnostico.txt", lineas);
}
