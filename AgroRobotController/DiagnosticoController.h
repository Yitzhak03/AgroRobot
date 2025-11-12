#pragma once

using namespace System;
using namespace System::Collections::Generic;
using namespace AgroRobotModel;

namespace AgroRobotController {

    public ref class DiagnosticoController {
    public:
        DiagnosticoController();

        // Operaciones principales
        void agregarDiagnosticoArchivo(Diagnostico^ nuevoDiagnostico);
        void editarDiagnosticoArchivo(int idDiagnostico, Diagnostico^ diagnosticoEditado);
        void eliminarDiagnosticoArchivo(int idDiagnostico);
        int generarNuevoId();

        // Búsquedas
        List<Diagnostico^>^ buscarTodosDiagnosticosArchivo();
        Diagnostico^ buscarDiagnosticoPorIdArchivo(int idDiagnostico);
        List<Diagnostico^>^ buscarDiagnosticosPorAnimalArchivo(int idAnimal);

        // Persistencia
        void escribirArchivo(List<Diagnostico^>^ listaDiagnosticos);
    };
}

