
#include "../../include/Steering/Steering.h"

Steering::Steering()
{
    motorAngle.leftAngle = 0;
    motorAngle.rightAngle = 0;
}

Steering::~Steering(){}

int8 Steering::init(){
    int8 retChk = SYS_NG;

    leftMotor = new Motor();
    retChk = leftMotor->init(MOTOR_LEFT,LARGE_MOTOR);
    if(retChk != SYS_OK){
        /* 左モータのインスタンスエラー */
        return retChk;
    }

    rightMotor = new Motor();
    retChk = rightMotor->init(MOTOR_RIGHT,LARGE_MOTOR);
    if(retChk != SYS_OK){
        /* 右モータのインスタンスエラー */
        return retChk;
    }

    return SYS_OK;
}

int8 Steering::rotateWheel(MotorPower motor_power){

    /* 引数チェック */
    if (motor_power.leftPower < -100 || motor_power.leftPower > 100 ||
        motor_power.rightPower < -100 || motor_power.rightPower > 100)
    {
        /* 引数エラー */
        return SYS_PARAM;
    }

    /* 変数宣言 */
    int32 lCount = 0;
    int32 rCount = 0;
    int8 retChk = SYS_NG;

    /* 右モータ　PWMset */
    retChk = rightMotor->setPWM(motor_power.rightPower);
    if(retChk != SYS_OK){
        /* 右モータのPWM値のエラー */
        return retChk;
    }
    /* 左モータ　PWMset */
    retChk = leftMotor->setPWM(motor_power.leftPower);
    if(retChk != SYS_OK){
        /* 左モータのPWM値のエラー */
        return retChk;
    }

    return SYS_OK;
}

int8 Steering::getMotorAngle(MotorAngle *iAngle){
    /* 引数チェック */ 
    if(iAngle == NULL){
        /* 引数エラー */
        return SYS_PARAM;
    }

    *iAngle=motorAngle;

    return SYS_OK;
}

int8 Steering::updateAngle(){

    int8 retChk = SYS_NG;                       /* エラーフラグ                    */

    /* 左モータ回転角get */
    retChk = leftMotor->getCounts(&motorAngle.leftAngle);
    if(retChk != SYS_OK){
        /* 左モータの回転角取得のエラー */
        return retChk;
    }

    /* 右モータ回転角get */
    retChk = rightMotor->getCounts(&motorAngle.rightAngle);
    if(retChk != SYS_OK){
        /* 右モータの回転角取得のエラー */
        return retChk;
    }

    return SYS_OK; 
}

int8 Steering::deletePort(){
    delete (leftMotor);
    delete (rightMotor);
    delete (armMotor);
    delete (tailMotor);
    return SYS_OK;
}

