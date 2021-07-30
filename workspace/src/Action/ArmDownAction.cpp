
#include "../../include/Action/ArmDownAction.h"

ArmDownAction::ArmDownAction(){}
ArmDownAction::~ArmDownAction(){}

int8 ArmDownAction::run(int32 speed,PIDData pid_data = {0.0f,0.0f,0.0f,0.0f},
    float angle = 0.0f,CurveData curve_data = {0.0f,(CurveType)0})
{
    frLog &msg = frLog::GetInstance();
    if( speed < -100 && speed > 100 ) {
        msg.LOG(LOG_ID_ERR,"ArmAction::run 引数エラー\n");
        return SYS_PARAM;
    }

    int8 retChk = SYS_NG;
    TrapezoidControl &trapezoid = TrapezoidControl::getInstance();
    Steering &steering          = Steering::getInstance();
    MotorPower motorPower;

    memset(&motorPower,0,sizeof(MotorPower));




    // アームを下げる
    retChk = steering.rotateArm(-100);
    if(retChk != SYS_OK){
        msg.LOG(LOG_ID_ERR,"ArmAction::run rotateArm err\n");
        return SYS_NG;
    }

    // 台形制御のターゲット値を設定
    retChk = trapezoid.setTargetSpeed(speed);
    if(retChk != SYS_OK){
        msg.LOG(LOG_ID_ERR,"ArmAction::run setTargetSpeed err\n");
        return SYS_NG;
    }
    // 台形制御からモータ速度を取得
    retChk = trapezoid.getMotorPower(&speed);
        if(retChk != SYS_OK){
        msg.LOG(LOG_ID_ERR,"ArmAction::run getMotorPower err\n");
        return SYS_NG;
    }

    // 計算
    motorPower.leftPower  = speed;
    motorPower.rightPower = speed;

    // 計算した値で出力
    retChk = steering.rotateWheel(motorPower);
     if(retChk != SYS_OK){
        msg.LOG(LOG_ID_ERR,"ArmAction::run rotateWheel err\n");
        return SYS_NG;
    }
    return SYS_OK;
}