//TiActionInfomation
//タイムアタックアクションインフォメーション
//

#include "../../include/TimeAttackInfomation/TiActionInfomation.h"

TiActionInfomation::TiActionInfomation(){
    memset(changeInfoData,0,sizeof(ChangeInfo) * TIMEATTACK_NUM);
    int16 index = 0;

/*
    //rgb切り替え値設定
    //r        :rの切り替え値
    //g        :gの切り替え値
    //b        :bの切り替え値
    //condition:切り替え地点の範囲指定(HIGH.LOW.NONE)
    changeInfoData[index].rgb_data.r=0;
    changeInfoData[index].rgb_data.g=0;
    changeInfoData[index].rgb_data.b=0;
    changeInfoData[index].rgb_data.condition=NONE;

    //座標切り替え値設定
    //xPosition :x座標の切り替え値
    //yPosition :y座標の切り替え値
    //xCondition:x座標切り替え地点の範囲指定(HIGH.LOW.NONE)
    //yCondition:y座標切り替え地点の範囲指定(HIGH.LOW.NONE)
    changeInfoData[index].pos_info_data.potision.xPosition=0f;
    changeInfoData[index].pos_info_data.potision.yPosition=0f;
    changeInfoData[index].pos_info_data.xCondition=NONE;
    changeInfoData[index].pos_info_data.yCondition=NONE;

    //向き切り替え値設定
    //direction:向きの切り替え値
    //condition:向きの切り替え地点の範囲指定(HIGH.LOW.NONE)
    changeInfoData[index].direction_data.direction=0;
    changeInfoData[index].direction_data.condition=NONE;

    //距離の切り替え値設定
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
    //(JUDGE_RGB,JUDGE_POS,JUDGE_DIS,JUDGE_DIR,JUDGE_NONE)
    // 色        座標      距離      向き       判断なし 
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

//template
    
    //----------------------------------------------------------
    //第一ストレート

    index = 0;
    changeInfoData[index].pos_info_data.potision.xPosition=2100;
    changeInfoData[index].pos_info_data.potision.yPosition=0;
    changeInfoData[index].pos_info_data.xCondition=LOW;
    changeInfoData[index].pos_info_data.yCondition=NONE;

    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=STRAIGHT;
    changeInfoData[index].speed=100;
    index++;

    index = 1;
    changeInfoData[index].pos_info_data.potision.xPosition=672.2462+30;
    changeInfoData[index].pos_info_data.potision.yPosition=0;
    changeInfoData[index].pos_info_data.xCondition=LOW;
    changeInfoData[index].pos_info_data.yCondition=NONE;

    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=LINE_TRACE;
    changeInfoData[index].speed=90;
    index++;

    index=2;
    changeInfoData[index].pos_info_data.potision.xPosition=0;
    changeInfoData[index].pos_info_data.potision.yPosition=570.5524f;
    changeInfoData[index].pos_info_data.xCondition=NONE;
    changeInfoData[index].pos_info_data.yCondition=HIGH;
    changeInfoData[index].direction_data.direction=1;
    changeInfoData[index].direction_data.condition=LOW;

    changeInfoData[index].judge=JUDGE_DIR;
    changeInfoData[index].section_act=CURVE;
    changeInfoData[index].speed=80;
    index++;

    index=3;
    changeInfoData[index].pos_info_data.potision.xPosition=0;
    changeInfoData[index].pos_info_data.potision.yPosition=1000;
    changeInfoData[index].pos_info_data.xCondition=NONE;
    changeInfoData[index].pos_info_data.yCondition=HIGH;

    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=LINE_TRACE;
    changeInfoData[index].speed=80;
    index++;

    index=4;
    changeInfoData[index].pos_info_data.potision.xPosition=0;
    changeInfoData[index].pos_info_data.potision.yPosition=1050;
    changeInfoData[index].pos_info_data.xCondition=NONE;
    changeInfoData[index].pos_info_data.yCondition=HIGH;

    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=STRAIGHT;
    changeInfoData[index].speed=90;
    index++;

    index = 5;
    changeInfoData[index].pos_info_data.potision.xPosition=2100;
    changeInfoData[index].pos_info_data.potision.yPosition=1050;
    changeInfoData[index].pos_info_data.xCondition=NONE;
    changeInfoData[index].pos_info_data.yCondition=LOW;
    changeInfoData[index].direction_data.direction=-180;
    changeInfoData[index].direction_data.condition=NONE;

    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=CURVE;
    changeInfoData[index].speed=90;
    index++;

    index = 6;
    changeInfoData[index].pos_info_data.potision.xPosition=0;
    changeInfoData[index].pos_info_data.potision.yPosition=799.9236;
    changeInfoData[index].pos_info_data.xCondition=NONE;
    changeInfoData[index].pos_info_data.yCondition=LOW;
    changeInfoData[index].direction_data.direction=-90;
    changeInfoData[index].direction_data.condition=HIGH;

    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=LINE_TRACE;
    changeInfoData[index].speed=80;
    index++;

    index = 7;
    changeInfoData[index].pos_info_data.potision.xPosition=948.763+35;
    changeInfoData[index].pos_info_data.potision.yPosition=0;
    changeInfoData[index].pos_info_data.xCondition=HIGH;
    changeInfoData[index].pos_info_data.yCondition=NONE;

    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=CURVE;
    changeInfoData[index].speed=85;
    index++;

    index = 8;
    changeInfoData[index].pos_info_data.potision.xPosition=1683.0844;
    changeInfoData[index].pos_info_data.potision.yPosition=0;
    changeInfoData[index].pos_info_data.xCondition=HIGH;
    changeInfoData[index].pos_info_data.yCondition=NONE;

    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=LINE_TRACE;
    changeInfoData[index].speed=80;
    index++;

    index = 9;
    changeInfoData[index].direction_data.direction=0;
    changeInfoData[index].direction_data.condition=HIGH;

    changeInfoData[index].judge=JUDGE_DIR;
    changeInfoData[index].section_act=CURVE;
    changeInfoData[index].speed=80;
    index++;

    index = 10;
    changeInfoData[index].pos_info_data.potision.xPosition=0;
    changeInfoData[index].pos_info_data.potision.yPosition=1018.5076;
    changeInfoData[index].pos_info_data.xCondition=NONE;
    changeInfoData[index].pos_info_data.yCondition=HIGH;

    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=STRAIGHT;
    changeInfoData[index].speed=80;
    index++;

    index = 11;
    changeInfoData[index].direction_data.direction=-180;
    changeInfoData[index].direction_data.condition=LOW;

    changeInfoData[index].judge=JUDGE_DIR;
    changeInfoData[index].section_act=CURVE;
    changeInfoData[index].speed=80;
    index++;

    index = 12;
    changeInfoData[index].direction_data.direction=3;
    changeInfoData[index].direction_data.condition=HIGH;

    changeInfoData[index].judge=JUDGE_DIR;
    changeInfoData[index].section_act=CURVE;
    changeInfoData[index].speed=80;
    index++;

    index = 13;
    changeInfoData[index].vData.v=85;
    changeInfoData[index].vData.condition=LOW;

    changeInfoData[index].judge=JUDGE_V;
    changeInfoData[index].section_act=STRAIGHT;
    changeInfoData[index].speed=80;
    index++;

    index = 14;
    changeInfoData[index].pos_info_data.potision.xPosition=0;
    changeInfoData[index].pos_info_data.potision.yPosition=2629.7312;
    changeInfoData[index].pos_info_data.xCondition=NONE;
    changeInfoData[index].pos_info_data.yCondition=HIGH;

    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=LINE_TRACE;
    changeInfoData[index].speed=95;
    index++;

    index=15;
    changeInfoData[index].sData.s=110;
    changeInfoData[index].sData.condition=HIGH;

    changeInfoData[index].judge=JUDGE_S;
    changeInfoData[index].section_act=LINE_TRACE;
    changeInfoData[index].speed=95;
    index++;

    index=16;
    changeInfoData[index].sData.s=80;
    changeInfoData[index].sData.condition=LOW;

    changeInfoData[index].judge=JUDGE_S;
    changeInfoData[index].section_act=LINE_TRACE;
    changeInfoData[index].speed=80;
    index++;

    index=17;
    changeInfoData[index].sData.s=110;
    changeInfoData[index].sData.condition=HIGH;

    changeInfoData[index].judge=JUDGE_S;
    changeInfoData[index].section_act=LINE_TRACE;
    changeInfoData[index].speed=50;
    index++;

    index=18;
    changeInfoData[index].pos_info_data.potision.xPosition=1762.79+75.8328;
    changeInfoData[index].pos_info_data.potision.yPosition=3392.27f;
    changeInfoData[index].pos_info_data.xCondition=LOW;
    changeInfoData[index].pos_info_data.yCondition=NONE;
    changeInfoData[index].direction_data.direction=0;
    changeInfoData[index].direction_data.condition=NONE;

    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=LINE_TRACE;
    changeInfoData[index].speed=30;

    index=19;
    changeInfoData[index].pos_info_data.potision.xPosition=1762.79;
    changeInfoData[index].pos_info_data.potision.yPosition=3392.27f;
    changeInfoData[index].pos_info_data.xCondition=LOW;
    changeInfoData[index].pos_info_data.yCondition=NONE;
    changeInfoData[index].direction_data.direction=0;
    changeInfoData[index].direction_data.condition=NONE;

    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=STRAIGHT;
    changeInfoData[index].speed=30;
}

TiActionInfomation::~TiActionInfomation(){
    delete(changeInfoData);
}

int8 TiActionInfomation::getter(int16 scene_num,ChangeInfo* change_info){

    memcpy(change_info,&changeInfoData[scene_num],sizeof(ChangeInfo));
    return SYS_OK;
}