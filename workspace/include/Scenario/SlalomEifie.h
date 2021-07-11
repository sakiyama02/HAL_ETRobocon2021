#pragma once
#include "../System/System.h"
#include "../Scenario/SceneControl.h"
#include "../../include/SlalomEifieInfomation/SlEfActionInfomation.h"
#include "../../include/SlalomEifieInfomation/SlEfCurveInfomation.h"
#include "../../include/SlalomEifieInfomation/SlEfPidInfomation.h"
#include "../../include/SlalomEifieInfomation/SlEfPositionCorrectionInfomation.h"
#include "../../include/Action/Action.h"
#include "../../include/Action/ArmAction.h"
#include "../../include/Action/Curve.h"
#include "../../include/Action/LineTrace.h"
#include "../../include/Action/Straight.h"
#include "../../include/Action/Turn.h"
#include "../../include/CarData/CarPosition.h"
#include "../../include/Sensor/SensorManager.h"

//
//SlalomEifie.h
//ライントレースのシーン制御クラス
//基底クラスSceneControl継承先
class SlalomEifie : public SceneControl{
    public:
    SlalomEifie();
    ~SlalomEifie();
    int8 sceneChenge(int16*);
    int8 run(int16);
    int8 colorJudge(RGBData,RGBData,Range);
    int8 xPositionJudge(float,float,Range);
    int8 yPositionJudge(float,float,Range);
    int8 distanceJudge(uint16,uint16);
    int8 directionJudge(float,float,Range);
};