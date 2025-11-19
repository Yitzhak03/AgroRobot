#pragma once
#include "MuestraController.h"
#include "GestorNutricionalController.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace AgroRobotModel;

namespace AgroRobotController {

    public ref class DiagnosticoController {
    public:
        DiagnosticoController();

        // Generación automática
        Diagnostico^ generarDiagnosticoParaAnimal(
            int idAnimal,
            MuestraController^ muestraController,
            GestorNutricionalController^ gestor
        );

        // Búsquedas
        int generarNuevoId();
        List<Diagnostico^>^ buscarTodosDiagnosticosArchivo();
        Diagnostico^ buscarDiagnosticoPorIdArchivo(int idDiagnostico);
        List<Diagnostico^>^ buscarDiagnosticosPorAnimalArchivo(int idAnimal);

        // Eliminación
        void eliminarDiagnosticoArchivo(int idDiagnostico);

        // Persistencia
        void escribirArchivo(List<Diagnostico^>^ listaDiagnosticos);
        void guardarDiagnosticoArchivo(Diagnostico^ diagnostico);
    };
}