#pragma once
#include "RegistroActividad.h"
namespace AgroRobotModel {
    using namespace System;

    // Forward declarations to avoid circular includes
    ref class Animal;

    public ref class Robot {
    public:
        property int Id;
        property String^ Estado;
        property String^ Bateria;
        property String^ UbicacionActual;
        property Animal^ AnimalAsignado;
        property RegistroActividad^ RegistroActividadd;
        Robot();
        Robot(
            int id,
            String^ estado,
            String^ bateria,
            String^ ubicacionActual,
            Animal^ animalAsignado,
            RegistroActividad^ registroActividadd
        );
    };
}