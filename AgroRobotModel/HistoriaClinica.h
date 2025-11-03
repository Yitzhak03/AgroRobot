#pragma once
#include "Reporte.h"
#include "Diagnostico.h"
namespace AgroRobotModel {
    using namespace System;
	using namespace System::Collections::Generic;
    public ref class HistoriaClinica {
    public: 
        property int IdAnimal;
        property String^ RegistrarAnalisis;
        property String^ RegistrarDietas;
        property String^ EvolucionSalud;
        property String^ PlanesNutricionales;
		property Reporte^ ReporteAsociado;
		property List<Diagnostico^>^ AnalisisRealizados;
        HistoriaClinica();
        HistoriaClinica(
            int idAnimal,
            String^ registrarAnalisis,
            String^ registrarDietas,
            String^ evolucionSalud,
            String^ planesNutricionales,
            Reporte^ reporteAsociado,
            List<Diagnostico^>^ AnalisisRealizados
        );
    };
}
