// 台形制御じゃないよ、加減速制御だよ
#include "../../include/Control/TrapezoidControl.h"

TrapezoidControl::TrapezoidControl()
{
    CarSpeed = 0;
    TargetSpeed = 0;
}

TrapezoidControl::~TrapezoidControl(){}
/* ------------------------------------------------------------------------- */
/* 関数名		： setTargetSpeed							      	          */
/* 機能名		： 目標速度を設定		                   	    	           */
/* 機能概要		： 目標速度を設定する                                            */
/* 引数			： int32            :taeget_speed   :目標速度                  */
/* 戻り値		： int8				:0				:正常終了				  */
/* 作成日		： 2021/07/23		 崎山　勇人		 新規作成			       */
/* ------------------------------------------------------------------------- */
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
/* ------------------------------------------------------------------------- */
/* 関数名		： getMotorPower							      	          */
/* 機能名		： 目標速度を取得		                   	    	           */
/* 機能概要		： 目標速度を取得する                                           */
/* 引数			： int32*            :motor_power   :速度瞬時値格納用           */
/* 戻り値		： int8				:0				:正常終了				  */
/* 作成日		： 2021/07/23		 崎山　勇人		 新規作成			       */
/* ------------------------------------------------------------------------- */
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
/* ------------------------------------------------------------------------- */
/* 関数名		： accelerate   							      	          */
/* 機能名		： 加減速       		                   	    	           */
/* 機能概要		： 一定間隔で速度瞬時値を加減速する                              */
/* 引数			： なし                                                        */
/* 戻り値		： int8				:0				:正常終了				  */
/* 作成日		： 2021/07/23		 崎山　勇人		 新規作成			       */
/* ------------------------------------------------------------------------- */
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