//
//  PidControl.cpp
//  Pid制御クラス
//
#include "../../include/Control/PidControl.h"

PidControl::PidControl()
{
    eDeviation = 0.0f;
    stackIntegral = 0.0f;
    moterRevison = 0;
}
PidControl::~PidControl(){}

/* -------------------------------------------------------------------------- */
/* 関数名       ：calcPid                                                      */
/* 機能名       ：pid計算                                                       */
/* 機能概要     ：PIDのゲイン値の計算                　                          */
/* 引数         ：PIDData *   :    pid_data                                     */
/* 戻り値       ：int        :    SYS_OK  :   正常終了                          */
/*              :            :   SYS_NG  :   異常終了                          */
/*              :           :   SYS_PARAM:   異常引数                          */
/* 作成日       ：2021/07/27         廣兼　聖太    新規作成                      */
/* -------------------------------------------------------------------------- */
int8 PidControl::calcPid(PIDData *pid_data)
{  
    frLog &msg = frLog::GetInstance();
    //argument check
    if (pid_data == NULL)
    {
        msg.LOG(LOG_ID_ERR, "calcPid argument エラー");
        return SYS_PARAM;
    }

    int8    retChk = SYS_NG;                    //戻り値確認変数
    uint16  vData = 0;                          //輝度のv値
    float   prevDeviation = eDeviation;         //前回の偏差
    float   kP = 0;                             //比例ゲイン
    float   kI = 0;                             //積分ゲイン
    float   kD = 0;                             //微分ゲイン
    SensorManager &sensorManager=SensorManager::getInstance();  //センサマネージャークラスのインスタンス生成
    
    //v値取得
    retChk = sensorManager.hsvGetter(&vData);
    //戻り値check
    if (retChk != SYS_OK)
    {
        msg.LOG(LOG_ID_ERR, "calcPid sensorManager.hsvGetter エラー");
        return retChk;
    }
    
    //現在値と目標値の偏差
    eDeviation = (float)vData - pid_data -> targetVal;
    
    //偏差の積み上げ
    stackIntegral += (prevDeviation + eDeviation) / 2.0f * DELTA_TIME;
    //比例ゲイン(kP)
    kP = pid_data -> pGain * eDeviation;
    //積分ゲイン(kI)
    kI = pid_data -> iGain * stackIntegral;
    //微分ゲイン(kD)
    if(prevDeviation!=0.0f){
        kD = pid_data -> dGain * (eDeviation - prevDeviation) / DELTA_TIME;
    }
    //モーター速度
    moterRevison = kP + kI + kD;


    return SYS_OK;
}


/* -------------------------------------------------------------------------- */
/* 関数名       ：getRevison                                                   */
/* 機能名       ：補正値格納                                                    */
/* 機能概要     ：引数に計算したモーター補正値を格納する                          */
/* 引数         ：float *   :    motor_Revison                                 */
/* 戻り値       ：int        :    SYS_OK  :   正常終了                          */
/*              :            :   SYS_NG  :   異常終了                          */
/*              :           :   SYS_PARAM:   異常引数                          */
/* 作成日       ：2021/07/27         廣兼　聖太    新規作成                      */
/* -------------------------------------------------------------------------- */

int8 PidControl::getRevison(float *motor_Revison)
{
    frLog &msg = frLog::GetInstance();
    //argument check
    if (motor_Revison == NULL)
    {
        msg.LOG(LOG_ID_ERR, "getRevison argument エラー");
        return SYS_PARAM;
    }    
    //引数にモーター補正格納
    *motor_Revison = moterRevison;

    return SYS_OK;
}


//
//  -datail
//  積分に必要な値を初期化
//

/* -------------------------------------------------------------------------- */
/* 関数名       ：initIntegral                                                 */
/* 機能名       ：初期化                                                        */
/* 機能概要     ：積分に必要な値を初期化                                          */
/* 引数         ：なし                                                         */
/* 戻り値       ：int        :    SYS_OK  :   正常終了                          */
/*              :            :   SYS_NG  :   異常終了                          */
/*              :           :   SYS_PARAM:   異常引数                          */
/* 作成日       ：2021/07/27         廣兼　聖太    新規作成                      */
/* -------------------------------------------------------------------------- */
int8 PidControl::initIntegral()
{
    //偏差初期化
    eDeviation = 0.0f;
    //偏差の積み上げ初期化
    stackIntegral = 0.0f;
    //補正値の初期化
    moterRevison = 0;
    
    return SYS_OK;
}
