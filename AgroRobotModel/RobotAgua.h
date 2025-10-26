#pragma once
#include "Robot.h"
namespace AGROModel {
    public ref class RobotAgua: Robot {
    public:
        property double CapacidadTanque;
        RobotAgua();
        RobotAgua(double capacidadTanque);
    };
}
