#include "../../include/Sensor/SonicSensor.h"

SonicSensor::SonicSensor() {}
SonicSensor::~SonicSensor() {}

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