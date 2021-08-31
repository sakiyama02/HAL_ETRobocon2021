#pragma once
#include "../System/System.h"

// 加速度
#define ACCELERATION 2

class TrapezoidControl{
private:
    int32 CarSpeed;
    int32 TargetSpeed;

public:
    TrapezoidControl();
    ~TrapezoidControl();

    int8 setTargetSpeed(int32 target_speed);

    int8 getMotorPower(int32* motor_power);

    int8 accelerate();


    static TrapezoidControl &getInstance()
    {
        static TrapezoidControl TrapezoidControl_;
        return TrapezoidControl_;
    }
};