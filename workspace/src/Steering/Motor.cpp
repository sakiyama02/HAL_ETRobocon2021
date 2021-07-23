
#include "../../include/Steering/Motor.h"

Motor::Motor(){}
Motor::~Motor(){}

int8 Motor::init(MotorPort port, motor_type_t type)
{
    frLog &msg = frLog::GetInstance();

    ER errChk;
    errChk = ev3_motor_config(static_cast<motor_port_t>(port), type);

    if (errChk != E_OK)
    {
        msg.LOG(LOG_ID_ERR, "Motor.init ev3_motor_config err/n");
        return SYS_NG;
    }
    portNum = port;
 
    return SYS_OK;
}

int8 Motor::getCounts(int32 *motorAngle)
{
    frLog &msg = frLog::GetInstance();

    if (motorAngle == NULL)
    {
        msg.LOG(LOG_ID_ERR, "Motor.getCounts 引数エラー\n");
        return SYS_PARAM;
    }
    *motorAngle = ev3_motor_get_counts(static_cast<motor_port_t>(portNum));
    
    return SYS_OK;
}

int8 Motor::getPWM(int32 *motorPower)
{
    frLog &msg = frLog::GetInstance();
    
    if (motorPower == NULL)
    {
        msg.LOG(LOG_ID_ERR, "Motor.getPWM 引数エラー\n");
        return SYS_PARAM;
    }
    *motorPower = ev3_motor_get_power(static_cast<motor_port_t>(portNum));
   
    return SYS_OK;
}

int8 Motor::resetCounts()
{
    frLog &msg = frLog::GetInstance();
 
    ER errChk = ev3_motor_reset_counts(static_cast<motor_port_t>(portNum));
    if (errChk != E_OK)
    {
        msg.LOG(LOG_ID_ERR, "Motor.resetCounts ev3_motor_reset_count err\n");
        return SYS_NG;
    }

    return SYS_OK;
}
// 2021年のETRobocon
// Motor::setCountsは使わない
int8 Motor::setCounts(int32 motorAngle, int32 motorPower)
{
    //frLog &msg = frLog::GetInstance();
 
    if (motorPower < -100 || motorPower > 100)
    {
    
        return SYS_PARAM;
    }
    int8 retChk = SYS_NG;
    int32 curAngle = 0;
    int32 angle = 0;

    retChk = getCounts(&angle);
    if (retChk != SYS_OK)
    {
    
        return retChk;
    }

    retChk = setPWM(motorPower);
    if (retChk != SYS_OK)
    {
     
        return retChk;
    }

    /* 指定回転角度まで回転を続ける */
    if(motorAngle > 0)
    {
        do
        {
            retChk = getCounts(&curAngle);
            if (retChk != SYS_OK)
            {
                return retChk;
            }
            
            tslp_tsk(10000);
        } while (curAngle - angle < motorAngle);
    }
    else
    {
        do
        {
            retChk = getCounts(&curAngle);
            if (retChk != SYS_OK)
            {
                return retChk;
            }
            tslp_tsk(10000);
        } while (curAngle - angle > motorAngle);
    }
    retChk = stop(true);
    if (retChk != SYS_OK)
    {
        
        return retChk;
    }
  
    return SYS_OK;
}

int8 Motor::setPWM(int32 motorPower)
{
    frLog &msg = frLog::GetInstance();
    
    if (motorPower < -100 || motorPower > 100)
    {
        msg.LOG(LOG_ID_ERR, "Motor.setPWM 引数エラー\n");
        return SYS_PARAM;
    }
    ER errChk = ev3_motor_set_power(static_cast<motor_port_t>(portNum), motorPower);
    if (errChk != E_OK)
    {
        msg.LOG(LOG_ID_ERR, "Motor.setPWM ev3_motor_set_power err\n");
        return SYS_NG;
    }

    return SYS_OK;
}

int8 Motor::stop(bool brake)
{
    frLog &msg = frLog::GetInstance();
    
    ER errChk = ev3_motor_stop(static_cast<motor_port_t>(portNum), brake);
    if (errChk != E_OK)
    {
        msg.LOG(LOG_ID_ERR, "Motor.stop ev3_motor_stop err\n");
        return SYS_NG;
    }

    return SYS_OK;
}