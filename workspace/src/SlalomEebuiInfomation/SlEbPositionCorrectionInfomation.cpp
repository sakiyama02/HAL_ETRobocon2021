//SlEbPositionCorrectionInfomation
//スラロームイーブイポジションコレクションインフォメーション
//

#include "../../include/SlalomEebuiInfomation/SlEbPositionCorrectionInfomation.h"

SlEbPositionCorrectionInfomation::SlEbPositionCorrectionInfomation(){
    memset(positionCorrectionData,0,sizeof(PositionCorrectionData)*TIMEATTACK_NUM);
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

SlEbPositionCorrectionInfomation::~SlEbPositionCorrectionInfomation(){
    delete(positionCorrectionData);
}

int8 SlEbPositionCorrectionInfomation::getter(int16 scene_num,PositionCorrectionData* positioncorrection_data){
    
    positioncorrection_data=&positionCorrectionData[scene_num];

    return SYS_OK;
}