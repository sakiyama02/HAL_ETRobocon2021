
#include "../../include/Action/ArmAction.h"

ArmAction::ArmAction(){}
ArmAction::~ArmAction(){}
/* ------------------------------------------------------------------------- */
/* 関数名		： run  							    	    	          */
/* 機能名		： 実行             		                    	          */
/* 機能概要		： アームを上げながら直進する                                   */
/* 引数			： int32            :speed          :速度                    */
/* 			    ： PIDData          :pid_data      :ゲイン値とターゲット値    */
/* 			    ： float            :angle         :角度                     */
/* 			    ： CurveData        :curve_data    :半径とカーブ方向          */
/* 戻り値		： int8				:0				:正常終了				  */
/* 作成日		： 2021/07/23		 崎山　勇人		 新規作成			       */
/* ------------------------------------------------------------------------- */
int8 ArmAction::run(int32 speed,PIDData pid_data = {0.0f,0.0f,0.0f,0.0f},
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

    // アームを上げる
    retChk = steering.rotateArm(25);
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