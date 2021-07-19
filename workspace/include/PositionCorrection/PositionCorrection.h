#pragma once
#include "../System/System.h"
#include "../../include/CarData/CarPosition.h"
#include "../../include/Sensor/SensorManager.h"
#include "workspace/include/Logger/frLog.h"
#define STATE＿ACT 0
#define STATE＿ACTAFTER 1
#define STATE＿NOTSEND 2
#define STATE＿NOWSEND 3
class PositionCorrection{
    public:
    PositionCorrection();
    ~PositionCorrection();
    int8 colorFix();
    int8 lineFix();
    int8 directionFix();
    int8 send_position();
    int8 PositionCorrection::controltaskgetter(JudgeType*);
    int8 PositionCorrection::movetaskgetter(Range*);
    int8 fixSetter(PositionCorrectionData);
    static PositionCorrection &getInstance()
    {
        static PositionCorrection positionCorrection_;
        return positionCorrection_;
    }
    private:
    int8 taskState=0;
    int8 sceneState=0;
    //appに操作してもらうタスクを知らせる
    JudgeType controltask=JUDGE_NONE;
    //appに起動と停止どちらを行うかを知らせる
    //HIGHで起動
    //LOWで停止
    Range movetask=NONE;
    PositionCorrectionData prePositionCorrectionData;
    int8 colorJudge(RGBData,RGBData,Range);
    int8 xPositionJudge(float,float,Range);
    int8 yPositionJudge(float,float,Range);
    int8 directionJudge(float,float,Range);
};