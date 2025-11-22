#pragma once
#include "GestorNutricionalController.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace AgroRobotModel;

namespace AgroRobotController {

    public ref class MuestraController {

    public:
        MuestraController();

        // Operaciones principales
        void agregarMuestraArchivo(Muestra^ nuevaMuestra, GestorNutricionalController^ gestor);
        void editarMuestraArchivo(int idMuestra, Muestra^ muestraEditada);
        void eliminarMuestraArchivo(int idMuestra);
        int generarNuevoId();

        // Búsquedas
        List<Muestra^>^ buscarTodasMuestrasArchivo(GestorNutricionalController^ gestor);
        Muestra^ buscarMuestraPorIdArchivo(int idMuestra, GestorNutricionalController^ gestor);
        List<Muestra^>^ buscarMuestrasPorAnimalArchivo(int idAnimal, GestorNutricionalController^ gestor);

        // Persistencia
        void escribirArchivo(List<Muestra^>^ listaMuestras);

    };
}