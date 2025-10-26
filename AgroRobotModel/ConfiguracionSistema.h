#pragma once
namespace AGROModel {
    using namespace System;

    // Forward declaration
    ref class Analisis;

    public ref class ConfiguracionSistema {
    public:
        property String^ HorarioOperacion;
        property String^ FrecuenciaAnalisis;
        property String^ UmbralesAlerta;
        property Analisis^ AnalisisDatos;
        ConfiguracionSistema();
        ConfiguracionSistema(
            String^ horarioOperacion,
            String^ frecuenciaAnalisis,
            String^ umbralesAlerta,
            Analisis^ analisisDatos
        );
    };
}