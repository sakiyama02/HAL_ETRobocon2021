
#include "../../include/CarData/CarPosition.h"

CarPosition::CarPosition()
{
    
    //タイムアタックの初期値
    carPos.xPosition = 3457 * 0.3527 * 2;
    carPos.yPosition = 277 * 0.3527 * 2;
    
    /*
    carPos.xPosition = 3457 * 0.3527 * 2;
    carPos.yPosition = 277 * 0.3527 * 2;
    */
    carDirection = 90.0f;
}

CarPosition::~CarPosition(){}

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

int8 CarPosition::setPos(PositionData set_pos)
{
    //frLog &msg = frLog::GetInstance();
    carPos = set_pos;

    return SYS_OK;
}

int8 CarPosition::xsetPos(float set_pos)
{
    //frLog &msg = frLog::GetInstance();
    carPos.xPosition = set_pos;

    return SYS_OK;
}

int8 CarPosition::ysetPos(float set_pos)
{
    //frLog &msg = frLog::GetInstance();
    carPos.yPosition = set_pos;

    return SYS_OK;
}


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

