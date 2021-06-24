#include "../../include/Sensor/ColorSensor.h"

ColorSensor::ColorSensor(){}
ColorSensor::~ColorSensor(){}

RGBData ColorSensor::getRGB(){

    RGBData rgbData;
    memset(&rgbData,0,sizeof(RGBData));
    ev3_color_sensor_get_rgb_raw(static_cast<sensor_port_t>(SENSOR_COLOR), &rgbData);
    
    return rgbData;
}

int8 ColorSensor::init(){
    ER result = ev3_sensor_config(static_cast<sensor_port_t>(SENSOR_COLOR), COLOR_SENSOR);
    if (result != E_OK)
    {
        return SYS_NG;
    }
    return SYS_OK;
}