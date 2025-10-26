#pragma once
#include "Dieta.h"
namespace AgroRobotModel {
    using namespace System;

    public ref class ParametroNutricional {
    public: 
        property int IdParametro;
        property String^ Nombre;
        property String^ RangoSaludable;
        property String^ RangoCritico;
        property String^ UnidadMedida;
		property Dieta^ DietaAsociada;
        ParametroNutricional();
        ParametroNutricional(
            int idParametro,
            String^ nombre,
            String^ rangoSaludable,
            String^ rangoCritico,
            String^ unidadMedida,
            Dieta^ dietaAsociada
        );
    };
}