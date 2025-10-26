#pragma once
namespace AgroRobotModel {
    using namespace System;
    using namespace System::Collections::Generic;

    // Forward declarations to avoid circular includes
    ref class Muestra;
    ref class Dieta;

    public ref class Analisis {
    public:
        property int Id;
        property int IdMuestra;
        property String^ Resultados;
        property String^ Observaciones;
        property String^ DiagnosticoGenerado;
        property List<Muestra^>^ Muestras;
        property Dieta^ DietaAsociada;
        Analisis();
        Analisis(
            int id,
            int idMuestra,
            String^ resultados,
            String^ observaciones,
            String^ diagnosticoGenerado,
            List<Muestra^>^ muestras,
            Dieta^ dietaAsociada
        );
    };
}