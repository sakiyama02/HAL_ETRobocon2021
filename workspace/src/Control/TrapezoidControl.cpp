
#include "../../include/Control/TrapezoidControl.h"

TrapezoidControl::TrapezoidControl()
{
    CarSpeed = 0;
    TargetSpeed = 0;
}

TrapezoidControl::~TrapezoidControl(){}

int8 TrapezoidControl::setTargetSpeed(int32 taeget_speed)
{
    frLog &msg = frLog::GetInstance();
    if( taeget_speed < -100 || taeget_speed > 100 ){
        msg.LOG(LOG_ID_ERR,"TrapezoidControl::setTargetSpeed 引数エラー\n");
        return SYS_PARAM;
    }

    if( TargetSpeed != taeget_speed ) {
        TargetSpeed = taeget_speed;
    }

    return SYS_OK;
}

int8 TrapezoidControl::getMotorPower(int32* motor_power)
{
    frLog &msg = frLog::GetInstance();
    if( motor_power == NULL ){
        msg.LOG(LOG_ID_ERR,"TrapezoidControl::getMotorPower 引数エラー\n");
        return SYS_PARAM;
    }

    *motor_power = CarSpeed;

    return SYS_OK;
}

int8 TrapezoidControl::accelerate()
{
    //frLog &msg = frLog::GetInstance();
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