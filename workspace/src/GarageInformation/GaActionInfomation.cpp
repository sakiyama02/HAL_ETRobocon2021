//GaActionInfomation
//ガレージアクションインフォメーション
//

#include "../../include/GarageInformation/GaActionInfomation.h"

GaActionInfomation::GaActionInfomation(){
    memset(changeInfoData,0,sizeof(ChangeInfo) * GARAGE_NUM);
    int16 index = 0;

//template
/*
    //rgb切り替え設定
    //r        :rの切り替え値
    //g        :gの切り替え値
    //b        :bの切り替え値
    //condition:切り替え地点の範囲指定(HIGH.LOW.NONE)
    changeInfoData[index].rgb_data.r=0;
    changeInfoData[index].rgb_data.g=0;
    changeInfoData[index].rgb_data.b=0;
    changeInfoData[index].rgb_data.condition=NONE;

    //座標切り替え設定
    //xPosition :x座標の切り替え値
    //yPosition :y座標の切り替え値
    //xCondition:x座標切り替え地点の範囲指定(HIGH.LOW.NONE)
    //yCondition:y座標切り替え地点の範囲指定(HIGH.LOW.NONE)
    changeInfoData[index].pos_info_data.potision.xPosition=0f;
    changeInfoData[index].pos_info_data.potision.yPosition=0f;
    changeInfoData[index].pos_info_data.xCondition=NONE;
    changeInfoData[index].pos_info_data.yCondition=NONE;

    //向き切り替え設定
    //direction:向きの切り替え値
    //condition:向きの切り替え地点の範囲指定(HIGH.LOW.NONE)
    changeInfoData[index].direction_data.direction=0;
    changeInfoData[index].direction_data.condition=NONE;

    //距離の切り替え設定
    //distance:距離の切り替え値
    changeInfoData[index].distance=0;

    //v値切り替え値設定
    //v:v値の切り替え値
    //condition:v値の切り替え地点の範囲指定(HIGH.LOW.NONE)
    changeInfoData[index].vData.v=0;
    changeInfoData[index].vData.condition=NONE;

    //s値切り替え値設定
    //s:s値の切り替え値
    //condition:s値の切り替え地点の範囲指定(HIGH.LOW.NONE)
    changeInfoData[index].sData.s=0;
    changeInfoData[index].sData.condition=NONE;

    //切り替え方法
    //judge:切り替え方法の指定
    //(JUDGE_RGB,JUDGE_POS,JUDGE_DIS,
    //JUDGE_DIR,JUDGE_NONE,JUDGE_SEND)
    changeInfoData[index].judge=JUDGE_NONE;

    //機体の動作設定
    //section_act:機体の動作設定
    //(LINE_TRACE,STRAIGHT,CURVE,LINE_CURVE,TURN,ARM_ACTION)
    changeInfoData[index].section_act=STRAIGHT;

    //機体の速度設定
    //speed:速度の設定
    changeInfoData[index].speed=0;

    index++;
*/


//1
    changeInfoData[index].direction_data.direction=92;  //上方向の誤差が許されないため、＋２度
    changeInfoData[index].direction_data.condition=LOW;

    changeInfoData[index].judge=JUDGE_DIR;
    changeInfoData[index].section_act=TURN;
    changeInfoData[index].speed=10;
    index++;
//2
    changeInfoData[index].pos_info_data.potision.xPosition=1685*2*0.3527;
    changeInfoData[index].pos_info_data.potision.yPosition=3711*2*0.3527;
    changeInfoData[index].pos_info_data.xCondition=HIGH;
    changeInfoData[index].pos_info_data.yCondition=NONE;

    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=STRAIGHT;
    changeInfoData[index].speed=-60;
    index++;

//3
    changeInfoData[index].pos_info_data.potision.xPosition=1923*2*0.3527;
    changeInfoData[index].pos_info_data.potision.yPosition=3711*2*0.3527;
    changeInfoData[index].pos_info_data.xCondition=LOW;
    changeInfoData[index].pos_info_data.yCondition=NONE;
    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=STRAIGHT;
    changeInfoData[index].speed=-90;
    index++;

//4
    changeInfoData[index].pos_info_data.potision.xPosition=2181*2*0.3527;
    changeInfoData[index].pos_info_data.potision.yPosition=3711*2*0.3527;
    changeInfoData[index].pos_info_data.xCondition=HIGH;
    changeInfoData[index].pos_info_data.yCondition=NONE;
    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=STRAIGHT;
    changeInfoData[index].speed=-60;
    index++;

//5
    changeInfoData[index].pos_info_data.potision.xPosition=2360*2*0.3527;
    changeInfoData[index].pos_info_data.potision.yPosition=3711*2*0.3527;
    changeInfoData[index].pos_info_data.xCondition=HIGH;
    changeInfoData[index].pos_info_data.yCondition=NONE;
    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=STRAIGHT;
    changeInfoData[index].speed=-30;
    index++;
//6
    changeInfoData[index].sData.s=100;
    changeInfoData[index].sData.condition=HIGH;
    changeInfoData[index].judge=JUDGE_S;
    changeInfoData[index].section_act=STRAIGHT;
    changeInfoData[index].speed=-10;
    index++;

//7
    changeInfoData[index].pos_info_data.potision.xPosition=2298*2*0.3527;
    changeInfoData[index].pos_info_data.potision.yPosition=3711*2*0.3527;
    changeInfoData[index].pos_info_data.xCondition=LOW;
    changeInfoData[index].pos_info_data.yCondition=NONE;
    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=STRAIGHT;
    changeInfoData[index].speed=20;
    index++;

//8
    changeInfoData[index].direction_data.direction=177;
    changeInfoData[index].direction_data.condition=HIGH;

    changeInfoData[index].judge=JUDGE_DIR;
    changeInfoData[index].section_act=TURN;
    changeInfoData[index].speed=10;
    index++;

//9
    changeInfoData[index].pos_info_data.potision.xPosition=2298*2*0.3527;
    changeInfoData[index].pos_info_data.potision.yPosition=3700*2*0.3527;
    changeInfoData[index].pos_info_data.xCondition=NONE;
    changeInfoData[index].pos_info_data.yCondition=LOW;
    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=STRAIGHT;
    changeInfoData[index].speed=20;
    index++;

//10
    changeInfoData[index].rgb_data.r=20;
    changeInfoData[index].rgb_data.g=20;
    changeInfoData[index].rgb_data.b=20;
    changeInfoData[index].rgb_data.condition=LOW;
    changeInfoData[index].judge=JUDGE_RGB;
    changeInfoData[index].section_act=STRAIGHT;
    changeInfoData[index].speed=20;
    index++;

//9
/*
    changeInfoData[index].pos_info_data.potision.xPosition=2298*2*0.3527;
    changeInfoData[index].pos_info_data.potision.yPosition=3450*2*0.3527;
    changeInfoData[index].pos_info_data.xCondition=NONE;
    changeInfoData[index].pos_info_data.yCondition=LOW;
    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=STRAIGHT;
    changeInfoData[index].speed=20;
    index++;
    */

//11
    changeInfoData[index].direction_data.direction=89;
    changeInfoData[index].direction_data.condition=LOW;

    changeInfoData[index].judge=JUDGE_DIR;
    changeInfoData[index].section_act=TURN;
    changeInfoData[index].speed=10;
    index++;
//12
    changeInfoData[index].pos_info_data.potision.xPosition=2050*2*0.3527;
    changeInfoData[index].pos_info_data.potision.yPosition=3463*2*0.3527;
    changeInfoData[index].pos_info_data.xCondition=LOW;
    changeInfoData[index].pos_info_data.yCondition=NONE;
    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=LINE_TRACE;
    changeInfoData[index].speed=15;
    index++;
//13
    changeInfoData[index].vData.v=115;
    changeInfoData[index].vData.condition=LOW;
    changeInfoData[index].judge=JUDGE_RGB;
    changeInfoData[index].section_act=STRAIGHT;
    changeInfoData[index].speed=20;
    index++;



//14
    changeInfoData[index].pos_info_data.potision.xPosition=1800*2*0.3527;
    changeInfoData[index].pos_info_data.potision.yPosition=3463*2*0.3527;
    changeInfoData[index].pos_info_data.xCondition=LOW;
    changeInfoData[index].pos_info_data.yCondition=NONE;
    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=STRAIGHT;
    changeInfoData[index].speed=50;
    index++;
    /*
//13

    changeInfoData[index].rgb_data.r=120;
    changeInfoData[index].rgb_data.g=29;
    changeInfoData[index].rgb_data.b=36;
    changeInfoData[index].rgb_data.condition=HIGH;
    changeInfoData[index].judge=JUDGE_RGB;
    changeInfoData[index].section_act=LINE_TRACE;
    changeInfoData[index].speed=20;
    index++;
*/
//15
    changeInfoData[index].direction_data.direction=0;
    changeInfoData[index].direction_data.condition=LOW;

    changeInfoData[index].judge=JUDGE_DIR;
    changeInfoData[index].section_act=CURVE;
    changeInfoData[index].speed=70;
    index++;
//16
    changeInfoData[index].direction_data.direction=90;
    changeInfoData[index].direction_data.condition=HIGH;

    changeInfoData[index].judge=JUDGE_DIR;
    changeInfoData[index].section_act=CURVE;
    changeInfoData[index].speed=70;
    index++;
//17
    changeInfoData[index].direction_data.direction=125; //130
    changeInfoData[index].direction_data.condition=HIGH;

    changeInfoData[index].judge=JUDGE_DIR;
    changeInfoData[index].section_act=CURVE;
    changeInfoData[index].speed=60;
    index++;
//18
    changeInfoData[index].pos_info_data.potision.xPosition=600*2*0.3527;
    changeInfoData[index].pos_info_data.potision.yPosition=3463*2*0.3527;
    changeInfoData[index].pos_info_data.xCondition=LOW;
    changeInfoData[index].pos_info_data.yCondition=NONE;
    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=STRAIGHT;
    changeInfoData[index].speed=30;
    index++;
//19
    changeInfoData[index].vData.v=117;
    changeInfoData[index].vData.condition=LOW;
    changeInfoData[index].judge=JUDGE_V;
    changeInfoData[index].section_act=STRAIGHT;
    changeInfoData[index].speed=20;
    index++; 

//20
    changeInfoData[index].vData.v=120;
    changeInfoData[index].vData.condition=HIGH;
    changeInfoData[index].judge=JUDGE_V;
    changeInfoData[index].section_act=STRAIGHT;
    changeInfoData[index].speed=5;
    index++; 

//21
    changeInfoData[index].direction_data.direction=178;
    changeInfoData[index].direction_data.condition=HIGH;
    changeInfoData[index].judge=JUDGE_DIR;
    changeInfoData[index].section_act=TURN;
    changeInfoData[index].speed=10;
    index++;
//22
    changeInfoData[index].pos_info_data.potision.xPosition=1900*2*0.3527;
    changeInfoData[index].pos_info_data.potision.yPosition=3613*2*0.3527;
    changeInfoData[index].pos_info_data.xCondition=NONE;
    changeInfoData[index].pos_info_data.yCondition=LOW;
    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=LINE_TRACE;
    changeInfoData[index].speed=10;
    index++;
//23
    changeInfoData[index].sData.s=180;
    changeInfoData[index].sData.condition=LOW;
    changeInfoData[index].judge=JUDGE_S;
    changeInfoData[index].section_act=LINE_TRACE;
    changeInfoData[index].speed=10;
    index++;

//24
    changeInfoData[index].pos_info_data.potision.xPosition=1900*2*0.3527;
    changeInfoData[index].pos_info_data.potision.yPosition=3300*2*0.3527; // 3200
    changeInfoData[index].pos_info_data.yCondition=LOW;
    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=LINE_TRACE;
    changeInfoData[index].speed=10;
    index++;



/*
//17
    changeInfoData[index].pos_info_data.potision.xPosition=700*2*0.3527;
    changeInfoData[index].pos_info_data.potision.yPosition=3177*2*0.3527;
    changeInfoData[index].pos_info_data.xCondition=LOW;
    changeInfoData[index].pos_info_data.yCondition=NONE;
    changeInfoData[index].judge=JUDGE_POS;

    changeInfoData[index].section_act=STRAIGHT;
    changeInfoData[index].speed=20;
    index++;

//16
    changeInfoData[index].vData.v=120;
    changeInfoData[index].vData.condition=LOW;
    changeInfoData[index].judge=JUDGE_V;
    changeInfoData[index].section_act=STRAIGHT;
    changeInfoData[index].speed=20;
    index++;

//17
    changeInfoData[index].pos_info_data.potision.xPosition=2004*2*0.3527;
    changeInfoData[index].pos_info_data.potision.yPosition=3177*2*0.3527;
    changeInfoData[index].pos_info_data.xCondition=NONE;
    changeInfoData[index].pos_info_data.yCondition=LOW;
    changeInfoData[index].judge=JUDGE_POS;

    changeInfoData[index].section_act=LINE_TRACE;
    changeInfoData[index].speed=20;
    index++;
  */  
//25
    changeInfoData[index].distance=6;
    changeInfoData[index].judge=JUDGE_DIS;
    changeInfoData[index].section_act=STRAIGHT;
    changeInfoData[index].speed=20;
    index++;
    
}

GaActionInfomation::~GaActionInfomation(){
    delete(changeInfoData);
}

int8 GaActionInfomation::getter(int16 scene_num,ChangeInfo* change_info){
    
    memcpy(change_info,&changeInfoData[scene_num],sizeof(ChangeInfo));

    return SYS_OK;
}