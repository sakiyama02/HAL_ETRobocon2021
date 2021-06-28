
#include "../../include/Control/TrapezoidControl.h"

TrapezoidControl::TrapezoidControl()
{
    CarSpeed = 0;
    TargetSpeed = 0;
}

TrapezoidControl::~TrapezoidControl(){}

int8 TrapezoidControl::setTargetSpeed(int32 taeget_speed)
{
    if( taeget_speed < -100 || taeget_speed > 100 ){
        return SYS_PARAM;
    }

    if( TargetSpeed != taeget_speed ) {
        TargetSpeed = taeget_speed;
    }

    return SYS_OK;
}

int8 TrapezoidControl::getMotorPower(int32* motor_power)
{
    if( motor_power == NULL ){
        return SYS_PARAM;
    }

    *motor_power = CarSpeed;

    return SYS_OK;
}

int8 TrapezoidControl::accelerate()
{
    if ( CarSpeed == TargetSpeed ){
        return SYS_OK;
    }


    if( CarSpeed < TargetSpeed ) {
        CarSpeed += ACCELERATION;

        if( CarSpeed > TargetSpeed ){
            CarSpeed = TargetSpeed;
        }
    } else {
        CarSpeed -= ACCELERATION;

        if( CarSpeed < TargetSpeed ){
            CarSpeed = TargetSpeed;
        }
    }

    return SYS_OK;
}