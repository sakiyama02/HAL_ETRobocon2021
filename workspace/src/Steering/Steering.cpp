
#include "../../include/Steering/Steering.h"
/* ------------------------------------------------------------------------- */
/* 関数名		： steering												      */
/* 機能名		： コンストラクタ										       */
/* 機能概要		： メンバー変数の初期化									        */
/* 引数			： なし													      */
/* 戻り値		： なし                                     			      */
/* 作成日		： 2021/07/23		 崎山　勇人		 新規作成			       */
/* ------------------------------------------------------------------------- */
Steering::Steering()
{
    motorAngle.leftAngle  = 0;
    motorAngle.rightAngle = 0;
}

Steering::~Steering(){}
/* ------------------------------------------------------------------------- */
/* 関数名		： init											    	      */
/* 機能名		： 初期化       										      */
/* 機能概要		： 各モータにポート番号を設定する						         */
/* 引数			： なし													      */
/* 戻り値		： int8				:0				:正常終了				  */
/* 作成日		： 2021/07/23		 崎山　勇人		 新規作成			       */
/* ------------------------------------------------------------------------- */
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
/* ------------------------------------------------------------------------- */
/* 関数名		： rotateArm									    	      */
/* 機能名		： アーム制御       									      */
/* 機能概要		： アームを制御する             						       */
/* 引数			： int32            :keepPower      :キープパワーという名のただの出力値 */
/* 戻り値		： int8				:0				:正常終了				  */
/* 作成日		： 2021/07/23		 崎山　勇人		 新規作成			       */
/* ------------------------------------------------------------------------- */
int8 Steering::rotateArm(int32 keepPower)
{
    frLog &msg = frLog::GetInstance();
    if(keepPower < -100 || keepPower > 100){
        msg.LOG(LOG_ID_ERR,"Steering::rotateArm 引数エラー\n");
        return SYS_PARAM;
    }

    int8 retChk = SYS_NG;

    retChk = armMotor->setPWM(keepPower);
     if(retChk != SYS_OK){
        msg.LOG(LOG_ID_ERR,"Steering::rotateArm setPWM err\n");
        return retChk;
    }

    return SYS_OK;
}
/* ------------------------------------------------------------------------- */
/* 関数名		： rotateWheel									    	      */
/* 機能名		： モータ制御       									      */
/* 機能概要		： モータを制御する             						       */
/* 引数			： int32            :motor_power    :モータへの出力値          */
/* 戻り値		： int8				:0				:正常終了				  */
/* 作成日		： 2021/07/23		 崎山　勇人		 新規作成			       */
/* ------------------------------------------------------------------------- */
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
/* ------------------------------------------------------------------------- */
/* 関数名		： getMotorAngle								    	      */
/* 機能名		： モータ角度取得       								      */
/* 機能概要		： モータ角度を取得する           						       */
/* 引数			： MotorAngle       :*iAngle        :角度格納用               */
/* 戻り値		： int8				:0				:正常終了				  */
/* 作成日		： 2021/07/23		 崎山　勇人		 新規作成			       */
/* ------------------------------------------------------------------------- */
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
/* ------------------------------------------------------------------------- */
/* 関数名		： updateAngle  								    	      */
/* 機能名		： モータ角度更新       								      */
/* 機能概要		： モータ角度を更新する           						       */
/* 引数			： なし                                                       */
/* 戻り値		： int8				:0				:正常終了				  */
/* 作成日		： 2021/07/23		 崎山　勇人		 新規作成			       */
/* ------------------------------------------------------------------------- */
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
/* ------------------------------------------------------------------------- */
/* 関数名		： deletePort     								    	      */
/* 機能名		：        			                					      */
/* 機能概要		： メンバー変数の解放           						       */
/* 引数			： なし                                                       */
/* 戻り値		： なし                                     				  */
/* 作成日		： 2021/07/23		 崎山　勇人		 新規作成			       */
/* ------------------------------------------------------------------------- */
int8 Steering::deletePort(){
    delete (leftMotor);
    delete (rightMotor);
    delete (armMotor);
    delete (tailMotor);
    return SYS_OK;
}

