//SlEfPositionCorrectionInfomation
//スラロームエーフィポジションコレクションインフォメーション
//

#include "../../include/SlalomEifieInfomation/SlEfPositionCorrectionInfomation.h"

SlEfPositionCorrectionInfomation::SlEfPositionCorrectionInfomation(){
    memset(positionCorrectionData,NONE,sizeof(PositionCorrectionData)*SLALOMEIFIE_NUM);
    int8 index = 0;

    positionCorrectionData[index].correctionValue.potision.xPosition=0;
    positionCorrectionData[index].correctionValue.potision.yPosition=0;
    positionCorrectionData[index].correctionValue.xCondition=NONE;
    positionCorrectionData[index].correctionValue.yCondition=NONE;
   
    positionCorrectionData[index].correctionPosition.potision.xPosition=0;
    positionCorrectionData[index].correctionPosition.potision.yPosition=0;
    positionCorrectionData[index].correctionPosition.xCondition=NONE;
    positionCorrectionData[index].correctionPosition.yCondition=NONE;

    positionCorrectionData[index].correctionRGB.r=0;
    positionCorrectionData[index].correctionRGB.g=0;
    positionCorrectionData[index].correctionRGB.b=0;
    positionCorrectionData[index].correctionRGB.condition=NONE;

    positionCorrectionData[index].correctionDirection.direction=0;
    positionCorrectionData[index].correctionDirection.condition=NONE;

    positionCorrectionData[index].distance=0;

    positionCorrectionData[index].correctionCondition=JUDGE_NONE;

    index++;

    //2
    positionCorrectionData[index].correctionCondition=JUDGE_NONE;

    index++;

    //3
    positionCorrectionData[index].correctionCondition=JUDGE_NONE;

    index++;

    //4
    positionCorrectionData[index].correctionCondition=JUDGE_NONE;

    index++;

    //5
    positionCorrectionData[index].correctionCondition=JUDGE_NONE;

    index++;

    //6
    positionCorrectionData[index].correctionCondition=JUDGE_NONE;

    index++;

    //7
    positionCorrectionData[index].correctionCondition=JUDGE_NONE;

    index++;

    //8
    positionCorrectionData[index].correctionCondition=JUDGE_NONE;

    index++;

    //9
    positionCorrectionData[index].correctionCondition=JUDGE_NONE;

    index++;
    positionCorrectionData[13].correctionValue.potision.xPosition=550*2*0.3527;
    positionCorrectionData[13].correctionValue.potision.yPosition=0;
    positionCorrectionData[13].correctionValue.xCondition=LOW;
    positionCorrectionData[13].correctionValue.yCondition=NONE;
    positionCorrectionData[13].correctionValueDirection.direction=90;
    positionCorrectionData[13].correctionValueDirection.condition=NONE;

    positionCorrectionData[13].correctionPosition.potision.xPosition=0;
    positionCorrectionData[13].correctionPosition.potision.yPosition=0;
    positionCorrectionData[13].correctionPosition.xCondition=NONE;
    positionCorrectionData[13].correctionPosition.yCondition=NONE;

    positionCorrectionData[13].correctionRGB.r=15;
    positionCorrectionData[13].correctionRGB.g=10;
    positionCorrectionData[13].correctionRGB.b=10;
    positionCorrectionData[13].correctionRGB.condition=LOW;

    positionCorrectionData[13].correctionDirection.direction=0;
    positionCorrectionData[13].correctionDirection.condition=NONE;

    positionCorrectionData[13].distance=0;

    positionCorrectionData[13].correctionCondition=JUDGE_RGB;

    index++;

}

SlEfPositionCorrectionInfomation::~SlEfPositionCorrectionInfomation(){
    delete(positionCorrectionData);
}

int8 SlEfPositionCorrectionInfomation::getter(int16 scene_num,PositionCorrectionData* positioncorrection_data){
    
    memcpy(positioncorrection_data,&positionCorrectionData[scene_num],sizeof(PositionCorrectionData));

    return SYS_OK;
}
