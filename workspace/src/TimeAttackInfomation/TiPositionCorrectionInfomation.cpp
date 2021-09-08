//TiPositionCorrectionInfomation
//タイムアタックポジションコレクションインフォメーション
//

#include "../../include/TimeAttackInfomation/TiPositionCorrectionInfomation.h"

TiPositionCorrectionInfomation::TiPositionCorrectionInfomation(){
    memset(positionCorrectionData,JUDGE_NONE,sizeof(PositionCorrectionData)*TIMEATTACK_NUM);
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
    index=1;
    positionCorrectionData[index].correctionValue.potision.xPosition=0;
    positionCorrectionData[index].correctionValue.potision.yPosition=277 * 0.3527 * 2;
    positionCorrectionData[index].correctionValue.xCondition=NONE;
    positionCorrectionData[index].correctionValue.yCondition=HIGH;
    positionCorrectionData[index].correctionValueDirection.direction=45;
    positionCorrectionData[index].correctionValueDirection.condition=NONE;

    positionCorrectionData[index].correctionPosition.potision.xPosition=670+30;
    positionCorrectionData[index].correctionPosition.potision.yPosition=0;
    positionCorrectionData[index].correctionPosition.xCondition=LOW;
    positionCorrectionData[index].correctionPosition.yCondition=NONE;
    positionCorrectionData[index].correctionCondition=JUDGE_POS;

    index=4;
    positionCorrectionData[index].correctionValue.potision.xPosition=305.4382;
    positionCorrectionData[index].correctionValue.potision.yPosition=0;
    positionCorrectionData[index].correctionValue.xCondition=HIGH;
    positionCorrectionData[index].correctionValue.yCondition=NONE;
    positionCorrectionData[index].correctionValueDirection.direction=0;
    positionCorrectionData[index].correctionValueDirection.condition=HIGH;

    positionCorrectionData[index].correctionPosition.potision.xPosition=0;
    positionCorrectionData[index].correctionPosition.potision.yPosition=1045;
    positionCorrectionData[index].correctionPosition.xCondition=NONE;
    positionCorrectionData[index].correctionPosition.yCondition=HIGH;
    positionCorrectionData[index].correctionCondition=JUDGE_POS;

    index=8;
    positionCorrectionData[index].correctionValue.potision.xPosition=0;
    positionCorrectionData[index].correctionValue.potision.yPosition=567.847;
    positionCorrectionData[index].correctionValue.xCondition=NONE;
    positionCorrectionData[index].correctionValue.yCondition=HIGH;
    positionCorrectionData[index].correctionValueDirection.direction=-90;
    positionCorrectionData[index].correctionValueDirection.condition=HIGH;

    positionCorrectionData[index].correctionPosition.potision.xPosition=1550;
    positionCorrectionData[index].correctionPosition.potision.yPosition=1045;
    positionCorrectionData[index].correctionPosition.xCondition=HIGH;
    positionCorrectionData[index].correctionPosition.yCondition=NONE;
    positionCorrectionData[index].correctionCondition=JUDGE_POS;

    index=17;
    positionCorrectionData[index].correctionValue.potision.xPosition=1914.4556; 
    positionCorrectionData[index].correctionValue.potision.yPosition=3392.974;
    positionCorrectionData[index].correctionValue.xCondition=HIGH;
    positionCorrectionData[index].correctionValue.yCondition=HIGH;
    positionCorrectionData[index].correctionValueDirection.direction=0;
    positionCorrectionData[index].correctionValueDirection.condition=NONE;

    positionCorrectionData[index].correctionS.s=100;
    positionCorrectionData[index].correctionS.condition=HIGH;

    positionCorrectionData[index].correctionCondition=JUDGE_S;

     //タイムアタック終了時の補正
    index=19;
    positionCorrectionData[index].correctionValue.potision.xPosition=1762.79;
    positionCorrectionData[index].correctionValue.potision.yPosition=3392.27;
    positionCorrectionData[index].correctionValue.xCondition=HIGH;
    positionCorrectionData[index].correctionValue.yCondition=HIGH;
    positionCorrectionData[index].correctionValueDirection.direction=90;
    positionCorrectionData[index].correctionValueDirection.condition=HIGH;

    positionCorrectionData[index].correctionPosition.potision.xPosition=1762.79;
    positionCorrectionData[index].correctionPosition.potision.yPosition=0;
    positionCorrectionData[index].correctionPosition.xCondition=LOW;
    positionCorrectionData[index].correctionPosition.yCondition=NONE;   
    positionCorrectionData[index].correctionCondition=JUDGE_POS;

 
}

TiPositionCorrectionInfomation::~TiPositionCorrectionInfomation(){
    delete(positionCorrectionData);
}

int8 TiPositionCorrectionInfomation::getter(int16 scene_num,PositionCorrectionData* positioncorrection_data){
    
    memcpy(positioncorrection_data,&positionCorrectionData[scene_num],sizeof(PositionCorrectionData));
    return SYS_OK;
}