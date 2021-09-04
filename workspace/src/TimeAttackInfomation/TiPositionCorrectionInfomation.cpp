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
    //第一カーブ時の補正
    
    index=2;
    positionCorrectionData[index].correctionValue.potision.xPosition=423.24;//406.9705; //672.2462-(半径375.1566*√2)/2
    positionCorrectionData[index].correctionValue.potision.yPosition=305.4382;//305.2767; //570.5524-(半径375.1566*√2)/2
    positionCorrectionData[index].correctionValue.xCondition=HIGH;
    positionCorrectionData[index].correctionValue.yCondition=HIGH;
    positionCorrectionData[index].correctionValueDirection.direction=45;
    positionCorrectionData[index].correctionValueDirection.condition=NONE;

    positionCorrectionData[index].correctionDirection.direction=45;
    positionCorrectionData[index].correctionDirection.condition=LOW;
    positionCorrectionData[index].correctionCondition=JUDGE_DIR;

    // 第一カーブ後の機体のずれの補正
    index=3;
    positionCorrectionData[index].correctionValue.potision.xPosition=0; 
    positionCorrectionData[index].correctionValue.potision.yPosition=0;
    positionCorrectionData[index].correctionValue.xCondition=NONE;
    positionCorrectionData[index].correctionValue.yCondition=NONE;
    positionCorrectionData[index].correctionValueDirection.direction=0;
    positionCorrectionData[index].correctionValueDirection.condition=HIGH;

    positionCorrectionData[index].correctionPosition.potision.xPosition=0.0f;
    positionCorrectionData[index].correctionPosition.potision.yPosition=1100.0f;
    positionCorrectionData[index].correctionPosition.xCondition=NONE;
    positionCorrectionData[index].correctionPosition.yCondition=HIGH;
    positionCorrectionData[index].correctionCondition=JUDGE_POS;

    // 第二カーブ時の補正
    index=4;
    positionCorrectionData[index].correctionValue.potision.xPosition=487.4314; 
    positionCorrectionData[index].correctionValue.potision.yPosition=1402.3352; 
    positionCorrectionData[index].correctionValue.xCondition=HIGH;
    positionCorrectionData[index].correctionValue.yCondition=HIGH;
    positionCorrectionData[index].correctionValueDirection.condition=NONE;

    positionCorrectionData[index].correctionDirection.direction=-90;
    positionCorrectionData[index].correctionDirection.condition=LOW;
    positionCorrectionData[index].correctionCondition=JUDGE_DIR;

    // 第二カーブ後の機体のずれの補正
    index=5;
    positionCorrectionData[index].correctionValue.potision.xPosition=0; 
    positionCorrectionData[index].correctionValue.potision.yPosition=0;
    positionCorrectionData[index].correctionValue.xCondition=NONE;
    positionCorrectionData[index].correctionValue.yCondition=NONE;
    positionCorrectionData[index].correctionValueDirection.direction=-180;
    positionCorrectionData[index].correctionValueDirection.condition=HIGH;

    positionCorrectionData[index].correctionPosition.potision.xPosition=0.0f;
    positionCorrectionData[index].correctionPosition.potision.yPosition=1000.0f;
    positionCorrectionData[index].correctionPosition.xCondition=NONE;
    positionCorrectionData[index].correctionPosition.yCondition=LOW;
    positionCorrectionData[index].correctionCondition=JUDGE_POS;
  
    // 第三カーブ時の補正
    index=6;
    positionCorrectionData[index].correctionValue.potision.xPosition=732.2052; 
    positionCorrectionData[index].correctionValue.potision.yPosition=640.5032; 
    positionCorrectionData[index].correctionValue.xCondition=HIGH;
    positionCorrectionData[index].correctionValue.yCondition=HIGH;
    positionCorrectionData[index].correctionValueDirection.condition=NONE;

    positionCorrectionData[index].correctionDirection.direction=-135;
    positionCorrectionData[index].correctionDirection.condition=LOW;
    positionCorrectionData[index].correctionCondition=JUDGE_DIR;

    // 第三カーブ後の機体のずれとy軸の補正
    index=7;
    positionCorrectionData[index].correctionValue.potision.xPosition=0; 
    positionCorrectionData[index].correctionValue.potision.yPosition=567.847f;
    positionCorrectionData[index].correctionValue.xCondition=NONE;
    positionCorrectionData[index].correctionValue.yCondition=HIGH;
    positionCorrectionData[index].correctionValueDirection.direction=-90;
    positionCorrectionData[index].correctionValueDirection.condition=HIGH;

    positionCorrectionData[index].correctionPosition.potision.xPosition=1100.0f;
    positionCorrectionData[index].correctionPosition.potision.yPosition=0;
    positionCorrectionData[index].correctionPosition.xCondition=HIGH;
    positionCorrectionData[index].correctionPosition.yCondition=NONE;
    positionCorrectionData[index].correctionCondition=JUDGE_POS;

    // 第四カーブ時の補正
    index=8;
    positionCorrectionData[index].correctionValue.potision.xPosition=1703.541; 
    positionCorrectionData[index].correctionValue.potision.yPosition=708.2216; 
    positionCorrectionData[index].correctionValue.xCondition=HIGH;
    positionCorrectionData[index].correctionValue.yCondition=HIGH;
    positionCorrectionData[index].correctionValueDirection.condition=NONE;

    positionCorrectionData[index].correctionDirection.direction=0;
    positionCorrectionData[index].correctionDirection.condition=HIGH;
    positionCorrectionData[index].correctionCondition=JUDGE_DIR;

    // 第五カーブ時の補正
    index=10;
    positionCorrectionData[index].correctionValue.potision.xPosition=1192.8314; 
    positionCorrectionData[index].correctionValue.potision.yPosition=1094.0754; 
    positionCorrectionData[index].correctionValue.xCondition=HIGH;
    positionCorrectionData[index].correctionValue.yCondition=HIGH;
    positionCorrectionData[index].correctionValueDirection.condition=NONE;

    positionCorrectionData[index].correctionDirection.direction=0;
    positionCorrectionData[index].correctionDirection.condition=LOW;
    positionCorrectionData[index].correctionCondition=JUDGE_DIR;

    // Zカーブ後の機体のずれとy軸の補正
    index=11;
    positionCorrectionData[index].correctionValue.potision.xPosition=0; 
    positionCorrectionData[index].correctionValue.potision.yPosition=1213.9934f;
    positionCorrectionData[index].correctionValue.xCondition=NONE;
    positionCorrectionData[index].correctionValue.yCondition=HIGH;
    positionCorrectionData[index].correctionValueDirection.direction=-90;
    positionCorrectionData[index].correctionValueDirection.condition=HIGH;

    positionCorrectionData[index].correctionPosition.potision.xPosition=1800.4966f;
    positionCorrectionData[index].correctionPosition.potision.yPosition=0;
    positionCorrectionData[index].correctionPosition.xCondition=HIGH;
    positionCorrectionData[index].correctionPosition.yCondition=NONE;
    positionCorrectionData[index].correctionCondition=JUDGE_POS;

    // 第六カーブ時の補正
    index=12;
    positionCorrectionData[index].correctionValue.potision.xPosition=2030.1412; 
    positionCorrectionData[index].correctionValue.potision.yPosition=1166.0262; 
    positionCorrectionData[index].correctionValue.xCondition=HIGH;
    positionCorrectionData[index].correctionValue.yCondition=HIGH;
    positionCorrectionData[index].correctionValueDirection.condition=NONE;

    positionCorrectionData[index].correctionDirection.direction=-135;
    positionCorrectionData[index].correctionDirection.condition=LOW;
    positionCorrectionData[index].correctionCondition=JUDGE_DIR;

    // 第六カーブ後の機体のずれとy軸の補正
    index=13;
    positionCorrectionData[index].correctionValue.potision.xPosition=0; 
    positionCorrectionData[index].correctionValue.potision.yPosition=0;
    positionCorrectionData[index].correctionValue.xCondition=NONE;
    positionCorrectionData[index].correctionValue.yCondition=NONE;
    positionCorrectionData[index].correctionValueDirection.direction=-180;
    positionCorrectionData[index].correctionValueDirection.condition=HIGH;

    positionCorrectionData[index].correctionPosition.potision.xPosition=0;
    positionCorrectionData[index].correctionPosition.potision.yPosition=900;
    positionCorrectionData[index].correctionPosition.xCondition=NONE;
    positionCorrectionData[index].correctionPosition.yCondition=LOW;   
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