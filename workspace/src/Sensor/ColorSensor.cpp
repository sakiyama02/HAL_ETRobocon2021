#include "../../include/Sensor/ColorSensor.h"

ColorSensor::ColorSensor(){}
ColorSensor::~ColorSensor(){}

/* -------------------------------------------------------------------------- */
/* 関数名       ：init                                                         */
/* 機能名       ：初期化                                                       */
/* 機能概要     ：EV3のカラーセンサの初期化                                      */
/* 引数         ：なし                                                         */
/* 戻り値       ：int        :   SYS_OK  :   正常終了                           */
/*              :           :   SYS_NG  :   異常終了                           */
/* 作成日       ：2021/07/27         廣兼　聖太    新規作成                      */
/* -------------------------------------------------------------------------- */
int8 ColorSensor::init(){
    frLog &msg = frLog::GetInstance();
    ER errChk = ev3_sensor_config(static_cast<sensor_port_t>(SENSOR_COLOR), COLOR_SENSOR);
    if (errChk != E_OK)
    {
        msg.LOG(LOG_ID_ERR, "init ev3_sensor_config エラー");
        return SYS_NG;
    }
    return SYS_OK;
}

/* -------------------------------------------------------------------------- */
/* 関数名       ：getRGB                                                      */
/* 機能名       ：RGBゲッター                                                  */
/* 機能概要     ：EV3のカラーセンサからRGB値を取得する　                          */
/* 引数         ：RGBData*   :    rgb_Data                                     */
/* 戻り値       ：int        :    SYS_OK  :   正常終了                          */
/*              :            :   SYS_NG  :   異常終了                          */
/*              :           :   SYS_PARAM:   異常引数                          */
/* 作成日       ：2021/07/27         廣兼　聖太    新規作成                      */
/* -------------------------------------------------------------------------- */

int8 ColorSensor::getRGB(RGBData* rgb_Data){
    frLog &msg = frLog::GetInstance();
    //argument check
    if (rgb_Data == NULL)
    {
        msg.LOG(LOG_ID_ERR, "init argument エラー");
        return SYS_PARAM;
    }
    rgb_raw_t rgbTmp;

    memset(&rgbTmp,0,sizeof(rgb_raw_t));
    ev3_color_sensor_get_rgb_raw(static_cast<sensor_port_t>(SENSOR_COLOR), &rgbTmp);
    
    rgb_Data->r = rgbTmp.r;
    rgb_Data->g = rgbTmp.g;
    rgb_Data->b = rgbTmp.b;

    return SYS_OK;
}