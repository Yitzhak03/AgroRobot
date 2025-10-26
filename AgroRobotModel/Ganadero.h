#pragma once
#include "Usuario.h"
namespace AGROModel {
    using namespace System;

    // Forward declarations to avoid circular includes
    ref class Robot;

    public ref class Ganadero: public Usuario {
    public: 
        property String^ UbicacionGranja;
        property Robot^ Robott;
        Ganadero();
        Ganadero(
            String^ ubicacionGranja,
            Robot^ robott
        );
    };
}