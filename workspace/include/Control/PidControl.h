//
//  PidControl.h
//  PID制御クラス
//
#pragma once
#include "../System/System.h"
#include "../Sensor/SensorManager.h"

//周期
#define DELTA_TIME 0.01f

class PidControl
{
private:
    //偏差
    float   eDeviation;
    //偏差の積み上げ
    float stackIntegral;
    //モーターパワー補正値
    float moterRevison;
public:
    PidControl();
    ~PidControl();

    //
    // -setting     PID操作量を計算
    // -argu        PIDのゲイン値,目標値
    // -return      SYS_OK 正常終了
    // -return      SYS_PARAM 引数エラー
    // -return      SYS_NG 異常終了

    int8 calcPid(PIDData*);

    //
    // -setting     モーターの補正値格納
    // -argu        モーター補正値
    // -return      SYS_OK 正常終了
    // -return      SYS_PARAM 引数エラー
    // -return      SYS_NG 異常終了

    int8 getRevison(float*);


    //
    // -setting     積分地初期化
    // -return      SYS_OK 正常終了
    // -return      SYS_PARAM 引数エラー
    // -return      SYS_NG 異常終了

    int8 initIntegral();

    
    // インスタンスの生成 
    static PidControl &getInstance()
    {
        static PidControl PidControl_;      
        return PidControl_;
    }

};