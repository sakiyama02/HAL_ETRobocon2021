///
/// curve.h
/// カーブ動作のクラスヘッダ
#pragma once
#include "../System/System.h"
#include "Action.h"
#include "../Steering/Steering.h"
#include "../Control/PidControl.h"
#include "../Control/TrapezoidControl.h"

class Curve:public Action{
private:
public:

    Curve();
    ~Curve();

    int8 run(int32 speed,PIDData pid_data,float angle,CurveData curve_data);

};
