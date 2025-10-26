#pragma once
#include "Robot.h"
namespace AgroRobotModel {
    public ref class RobotAgua: Robot {
    public:
        property double CapacidadTanque;
        RobotAgua();
        RobotAgua(double capacidadTanque);
    };
}
