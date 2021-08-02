#pragma once
#include "../System/System.h"
#include "../../include/CarData/CarPosition.h"
#include "../../include/Sensor/SensorManager.h"
#include "workspace/include/Logger/frLog.h"
#define STATE_ACT 0
#define STATE_ACTAFTER 1
#define STATE_NOTSEND 2
#define STATE_NOWSEND 3
class PositionCorrection{
    public:
    PositionCorrection();
    ~PositionCorrection();
    int8 colorFix();
    int8 lineFix();
    int8 directionFix();
    int8 vFix();
    int8 sFix();
    int8 distanceFix();
    int8 send_position();
    int8 controltaskgetter(JudgeType*);
    int8 movetaskgetter(Range*);
    int8 controltasksetter(JudgeType);
    int8 movetasksetter(Range);
    int8 fixSetter(PositionCorrectionData);
    static PositionCorrection &getInstance()
    {
        static PositionCorrection positionCorrection_;
        return positionCorrection_;
    }
    private:
    int8 taskState=0;
    int8 sceneState=0;
    JudgeType controltask=JUDGE_NONE;
    Range movetask=NONE;
    PositionCorrectionData prePositionCorrectionData;
    int8 colorJudge(RGBData,RGBData,Range);
    int8 xPositionJudge(float,float,Range);
    int8 yPositionJudge(float,float,Range);
    int8 directionJudge(float,float,Range);
    int8 distanceJudge(uint16,uint16);
    int8 vJudge(uint16,uint16,Range);
    int8 sJudge(uint16,uint16,Range);
    int8 posSetter(PosInfoData);
    int8 dirSetter(DirectionData);
};