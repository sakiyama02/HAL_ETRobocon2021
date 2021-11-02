
#include "../../include/CarData/CarPosition.h"

/* ------------------------------------------------------------------------- */
/* 関数名		： CarPosition				              	    	          */
/* 機能名		： コンストラクタ                                  		      */
/* 機能概要		： 座標と向きの初期化                          			       */
/* 引数			： なし                                                       */
/* 戻り値		： なし                                     				  */
/* 作成日		： 2021/07/23		 崎山　勇人		 新規作成			       */
/* ------------------------------------------------------------------------- */
CarPosition::CarPosition()
{
    
    //タイムアタックの初期値
    /*
    carPos.xPosition = 417*2*0.3527;
    carPos.yPosition = 3600*2*0.3527;
    */
    carDirection = 90.0f;
    
    carPos.xPosition = 3457 * 0.3527 * 2;
    carPos.yPosition = 277 * 0.3527 * 2;
    
    //carDirection = 90.0f;
}

CarPosition::~CarPosition(){}
/* ------------------------------------------------------------------------- */
/* 関数名		： update									    	          */
/* 機能名		： 更新       									             */
/* 機能概要		： 自己位置を更新する                   				      */
/* 引数			： なし                                                       */
/* 戻り値		： int8				:0				:正常終了				  */
/* 作成日		： 2021/07/23		 崎山　勇人		 新規作成			       */
/* ------------------------------------------------------------------------- */
int8 CarPosition::update()
{
    calcstate=1;
    frLog &msg = frLog::GetInstance();
    int8 retChk=SYS_NG;
    Steering &steering = Steering::getInstance();
    MotorAngle preAngle;
    MotorAngle nowAngle;
    WheelDist wheelDist;

    memset(&preAngle,0,sizeof(MotorAngle));
    memset(&nowAngle,0,sizeof(MotorAngle));
    memset(&wheelDist,0,sizeof(WheelDist));

    /* モータの角度差異取得 -------------------------------------------- */

    // 前回モータ角度取得
    retChk = steering.getMotorAngle(&preAngle);
    if( retChk != SYS_OK ){
        msg.LOG(LOG_ID_ERR,"CarPos::update getMotorAngle pre err\n");
        return retChk;
    }
    // モータ角度更新
    retChk = steering.updateAngle();
    if( retChk != SYS_OK){
        msg.LOG(LOG_ID_ERR,"CarPos::update updateAngle err\n");
        return retChk;
    }
    // 最新モータ角度取得
     retChk = steering.getMotorAngle(&nowAngle);
    if( retChk != SYS_OK ){
        msg.LOG(LOG_ID_ERR,"CarPos:update getMotorAngle now err\n");
        return retChk;
    }

    wheelDist.leftMove  = (float)(nowAngle.leftAngle  - preAngle.leftAngle);
    wheelDist.rightMove = (float)nowAngle.rightAngle - preAngle.rightAngle;

    wheelDist.leftMove  *=DIST;
    wheelDist.rightMove *=DIST;


    /* 計算し更新 */
    retChk = calcOdometry(&wheelDist);
    if( retChk != SYS_OK ){
        msg.LOG(LOG_ID_ERR,"CarPos::update calcOdometry err\n");
        return retChk;
    }
    msg.LOG(LOG_ID_COORDINATE,"X:%f,Y:%f\n",carPos.xPosition,carPos.yPosition);
    msg.LOG(LOG_ID_COORDINATE,"角度:%f\n",carDirection);
    if(carDirection>=600||carDirection<=-600){
        msg.LOG(LOG_ID_ERR,"車体角度が異常のため強制終了\n");
        act_tsk(END_TASK);
        return SYS_NG;
    }
    calcstate=0;
    return SYS_OK;
}
/* ------------------------------------------------------------------------- */
/* 関数名		： calcOdometry								    	          */
/* 機能名		： オドメトリ計算 								             */
/* 機能概要		： オドメトリ計算を行う                   	   			      */
/* 引数			： WheelDist*       :wheel_dist     :両モータの差分           */
/* 戻り値		： int8				:0				:正常終了				  */
/* 作成日		： 2021/07/23		 崎山　勇人		 新規作成			       */
/* ------------------------------------------------------------------------- */
int8 CarPosition::calcOdometry(WheelDist* wheel_dist)
{
    frLog &msg = frLog::GetInstance();
    if( wheel_dist == NULL ){
        msg.LOG(LOG_ID_ERR,"CarPosition::calcOdometry 引数エラー\n");
        return SYS_PARAM;
    }
    float  angle    = 0.0f;
    double dist     = 0.0f;
    double rad      = 0.0f;
    double addRad   = 0.0f;
    PositionData addPos;

    memset(&addPos,0,sizeof(PositionData));

    /* 座標計算 */
    dist  = (double)(wheel_dist->rightMove + wheel_dist->leftMove ) / 2.0f;
    angle = (float)(360.0f / ( 2.0f * PI * CAR_WIDTH)) * (wheel_dist->leftMove - wheel_dist->rightMove);

    /* 角度をラジアン変換 */
    addRad  = (( double )( angle )) * ( PI / 180.0f );
    rad     = (( double )( carDirection )) * ( PI / 180.0f );

    /* /2.0fいるかわかんない */
    addPos.xPosition = (float)-(dist * std::sin(rad + addRad / 2.0f ));
    addPos.yPosition = (float)(dist * std::cos(rad + addRad / 2.0f ));

    /* 座標更新 */
    carPos.xPosition += addPos.xPosition;
    carPos.yPosition += addPos.yPosition;

    /* 角度更新 */
    carDirection += angle;

     /*
    addPos.xPosition /= UNIT;
    addPos.yPosition /= UNIT;
    */

    return SYS_OK;
}
/* ------------------------------------------------------------------------- */
/* 関数名		： getPos							    	    	          */
/* 機能名		： 自己位置座標を取得 								             */
/* 機能概要		： 自己位置座標を返す                   	   		   	      */
/* 引数			： PositionData*    :car_pos        :座標格納用                */
/* 戻り値		： int8				:0				:正常終了				  */
/* 作成日		： 2021/07/23		 崎山　勇人		 新規作成			       */
/* ------------------------------------------------------------------------- */
int8 CarPosition::getPos(PositionData* car_pos)
{
    frLog &msg = frLog::GetInstance();
    /* 引数チェック */
    if( car_pos == NULL ){
        msg.LOG(LOG_ID_ERR,"CarPosition::getPos 引数エラー\n");
        return SYS_PARAM;
    }

    *car_pos = carPos;

    return SYS_OK;
}
/* ------------------------------------------------------------------------- */
/* 関数名		： setPos							    	    	          */
/* 機能名		： 自己位置座標(x,y)を上書き 						           */
/* 機能概要		： 自己位置座標(x,y)を上書きする                   	              */
/* 引数			： PositionData     :set_pos        :座標                     */
/* 戻り値		： int8				:0				:正常終了				  */
/* 作成日		： 2021/07/23		 崎山　勇人		 新規作成			       */
/* ------------------------------------------------------------------------- */
int8 CarPosition::setPos(PositionData set_pos)
{
    //frLog &msg = frLog::GetInstance();
    carPos = set_pos;

    return SYS_OK;
}
/* ------------------------------------------------------------------------- */
/* 関数名		： xsetPos							    	    	          */
/* 機能名		： 自己位置座標(x)を上書き 					    	           */
/* 機能概要		： 自己位置座標(x)を上書きする                                 */
/* 引数			： float            :set_pos        :x座標                    */
/* 戻り値		： int8				:0				:正常終了				  */
/* 作成日		： 2021/07/23		 崎山　勇人		 新規作成			       */
/* ------------------------------------------------------------------------- */
int8 CarPosition::xsetPos(float set_pos)
{
    //frLog &msg = frLog::GetInstance();
    carPos.xPosition = set_pos;

    return SYS_OK;
}
/* ------------------------------------------------------------------------- */
/* 関数名		： ysetPos							    	    	          */
/* 機能名		： 自己位置座標(y)を上書き 					    	           */
/* 機能概要		： 自己位置座標(y)を上書きする                                 */
/* 引数			： float            :set_pos        :y座標                    */
/* 戻り値		： int8				:0				:正常終了				  */
/* 作成日		： 2021/07/23		 崎山　勇人		 新規作成			       */
/* ------------------------------------------------------------------------- */
int8 CarPosition::ysetPos(float set_pos)
{
    //frLog &msg = frLog::GetInstance();
    carPos.yPosition = set_pos;

    return SYS_OK;
}
/* ------------------------------------------------------------------------- */
/* 関数名		： getDir							    	    	          */
/* 機能名		： 自己位置角度を取得		            	    	           */
/* 機能概要		： 自己位置角度を取得する                                       */
/* 引数			： float*           :car_dir        :角度格納用                */
/* 戻り値		： int8				:0				:正常終了				  */
/* 作成日		： 2021/07/23		 崎山　勇人		 新規作成			       */
/* ------------------------------------------------------------------------- */
int8 CarPosition::getDir(float* car_dir)
{
    frLog &msg = frLog::GetInstance();
    /* 引数チェック */
    if( car_dir == NULL ){
        msg.LOG(LOG_ID_ERR,"CarPosition::getDir 引数エラー\n");
        return SYS_PARAM;
    }

    *car_dir = carDirection;

    return SYS_OK;
}
/* ------------------------------------------------------------------------- */
/* 関数名		： setDir							    	    	          */
/* 機能名		： 自己位置角度を上書き		            	    	           */
/* 機能概要		： 自己位置角度を上書きする                                     */
/* 引数			： float            :angle          :角度                    */
/* 戻り値		： int8				:0				:正常終了				  */
/* 作成日		： 2021/07/23		 崎山　勇人		 新規作成			       */
/* ------------------------------------------------------------------------- */
int8 CarPosition::setDir(float angle)
{
    //frLog &msg = frLog::GetInstance();
    /* 引数チェック */
    /* 範囲で引数チェックが必要 
        return SYS_NG;
    */

    carDirection = angle;

    return SYS_OK;
}

