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

    index=14;
    /*
    positionCorrectionData[index].correctionValue.potision.xPosition=550*2*0.3527;
    positionCorrectionData[index].correctionValue.potision.yPosition=0;
    positionCorrectionData[index].correctionValue.xCondition=LOW;
    positionCorrectionData[index].correctionValue.yCondition=NONE;
    positionCorrectionData[index].correctionValueDirection.direction=90;
    positionCorrectionData[index].correctionValueDirection.condition=NONE;

    positionCorrectionData[index].correctionPosition.potision.xPosition=0;
    positionCorrectionData[index].correctionPosition.potision.yPosition=0;
    positionCorrectionData[index].correctionPosition.xCondition=NONE;
    positionCorrectionData[index].correctionPosition.yCondition=NONE;

    positionCorrectionData[index].correctionRGB.r=15;
    positionCorrectionData[index].correctionRGB.g=10;
    positionCorrectionData[index].correctionRGB.b=10;
    positionCorrectionData[index].correctionRGB.condition=LOW;

    positionCorrectionData[index].correctionDirection.direction=0;
    positionCorrectionData[index].correctionDirection.condition=NONE;

    positionCorrectionData[index].distance=0;

    positionCorrectionData[index].correctionCondition=JUDGE_RGB;

    index++;
    */

    //15
    index=14;
    positionCorrectionData[index].correctionV.v = 50;
    positionCorrectionData[index].correctionV.condition = LOW;

    positionCorrectionData[index].correctionValue.potision.xPosition=417*2*0.3527;
    positionCorrectionData[index].correctionValue.potision.yPosition=0;
    positionCorrectionData[index].correctionValue.xCondition=LOW;
    positionCorrectionData[index].correctionValue.yCondition=NONE;

    positionCorrectionData[index].correctionCondition=JUDGE_V;
    
    //19
    index=18;
    positionCorrectionData[index].correctionPosition.potision.yPosition=2600;
    positionCorrectionData[index].correctionPosition.xCondition=NONE;
    positionCorrectionData[index].correctionPosition.yCondition=LOW;

    positionCorrectionData[index].correctionValue.potision.xPosition=420*2*0.3527;
    positionCorrectionData[index].correctionValue.potision.yPosition=0;
    positionCorrectionData[index].correctionValue.xCondition=LOW;
    positionCorrectionData[index].correctionValue.yCondition=NONE;

    positionCorrectionData[index].correctionCondition=JUDGE_POS;

    //20
    index = 19;
    positionCorrectionData[index].correctionValueDirection.direction=180;
    positionCorrectionData[index].correctionValueDirection.condition=HIGH;

    positionCorrectionData[index].correctionS.s=110;
    positionCorrectionData[index].correctionS.condition=HIGH;

    positionCorrectionData[index].correctionValue.xCondition=NONE;
    positionCorrectionData[index].correctionValue.yCondition=NONE;

    positionCorrectionData[index].correctionCondition=JUDGE_S;

    index++;
}

SlEfPositionCorrectionInfomation::~SlEfPositionCorrectionInfomation(){
    delete(positionCorrectionData);
}

int8 SlEfPositionCorrectionInfomation::getter(int16 scene_num,PositionCorrectionData* positioncorrection_data){
    
    memcpy(positioncorrection_data,&positionCorrectionData[scene_num],sizeof(PositionCorrectionData));

    return SYS_OK;
}
