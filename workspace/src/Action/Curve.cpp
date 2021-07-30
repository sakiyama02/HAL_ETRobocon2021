///
/// Curve.cpp
/// カーブ動作のクラス

#include "../../include/Action/Curve.h"

Curve::Curve(){}
Curve::~Curve(){}

int8 Curve::run(int32 speed,PIDData pid_data,float angle,CurveData curve_data)
{
    frLog &msg = frLog::GetInstance();
    if( speed < -100 && speed > 100 ) {
        msg.LOG(LOG_ID_ERR,"Curve::run 引数エラー\n");
        return SYS_PARAM;
    }

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
        msg.LOG(LOG_ID_ERR,"Curve::run setTargetSpeed err\n");
        return SYS_NG;
    }
    // 台形制御からモータ速度を取得
    retChk = trapezoid.getMotorPower(&speed);
        if(retChk != SYS_OK){
        msg.LOG(LOG_ID_ERR,"Curve::run getMotorPower err\n");
        return SYS_NG;
    }

    // 左カーブの比率
    if( curve_data.dirction == CURVE_LEFT ) {
        ratioLeft  = (curve_data.radius - CAR_WIDTH / 2)/(curve_data.radius + CAR_WIDTH / 2);
        ratioRight = 1;
    } 
    // 左カーブの比率
    else if( curve_data.dirction == CURVE_RIGHT ) {
        ratioLeft  = 1;
        ratioRight = (curve_data.radius - CAR_WIDTH / 2)/(curve_data.radius + CAR_WIDTH / 2);
    }
    // カーブの比率計算
    motorPower.leftPower  = speed * ratioLeft;
    motorPower.rightPower = speed * ratioRight;

    // pid値を渡して補正値を計算する
    retChk = pidControl.calcPid(&pid_data);
    if(retChk != SYS_OK){
        msg.LOG(LOG_ID_ERR,"Curve::run getMotorPower err\n");
        return SYS_NG;
    }

    // pidの補正値を取得
    retChk = pidControl.getRevison(&revision);
    if(retChk != SYS_OK){
        msg.LOG(LOG_ID_ERR,"Curve::run getRevision err\n");
        return SYS_NG;
    }

    // 出力値計算
    motorPower.leftPower  += revision;
    motorPower.rightPower -= revision;
    if(motorPower.leftPower > 100){
        motorPower.leftPower = 100;
    } else if(motorPower.rightPower > 100){
        motorPower.rightPower = 100;
    }

    if(motorPower.rightPower < -100){
        motorPower.rightPower = -100;
    } else if(motorPower.leftPower < -100){
        motorPower.leftPower = -100;
    }

   // 計算した値で出力
    retChk = steering.rotateWheel(motorPower);
     if(retChk != SYS_OK){
        msg.LOG(LOG_ID_ERR,"Curve::run rotateWheel err\n");
        return SYS_NG;
    }

    return SYS_OK;
}