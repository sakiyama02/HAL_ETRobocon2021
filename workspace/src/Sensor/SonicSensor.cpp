#include "../../include/Sensor/SonicSensor.h"

SonarSensor::SonarSensor() {}
SonarSensor::~SonarSensor() {}

int8 SonarSensor::init()
{
    ER errChk;
    errChk = ev3_sensor_config(static_cast<sensor_port_t>(SENSOR_SONAR), ULTRASONIC_SENSOR);
    if (errChk != E_OK)
    {
        return SYS_NG;
    }
    return SYS_OK;
}

int16 SonarSensor::getDistance()
{
    if (distance == NULL)
    {
        return SYS_PARAM;
    }
    return SYS_OK;
}