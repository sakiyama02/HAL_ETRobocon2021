//
//  PidControl.cpp
//  Pid制御クラス
//
#include "../../include/Control/PidControl.h"

PidControl::PidControl()
{
    eDeviation = 0.0f;
    stackIntegral = 0.0f;
    motorPow = 0;
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
    motorPow = (int32)(kP + kI + kD) + *motor_pow;


    return SYS_OK;
}

//
//  -datail
//  引数に計算したモーターパワーを格納する
//
int8 PidControl::getPow(int32 *motor_pow)
{
    //argument check
    if (motor_pow == NULL)
    {
        return SYS_PARAM;
    }    
    //引数にモーターパワー格納
    *motor_pow = motorPow;

    return SYS_OK;
}