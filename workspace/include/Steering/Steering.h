

#include "../System/System.h"
#include "Motor.h"

class Steering
{
    private:
    Steering();
    ~Steering();

    MotorAngle motorAngle;

    Motor* leftMotor;
    Motor* rightMotor; 

    public:
    int8 init();
    int8 rotateWheel(MotorPower motorPower);
    int8 getMotorAngle(MotorAngle *iAngle);
    int8 updateAngle();

    static Steering &getInstance()
    {
        static Steering Steering_;
        return Steering_;
    }
};