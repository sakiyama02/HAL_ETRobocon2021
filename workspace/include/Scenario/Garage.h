#pragma once
#include "../System/System.h"
#include "../Scenario/SceneControl.h"
#include "../../include/GarageInformation/GaActionInfomation.h"
#include "../../include/GarageInformation/GaCurveInfomation.h"
#include "../../include/GarageInformation/GaPidInfomation.h"
#include "../../include/GarageInformation/GaPositionCorrectionInfomation.h"
#include "../../include/Action/Action.h"
#include "../../include/Action/ArmAction.h"
#include "../../include/Action/Curve.h"
#include "../../include/Action/LineTrace.h"
#include "../../include/Action/Straight.h"
#include "../../include/Action/Turn.h"
#include "../../include/CarData/CarPosition.h"
#include "../../include/Sensor/SensorManager.h"
//
//Garage.h
//ライントレースのシーン制御クラス
//基底クラスSceneControl継承先
class Garage : public SceneControl{
    public:

    Garage();
    ~Garage();
    int8 sceneChenge(int16*);
    int8 run(int16);
    int8 colorJudge(RGBData,RGBData,int8);
    int8 xPositionJudge(float,float,int8);
    int8 yPositionJudge(float,float,int8);
    int8 distanceJudge(uint16,uint16);
    int8 directionJudge(float,float,int8);
};