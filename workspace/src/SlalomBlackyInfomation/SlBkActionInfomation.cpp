//SlBkActionInfomation
//スラロームブラッキーアクションインフォメーション
//

#include "../../include/SlalomBlackyInfomation/SlBkActionInfomation.h"

SlBkActionInfomation::SlBkActionInfomation(){
    memset(changeInfoData,0,sizeof(ChangeInfo) * SLALOMBLACKY_NUM);
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
    /*
    changeInfoData[index].direction_data.direction=147;
    changeInfoData[index].direction_data.condition=HIGH;

    changeInfoData[index].distance=0;
    changeInfoData[index].judge=JUDGE_DIR;
    changeInfoData[index].section_act=TURN;
    changeInfoData[index].speed=10;
    */
    changeInfoData[index].direction_data.direction=147;
    changeInfoData[index].direction_data.condition=HIGH;

    changeInfoData[index].judge=JUDGE_DIR;
    changeInfoData[index].section_act=CURVE;
    changeInfoData[index].speed=20;//5;


    index++;

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    //2
    changeInfoData[index].pos_info_data.potision.xPosition=340;
    //changeInfoData[index].pos_info_data.potision.yPosition=3291;//3096
    changeInfoData[index].pos_info_data.xCondition=LOW;
    changeInfoData[index].pos_info_data.yCondition=NONE;//LOW

    changeInfoData[index].distance=0;
    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=STRAIGHT;
    changeInfoData[index].speed=10;//10;

    index++;


    //3
    changeInfoData[index].pos_info_data.potision.xPosition=320;
    //changeInfoData[index].pos_info_data.potision.yPosition=3137;//3096
    changeInfoData[index].pos_info_data.xCondition=LOW;
    changeInfoData[index].pos_info_data.yCondition=NONE;//LOW

    changeInfoData[index].distance=0;
    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=STRAIGHT;
    changeInfoData[index].speed=25;

    index++;

    //4
    changeInfoData[index].pos_info_data.potision.xPosition=240;
    //changeInfoData[index].pos_info_data.potision.yPosition=3110;//3096
    changeInfoData[index].pos_info_data.xCondition=LOW;
    changeInfoData[index].pos_info_data.yCondition=NONE;//LOW

    changeInfoData[index].distance=0;
    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=STRAIGHT;
    changeInfoData[index].speed=15;

    index++;
/*
    changeInfoData[index].direction_data.direction=90;
    changeInfoData[index].direction_data.condition=LOW;

    changeInfoData[index].judge=JUDGE_DIR;
    changeInfoData[index].section_act=CURVE;
    changeInfoData[index].speed=20;//5;


    index++;

    changeInfoData[index].direction_data.direction=270;
    changeInfoData[index].direction_data.condition=HIGH;

    changeInfoData[index].judge=JUDGE_DIR;
    changeInfoData[index].section_act=CURVE;
    changeInfoData[index].speed=5;


    index++;
*/

    //5
    changeInfoData[index].direction_data.direction=180;
    changeInfoData[index].direction_data.condition=HIGH;

    changeInfoData[index].judge=JUDGE_DIR;
    changeInfoData[index].section_act=CURVE;
    changeInfoData[index].speed=10;//5;


    index++;
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    //6
    changeInfoData[index].pos_info_data.potision.xPosition=225;
    changeInfoData[index].pos_info_data.potision.yPosition=2960;
    changeInfoData[index].pos_info_data.xCondition=NONE;
    changeInfoData[index].pos_info_data.yCondition=LOW;

    changeInfoData[index].distance=0;
    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=STRAIGHT;
    changeInfoData[index].speed=25;

    index++;


    //**************************************************************************

    //7
    changeInfoData[index].pos_info_data.potision.xPosition=225;
    changeInfoData[index].pos_info_data.potision.yPosition=2850;//2933//2860
    changeInfoData[index].pos_info_data.xCondition=NONE;
    changeInfoData[index].pos_info_data.yCondition=LOW;

    changeInfoData[index].distance=0;
    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=ARM_ACTION;
    changeInfoData[index].speed=15;

    index++;

    //8
    changeInfoData[index].pos_info_data.potision.xPosition=225;
    changeInfoData[index].pos_info_data.potision.yPosition=2835;//2912
    changeInfoData[index].pos_info_data.xCondition=NONE;
    changeInfoData[index].pos_info_data.yCondition=LOW;

    changeInfoData[index].distance=0;
    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=ARMDOWN_ACTION;
    changeInfoData[index].speed=10;

    index++;


    //9
    changeInfoData[index].pos_info_data.potision.xPosition=225;
    changeInfoData[index].pos_info_data.potision.yPosition=2800;//2876+//2780
    changeInfoData[index].pos_info_data.xCondition=NONE;
    changeInfoData[index].pos_info_data.yCondition=LOW;

    changeInfoData[index].distance=0;
    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=STRAIGHT;
    changeInfoData[index].speed=20;

    index++;
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    //10
    changeInfoData[index].direction_data.direction=215;//265;
    changeInfoData[index].direction_data.condition=HIGH;

    changeInfoData[index].distance=0;
    changeInfoData[index].judge=JUDGE_DIR;
    changeInfoData[index].section_act=TURN;
    changeInfoData[index].speed=20;

    index++;

    //11
    changeInfoData[index].vData.v=85;
    changeInfoData[index].vData.condition=LOW;  
    changeInfoData[index].judge=JUDGE_V;
    changeInfoData[index].section_act=STRAIGHT;
    changeInfoData[index].speed=20;
    
    index++;
    //12
    changeInfoData[index].vData.v=90;
    changeInfoData[index].vData.condition=HIGH;  
    changeInfoData[index].judge=JUDGE_V;
    changeInfoData[index].section_act=STRAIGHT;
    changeInfoData[index].speed=20;
/*
    changeInfoData[index].pos_info_data.potision.xPosition=200;
    changeInfoData[index].pos_info_data.potision.yPosition=2800;//2876
    changeInfoData[index].pos_info_data.xCondition=HIGH;
    changeInfoData[index].pos_info_data.yCondition=NONE;

    changeInfoData[index].distance=0;
    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=STRAIGHT;
    changeInfoData[index].speed=10;
*/

    index++;

    //13
    changeInfoData[index].direction_data.direction=180;
    changeInfoData[index].direction_data.condition=LOW;

    changeInfoData[index].distance=0;
    changeInfoData[index].judge=JUDGE_DIR;
    changeInfoData[index].section_act=TURN;
    changeInfoData[index].speed=25;

    index++;

    //14
    changeInfoData[index].pos_info_data.potision.xPosition=200;
    changeInfoData[index].pos_info_data.potision.yPosition=2690;//2876
    changeInfoData[index].pos_info_data.xCondition=NONE;
    changeInfoData[index].pos_info_data.yCondition=LOW;
    changeInfoData[index].distance=0;
    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=LINE_TRACE;
    changeInfoData[index].speed=10;

    index++;

    //15
    changeInfoData[index].pos_info_data.potision.xPosition=200;
    changeInfoData[index].pos_info_data.potision.yPosition=2600;//2876
    changeInfoData[index].pos_info_data.xCondition=NONE;
    changeInfoData[index].pos_info_data.yCondition=LOW;
    changeInfoData[index].distance=0;
    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=LINE_TRACE;
    changeInfoData[index].speed=10;

    index++;

    //16
    changeInfoData[index].sData.s=80;
    changeInfoData[index].sData.condition=HIGH;

    changeInfoData[index].distance=0;
    changeInfoData[index].judge=JUDGE_S;
    changeInfoData[index].section_act=LINE_TRACE;
    changeInfoData[index].speed=10;



}

SlBkActionInfomation::~SlBkActionInfomation(){
    delete(changeInfoData);
}

int8 SlBkActionInfomation::getter(int16 scene_num,ChangeInfo* change_info){
    
    memcpy(change_info,&changeInfoData[scene_num],sizeof(ChangeInfo));

    return SYS_OK;
}


