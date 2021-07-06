#include "../../include/Sensor/ColorSensor.h"

ColorSensor::ColorSensor(){}
ColorSensor::~ColorSensor(){}

int8 ColorSensor::init(){
    ER errChk = ev3_sensor_config(static_cast<sensor_port_t>(SENSOR_COLOR), COLOR_SENSOR);
    if (errChk != E_OK)
    {
        return SYS_NG;
    }
    return SYS_OK;
}

int8 ColorSensor::getRGB(RGBData* rgb_Data){

    //argument check
    if (rgb_Data == NULL)
    {
        return SYS_PARAM;
    }
    rgb_raw_t rgbTmp;

    memset(&rgbTmp,0,sizeof(RGBData));
    ev3_color_sensor_get_rgb_raw(static_cast<sensor_port_t>(SENSOR_COLOR), &rgbTmp);
    
    rgb_Data->r = rgbTmp.r;
    rgb_Data->g = rgbTmp.g;
    rgb_Data->b = rgbTmp.b;

    return SYS_OK;
}