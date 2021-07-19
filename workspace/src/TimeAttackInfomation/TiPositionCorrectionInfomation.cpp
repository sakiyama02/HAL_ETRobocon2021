//TiPositionCorrectionInfomation
//タイムアタックポジションコレクションインフォメーション
//

#include "../../include/TimeAttackInfomation/TiPositionCorrectionInfomation.h"

TiPositionCorrectionInfomation::TiPositionCorrectionInfomation(){
    memset(positionCorrectionData,0,sizeof(PositionCorrectionData)*TIMEATTACK_NUM);
    int8 index = 0;

//template
/*
    positionCorrectionData[index].correctionValue.potision.xPosition=0;
    positionCorrectionData[index].correctionValue.potision.yPosition=0;
   
    positionCorrectionData[index].correctionPosition.potision.xPosition=0;
    positionCorrectionData[index].correctionPosition.potision.yPosition=0;
    positionCorrectionData[index].correctionPosition.xCondition=0;
    positionCorrectionData[index].correctionPosition.yCondition=0;

    positionCorrectionData[index].correctionRGB.r=0;
    positionCorrectionData[index].correctionRGB.g=0;
    positionCorrectionData[index].correctionRGB.b=0;
    positionCorrectionData[index].correctionRGB.condition=0;

    positionCorrectionData[index].correctionDirection.direction=0;
    positionCorrectionData[index].correctionDirection.condition=0;

    positionCorrectionData[index].correctionCondition=0;

    index++;
*/
}

TiPositionCorrectionInfomation::~TiPositionCorrectionInfomation(){
    delete(positionCorrectionData);
}

int8 TiPositionCorrectionInfomation::getter(int16 scene_num,PositionCorrectionData* positioncorrection_data){
    
    memcpy(positioncorrection_data,&positionCorrectionData[scene_num],sizeof(PositionCorrectionData));
    return SYS_OK;
}