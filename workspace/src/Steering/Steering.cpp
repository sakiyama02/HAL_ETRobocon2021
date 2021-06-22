
#include "../../include/Steering/Steering.h"

Steering::Steering()
{

}

Steering::~Steering(){}

int8 Steering::rotateWheel(MotorPower motor_Power,Motorport motor_Port){

    /* 引数チェック */
    if (motorPower.leftPower < -100 || motorPower.leftPower > 100 ||
        motorPower.rightPower < -100 || motorPower.rightPower > 100)
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