#pragma once
#include "../System/System.h"
#include "Action.h"
#include "../Steering/Steering.h"
#include "../Control/TrapezoidControl.h"

class ArmAction : public Action{
    private:
    public:

    ArmAction();
    ~ArmAction();

    int8 run(int32 speed,PIDData pid_data,float angle,CurveData curve_data);
};