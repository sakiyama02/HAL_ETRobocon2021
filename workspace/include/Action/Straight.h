#pragma once
#include "../System/System.h"
#include "Action.h"
#include "../Steering/Steering.h"
#include "../Control/TrapezoidControl.h"

class Straight : public Action{
    private:
    public:

    Straight();
    ~Straight();

    int8 run(int32 speed,PIDData pid_data,float angle,CurveData curve_data);
};