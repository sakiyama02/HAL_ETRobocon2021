
#include "../../include/CarData/CarPosition.h"

CarPosition::CarPosition()
{
    carPos.xPosition = 0.0f;
    carPos.yPosition = 0.0f;

    carDirection = 0.0f;
}

CarPosition::~CarPosition(){}

int8 CarPosition::updatePos()
{
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
        return retChk;
    }
    // モータ角度更新
    retChk = steering.updateAngle();
    if( retChk != SYS_OK){
        return retChk;
    }
    // 最新モータ角度取得
     retChk = steering.getMotorAngle(&nowAngle);
    if( retChk != SYS_OK ){
        return retChk;
    }

    wheelDist.leftMove  = (float)(nowAngle.leftAngle  - preAngle.leftAngle);
    wheelDist.rightMove = (float)nowAngle.rightAngle - preAngle.rightAngle;

    wheelDist.leftMove  *=DIST;
    wheelDist.rightMove *=DIST;


    /* 計算し更新 */
    retChk = calcOdometry(&wheelDist);
    if( retChk != SYS_OK ){
        return retChk;
    }

    return SYS_OK;
}

int8 CarPosition::calcOdometry(WheelDist* wheel_dist)
{
    if( wheel_dist == NULL ){
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
    angle = (float)(360.0f / ( 2.0f * PI * CAR_WIDTH)) * (wheel_dist->rightMove - wheel_dist->leftMove);

    /* 角度をラジアン変換 */
    addRad  = (( double )( angle )) * ( PI / 180.0f );
    rad     = (( double )( angle )) * ( PI / 180.0f );

    /* /2.0fいるかわかんない */
    addPos.xPosition = (float) (dist * std::cos(rad + addRad / 2.0f ));
    addPos.yPosition = (float)-(dist * std::sin(rad + addRad / 2.0f ));

    /* 座標更新 */
    carPos.xPosition += addPos.xPosition;
    carPos.yPosition += addPos.yPosition;

    /* 角度更新 */
    carDirection += addRad;

     /*
    addPos.xPosition /= UNIT;
    addPos.yPosition /= UNIT;
    */

    return SYS_OK;
}

int8 CarPosition::getPos(PositionData* car_pos)
{
    /* 引数チェック */
    if( car_pos == NULL ){
        return SYS_PARAM;
    }

    *car_pos = carPos;

    return SYS_OK;
}

int8 CarPosition::setPos(PositionData set_pos)
{
    carPos = set_pos;

    return SYS_OK;
}

int8 CarPosition::getDir(float* car_dir)
{
    /* 引数チェック */
    if( car_dir == NULL ){
        return SYS_PARAM;
    }

    *car_dir = carDirection;

    return SYS_OK;
}

int8 CarPosition::setAngle(float angle)
{
    /* 引数チェック */
    /* 範囲で引数チェックが必要 
        return SYS_NG;
    */

    carDirection = angle;

    return SYS_OK;
}

