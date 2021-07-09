
#include "../../include/Action/ArmAction.h"

ArmAction::ArmAction(){}
ArmAction::~ArmAction(){}

int8 ArmAction::run(int32 speed,PIDData pid_data = {0.0f,0.0f,0.0f,0.0f},
    float angle = 0.0f,CurveData curve_data = {0.0f,(CurveType)0})
{
    frLog &msg = frLog::GetInstance();
    if( speed < -100 && speed > 100 ) {
        msg.LOG(LOG_ID_ERR,"ArmAction 引数エラー\n");
        return SYS_PARAM;
    }

    int8 retChk = SYS_NG;
    TrapezoidControl &trapezoid = TrapezoidControl::getInstance();
    Steering &steering          = Steering::getInstance();
    MotorPower motorPower;

    memset(&motorPower,0,sizeof(MotorPower));

    // アームを上げる
    retChk = steering.rotateArm(30);
    if(retChk != SYS_OK){
        msg.LOG(LOG_ID_ERR,"ArmAction rotateArm err\n");
        return SYS_NG;
    }

    // 台形制御のターゲット値を設定
    retChk = trapezoid.setTargetSpeed(speed);
    if(retChk != SYS_OK){
        msg.LOG(LOG_ID_ERR,"ArmAction setTargetSpeed err\n");
        return SYS_NG;
    }
    // 台形制御からモータ速度を取得
    retChk = trapezoid.getMotorPower(&speed);
        if(retChk != SYS_OK){
        msg.LOG(LOG_ID_ERR,"ArmAction getMotorPower err\n");
        return SYS_NG;
    }

    // 計算
    motorPower.leftPower  = speed;
    motorPower.rightPower = speed;

    // 計算した値で出力
    retChk = steering.rotateWheel(motorPower);
     if(retChk != SYS_OK){
        msg.LOG(LOG_ID_ERR,"ArmAction rotateWheel err\n");
        return SYS_NG;
    }
    return SYS_OK;
}