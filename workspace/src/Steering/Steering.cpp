
#include "../../include/Steering/Steering.h"

Steering::Steering()
{
    motorAngle.leftAngle = 0;
    motorAngle.rightAngle = 0;
}

Steering::~Steering(){}

int8 Steering::init()
{
    frLog &msg = frLog::GetInstance();
    int8 retChk = SYS_NG;

    leftMotor = new Motor();
    retChk = leftMotor->init(MOTOR_LEFT,LARGE_MOTOR);
    if(retChk != SYS_OK){
        msg.LOG(LOG_ID_ERR,"Steering.init leftMotor err\n");
        return retChk;
    }

    rightMotor = new Motor();
    retChk = rightMotor->init(MOTOR_RIGHT,LARGE_MOTOR);
    if(retChk != SYS_OK){
        msg.LOG(LOG_ID_ERR,"Steering.init rightMotor err\n");
        return retChk;
    }

    armMotor = new Motor();
    retChk = armMotor->init(MOTOR_ARM, LARGE_MOTOR);
    if(retChk != SYS_OK){
        msg.LOG(LOG_ID_ERR,"Steering.init armMotor err\n");
        return retChk;
    }

    tailMotor = new Motor();
    retChk = tailMotor->init(MOTOR_TAIL, MEDIUM_MOTOR);
    if (retChk != SYS_OK)
    {
        msg.LOG(LOG_ID_ERR,"Steering.init tailMotor err\n");
        return retChk;
    }

    return SYS_OK;
}

int8 Steering::rotateArm(int32 keepPower)
{
    frLog &msg = frLog::GetInstance();
    if(keepPower < -100 || keepPower > 100){
        msg.LOG(LOG_ID_ERR,"Steering::rotateArm 引数エラー\n");
        return SYS_PARAM;
    }

    int8 retChk = SYS_NG;

    /* 指定角度でアームを固定する */
    retChk = armMotor->setPWM(keepPower);
     if(retChk != SYS_OK){
        msg.LOG(LOG_ID_ERR,"Steering::rotateArm setPWM err\n");
        return retChk;
    }

    return SYS_OK;
}

int8 Steering::rotateWheel(MotorPower motor_power)
{
    frLog &msg = frLog::GetInstance();
    /* 引数チェック */
    if (motor_power.leftPower < -100 || motor_power.leftPower > 100 ||
        motor_power.rightPower < -100 || motor_power.rightPower > 100)
    {
        msg.LOG(LOG_ID_ERR,"Steering::rotateWheel 引数エラー\n");
        return SYS_PARAM;
    }

    /* 変数宣言 */
    //int32 lCount = 0;
    //int32 rCount = 0;
    int8 retChk = SYS_NG;

    /* 右モータ　PWMset */
    retChk = rightMotor->setPWM(motor_power.rightPower);
    if(retChk != SYS_OK){
        msg.LOG(LOG_ID_ERR,"Steering::rotateWheel setPWM right err\n");
        return retChk;
    }
    /* 左モータ　PWMset */
    retChk = leftMotor->setPWM(motor_power.leftPower);
    if(retChk != SYS_OK){
        msg.LOG(LOG_ID_ERR,"Steering::rotateWheel setPWM left err\n");
        return retChk;
    }

    return SYS_OK;
}

int8 Steering::getMotorAngle(MotorAngle *iAngle)
{
    frLog &msg = frLog::GetInstance();
    /* 引数チェック */ 
    if(iAngle == NULL){
        msg.LOG(LOG_ID_ERR,"Steering::getMotorAngle 引数エラー\n");
        return SYS_PARAM;
    }

    *iAngle=motorAngle;

    return SYS_OK;
}

int8 Steering::updateAngle()
{
    frLog &msg = frLog::GetInstance();
    int8 retChk = SYS_NG;                       /* エラーフラグ                    */

    /* 左モータ回転角get */
    retChk = leftMotor->getCounts(&motorAngle.leftAngle);
    if(retChk != SYS_OK){
        msg.LOG(LOG_ID_ERR,"Steering::updateAngle getCounts left err\n");
        return retChk;
    }

    /* 右モータ回転角get */
    retChk = rightMotor->getCounts(&motorAngle.rightAngle);
    if(retChk != SYS_OK){
        msg.LOG(LOG_ID_ERR,"Steering::updateAngle getCounts right err\n");
        return retChk;
    }

    /* 小さな誤差は真っ直ぐに進んでいる判定にする  */
    if( motorAngle.rightAngle-motorAngle.leftAngle<3&&
        motorAngle.rightAngle-motorAngle.leftAngle>0){

        motorAngle.leftAngle=motorAngle.rightAngle;
    }else if( motorAngle.leftAngle-motorAngle.rightAngle<3&&
        motorAngle.leftAngle-motorAngle.rightAngle>0){

        motorAngle.rightAngle=motorAngle.leftAngle;
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

