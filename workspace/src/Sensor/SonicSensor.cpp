#include "../../include/Sensor/SonicSensor.h"

SonarSensor::SonarSensor() {}
SonarSensor::~SonarSensor() {}

int8 SonarSensor::init()
{
    frLog &msg = frLog::GetInstance();
    msg.LOG(LOG_ID_TRACE, "SonarSensor::init -st-");
    ER errChk;
    errChk = ev3_sensor_config(static_cast<sensor_port_t>(SENSOR_SONAR), ULTRASONIC_SENSOR);
    if (errChk != E_OK)
    {
        msg.LOG(LOG_ID_ERR, "%s %d -error-",__PRETTY_FUNCTION__,__LINE__);
        return SYS_NG;
    }
    msg.LOG(LOG_ID_TRACE, "SonarSensor::init -en-");
    return SYS_OK;
}

int8 SonarSensor::getDistance(int16 *distance)
{
    frLog &msg = frLog::GetInstance();
    msg.LOG(LOG_ID_TRACE, "SonarSensor::getDistance -st-");
    if (distance == NULL)
    {
        msg.LOG(LOG_ID_ERR, "%s %d -error-",__PRETTY_FUNCTION__,__LINE__);
        return SYS_PARAM;
    }
    *distance = ev3_ultrasonic_sensor_get_distance(static_cast<sensor_port_t>(SENSOR_SONAR));
    msg.LOG(LOG_ID_TRACE, "SonarSensor::getDistance -en-");
    return SYS_OK;
}