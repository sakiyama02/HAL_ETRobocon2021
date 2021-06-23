//
//  SensorManager.h
//  センサ管理クラス
//

#include "../System/System.h"
#include "ColorSensor.h"
#include "SonicSensor.h"

class SensorManager
{
private:
    //rgb値の格納変数
    static RGBDATE rgbStorage
    
    //距離値の格納変数
    static int32 distanceStorage
    

    //
    // -setting      RGB値取得

    int8 get_Rgb();

    //
    // -setting      超音波センサーの値取得

    int8 get_Distance();


public:
    SensorManager();

    ~SensorManager();

    //
    // -setting     RGB情報格納
    // -argu        RGB情報を格納する構造体
    // -return      SYS_OK 正常終了
    // -return      SYS_PARAM 引数エラー
    // -return      SYS_NG 異常終了
    int8 rgb_Getter(RGBDATE*);

    //
    // -setting     V情報格納
    // -argu        v情報を格納する構造体
    // -return      SYS_OK 正常終了
    // -return      SYS_PARAM 引数エラー
    // -return      SYS_NG 異常終了
    int8 hsv_Getter(uint16*);

}