

#include "../System/System.h"
#include "Motor.h"

class Steering
{
    private:
    Steering();
    ~Steering();



    public:

    int8 rotateWheel(MotorPower motorPower,Motorport motor_port);
};