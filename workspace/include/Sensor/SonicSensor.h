//
//  ColorSenser.h
//  超音波センサークラス
//
#pragma once
#include "../System/System.h"

class SonicSensor
{
private:

public:
    SonicSensor();

    ~SonicSensor();

    //
    // -setting     超音波センサーから距離を取得する
    // -argu        getする距離の長さのpointer
    // -return      SYS_OK 正常終了
    // -return      SYS_PARAM 引数エラー
    // -return      SYS_NG 異常終了

    int8 getDistance(uint16*);   

    //
    // -setting     超音波センサーのポート設定
    // -return      SYS_OK 正常終了
    // -return      SYS_NG 異常終了

    int8 init();

};