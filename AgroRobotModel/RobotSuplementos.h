#pragma once
#include "Robot.h"
namespace AGROModel {
    public ref class RobotSuplementos: Robot {
    public:
        property int Dispensadores;
        RobotSuplementos();
        RobotSuplementos(int dispensadores);
    };
}
