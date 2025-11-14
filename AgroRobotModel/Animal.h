#pragma once
#include "Dieta.h"
#include "HistoriaClinica.h"
namespace AgroRobotModel {
    using namespace System;
	using namespace System::Collections::Generic;

    // Forward declarations to avoid circular includes
    ref class Muestra;

    public ref class Animal {
    public: 
        property int IdAnimal;
        property String^ Especie;
        property double Peso;
        property double Edad;
        property String^ EstadoSalud;
        property String^ UltimaDieta;
		property List<Muestra^>^ Muestras;
		property Dieta^ Dietaa;
		property List<HistoriaClinica^>^ HistoriasClinicas;
        property String^ UltimaVezAlimentado;
        Animal();
        Animal(
            int idAnimal,
            String^ especie,
            double peso,
            double edad,
            String^ estadoSalud,
            String^ ultimaDieta,
			List<Muestra^>^ muestras,
			Dieta^ dietaa,
            List<HistoriaClinica^>^ historiasClinicas,
            String^ ultimaVezAlimentado
        );
    };
}
