#include "../../include/Sensor/SonicSensor.h"

SonicSensor::SonicSensor() {}
SonicSensor::~SonicSensor() {}
/* -------------------------------------------------------------------------- */
/* 関数名       ：init                                                         */
/* 機能名       ：初期化                                                       */
/* 機能概要     ：EV3の超音波センサの初期化                                      */
/* 引数         ：なし                                                         */
/* 戻り値       ：int        :   SYS_OK  :   正常終了                           */
/*              :           :   SYS_NG  :   異常終了                           */
/* 作成日       ：2021/07/27         廣兼　聖太    新規作成                      */
/* -------------------------------------------------------------------------- */
int8 SonicSensor::init()
{
    frLog &msg = frLog::GetInstance();
    ER errChk;
    errChk = ev3_sensor_config(static_cast<sensor_port_t>(SENSOR_SONAR), ULTRASONIC_SENSOR);
    if (errChk != E_OK)
    {
        msg.LOG(LOG_ID_ERR, "init ev3_sensor_config エラー");
        return SYS_NG;
    }
    return SYS_OK;
}
/* -------------------------------------------------------------------------- */
/* 関数名       ：getDistance                                                  */
/* 機能名       ：距離ゲッター                                                  */
/* 機能概要     ：EV3の超音波センサから距離を取得する 　                          */
/* 引数         ：uint16*   :    distance_Data                                */
/* 戻り値       ：int        :    SYS_OK  :   正常終了                          */
/*              :            :   SYS_NG  :   異常終了                          */
/*              :           :   SYS_PARAM:   異常引数                          */
/* 作成日       ：2021/07/27         廣兼　聖太    新規作成                      */
/* -------------------------------------------------------------------------- */
int8 SonicSensor::getDistance(uint16* distance_Data)
{
    frLog &msg = frLog::GetInstance();
    //argument check
    if (distance_Data == NULL)
    {
        msg.LOG(LOG_ID_ERR, "getDistance argument エラー");
        return SYS_PARAM;
    }

    *distance_Data = ev3_ultrasonic_sensor_get_distance(static_cast<sensor_port_t>(SENSOR_SONAR));
    return SYS_OK;
}