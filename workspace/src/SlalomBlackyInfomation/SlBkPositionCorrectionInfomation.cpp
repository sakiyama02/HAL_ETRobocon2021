//SlBkPositionCorrectionInfomation
//スラロームブラッキーポジションコレクションインフォメーション
//

#include "../../include/SlalomBlackyInfomation/SlBkPositionCorrectionInfomation.h"

SlBkPositionCorrectionInfomation::SlBkPositionCorrectionInfomation(){
    memset(positionCorrectionData,0,sizeof(PositionCorrectionData)*SLALOMBLACKY_NUM);
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
      
    //目標値に達した時設定する角度補正値
    //direction :角度補正値
    //condition:角度補正値設定フラグ(HIGH,LOWで設定あり NONEで設定なし)
    positionCorrectionData[index].correctionValueDirection.direction=0f;
    positionCorrectionData[index].correctionValueDirection.condition=NONE;
   
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

    //V値目標設定
    //v        :v値の切り替え値
    //condition:v値の切り替え地点の範囲指定(HIGH.LOW.NONE)
    positionCorrectionData[index].correctionV.v;
    positionCorrectionData[index].correctionV.condition;

    //距離目標設定
    //距離     :距離の切り替え値
    positionCorrectionData[index].distance=0;

    //目標値を判断する数値設定
    //correctionCondition:判断方法の指定
    //(JUDGE_RGB,JUDGE_POS,JUDGE_DIR,JUDGE_NONE)
    // 色　       座標      向き       判断なし 
    positionCorrectionData[index].correctionCondition=JUDGE_NONE;

    index++;
*/    
    //16
    //16
    index = 15;

    positionCorrectionData[index].correctionValueDirection.direction=180;
    positionCorrectionData[index].correctionValueDirection.condition=HIGH;

    positionCorrectionData[index].correctionS.s=80;
    positionCorrectionData[index].correctionS.condition=HIGH;
    positionCorrectionData[index].correctionValue.potision.xPosition=420*2*0.3527;
    positionCorrectionData[index].correctionValue.potision.yPosition=3600*2*0.3527;

    positionCorrectionData[index].correctionValue.xCondition=HIGH;
    positionCorrectionData[index].correctionValue.yCondition=HIGH;

    positionCorrectionData[index].correctionCondition=JUDGE_S;

    index++;
}

SlBkPositionCorrectionInfomation::~SlBkPositionCorrectionInfomation(){
    delete(positionCorrectionData);
}

int8 SlBkPositionCorrectionInfomation::getter(int16 scene_num,PositionCorrectionData* positioncorrection_data){
    
    memcpy(positioncorrection_data,&positionCorrectionData[scene_num],sizeof(PositionCorrectionData));

    return SYS_OK;
}

