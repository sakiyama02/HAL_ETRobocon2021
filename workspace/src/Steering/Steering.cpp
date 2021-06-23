
#include "../../include/Steering/Steering.h"

Steering::Steering()
{

}

Steering::~Steering(){}

int8 Steering::init(){
    int8 retChk = SYS_NG;

    leftMotor = new Motor();
    retChk = leftMotor->init(MOTOR_LEFT,LARGE_MOTOR);

    rightMotor = new Motor();
    retChk = rightMotor->init(MOTOR_RIGHT,LARGE_MOTOR);

}

int8 Steering::rotateWheel(MotorPower motor_power){

    /* 引数チェック */
    if (motor_power.leftPower < -100 || motor_power.leftPower > 100 ||
        motor_power.rightPower < -100 || motor_power.rightPower > 100)
    {}

    /* 変数宣言 */
    int32 lCount = 0;
    int32 rCount = 0;
    int8 retChk = SYS_NG;

    /* 左モータ回転角get */
    // retChk = leftMotor->getCounts(&lCounts);
    /* 右モータ回転角get */
    // retChk = rightMotor->getCounts(&rCounts);
    /* 回転角計算 */
    /* 右モータ　PWMset */
    /* 左モータ　PWMset */


}

int8 Steering::getMotorAngle(MotorAngle *iAngle){


}