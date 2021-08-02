#pragma once
#include "../System/System.h"
#include "../Steering/Steering.h"
#include <math.h>
#include <cmath>

#define PI 3.141592653589793
#define DIST (((PI) * (double)CAR_WHEEL_WIDTH) / 360.0f)

class CarPosition
{
private:
    PositionData carPos;
    float carDirection;
    CarPosition();
    ~CarPosition();
    CarPosition(const CarPosition &x);
    CarPosition&operator=(const CarPosition &){ return *this; };

    int8 calcOdometry(WheelDist* wheel_dist);
public:

    // CarPositionのインスタンス
    static CarPosition &getInstance()
    {
        static CarPosition carPosition;
        return carPosition;
    }

    int8 update();

    int8 getPos(PositionData* car_pos);

    int8 setPos(PositionData set_pos);

    int8 xsetPos(float set_pos);

    int8 ysetPos(float set_pos);

    int8 getDir(float* car_dir);

    int8 setDir(float angle);

    int8 calcstate=0;    
};
