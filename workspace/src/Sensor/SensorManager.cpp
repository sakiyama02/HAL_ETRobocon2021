//
//  SensorManager.h
//  センサー管理クラス
//

#include "../../include/Sensor/SensorManager.h"

//
//  -datail
//  カラーセンサークラスからＲＧＢ値を取得する関数を呼び、
//                                 変数のrgbを更新
//
int8 SensorManager::get_Rgb()
{  
    //rgb値取得
    rgbStorage=ColorSenser.getRGB();

    return SYS_OK;
}


//
//  -datail
//  超音波センサーから距離を取得する関数を呼び、
//                  変数のdistanceStorageを更新
//
int8 SensorManager::get_Distance()
{
    //距離取得
    distanceStorage = SonicSensor.getDistance();

    return SYS_OK;
}

//
//  -datail
//  引数で入ってきた構造体ポインタにRGB情報に格納する
//
int8 SensorManager::rgb_Getter(RGBDATE* rgb_data)
{
    //argument check
    if (rgb＿data == NULL)
    {
        return SYS_PARAM;
    }

    //引数にカラーセンサーの値を格納
    rgb_data = &rgbStorage;

    return SYS_OK;
}

//
//  -datail
//  引数で入ってきたhsvのv値をv値情報に格納する
//
int8 SensorManager::hsv_Getter(uint16* v_data)
{    
    //argument check
    if (v_data == NULL)
    {
        return SYS_PARAM;
    }

    //hsvのv値を格納
    if(rgbStorage.r > rgbStorage.g && rgbStorage.r > rgbStorage.b)
    {
        v_data = rgbStorage.r;
    }
    else if(rgbStorage.g > rgbStorage.r && rgbStorage.g > rgbStorage.b)
    {
        v_data = rgbStorage.g;
    }
    else if(rgbStorage.b > rgbStorage.r && rgbStorage.b > rgbStorage.g)
    {
        v_data = rgbStorage.b;
    }

    return SYS_OK;
}

//
//  -datail 
//  引数で入ってきたポインタに超音波の値情報を
//                  超音波変数に格納する
//

int8 SensorManager::distance_Getter(uint16* distance_data)
{
    //argument check
        if (distance_data == NULL)
    {
        return SYS_PARAM;
    }

    //超音波センサーの値を格納
    distanceStorage = distance_data;

     return SYS_OK;
}

//
//  -datail 
//  センサーのポート設定を行う
//

int8 SensorManager::sensor_init()
{
    int8 retChk = SYS_NG;           //戻り値確認変数

    //カラーセンサーのポート設定
    retChk = ColorSensor.ColorSensor();
        if (retChk != SYS_OK)
    {
        return retChk;
    }

    //超音波センサーのポート設定
    retChk = SonicSensor.SonicSensor();
        if (retChk != SYS_OK)
    {
        return retChk;
    }

    return SYS_OK;
}