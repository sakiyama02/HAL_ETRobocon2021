//
//  SensorManager.h
//  センサ管理クラス
//
#pragma once
#include "../System/System.h"
#include "ColorSensor.h"
#include "SonicSensor.h"

class SensorManager
{
private:
    //rgb値の格納変数
    RGBData rgbStorage;
    
    //距離値の格納変数
    uint16 distanceStorage;

    //カラーセンサーの実体生成
    ColorSensor colorSensor;

    //超音波センサーの実体生成
    SonicSensor sonicSensor;

    //
    // -setting      RGB値取得

    //int8 getRgb();
    // -return      SYS_OK 正常終了

    //
    // -setting      超音波センサーの値取得
    // -return      SYS_OK 正常終了
    int8 getDistance();


public:

    SensorManager();
    ~SensorManager();
    int8 getRgb();
    //
    // -setting     RGB情報格納
    // -argu        RGBの値
    // -return      SYS_OK 正常終了
    // -return      SYS_PARAM 引数エラー
    // -return      SYS_NG 異常終了
    int8 rgbGetter(RGBData*);

    //
    // -setting     v情報格納
    // -argu        hsvのv値
    // -return      SYS_OK 正常終了
    // -return      SYS_PARAM 引数エラー
    // -return      SYS_NG 異常終了
    int8 hsvGetter(uint16*);

    //
    // -setting     s情報格納
    // -argu        hsvのs値
    // -return      SYS_OK 正常終了
    // -return      SYS_PARAM 引数エラー
    // -return      SYS_NG 異常終了
    int8 saturationGetter(uint16*);
    //
    // -setting     超音波の値情報格納
    // -argu        超音波の値
    // -return      SYS_OK 正常終了
    // -return      SYS_PARAM 引数エラー
    // -return      SYS_NG 異常終了
    int8 distanceGetter(uint16*);

    //
    // -setting     センサーのポート設定
    // -return      SYS_OK 正常終了
    // -return      SYS_NG 異常終了
    int8 initSensor();

    static SensorManager& getInstance()
    {
	static SensorManager SensorManager_;	// インスタンスの生成 
    return SensorManager_;
    }

};