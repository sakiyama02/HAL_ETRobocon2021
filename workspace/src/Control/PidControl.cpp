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

//
//  -datail
//  PIDの計算
//
int8 PidControl::calcPid(int32 *motor_pow,PIDData *pid_data)
{  
    //argument check
    if (motor_pow == NULL)
    {
        return SYS_PARAM;
    }
    if (pid_data == NULL)
    {
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
    kD = pid_data -> dGain * (eDeviation - prevDeviation) / DELTA_TIME;
    //モーター速度
    moterRevison = kP + kI + kD;


    return SYS_OK;
}

//
//  -datail
//  引数に計算したモーター補正値を格納する
//
int8 PidControl::getRevison(float *motor_Revison)
{
    //argument check
    if (motor_Revison == NULL)
    {
        return SYS_PARAM;
    }    
    //引数にモーター補正格納
    *motor_Revison = moterRevison;

    return SYS_OK;
}