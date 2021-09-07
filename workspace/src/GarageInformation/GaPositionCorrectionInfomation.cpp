//GaPositionCorrectionInfomation
//ガレージポジションコレクションインフォメーション
//

#include "../../include/GarageInformation/GaPositionCorrectionInfomation.h"

GaPositionCorrectionInfomation::GaPositionCorrectionInfomation(){
    memset(positionCorrectionData,0,sizeof(PositionCorrectionData)*GARAGE_NUM);
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
//1
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
    
//2
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

//3
    positionCorrectionData[index].correctionValue.potision.xPosition=0;
    positionCorrectionData[index].correctionValue.potision.yPosition=3711*2*0.3527;
    positionCorrectionData[index].correctionValue.xCondition=NONE;
    positionCorrectionData[index].correctionValue.yCondition=HIGH;
   
    positionCorrectionData[index].correctionPosition.potision.xPosition=2100*2*0.3527;
    positionCorrectionData[index].correctionPosition.potision.yPosition=0;
    positionCorrectionData[index].correctionPosition.xCondition=HIGH;
    positionCorrectionData[index].correctionPosition.yCondition=NONE;

    positionCorrectionData[index].correctionRGB.r=0;
    positionCorrectionData[index].correctionRGB.g=0;
    positionCorrectionData[index].correctionRGB.b=0;
    positionCorrectionData[index].correctionRGB.condition=NONE;

    positionCorrectionData[index].correctionDirection.direction=0;
    positionCorrectionData[index].correctionDirection.condition=NONE;

    positionCorrectionData[index].correctionCondition=JUDGE_NONE;

    index++;
//4
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

//5
index++;

//5
/*
    positionCorrectionData[index].correctionValue.potision.xPosition=2500*2*0.3527;
    positionCorrectionData[index].correctionValue.potision.yPosition=0;
    positionCorrectionData[index].correctionValue.xCondition=HIGH;
    positionCorrectionData[index].correctionValue.yCondition=NONE;
    positionCorrectionData[index].correctionValueDirection.condition=NONE;
   
    positionCorrectionData[index].correctionPosition.potision.xPosition=0;
    positionCorrectionData[index].correctionPosition.potision.yPosition=0;
    positionCorrectionData[index].correctionPosition.xCondition=LOW;
    positionCorrectionData[index].correctionPosition.yCondition=NONE;

    positionCorrectionData[index].correctionRGB.r=20;
    positionCorrectionData[index].correctionRGB.g=10;
    positionCorrectionData[index].correctionRGB.b=10;
    positionCorrectionData[index].correctionRGB.condition=LOW;

    positionCorrectionData[index].correctionDirection.direction=0;
    positionCorrectionData[index].correctionDirection.condition=NONE;

    positionCorrectionData[index].correctionCondition=JUDGE_RGB;

    index++;
*/


//6
    positionCorrectionData[index].correctionValue.potision.xPosition=0;
    positionCorrectionData[index].correctionValue.potision.yPosition=0;
    positionCorrectionData[index].correctionValue.xCondition=NONE;
    positionCorrectionData[index].correctionValue.yCondition=NONE;
   
    positionCorrectionData[index].correctionPosition.potision.xPosition=0;
    positionCorrectionData[index].correctionPosition.potision.yPosition=0;
    positionCorrectionData[index].correctionPosition.xCondition=NONE;
    positionCorrectionData[index].correctionPosition.yCondition=NONE;

    positionCorrectionData[index].correctionRGB.r=10;
    positionCorrectionData[index].correctionRGB.g=10;
    positionCorrectionData[index].correctionRGB.b=10;
    positionCorrectionData[index].correctionRGB.condition=LOW;

    positionCorrectionData[index].correctionDirection.direction=0;
    positionCorrectionData[index].correctionDirection.condition=NONE;

    positionCorrectionData[index].correctionCondition=JUDGE_NONE;

    index++;

//7
index++;

//8
    positionCorrectionData[index].correctionValue.potision.xPosition=0;
    positionCorrectionData[index].correctionValue.potision.yPosition=0;
    positionCorrectionData[index].correctionValue.xCondition=NONE;
    positionCorrectionData[index].correctionValue.yCondition=NONE;
   
    positionCorrectionData[index].correctionPosition.potision.xPosition=0;
    positionCorrectionData[index].correctionPosition.potision.yPosition=0;
    positionCorrectionData[index].correctionPosition.xCondition=NONE;
    positionCorrectionData[index].correctionPosition.yCondition=NONE;

    positionCorrectionData[index].correctionRGB.r=10;
    positionCorrectionData[index].correctionRGB.g=10;
    positionCorrectionData[index].correctionRGB.b=10;
    positionCorrectionData[index].correctionRGB.condition=LOW;

    positionCorrectionData[index].correctionDirection.direction=0;
    positionCorrectionData[index].correctionDirection.condition=NONE;

    positionCorrectionData[index].correctionCondition=JUDGE_NONE;

    index++;

//9
    positionCorrectionData[index].correctionValue.potision.xPosition=0;
    positionCorrectionData[index].correctionValue.potision.yPosition=3463*2*0.3527;
    positionCorrectionData[index].correctionValue.xCondition=NONE;
    positionCorrectionData[index].correctionValue.yCondition=HIGH;
    positionCorrectionData[index].correctionValueDirection.condition=NONE;
    positionCorrectionData[index].correctionPosition.potision.xPosition=0;
    positionCorrectionData[index].correctionPosition.potision.yPosition=0;
    positionCorrectionData[index].correctionPosition.xCondition=NONE;
    positionCorrectionData[index].correctionPosition.yCondition=NONE;

    positionCorrectionData[index].correctionRGB.r=10;
    positionCorrectionData[index].correctionRGB.g=10;
    positionCorrectionData[index].correctionRGB.b=10;
    positionCorrectionData[index].correctionRGB.condition=LOW;

    positionCorrectionData[index].correctionDirection.direction=0;
    positionCorrectionData[index].correctionDirection.condition=NONE;

    positionCorrectionData[index].correctionCondition=JUDGE_RGB;

    index++;

//10
index++;
//11
index++;
//12
    positionCorrectionData[index].correctionValue.potision.xPosition=0;
    positionCorrectionData[index].correctionValue.potision.yPosition=3411*2*0.3527; //3411
    positionCorrectionData[index].correctionValue.xCondition=NONE;
    positionCorrectionData[index].correctionValue.yCondition=HIGH;
    positionCorrectionData[index].correctionValueDirection.direction=90.0f;
    positionCorrectionData[index].correctionValueDirection.condition=HIGH;
    positionCorrectionData[index].correctionPosition.potision.xPosition=2100*2*0.3527;
    positionCorrectionData[index].correctionPosition.potision.yPosition=0;
    positionCorrectionData[index].correctionPosition.xCondition=LOW;
    positionCorrectionData[index].correctionPosition.yCondition=NONE;

    positionCorrectionData[index].correctionCondition=JUDGE_POS;
    index++;
    
//13
index++;
//14
index++;
//15
index++;
//16
index++;
//17
index++;
//18
index++;
//19
index++;
//20
index++;
//21
index++;
//22
index++;
//23
index++;
//24
index++;
/*
  //19
    positionCorrectionData[18].correctionValue.potision.xPosition=1980*2*0.3527;
    positionCorrectionData[18].correctionValue.potision.yPosition=3613*2*0.3527;
    positionCorrectionData[18].correctionValue.xCondition=NONE;
    positionCorrectionData[18].correctionValue.yCondition=HIGH;
    positionCorrectionData[18].correctionValueDirection.condition=NONE;
    positionCorrectionData[18].correctionPosition.potision.xPosition=0;
    positionCorrectionData[18].correctionPosition.potision.yPosition=0;
    positionCorrectionData[18].correctionPosition.xCondition=NONE;
    positionCorrectionData[18].correctionPosition.yCondition=NONE;

    positionCorrectionData[18].correctionRGB.r=82;
    positionCorrectionData[18].correctionRGB.g=15;
    positionCorrectionData[18].correctionRGB.b=15;
    positionCorrectionData[18].correctionRGB.condition=HIGH;

    positionCorrectionData[18].correctionS.s=150;
    positionCorrectionData[18].correctionS.condition=HIGH;

    positionCorrectionData[18].correctionDirection.direction=0;
    positionCorrectionData[18].correctionDirection.condition=NONE;

    positionCorrectionData[18].correctionCondition=JUDGE_S;

    index++;
    

  //20
    positionCorrectionData[19].correctionValue.potision.xPosition=1980*2*0.3527;
    positionCorrectionData[19].correctionValue.potision.yPosition=3400*2*0.3527;
    positionCorrectionData[19].correctionValue.xCondition=HIGH;
    positionCorrectionData[19].correctionValue.yCondition=NONE;
    positionCorrectionData[19].correctionValueDirection.condition=NONE;
    positionCorrectionData[19].correctionPosition.potision.xPosition=0;
    positionCorrectionData[19].correctionPosition.potision.yPosition=0;
    positionCorrectionData[19].correctionPosition.xCondition=NONE;
    positionCorrectionData[19].correctionPosition.yCondition=NONE;

    positionCorrectionData[19].correctionRGB.r=10;
    positionCorrectionData[19].correctionRGB.g=10;
    positionCorrectionData[19].correctionRGB.b=10;
    positionCorrectionData[19].correctionRGB.condition=HIGH;

    positionCorrectionData[19].correctionV.v=80;
    positionCorrectionData[19].correctionV.condition=LOW;

    positionCorrectionData[19].correctionDirection.direction=0;
    positionCorrectionData[19].correctionDirection.condition=NONE;

    positionCorrectionData[19].correctionCondition=JUDGE_V;

    index++;
    
*/
  //21
  /*
    positionCorrectionData[20].correctionValue.potision.xPosition=1980*2*0.3527;
    positionCorrectionData[20].correctionValue.potision.yPosition=0;
    positionCorrectionData[20].correctionValue.xCondition=HIGH;
    positionCorrectionData[20].correctionValue.yCondition=NONE;
    positionCorrectionData[20].correctionValueDirection.condition=NONE;
    positionCorrectionData[20].correctionPosition.potision.xPosition=0;
    positionCorrectionData[20].correctionPosition.potision.yPosition=0;
    positionCorrectionData[20].correctionPosition.xCondition=NONE;
    positionCorrectionData[20].correctionPosition.yCondition=NONE;

    positionCorrectionData[20].correctionRGB.r=82;
    positionCorrectionData[20].correctionRGB.g=15;
    positionCorrectionData[20].correctionRGB.b=15;
    positionCorrectionData[20].correctionRGB.condition=HIGH;

    positionCorrectionData[20].correctionDirection.direction=0;
    positionCorrectionData[20].correctionDirection.condition=NONE;

    positionCorrectionData[20].correctionCondition=JUDGE_RGB;

    index++;
    */
/*
    index = 22;
    positionCorrectionData[index].correctionV.v = 100;
    positionCorrectionData[index].correctionV.condition = HIGH;

     positionCorrectionData[index].correctionValueDirection.direction=180;
    positionCorrectionData[index].correctionValueDirection.condition=LOW;

    positionCorrectionData[index].correctionCondition=JUDGE_V;
*/

//25
    positionCorrectionData[index].correctionValue.potision.xPosition=1900*2*0.3527;
    positionCorrectionData[index].correctionValue.potision.yPosition=3385*2*0.3527;
    positionCorrectionData[index].correctionValue.xCondition=LOW;
    positionCorrectionData[index].correctionValue.yCondition=HIGH;
    positionCorrectionData[index].correctionValueDirection.direction=180;
    positionCorrectionData[index].correctionValueDirection.condition=NONE;
    positionCorrectionData[index].correctionS.s = 190;
    positionCorrectionData[index].correctionS.condition = LOW;
    positionCorrectionData[index].correctionCondition=JUDGE_S;
    index++;
}

GaPositionCorrectionInfomation::~GaPositionCorrectionInfomation(){
    delete(positionCorrectionData);
}

int8 GaPositionCorrectionInfomation::getter(int16 scene_num,PositionCorrectionData* positioncorrection_data){
    
    memcpy(positioncorrection_data,&positionCorrectionData[scene_num],sizeof(PositionCorrectionData));

    return SYS_OK;
}