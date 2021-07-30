#pragma once
#include "../System/System.h"
#include "../Scenario/SceneControl.h"
#include "../../include/SlalomEebuiInfomation/SlEbActionInfomation.h"
#include "../../include/SlalomEebuiInfomation/SlEbCurveInfomation.h"
#include "../../include/SlalomEebuiInfomation/SlEbPidInfomation.h"
#include "../../include/SlalomEebuiInfomation/SlEbPositionCorrectionInfomation.h"
#include "../../include/Action/Action.h"
#include "../../include/Action/ArmAction.h"
#include "../../include/Action/ArmDownAction.h"
#include "../../include/Action/Curve.h"
#include "../../include/Action/LineTrace.h"
#include "../../include/Action/Straight.h"
#include "../../include/Action/Turn.h"
#include "../../include/CarData/CarPosition.h"
#include "../../include/Sensor/SensorManager.h"
#include "../../include/PositionCorrection/PositionCorrection.h"

//
//SlalomEebui.h
//ライントレースのシーン制御クラス
//基底クラスSceneControl継承先
class SlalomEebui : public SceneControl{
    public:
        SlalomEebui();
        ~SlalomEebui();
        int8 sceneChenge(int16*);
        int8 run(int16);
        int8 colorJudge(RGBData,RGBData,Range);
        int8 xPositionJudge(float,float,Range);
        int8 yPositionJudge(float,float,Range);
        int8 distanceJudge(uint16,uint16);
        int8 directionJudge(float,float,Range);
        int8 vJudge(uint16,uint16,Range);
};