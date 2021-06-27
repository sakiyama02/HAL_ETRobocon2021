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
    // -return      SYS_OK 正常終了

    //
    // -setting      超音波センサーの値取得
    // -return      SYS_OK 正常終了
    int8 get_Distance();


public:
    SensorManager();

    ~SensorManager();

    //
    // -setting     RGB情報格納
    // -argu        RGBの値
    // -return      SYS_OK 正常終了
    // -return      SYS_PARAM 引数エラー
    // -return      SYS_NG 異常終了
    int8 rgb_Getter(RGBData*);

    //
    // -setting     v情報格納
    // -argu        hsvのv値
    // -return      SYS_OK 正常終了
    // -return      SYS_PARAM 引数エラー
    // -return      SYS_NG 異常終了
    int8 hsv_Getter(uint16*);

    //
    // -setting     超音波の値情報格納
    // -argu        超音波の値
    // -return      SYS_OK 正常終了
    // -return      SYS_PARAM 引数エラー
    // -return      SYS_NG 異常終了
    int8 distance_Getter(uint16*);

    //
    // -setting     センサーのポート設定
    // -return      SYS_OK 正常終了
    // -return      SYS_NG 異常終了
    int8 sensor_init();

};