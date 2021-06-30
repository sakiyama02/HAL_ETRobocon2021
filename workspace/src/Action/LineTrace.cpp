
#include "../../include/Action/LineTrace.h"

LineTrace::LineTrace(){}
LineTrace::~LineTrace(){}

int8 LineTrace::run(int32 speed,PIDData pid_data,float angle = 0.0f,CurveData curve_data = {0.0f,(CurveType)0})
{
    int8 retChk = SYS_NG;
    float revision = 0.0f;
    TrapezoidControl &trapezoid = TrapezoidControl::getInstance();
    PidControl &pidControl      = PidControl::getInstance();
    Steering &steering          = Steering::getInstance();
    MotorPower motorPower;

    memset(&motorPower,0,sizeof(MotorPower));

    // 台形制御のターゲット値を設定
    retChk = trapezoid.setTargetSpeed(speed);
    if(retChk != SYS_OK){
        return SYS_NG;
    }
    // 台形制御からモータ速度を取得
    retChk = trapezoid.getMotorPower(&speed);
        if(retChk != SYS_OK){
        return SYS_NG;
    }

    // pid値を渡して補正値を計算する
    retChk = pidControl.calcPid(&pid_data);
    if(retChk != SYS_OK){
        return SYS_NG;
    }

    // pidの補正値を取得
    retChk = pidControl.getRevison(&revision);
    if(retChk != SYS_OK){
        return SYS_NG;
    }

    // 計算
    motorPower.leftPower  = speed + revision;
    motorPower.rightPower = speed - revision;

    // 計算した値で出力
    retChk = steering.rotateWheel(motorPower);
     if(retChk != SYS_OK){
        return SYS_NG;
    }


    return SYS_OK;
}