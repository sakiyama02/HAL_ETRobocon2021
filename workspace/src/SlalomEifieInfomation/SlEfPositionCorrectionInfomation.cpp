//SlEfPositionCorrectionInfomation
//スラロームエーフィポジションコレクションインフォメーション
//

#include "../../include/SlalomEifieInfomation/SlEfPositionCorrectionInfomation.h"

SlEfPositionCorrectionInfomation(){
    memset(positinCorrectionData,0,sizeof(PositionCorrectionData)*TIMEATTACK_NUM);
    int8 index = 0;

//template
/*
    positionCorrectionData[index].correctionValue.xPosition
    positionCorrectionData[index].correctionValue.yPosition

    positionCorrectionData[index].correctionPosition.xPosition
    positionCorrectionData[index].correctionPosition.yPosition

    positionCorrectionData[index].correctionRGB.r=0f;
    positionCorrectionData[index].correctionRGB.g=0f;
    positionCorrectionData[index].correctionRGB.b=0f;
    positionCorrectionData[index].correctionRGB.condition=0f;

    positionCorrectionData[index].correctionDirection.direction=0f;
    positionCorrectionData[index].correctionDirection.condition=0f;

    positionCorrectionData[index].correctionCondition=0f;

    index++;
*/    

}

int8 getter(int16 scene_num,PositinCorrectionData* positioncorrection_data){
    
    positioncorrection_data=positionCorrectionData[scene_num];

    return SYS_OK;
}