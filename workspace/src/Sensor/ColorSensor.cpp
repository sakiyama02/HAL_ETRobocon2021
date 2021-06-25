#include "../../include/Sensor/ColorSensor.h"

ColorSensor::ColorSensor(){}
ColorSensor::~ColorSensor(){}

int8 ColorSensor::init(){
    ER result = ev3_sensor_config(static_cast<sensor_port_t>(SENSOR_COLOR), COLOR_SENSOR);
    if (result != E_OK)
    {
        return SYS_NG;
    }
    return SYS_OK;
}

int8 ColorSensor::getRGB(RGBData *rgbData){
    RGBData tmpRgb;

    memset(&tmpData,0,sizeof(RGBData));

    frLog &msg = frLog::GetInstance();
    msg.LOG(LOG_ID_TRACE, "ColorSensor::getRGB -st-");    
    if (rgbData == NULL)
    {
        msg.LOG(LOG_ID_ERR, "%s %d -error-",__PRETTY_FUNCTION__,__LINE__);
        return SYS_PARAM;
    }
    ev3_color_sensor_get_rgb_raw(static_cast<sensor_port_t>(SENSOR_COLOR), &tmpRgb);
    
    rgbData->r=tmpRgb.r;
    rgbData->g=tmpRgb.g;
    rgbData->b=tmpRgb.b;

    if (result != E_OK)
    {
        return SYS_NG;
    }
    return SYS_OK;
}