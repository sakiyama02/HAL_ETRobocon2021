
#include "../../include/CarData/CarPosition.h"

CarPosition::CarPosition(){


}

CarPosition::~CarPosition(){}

int8 CarPosition::updatePos(){
    int8 retChk=SYS_NG;
    Steering &steering = Steering::getInstance();
    MotorAngle preAngle;
    MotorAngle nowAngle;
    WheelDist wheelDist;

    memset(&preAngle,0,sizeof(MotorAngle));
    memset(&nowAngle,0,sizeof(MotorAngle));
    memset(&wheelDist,0,sizeof(WheelDist));

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

    wheelDist.leftMove *=DIST;
    wheelDist.rightMove*=DIST;
    
    calcOdometry(&wheelDist);

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

    addPos.xPosition = (float)dist * std::cos(rad + addRad / 2.0f );
    addPos.yPosition = (float)-(dist * std::cos(rad + addRad / 2.0f ));

    

    return SYS_OK;
}