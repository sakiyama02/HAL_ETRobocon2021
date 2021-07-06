//
//  ColorSensor.h
//  カラーセンサークラス
//
#pragma once
#include "../System/System.h"

class ColorSensor
{
private:

public:
    ColorSensor();

    ~ColorSensor();

    //RyujiEV3ライブラリ
    // -setting     カラーセンサーからＲＧＢ値を取得する
    // -argu        getするRBGのpointer
    // -return      SYS_OK 正常終了
    // -return      SYS_PARAM 引数エラー
    // -return      SYS_NG 異常終了
    
    int8 getRGB(RGBData*);

    //
    // -setting     カラーセンサーのポート設定
    // -return      SYS_OK 正常終了
    // -return      SYS_NG 異常終了

    int8 init();

};