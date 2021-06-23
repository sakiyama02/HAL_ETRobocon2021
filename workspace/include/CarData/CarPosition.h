
#include "../System/System.h"
#include "../Steering/Steering.h"

#define PI 3.14159265359
#define DIST (((PI) * (double)CAR_WHEEL_WIDTH) / 360.0f)

class CarPosition
{
private:
    Position carPos;
    float carDirection;
    CarPosition();
    ~CarPosition();
    CarPosition(const car_position &x);
    CarPosition&operator=(const car_position &){ return *this; };

    int8 calcOdometry(WheelDist* wheel_dist);
public:

    // CarPositionのインスタンス
    static CarPosition &getInstance()
    {
        static CarPosition carPosition;
        return carPosition;
    }

    int8 updatePos();

    int8 updateDir();

    int8 getPos(Position car_pos);

    int8 getDir(DirectionData);
};
