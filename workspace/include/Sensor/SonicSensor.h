//
//  ColorSenser.h
//  超音波センサークラス
//

#include "../System/System.h"

class SonicSensor
{
private:

public:
    SonicSensor();

    ~SonicSensor();

    //
    // -setting     超音波センサーから距離を取得する
    // -return      距離の長さ

    int16 getDistance();   

    //
    // -setting     超音波センサー初期化

    int8 SonicSensor();

}