//SlEfActionInfomation
//スラロームエーフィアクションインフォメーション
//

#include "../../include/SlalomEifieInfomation/SlEfActionInfomation.h"

SlEfActionInfomation::SlEfActionInfomation(){
    memset(changeInfoData,0,sizeof(ChangeInfo) * SLALOMEIFIE_NUM);
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
    changeInfoData[index].pos_info_data.potision.xPosition=315;
    changeInfoData[index].pos_info_data.xCondition=LOW;
    changeInfoData[index].pos_info_data.yCondition=NONE;//LOW

    changeInfoData[index].distance=0;
    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=STRAIGHT;
    changeInfoData[index].speed=10;

    index++;
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    //2
    changeInfoData[index].direction_data.direction=175;
    changeInfoData[index].direction_data.condition=HIGH;

    changeInfoData[index].distance=0;
    changeInfoData[index].judge=JUDGE_DIR;
    changeInfoData[index].section_act=TURN;
    changeInfoData[index].speed=10;

    index++;
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    //3
    
    changeInfoData[index].pos_info_data.potision.yPosition=3170;
    changeInfoData[index].pos_info_data.xCondition=NONE;
    changeInfoData[index].pos_info_data.yCondition=LOW;
    
    //距離
    /*
    changeInfoData[index].distance=5;
    */

    changeInfoData[index].distance=0;
    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=STRAIGHT;
    changeInfoData[index].speed=10;

    index++;
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    //4
    changeInfoData[index].direction_data.direction=205;
    changeInfoData[index].direction_data.condition=HIGH;

    changeInfoData[index].distance=0;
    changeInfoData[index].judge=JUDGE_DIR;
    changeInfoData[index].section_act=TURN;
    changeInfoData[index].speed=10;

    index++;

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    //5
    changeInfoData[index].pos_info_data.potision.xPosition=320;
    changeInfoData[index].pos_info_data.xCondition=HIGH;
    changeInfoData[index].pos_info_data.yCondition=NONE;

    changeInfoData[index].distance=0;
    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=STRAIGHT;
    changeInfoData[index].speed=10;

    index++;

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    //6
    changeInfoData[index].direction_data.direction=217;
    changeInfoData[index].direction_data.condition=HIGH;

    changeInfoData[index].distance=0;
    changeInfoData[index].judge=JUDGE_DIR;
    changeInfoData[index].section_act=TURN;
    changeInfoData[index].speed=10;

    index++;
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    //7
    changeInfoData[index].pos_info_data.potision.xPosition=430;
    changeInfoData[index].pos_info_data.xCondition=HIGH;
    changeInfoData[index].pos_info_data.yCondition=NONE;

    changeInfoData[index].distance=0;
    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=STRAIGHT;
    changeInfoData[index].speed=10;

    index++;

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    //8
    changeInfoData[index].direction_data.direction=175;
    changeInfoData[index].direction_data.condition=LOW;

    changeInfoData[index].distance=0;
    changeInfoData[index].judge=JUDGE_DIR;
    changeInfoData[index].section_act=TURN;
    changeInfoData[index].speed=10;

    index++;

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    //9
    changeInfoData[index].pos_info_data.potision.yPosition=2850;
    changeInfoData[index].pos_info_data.xCondition=NONE;
    changeInfoData[index].pos_info_data.yCondition=LOW;

    changeInfoData[index].distance=0;
    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=ARM_ACTION;
    changeInfoData[index].speed=15;

    index++;

    //10
    changeInfoData[index].pos_info_data.potision.yPosition=2835;
    changeInfoData[index].pos_info_data.xCondition=NONE;
    changeInfoData[index].pos_info_data.yCondition=LOW;

    changeInfoData[index].distance=0;
    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=ARMDOWN_ACTION;
    changeInfoData[index].speed=15;

    index++;


    //11
    changeInfoData[index].pos_info_data.potision.yPosition=2800;
    changeInfoData[index].pos_info_data.xCondition=NONE;
    changeInfoData[index].pos_info_data.yCondition=LOW;

    changeInfoData[index].distance=0;
    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=STRAIGHT;
    changeInfoData[index].speed=10;

    index++;
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    //12
    changeInfoData[index].pos_info_data.potision.yPosition=4000*2*0.3527;
    //changeInfoData[index].pos_info_data.potision.yPosition=3291;//3096
    changeInfoData[index].pos_info_data.xCondition=NONE;
    changeInfoData[index].pos_info_data.yCondition=LOW;

    changeInfoData[index].distance=0;
    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=STRAIGHT;
    changeInfoData[index].speed=10;

    index++;
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    //13
    changeInfoData[index].direction_data.direction=89;
    changeInfoData[index].direction_data.condition=LOW;

    changeInfoData[index].distance=0;
    changeInfoData[index].judge=JUDGE_DIR;
    changeInfoData[index].section_act=TURN;
    changeInfoData[index].speed=10;

    index++; 

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    //14
    changeInfoData[index].rgb_data.r=20;
    changeInfoData[index].rgb_data.g=20;
    changeInfoData[index].rgb_data.b=20;
    changeInfoData[index].rgb_data.condition=LOW;  
    changeInfoData[index].judge=JUDGE_RGB;
    changeInfoData[index].section_act=STRAIGHT;
    changeInfoData[index].speed=10;

    index++;
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    //15
    changeInfoData[index].pos_info_data.potision.xPosition=400*2*0.3527;
    //changeInfoData[index].pos_info_data.potision.yPosition=3291;//3096
    changeInfoData[index].pos_info_data.xCondition=LOW;
    changeInfoData[index].pos_info_data.yCondition=NONE;

    changeInfoData[index].distance=0;
    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=STRAIGHT;
    changeInfoData[index].speed=10;

    index++;
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    //16
    changeInfoData[index].direction_data.direction=180;
    changeInfoData[index].direction_data.condition=HIGH;

    changeInfoData[index].distance=0;
    changeInfoData[index].judge=JUDGE_DIR;
    changeInfoData[index].section_act=TURN;
    changeInfoData[index].speed=10;

    index++; 

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    //17
    changeInfoData[index].sData.s=110;
    changeInfoData[index].sData.condition=HIGH;

    changeInfoData[index].distance=0;
    changeInfoData[index].judge=JUDGE_S;
    changeInfoData[index].section_act=LINE_TRACE;
    changeInfoData[index].speed=10;
}

SlEfActionInfomation::~SlEfActionInfomation(){
    delete(changeInfoData);
}

int8 SlEfActionInfomation::getter(int16 scene_num,ChangeInfo* change_info){
    
    memcpy(change_info,&changeInfoData[scene_num],sizeof(ChangeInfo));

    return SYS_OK;
}

