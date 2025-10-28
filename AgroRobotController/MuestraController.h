#pragma once

using namespace System;
using namespace System::Collections::Generic;
using namespace AgroRobotModel;

namespace AgroRobotController {

    public ref class MuestraController {
    public:
        MuestraController();

        // Operaciones principales
        void agregarMuestraArchivo(Muestra^ nuevaMuestra);
        void editarMuestraArchivo(int idMuestra, Muestra^ muestraEditada);
        void eliminarMuestraArchivo(int idMuestra);

        // Búsquedas
        List<Muestra^>^ buscarTodasMuestrasArchivo();
        Muestra^ buscarMuestraPorIdArchivo(int idMuestra);
        List<Muestra^>^ buscarMuestrasPorAnimalArchivo(int idAnimal);

        // Persistencia
        void escribirArchivo(List<Muestra^>^ listaMuestras);
    };
}