
#include "../../include/Steering/Motor.h"

Motor::Motor(){}
Motor::~Motor(){}
/* ------------------------------------------------------------------------- */
/* 関数名		： init				            				    	      */
/* 機能名		： 初期化                  								      */
/* 機能概要		：                                 						      */
/* 引数			： MotorPort        :port           :ポート番号               */
/*              ： motor_type_t		:0				:モータタイプ			  */
/* 戻り値		： int8				:0				:正常終了				  */
/* 作成日		： 2021/07/23		 崎山　勇人		 新規作成			       */
/* ------------------------------------------------------------------------- */
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
/* ------------------------------------------------------------------------- */
/* 関数名		： getCounts				            		    	      */
/* 機能名		： モータ角度の取得                  					      */
/* 機能概要		： モータ角度の取得                 					       */
/* 引数			： int32            :*motorAngle    :角度格納                 */
/* 戻り値		： int8				:0				:正常終了				  */
/* 作成日		： 2021/07/23		 崎山　勇人		 新規作成			       */
/* ------------------------------------------------------------------------- */
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
/* ------------------------------------------------------------------------- */
/* 関数名		： getPWM				            		    	          */
/* 機能名		： モータ角度の取得                  					      */
/* 機能概要		： モータ角度の取得                 					       */
/* 引数			： int32            :*motorPower    :現在速度格納             */
/* 戻り値		： int8				:0				:正常終了				  */
/* 作成日		： 2021/07/23		 崎山　勇人		 新規作成			       */
/* ------------------------------------------------------------------------- */
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
/* ------------------------------------------------------------------------- */
/* 関数名		： resetCounts				            	    	          */
/* 機能名		： モータ角度の初期化                  					      */
/* 機能概要		： モータ角度の初期化                 					       */
/* 引数			： なし                                                      */
/* 戻り値		： int8				:0				:正常終了				  */
/* 作成日		： 2021/07/23		 崎山　勇人		 新規作成			       */
/* ------------------------------------------------------------------------- */
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
/* ------------------------------------------------------------------------- */
/* 関数名		： setCounts				            	    	          */
/* 機能名		： 指定した角度に動かす               					      */
/* 機能概要		： 指定した角度に動かす                					       */
/* 引数			： int32            :motorAngle     :指定角度                 */
/*  			： int32            :motorPower     :キープパワー             */
/* 戻り値		： int8				:0				:正常終了				  */
/* 作成日		： 2021/07/23		 崎山　勇人		 新規作成			       */
/* ------------------------------------------------------------------------- */
// 2021年では使用していない
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
/* ------------------------------------------------------------------------- */
/* 関数名		： setPWM				                	    	          */
/* 機能名		：                                     					      */
/* 機能概要		： 指定した出力値でモータを動かす           			       */
/* 引数			： int32            :motorPower     :出力値                   */
/* 戻り値		： int8				:0				:正常終了				  */
/* 作成日		： 2021/07/23		 崎山　勇人		 新規作成			       */
/* ------------------------------------------------------------------------- */
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
/* ------------------------------------------------------------------------- */
/* 関数名		： stop 				                	    	          */
/* 機能名		：                                     					      */
/* 機能概要		： モータを止める                              			       */
/* 引数			： bool             :brake          :                        */
/* 戻り値		： int8				:0				:正常終了				  */
/* 作成日		： 2021/07/23		 崎山　勇人		 新規作成			       */
/* ------------------------------------------------------------------------- */
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