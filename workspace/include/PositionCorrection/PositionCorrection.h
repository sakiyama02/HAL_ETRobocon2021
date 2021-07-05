#include "../System/System.h"

class PositionCorrection{
    public:
    PositionCorrection();
    ~PositionCorrection();
    int8 FixSetter(PositionCorrectionData positionCorrection_Data);
    private:
    int8 taskState=0;
    int8 sceneState=0;
    PositionCorrectionData prePositionCorrectionData;
    int8 colorFix();
    int8 lineFix();
    int8 directionFix();
    static PositionCorrection &getInstance()
    {
        static PositionCorrection positionCorrection_;
        return positionCorrection_;
    }
};