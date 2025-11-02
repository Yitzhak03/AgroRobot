#include "MuestraController.h"

using namespace AgroRobotController;
using namespace System::IO;

MuestraController::MuestraController() {
}

// Leer todas las muestras desde archivo
List<Muestra^>^ MuestraController::buscarTodasMuestrasArchivo() {
    List<Muestra^>^ listaMuestras = gcnew List<Muestra^>();
    if (!File::Exists("muestras.txt")) return listaMuestras;

    array<String^>^ lineas = File::ReadAllLines("muestras.txt");
    for each (String ^ linea in lineas) {
        array<String^>^ campos = linea->Split(';');
        int idMuestra = Convert::ToInt32(campos[0]);
        int idAnimal = Convert::ToInt32(campos[1]);
        String^ tipo = campos[2];
        String^ fechaToma = campos[3];

        // Campos de heces
        String^ consistencia = campos[4];
        String^ colorHeces = campos[5];
        String^ olor = campos[6];
        String^ parasitos = campos[7];

        // Campos de sangre
        String^ cantidadExtraida = campos[8];
       // String^ colorSangre = campos[9];
        String^ coagulos = campos[9];
        String^ contaminacion = campos[10];
        String^ colorSangre = campos[11];

        Muestra^ muestra = gcnew Muestra(idMuestra, idAnimal, tipo, fechaToma,
            consistencia, colorHeces, olor, parasitos,
            cantidadExtraida, coagulos, contaminacion, colorSangre);

        listaMuestras->Add(muestra);
    }
    return listaMuestras;
}

// Buscar muestra por ID
Muestra^ MuestraController::buscarMuestraPorIdArchivo(int idMuestra) {
    List<Muestra^>^ lista = buscarTodasMuestrasArchivo();
    for each (Muestra ^ m in lista) {
        if (m->getIdMuestra() == idMuestra)
            return m;
    }
    return nullptr;
}

// Buscar muestras por ID de animal
List<Muestra^>^ MuestraController::buscarMuestrasPorAnimalArchivo(int idAnimal) {
    List<Muestra^>^ lista = buscarTodasMuestrasArchivo();
    List<Muestra^>^ resultado = gcnew List<Muestra^>();
    for each (Muestra ^ m in lista) {
        if (m->getIdAnimal() == idAnimal)
            resultado->Add(m);
    }
    return resultado;
}

// Agregar nueva muestra
void MuestraController::agregarMuestraArchivo(Muestra^ nuevaMuestra) {
    List<Muestra^>^ lista = buscarTodasMuestrasArchivo();
    lista->Add(nuevaMuestra);
    escribirArchivo(lista);
}

// Editar muestra existente
void MuestraController::editarMuestraArchivo(int idMuestra, Muestra^ muestraEditada) {
    List<Muestra^>^ lista = buscarTodasMuestrasArchivo();
    for (int i = 0; i < lista->Count; i++) {
        if (lista[i]->getIdMuestra() == idMuestra) {
            lista[i]->setIdAnimal(muestraEditada->getIdAnimal());
            lista[i]->setTipo(muestraEditada->getTipo());
            lista[i]->setFechaToma(muestraEditada->getFechaToma());

            lista[i]->setConsistencia(muestraEditada->getConsistencia());
            lista[i]->setColorHeces(muestraEditada->getColorHeces());
            lista[i]->setOlor(muestraEditada->getOlor());
            lista[i]->setParasitos(muestraEditada->getParasitos());

            lista[i]->setCantidadExtraida(muestraEditada->getCantidadExtraida());
            //lista[i]->setColorSangre(muestraEditada->getColorSangre());
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
    List<Muestra^>^ lista = buscarTodasMuestrasArchivo();
    for (int i = 0; i < lista->Count; i++) {
        if (lista[i]->getIdMuestra() == idMuestra) {
            lista->RemoveAt(i);
            break;
        }
    }
    escribirArchivo(lista);
}

// Guardar lista completa en archivo
void MuestraController::escribirArchivo(List<Muestra^>^ listaMuestras) {
    array<String^>^ lineas = gcnew array<String^>(listaMuestras->Count);
    for (int i = 0; i < listaMuestras->Count; i++) {
        Muestra^ m = listaMuestras[i];
        /*lineas[i] = m->getIdMuestra() + ";" + m->getIdAnimal() + ";" + m->getTipo() + ";" + m->getFechaToma() + ";" +
            m->getConsistencia() + ";" + m->getColorHeces() + ";" + m->getOlor() + ";" + m->getParasitos() + ";" +
            m->getCantidadExtraida() + ";" + m->getColorSangre() + ";" + m->getCoagulos() + ";" + m->getContaminacion();*/
        lineas[i] = m->getIdMuestra() + ";" + m->getIdAnimal() + ";" + m->getTipo() + ";" + m->getFechaToma() + ";" +
            m->getConsistencia() + ";" + m->getColorHeces() + ";" + m->getOlor() + ";" + m->getParasitos() + ";" +
            m->getCantidadExtraida() + ";" + m->getCoagulos() + ";" + m->getContaminacion() + "; " + m->getColorSangre();
    }
    File::WriteAllLines("muestras.txt", lineas);
}
