#pragma once
#include "../System/System.h"
#include "Action.h"
#include "../Steering/Steering.h"
#include "../Control/TrapezoidControl.h"
#include "../CarData/CarPosition.h"

class Turn : public Action {
private:

public:
    Turn();
    ~Turn();

    int8 run(int32 speed,PIDData pid_data,float angle,CurveData curve_data);

};