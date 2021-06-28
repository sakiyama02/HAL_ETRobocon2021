#include "../../include/Sensor/SonicSensor.h"

SonicSensor::SonicSensor() {}
SonicSensor::~SonicSensor() {}

int8 SonicSensor::init()
{
    ER errChk;
    errChk = ev3_sensor_config(static_cast<sensor_port_t>(SENSOR_SONAR), ULTRASONIC_SENSOR);
    if (errChk != E_OK)
    {
        return SYS_NG;
    }
    return SYS_OK;
}

int8 SonicSensor::getDistance(uint16* distance_Data)
{
    //argument check
    if (distance_Data == NULL)
    {
        return SYS_PARAM;
    }

    *distance_Data = ev3_ultrasonic_sensor_get_distance(static_cast<sensor_port_t>(SENSOR_SONAR));
    return SYS_OK;
}