#pragma once
#include "Usuario.h"
namespace AgroRobotModel {
    using namespace System;

    /*Declaración para evitar referencias circulares*/
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