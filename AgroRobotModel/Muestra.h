#pragma once
namespace AGROModel {
    using namespace System;

    // Forward declarations to avoid circular includes
    ref class Ganadero;

    public ref class Muestra {
    public: 
        property int IdMuestra;
        property int IdAnimal;
        property String^ Tipo;
        property String^ FechaToma;
        property String^ DatosCrudos;
		property Ganadero^ Ganaderoo;
        Muestra();
        Muestra(
            int idMuestra,
            int idAnimal,
            String^ tipo,
            String^ fechaToma,
            String^ datosCrudos,
            Ganadero^ ganaderoo
        );
    };
}