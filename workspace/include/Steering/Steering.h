

#include "../System/System.h"
#include "Motor.h"

class Steering
{
    private:
    Steering();
    ~Steering();

    int32 lPrevAngle;
    int32 rPrevAngle;

    

    public:
    int8 init();
    int8 rotateWheel(MotorPower motorPower,Motorport motor_port);
    int8 getMotorangle(int32 *iAngle);
};