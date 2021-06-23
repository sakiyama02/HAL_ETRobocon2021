
#include "../System/System.h"
#include "../Steering/Steering.h"

class CarPosition
{
private:
    Position carPos;
    float carDirection;
    CarPosition();
    ~CarPosition();
    CarPosition(const car_position &x);
    CarPosition&operator=(const car_position &){ return *this; };
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

    int8 getDir(DirectionData)
}
