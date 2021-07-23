//SlEfPositionCorrectionInfomation
//スラロームエーフィポジションコレクションインフォメーション
//

#include "../../include/SlalomEifieInfomation/SlEfPositionCorrectionInfomation.h"

SlEfPositionCorrectionInfomation::SlEfPositionCorrectionInfomation(){
    memset(positionCorrectionData,0,sizeof(PositionCorrectionData)*SLALOMEIFIE_NUM);
    int8 index = 0;

//template
/*
    //目標値に達した時設定する座標補正値
    //xPosition :x座標補正値
    //yPosition :y座標補正値
    //xCondition:x座標補正値設定フラグ(HIGH,LOWで設定あり NONEで設定なし)
    //yCondition:y座標補正値設定フラグ(HIGH,LOWで設定あり NONEで設定なし)
    positionCorrectionData[index].correctionValue.potision.xPosition=0f;
    positionCorrectionData[index].correctionValue.potision.yPosition=0f;
    positionCorrectionData[index].correctionValue.xCondition=NONE;
    positionCorrectionData[index].correctionValue.yCondition=NONE;
   
    //座標目標値の設定
    //xPosition :x座標の切り替え値
    //yPosition :y座標の切り替え値
    //xCondition:x座標切り替え地点の範囲指定(HIGH.LOW.NONE)
    //yCondition:y座標切り替え地点の範囲指定(HIGH.LOW.NONE)
    positionCorrectionData[index].correctionPosition.potision.xPosition=0f;
    positionCorrectionData[index].correctionPosition.potision.yPosition=0f;
    positionCorrectionData[index].correctionPosition.xCondition=NONE;
    positionCorrectionData[index].correctionPosition.yCondition=NONE;

    //rgb目標値設定
    //r        :rの切り替え値
    //g        :gの切り替え値
    //b        :bの切り替え値
    //condition:切り替え地点の範囲指定(HIGH.LOW.NONE)
    positionCorrectionData[index].correctionRGB.r=0;
    positionCorrectionData[index].correctionRGB.g=0;
    positionCorrectionData[index].correctionRGB.b=0;
    positionCorrectionData[index].correctionRGB.condition=NONE;

    //向き目標値設定
    //direction:向きの切り替え値
    //condition:向きの切り替え地点の範囲指定(HIGH.LOW.NONE)
    positionCorrectionData[index].correctionDirection.direction=0;
    positionCorrectionData[index].correctionDirection.condition=NONE;

    //目標値を判断する数値設定
    //correctionCondition:判断方法の指定
    //(JUDGE_RGB,JUDGE_POS,JUDGE_DIR,JUDGE_NONE)
    // 色　       座標      向き       判断なし 
    positionCorrectionData[index].correctionCondition=JUDGE_NONE;

    index++;
*/    
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

    positionCorrectionData[index].correctionCondition=JUDGE_NONE;

    index++;

}

SlEfPositionCorrectionInfomation::~SlEfPositionCorrectionInfomation(){
    delete(positionCorrectionData);
}

int8 SlEfPositionCorrectionInfomation::getter(int16 scene_num,PositionCorrectionData* positioncorrection_data){
    
    memcpy(positioncorrection_data,&positionCorrectionData[scene_num],sizeof(PositionCorrectionData));

    return SYS_OK;
}