

#include "../../include/Action/Turn.h"

Turn::Turn(){}
Turn::~Turn(){}

int8 Turn::run(int32 speed,PIDData pid_data,float angle,CurveData curve_data = {0.0f,(CurveType)0})
{
    frLog &msg = frLog::GetInstance();
    if( speed < -100 && speed > 100 ) {
        msg.LOG(LOG_ID_ERR,"Turn::run 引数エラー\n");
        return SYS_PARAM;
    }

    int8 retChk = SYS_NG;
    float nowAngle = 0.0f;
    MotorPower        motorPower;
    Steering         &steering    = Steering::getInstance();
    TrapezoidControl &trapezoid   = TrapezoidControl::getInstance();
    CarPosition      &carPosiiton = CarPosition::getInstance();
   
    memset(&motorPower,0,sizeof(MotorPower));

    // 現在の車体角度取得
    retChk = carPosiiton.getDir(&nowAngle);
    if(retChk != SYS_OK){
        msg.LOG(LOG_ID_ERR,"Turn::run getDir err\n");
        return SYS_NG;
    }

    // 台形制御のターゲット値を設定
    retChk = trapezoid.setTargetSpeed(speed);
    if(retChk != SYS_OK){
        msg.LOG(LOG_ID_ERR,"Turn::run setTargetSpeed err\n");
        return SYS_NG;
    }
    // 台形制御からモータ速度を取得
    retChk = trapezoid.getMotorPower(&speed);
        if(retChk != SYS_OK){
        msg.LOG(LOG_ID_ERR,"Turn::run getMotorPower err\n");
        return SYS_NG;
    }

    // 方向を決める
    if( nowAngle > angle ) {
        motorPower.leftPower  = -speed;
        motorPower.rightPower =  speed;
    } else if ( nowAngle < angle ) {
        motorPower.leftPower  =  speed;
        motorPower.rightPower =  -speed;
    }

    // 計算した値で出力
    retChk = steering.rotateWheel(motorPower);
     if(retChk != SYS_OK){
        msg.LOG(LOG_ID_ERR,"Turn::run rotateWheel err\n");
        return SYS_NG;
    }
    
    return SYS_OK;
}
