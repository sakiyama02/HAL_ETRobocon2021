//SlEbActionInfomation
//スラロームイーブイアクションインフォメーション
//

#include "../../include/SlalomEebuiInfomation/SlEbActionInfomation.h"

SlEbActionInfomation::SlEbActionInfomation(){
    memset(changeInfoData,0,sizeof(ChangeInfo) * SLALOMEEBUI_NUM);
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
    changeInfoData[index].pos_info_data.potision.xPosition=1618;
    changeInfoData[index].pos_info_data.potision.yPosition=3392;
    changeInfoData[index].pos_info_data.xCondition=LOW;
    changeInfoData[index].pos_info_data.yCondition=NONE;

    changeInfoData[index].distance=0;
    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=LINE_TRACE;
    changeInfoData[index].speed=15;

    index++;

    //2
    changeInfoData[index].pos_info_data.potision.xPosition=1560;//1503;1578
    changeInfoData[index].pos_info_data.potision.yPosition=3392;
    changeInfoData[index].pos_info_data.xCondition=LOW;
    changeInfoData[index].pos_info_data.yCondition=NONE;

    changeInfoData[index].distance=0;
    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=STRAIGHT;//ARM_ACTION;
    changeInfoData[index].speed=10;

    index++;

    //3
    changeInfoData[index].pos_info_data.potision.xPosition=1650;//1618;//1762.79;
    changeInfoData[index].pos_info_data.potision.yPosition=3392;
    changeInfoData[index].pos_info_data.xCondition=HIGH;
    changeInfoData[index].pos_info_data.yCondition=NONE;

    changeInfoData[index].distance=0;
    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=STRAIGHT;
    changeInfoData[index].speed=-30;

    index++;

    //4
    changeInfoData[index].pos_info_data.potision.xPosition=1650;//1618;
    changeInfoData[index].pos_info_data.potision.yPosition=3392;
    changeInfoData[index].pos_info_data.xCondition=LOW;
    changeInfoData[index].pos_info_data.yCondition=NONE;

    changeInfoData[index].distance=0;
    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=LINE_TRACE;
    changeInfoData[index].speed=30;

    index++;

    //5
    changeInfoData[index].pos_info_data.potision.xPosition=1503;
    changeInfoData[index].pos_info_data.potision.yPosition=3392;
    changeInfoData[index].pos_info_data.xCondition=LOW;
    changeInfoData[index].pos_info_data.yCondition=NONE;

    changeInfoData[index].distance=0;
    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=ARM_ACTION;
    changeInfoData[index].speed=20;

    index++;

    //6
    changeInfoData[index].pos_info_data.potision.xPosition=1482;
    changeInfoData[index].pos_info_data.potision.yPosition=3392;
    changeInfoData[index].pos_info_data.xCondition=LOW;
    changeInfoData[index].pos_info_data.yCondition=NONE;

    changeInfoData[index].distance=0;
    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=ARMDOWN_ACTION;
    changeInfoData[index].speed=20;

    index++;


    //7

    changeInfoData[index].pos_info_data.potision.xPosition=1390;
    changeInfoData[index].pos_info_data.potision.yPosition=3392;
    changeInfoData[index].pos_info_data.xCondition=LOW;
    changeInfoData[index].pos_info_data.yCondition=NONE;

    changeInfoData[index].distance=0;
    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=STRAIGHT;
    changeInfoData[index].speed=40;

    index++;

    //8
    changeInfoData[index].pos_info_data.potision.xPosition=1299;//1269;
    changeInfoData[index].pos_info_data.potision.yPosition=3382;
    changeInfoData[index].pos_info_data.xCondition=LOW;
    changeInfoData[index].pos_info_data.yCondition=NONE;

    changeInfoData[index].distance=0;
    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=LINE_TRACE;
    changeInfoData[index].speed=10;

    index++;

    //9
    changeInfoData[index].pos_info_data.potision.xPosition=1284;//1234;
    changeInfoData[index].pos_info_data.potision.yPosition=3382;
    changeInfoData[index].pos_info_data.xCondition=LOW;
    changeInfoData[index].pos_info_data.yCondition=NONE;

    changeInfoData[index].distance=0;
    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=LINE_TRACE;
    changeInfoData[index].speed=10;

    index++;


    //10
    changeInfoData[index].pos_info_data.potision.xPosition=1269;//1199;
    changeInfoData[index].pos_info_data.potision.yPosition=3382;
    changeInfoData[index].pos_info_data.xCondition=LOW;
    changeInfoData[index].pos_info_data.yCondition=NONE;

    changeInfoData[index].distance=0;
    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=LINE_TRACE;
    changeInfoData[index].speed=10;

    index++;

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    //11
    changeInfoData[index].direction_data.direction=119;
    changeInfoData[index].direction_data.condition=HIGH;

    changeInfoData[index].judge=JUDGE_DIR;
    changeInfoData[index].section_act=CURVE;
    changeInfoData[index].speed=30;//5;

    index++;
    //12
    changeInfoData[index].direction_data.direction=91;
    changeInfoData[index].direction_data.condition=LOW;

    changeInfoData[index].judge=JUDGE_DIR;
    changeInfoData[index].section_act=CURVE;
    changeInfoData[index].speed=30;//20;//5;

    index++;

    //13
    
    changeInfoData[index].vData.v=13;
    changeInfoData[index].vData.condition=LOW;
    //changeInfoData[index].direction_data.direction=1;
    //changeInfoData[index].direction_data.condition=LOW;

    changeInfoData[index].judge=JUDGE_V;
    changeInfoData[index].section_act=CURVE;
    changeInfoData[index].speed=30;//5;

    index++;

    //14
    changeInfoData[index].direction_data.direction=45;
    changeInfoData[index].direction_data.condition=LOW;

    changeInfoData[index].judge=JUDGE_DIR;
    changeInfoData[index].section_act=CURVE;
    changeInfoData[index].speed=30;//5;

    index++;


    //15
    changeInfoData[index].direction_data.direction=91;
    changeInfoData[index].direction_data.condition=HIGH;

    changeInfoData[index].judge=JUDGE_DIR;
    changeInfoData[index].section_act=CURVE;
    changeInfoData[index].speed=30;//5;

    index++;

    //16
    changeInfoData[index].vData.v=13;
    changeInfoData[index].vData.condition=LOW;
    changeInfoData[index].judge=JUDGE_V;
    changeInfoData[index].section_act=CURVE;
    changeInfoData[index].speed=30;//5;

    index++;

    //17
    changeInfoData[index].direction_data.direction=120;
    changeInfoData[index].direction_data.condition=HIGH;

    changeInfoData[index].judge=JUDGE_DIR;
    changeInfoData[index].section_act=CURVE;
    changeInfoData[index].speed=30;//5;

    index++;

    //18
    changeInfoData[index].direction_data.direction=91;
    changeInfoData[index].direction_data.condition=LOW;

    changeInfoData[index].judge=JUDGE_DIR;
    changeInfoData[index].section_act=CURVE;
    changeInfoData[index].speed=30;//5;

    index++;
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    //19
    changeInfoData[index].pos_info_data.potision.xPosition=440;//380;
    changeInfoData[index].pos_info_data.xCondition=LOW;
    changeInfoData[index].pos_info_data.yCondition=NONE;

    changeInfoData[index].distance=0;
    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=STRAIGHT;
    changeInfoData[index].speed=30;

    index++;
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    //20
    changeInfoData[index].direction_data.direction=130;//147;
    changeInfoData[index].direction_data.condition=HIGH;

    changeInfoData[index].judge=JUDGE_DIR;
    changeInfoData[index].section_act=CURVE;
    changeInfoData[index].speed=5;
    index++;
    //21
    changeInfoData[index].direction_data.direction=133;//147;
    changeInfoData[index].direction_data.condition=HIGH;

    changeInfoData[index].judge=JUDGE_DIR;
    changeInfoData[index].section_act=CURVE;
    changeInfoData[index].speed=5;
    index++;
}

SlEbActionInfomation::~SlEbActionInfomation(){
    delete(changeInfoData);
}

int8 SlEbActionInfomation::getter(int16 scene_num,ChangeInfo* change_info){
    
    memcpy(change_info,&changeInfoData[scene_num],sizeof(ChangeInfo));

    return SYS_OK;
}






