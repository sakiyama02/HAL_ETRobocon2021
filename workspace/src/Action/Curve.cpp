///
/// Curve.cpp
/// カーブ動作のクラス

#include "../../include/Action/Curve.h"

Curve::Curve(){}
Curve::~Curve(){}

int8 Curve::run(int32 speed,PIDData pid_data,float angle,CurveData curve_data)
{
    int8  retChk     = SYS_NG;
    float revision   = 0.0f;
    float ratioLeft  = 0.0f;
    float ratioRight = 0.0f;
    TrapezoidControl &trapezoid = TrapezoidControl::getInstance();
    PidControl &pidControl      = PidControl::getInstance();
    Steering &steering          = Steering::getInstance();
    MotorPower motorPower;


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

    // 左カーブの比率
    if( curve_data.dirction == CURVE_LEFT ) {
        ratioLeft  = curve_data.radius + CAR_WIDTH / 2;
        ratioRight = curve_data.radius - CAR_WIDTH / 2;
    } 
    // 左カーブの比率
    else if( curve_data.dirction == CURVE_RIGHT ) {
        ratioLeft  = curve_data.radius - CAR_WIDTH / 2;
        ratioRight = curve_data.radius + CAR_WIDTH / 2;
    }
    // カーブの比率計算
    motorPower.leftPower  = speed * ratioLeft;
    motorPower.rightPower = speed * ratioRight;

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

    // 出力値計算
    motorPower.leftPower  += revision;
    motorPower.rightPower -= revision;

   // 計算した値で出力
    retChk = steering.rotateWheel(motorPower);
     if(retChk != SYS_OK){
        return SYS_NG;
    }

    return SYS_OK;
}