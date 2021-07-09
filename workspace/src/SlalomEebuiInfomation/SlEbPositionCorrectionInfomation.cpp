//SlEbPositionCorrectionInfomation
//スラロームイーブイポジションコレクションインフォメーション
//

#include "../../include/SlalomEebuiInfomation/SlEbPositionCorrectionInfomation.h"

SlEbPositionCorrectionInfomation::SlEbPositionCorrectionInfomation(){
    memset(positionCorrectionData,0,sizeof(PositionCorrectionData)*TIMEATTACK_NUM);
    int8 index = 0;

//template
/*
    positionCorrectionData[index].correctionValue.xPosition=0;
    positionCorrectionData[index].correctionValue.yPosition=0;

    positionCorrectionData[index].correctionPosition.xPosition=0;
    positionCorrectionData[index].correctionPosition.yPosition=0;

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

SlEbPositionCorrectionInfomation::~SlEbPositionCorrectionInfomation(){
    delete(positionCorrectionData);
}

int8 SlEbPositionCorrectionInfomation::getter(int16 scene_num,PositionCorrectionData* positioncorrection_data){
    
    memcpy(positioncorrection_data,&positionCorrectionData[scene_num],sizeof(PositionCorrectionData));

    return SYS_OK;
}