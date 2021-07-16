#pragma once
#include "../System/System.h"
#include "../../include/CarData/CarPosition.h"
#include "../../include/Sensor/SensorManager.h"
#define STATE＿ACT 0
#define STATE＿ACTAFTER 1;
class PositionCorrection{
    public:
    PositionCorrection();
    ~PositionCorrection();
    int8 FixSetter(PositionCorrectionData positionCorrection_Data);
    static PositionCorrection &getInstance()
    {
        static PositionCorrection positionCorrection_;
        return positionCorrection_;
    }
    private:
    int8 taskState=0;
    int8 sceneState=0;
    PositionCorrectionData prePositionCorrectionData;
    int8 colorFix();
    int8 lineFix();
    int8 directionFix();
    int8 colorJudge(RGBData,RGBData,Range);
    int8 xPositionJudge(float,float,Range);
    int8 yPositionJudge(float,float,Range);
    int8 directionJudge(float,float,Range);
};