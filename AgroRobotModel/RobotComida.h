#pragma once
#include "Robot.h"
namespace AGROModel {
    public ref class RobotComida: Robot {
    public:
        property double CapacidadCarga;
        RobotComida();
        RobotComida(double capacidadCarga);
    };
}
