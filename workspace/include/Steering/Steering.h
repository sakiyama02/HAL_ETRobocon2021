

#include "../System/System.h"
#include "Motor.h"

class Steering
{
    private:
    Steering();
    ~Steering();

    int32 lPrevAngle;
    int32 rPrevAngle;

    Motor* leftMotor;
    Motor* rightMotor; 

    

    public:
    int8 init();
    int8 rotateWheel(MotorPower motorPower);
    int8 getMotorAngle(MotorAngle *iAngle);
};