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
    changeInfoData[index].speed=30;

    index++;

    //2
    changeInfoData[index].pos_info_data.potision.xPosition=1503;
    changeInfoData[index].pos_info_data.potision.yPosition=3392;
    changeInfoData[index].pos_info_data.xCondition=LOW;
    changeInfoData[index].pos_info_data.yCondition=NONE;

    changeInfoData[index].distance=0;
    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=ARM_ACTION;
    changeInfoData[index].speed=20;

    index++;

    //3
    changeInfoData[index].pos_info_data.potision.xPosition=1482;
    changeInfoData[index].pos_info_data.potision.yPosition=3392;
    changeInfoData[index].pos_info_data.xCondition=LOW;
    changeInfoData[index].pos_info_data.yCondition=NONE;

    changeInfoData[index].distance=0;
    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=ARMDOWN_ACTION;
    changeInfoData[index].speed=20;

    index++;


    //4

    changeInfoData[index].pos_info_data.potision.xPosition=1390;
    changeInfoData[index].pos_info_data.potision.yPosition=3392;
    changeInfoData[index].pos_info_data.xCondition=LOW;
    changeInfoData[index].pos_info_data.yCondition=NONE;

    changeInfoData[index].distance=0;
    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=STRAIGHT;
    changeInfoData[index].speed=30;

    index++;

    //5
    changeInfoData[index].pos_info_data.potision.xPosition=1234;
    changeInfoData[index].pos_info_data.potision.yPosition=3382;
    changeInfoData[index].pos_info_data.xCondition=LOW;
    changeInfoData[index].pos_info_data.yCondition=NONE;

    changeInfoData[index].distance=0;
    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=LINE_TRACE;
    changeInfoData[index].speed=20;

    index++;


    //6
    changeInfoData[index].pos_info_data.potision.xPosition=1199;
    changeInfoData[index].pos_info_data.potision.yPosition=3382;
    changeInfoData[index].pos_info_data.xCondition=LOW;
    changeInfoData[index].pos_info_data.yCondition=NONE;

    changeInfoData[index].distance=0;
    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=LINE_TRACE;
    changeInfoData[index].speed=10;

    index++;
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    //7
    changeInfoData[index].direction_data.direction=119;
    changeInfoData[index].direction_data.condition=HIGH;

    changeInfoData[index].distance=0;
    changeInfoData[index].judge=JUDGE_DIR;
    changeInfoData[index].section_act=TURN;
    changeInfoData[index].speed=10;

    index++;
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
   //8
    changeInfoData[index].pos_info_data.potision.xPosition=1175;
    changeInfoData[index].pos_info_data.potision.yPosition=3333;
    changeInfoData[index].pos_info_data.xCondition=LOW;
    changeInfoData[index].pos_info_data.yCondition=NONE;

    changeInfoData[index].distance=0;
    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=STRAIGHT;
    changeInfoData[index].speed=10;

    index++;

   //9
    changeInfoData[index].pos_info_data.potision.xPosition=1129;
    changeInfoData[index].pos_info_data.potision.yPosition=3333;
    changeInfoData[index].pos_info_data.xCondition=LOW;
    changeInfoData[index].pos_info_data.yCondition=LOW;

    changeInfoData[index].distance=0;
    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=STRAIGHT;
    changeInfoData[index].speed=25;//15

    index++;

    //10
    changeInfoData[index].pos_info_data.potision.xPosition=1096;
    changeInfoData[index].pos_info_data.potision.yPosition=3311;
    changeInfoData[index].pos_info_data.xCondition=LOW;
    changeInfoData[index].pos_info_data.yCondition=LOW;

    changeInfoData[index].distance=0;
    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=STRAIGHT;
    changeInfoData[index].speed=10;

    index++;
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    //11
    changeInfoData[index].direction_data.direction=91;
    changeInfoData[index].direction_data.condition=LOW;

    changeInfoData[index].distance=0;
    changeInfoData[index].judge=JUDGE_DIR;
    changeInfoData[index].section_act=TURN;
    changeInfoData[index].speed=10;

    index++;
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    //12
    changeInfoData[index].pos_info_data.potision.xPosition=1066;
    changeInfoData[index].pos_info_data.xCondition=LOW;
    changeInfoData[index].pos_info_data.yCondition=NONE;

    changeInfoData[index].distance=0;
    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=STRAIGHT;
    changeInfoData[index].speed=10;

    index++;
    //13
    changeInfoData[index].pos_info_data.potision.xPosition=1006;//1006
    changeInfoData[index].pos_info_data.xCondition=LOW;
    changeInfoData[index].pos_info_data.yCondition=NONE;

    changeInfoData[index].distance=0;
    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=STRAIGHT;
    changeInfoData[index].speed=25;

    index++;

    //14
    changeInfoData[index].pos_info_data.potision.xPosition=970;
    changeInfoData[index].pos_info_data.xCondition=LOW;
    changeInfoData[index].pos_info_data.yCondition=NONE;

    changeInfoData[index].distance=0;
    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=STRAIGHT;
    changeInfoData[index].speed=10;

    index++;
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    //15
    changeInfoData[index].direction_data.direction=40;
    changeInfoData[index].direction_data.condition=LOW;

    changeInfoData[index].distance=0;
    changeInfoData[index].judge=JUDGE_DIR;
    changeInfoData[index].section_act=TURN;
    changeInfoData[index].speed=10;

    index++;
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    //16
    changeInfoData[index].pos_info_data.potision.yPosition=3321;
    changeInfoData[index].pos_info_data.xCondition=NONE;
    changeInfoData[index].pos_info_data.yCondition=HIGH;

    changeInfoData[index].distance=0;
    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=STRAIGHT;
    changeInfoData[index].speed=10;//15

    index++;

    //17
    changeInfoData[index].pos_info_data.potision.yPosition=3370;
    changeInfoData[index].pos_info_data.xCondition=NONE;
    changeInfoData[index].pos_info_data.yCondition=HIGH;

    changeInfoData[index].distance=0;
    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=STRAIGHT;
    changeInfoData[index].speed=25;//15

    index++;

    //18
    changeInfoData[index].pos_info_data.potision.xPosition=902;
    changeInfoData[index].pos_info_data.potision.yPosition=3402;
    changeInfoData[index].pos_info_data.xCondition=LOW;
    changeInfoData[index].pos_info_data.yCondition=HIGH;

    changeInfoData[index].distance=0;
    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=STRAIGHT;
    changeInfoData[index].speed=10;

    index++;
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    //19
    changeInfoData[index].direction_data.direction=60;
    changeInfoData[index].direction_data.condition=HIGH;

    changeInfoData[index].distance=0;
    changeInfoData[index].judge=JUDGE_DIR;
    changeInfoData[index].section_act=TURN;
    changeInfoData[index].speed=10;

    index++;
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    //20
    changeInfoData[index].pos_info_data.potision.xPosition=870;
    changeInfoData[index].pos_info_data.xCondition=LOW;
    changeInfoData[index].pos_info_data.yCondition=NONE;

    changeInfoData[index].distance=0;
    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=STRAIGHT;
    changeInfoData[index].speed=10;//25

    index++;

    //21
    //changeInfoData[index].pos_info_data.potision.xPosition=866;
    changeInfoData[index].pos_info_data.potision.yPosition=3415;
    changeInfoData[index].pos_info_data.xCondition=NONE;
    changeInfoData[index].pos_info_data.yCondition=HIGH;

    changeInfoData[index].distance=0;
    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=STRAIGHT;
    changeInfoData[index].speed=25;//25

    index++;

    //22
    changeInfoData[index].pos_info_data.potision.xPosition=838;
    changeInfoData[index].pos_info_data.potision.yPosition=3435;//3438
    changeInfoData[index].pos_info_data.xCondition=LOW;
    changeInfoData[index].pos_info_data.yCondition=HIGH;

    changeInfoData[index].distance=0;
    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=STRAIGHT;
    changeInfoData[index].speed=10;

    index++;
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    //23
    changeInfoData[index].direction_data.direction=87;
    changeInfoData[index].direction_data.condition=HIGH;

    changeInfoData[index].distance=0;
    changeInfoData[index].judge=JUDGE_DIR;
    changeInfoData[index].section_act=TURN;
    changeInfoData[index].speed=10;

    index++;
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    //24
    changeInfoData[index].pos_info_data.potision.xPosition=851;
    changeInfoData[index].pos_info_data.xCondition=LOW;
    changeInfoData[index].pos_info_data.yCondition=NONE;

    changeInfoData[index].distance=0;
    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=STRAIGHT;
    changeInfoData[index].speed=10;

    index++;

    //25
    changeInfoData[index].pos_info_data.potision.xPosition=780;
    changeInfoData[index].pos_info_data.xCondition=LOW;
    changeInfoData[index].pos_info_data.yCondition=NONE;

    changeInfoData[index].distance=0;
    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=STRAIGHT;
    changeInfoData[index].speed=30;

    index++;

    //26
    changeInfoData[index].pos_info_data.potision.xPosition=735;
    changeInfoData[index].pos_info_data.xCondition=LOW;
    changeInfoData[index].pos_info_data.yCondition=NONE;

    changeInfoData[index].distance=0;
    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=STRAIGHT;
    changeInfoData[index].speed=10;

    index++;
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    //27
    changeInfoData[index].direction_data.direction=133;//135//124++129
    changeInfoData[index].direction_data.condition=HIGH;

    changeInfoData[index].distance=0;
    changeInfoData[index].judge=JUDGE_DIR;
    changeInfoData[index].section_act=TURN;
    changeInfoData[index].speed=10;

    index++;
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    //28
    //changeInfoData[index].pos_info_data.potision.xPosition=642;//674///603***585
    changeInfoData[index].pos_info_data.potision.yPosition=3423;//3376//3368
    changeInfoData[index].pos_info_data.xCondition=NONE;
    changeInfoData[index].pos_info_data.yCondition=LOW;

    changeInfoData[index].distance=0;
    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=STRAIGHT;
    changeInfoData[index].speed=10;//15

    index++;

    //29
    //changeInfoData[index].pos_info_data.potision.xPosition=642;//674///603***585
    changeInfoData[index].pos_info_data.potision.yPosition=3400;//3376//3368
    changeInfoData[index].pos_info_data.xCondition=NONE;
    changeInfoData[index].pos_info_data.yCondition=LOW;

    changeInfoData[index].distance=0;
    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=STRAIGHT;
    changeInfoData[index].speed=25;//15

    index++;

    //30
    //changeInfoData[index].pos_info_data.potision.xPosition=642;//674///603***585
    changeInfoData[index].pos_info_data.potision.yPosition=3368;//3376//3368
    changeInfoData[index].pos_info_data.xCondition=NONE;
    changeInfoData[index].pos_info_data.yCondition=LOW;

    changeInfoData[index].distance=0;
    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=STRAIGHT;
    changeInfoData[index].speed=10;

    index++;
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    //31
    changeInfoData[index].direction_data.direction=114;//89//100or110
    changeInfoData[index].direction_data.condition=LOW;

    changeInfoData[index].distance=0;
    changeInfoData[index].judge=JUDGE_DIR;
    changeInfoData[index].section_act=TURN;
    changeInfoData[index].speed=10;

    index++;
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    //32
    changeInfoData[index].pos_info_data.potision.yPosition=3353;
    changeInfoData[index].pos_info_data.xCondition=NONE;
    changeInfoData[index].pos_info_data.yCondition=LOW;

    changeInfoData[index].distance=0;
    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=STRAIGHT;
    changeInfoData[index].speed=15;//25

    index++;

    //33
    //changeInfoData[index].pos_info_data.potision.xPosition=580;
    //changeInfoData[index].pos_info_data.xCondition=LOW;
    changeInfoData[index].pos_info_data.potision.yPosition=3333;//3376++3368**3356
    changeInfoData[index].pos_info_data.xCondition=NONE;
    changeInfoData[index].pos_info_data.yCondition=LOW;

    changeInfoData[index].distance=0;
    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=STRAIGHT;
    changeInfoData[index].speed=10;

    index++;
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    //34
    changeInfoData[index].direction_data.direction=92;//93//100or110
    changeInfoData[index].direction_data.condition=LOW;

    changeInfoData[index].distance=0;
    changeInfoData[index].judge=JUDGE_DIR;
    changeInfoData[index].section_act=TURN;
    changeInfoData[index].speed=10;

    index++;
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    //35

    changeInfoData[index].pos_info_data.potision.xPosition=550;
    changeInfoData[index].pos_info_data.xCondition=LOW;
    changeInfoData[index].pos_info_data.yCondition=NONE;

    changeInfoData[index].distance=0;
    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=STRAIGHT;
    changeInfoData[index].speed=10;

    index++;

    //36

    changeInfoData[index].pos_info_data.potision.xPosition=535;
    changeInfoData[index].pos_info_data.xCondition=LOW;
    changeInfoData[index].pos_info_data.yCondition=NONE;

    changeInfoData[index].distance=0;
    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=STRAIGHT;
    changeInfoData[index].speed=25;

    index++;

    //37

    changeInfoData[index].pos_info_data.potision.xPosition=520;
    changeInfoData[index].pos_info_data.xCondition=LOW;
    changeInfoData[index].pos_info_data.yCondition=NONE;

    changeInfoData[index].distance=0;
    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=STRAIGHT;
    changeInfoData[index].speed=40;

    index++;
    
    //38

    changeInfoData[index].pos_info_data.potision.xPosition=490;
    changeInfoData[index].pos_info_data.xCondition=LOW;
    changeInfoData[index].pos_info_data.yCondition=NONE;

    changeInfoData[index].distance=0;
    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=STRAIGHT;
    changeInfoData[index].speed=60;

    index++;
    
    //39

    changeInfoData[index].pos_info_data.potision.xPosition=450;
    changeInfoData[index].pos_info_data.xCondition=LOW;
    changeInfoData[index].pos_info_data.yCondition=NONE;

    changeInfoData[index].distance=0;
    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=STRAIGHT;
    changeInfoData[index].speed=40;

    index++;

    //40

    changeInfoData[index].pos_info_data.potision.xPosition=400;
    changeInfoData[index].pos_info_data.xCondition=LOW;
    changeInfoData[index].pos_info_data.yCondition=NONE;

    changeInfoData[index].distance=0;
    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=STRAIGHT;
    changeInfoData[index].speed=25;

    index++;

    //41

    changeInfoData[index].pos_info_data.potision.xPosition=350;
    changeInfoData[index].pos_info_data.xCondition=LOW;
    changeInfoData[index].pos_info_data.yCondition=NONE;

    changeInfoData[index].distance=0;
    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=STRAIGHT;
    changeInfoData[index].speed=10;

    index++;
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
}

SlEbActionInfomation::~SlEbActionInfomation(){
    delete(changeInfoData);
}

int8 SlEbActionInfomation::getter(int16 scene_num,ChangeInfo* change_info){
    
    memcpy(change_info,&changeInfoData[scene_num],sizeof(ChangeInfo));

    return SYS_OK;
}


