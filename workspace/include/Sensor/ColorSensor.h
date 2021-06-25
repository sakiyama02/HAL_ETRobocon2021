//
//  ColorSensor.h
//  カラーセンサークラス
//

#include "../System/System.h"

class ColorSensor
{
private:

public:
    ColorSensor();

    ~ColorSensor();

    //RyujiEV3ライブラリ
    // -setting     カラーセンサーからＲＧＢ値を取得する
    // -return      RGB値

    RGB getRGB();   

    //
    // -setting     カラーセンサーのポート設定

    int8 ColorSensor();

}