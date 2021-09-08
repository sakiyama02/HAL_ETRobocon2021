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
    
    index = 0;
/*
    //1ラインまで
    changeInfoData[index].vData.v=15;
    changeInfoData[index].vData.condition=LOW; 
    changeInfoData[index].judge=JUDGE_V;
    changeInfoData[index].section_act=STRAIGHT;
    changeInfoData[index].speed=20;

    index++;
    
    //2バック
    changeInfoData[index].pos_info_data.potision.xPosition=621*0.3527*2-10;
    changeInfoData[index].pos_info_data.xCondition=HIGH;
    changeInfoData[index].pos_info_data.yCondition=NONE;

    changeInfoData[index].distance=0;
    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=STRAIGHT;
    changeInfoData[index].speed=-10;

    index++;

    //3
    changeInfoData[index].pos_info_data.potision.xPosition=640*0.3527*2;//550*0.3527*2;
    changeInfoData[index].pos_info_data.xCondition=LOW;
    changeInfoData[index].pos_info_data.yCondition=NONE;

    changeInfoData[index].distance=0;
    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=STRAIGHT;
    changeInfoData[index].speed=15;

    index++;
*/
    //1カーブ
    changeInfoData[index].direction_data.direction=178;
    changeInfoData[index].direction_data.condition=HIGH;

    changeInfoData[index].judge=JUDGE_DIR;
    changeInfoData[index].section_act=CURVE;
    changeInfoData[index].speed=15;

    index++;

/*
    //直進
    changeInfoData[index].pos_info_data.potision.yPosition=4600*0.3527*2;//4790*0.3527*2;
    changeInfoData[index].pos_info_data.xCondition=NONE;
    changeInfoData[index].pos_info_data.yCondition=LOW;

    changeInfoData[index].distance=0;
    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=STRAIGHT;
    changeInfoData[index].speed=10;

    index++;
*/
    //2
    //カーブ
    changeInfoData[index].direction_data.direction=230;//190;
    changeInfoData[index].direction_data.condition=HIGH;

    changeInfoData[index].judge=JUDGE_DIR;
    changeInfoData[index].section_act=CURVE;
    changeInfoData[index].speed=15;

    index++;
    //3
    //カーブ
    changeInfoData[index].direction_data.direction=180;
    changeInfoData[index].direction_data.condition=LOW;

    changeInfoData[index].judge=JUDGE_DIR;
    changeInfoData[index].section_act=CURVE;
    changeInfoData[index].speed=15;

    index++;


/*
    //4
    changeInfoData[index].pos_info_data.potision.yPosition=(4320*0.3527*2);
    changeInfoData[index].pos_info_data.xCondition=NONE;
    changeInfoData[index].pos_info_data.yCondition=LOW;

    changeInfoData[index].distance=0;
    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=STRAIGHT;
    changeInfoData[index].speed=10;

    index++;

    //5
    changeInfoData[index].direction_data.direction=215;
    changeInfoData[index].direction_data.condition=LOW;

    changeInfoData[index].distance=0;
    changeInfoData[index].judge=JUDGE_DIR;
    changeInfoData[index].section_act=TURN;
    changeInfoData[index].speed=10;

    index++;

    //6
    changeInfoData[index].pos_info_data.potision.yPosition=(4250*0.3527*2);
    changeInfoData[index].pos_info_data.xCondition=NONE;
    changeInfoData[index].pos_info_data.yCondition=LOW;

    changeInfoData[index].distance=0;
    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=STRAIGHT;
    changeInfoData[index].speed=10;

    index++;

    //7
    changeInfoData[index].direction_data.direction=182;//180;
    changeInfoData[index].direction_data.condition=LOW;

    changeInfoData[index].distance=0;
    changeInfoData[index].judge=JUDGE_DIR;
    changeInfoData[index].section_act=TURN;
    changeInfoData[index].speed=10;

    index++;

*/

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    //4障害物間3回目の直進する
    changeInfoData[index].pos_info_data.potision.yPosition=3000;
    changeInfoData[index].pos_info_data.xCondition=NONE;
    changeInfoData[index].pos_info_data.yCondition=LOW;

    changeInfoData[index].distance=0;
    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=STRAIGHT;
    changeInfoData[index].speed=25;
    index++;

    //5板を下りる
    changeInfoData[index].pos_info_data.potision.yPosition=2840;//2845;
    changeInfoData[index].pos_info_data.xCondition=NONE;
    changeInfoData[index].pos_info_data.yCondition=LOW;

    changeInfoData[index].distance=0;
    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=ARM_ACTION;
    changeInfoData[index].speed=15;

    index++;

    //6板下りる
    changeInfoData[index].pos_info_data.potision.yPosition=2820;//2810;//2818;
    changeInfoData[index].pos_info_data.xCondition=NONE;
    changeInfoData[index].pos_info_data.yCondition=LOW;

    changeInfoData[index].distance=0;
    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=ARMDOWN_ACTION;
    changeInfoData[index].speed=10;

    index++;


    //7直進する
    changeInfoData[index].pos_info_data.potision.yPosition=3950*2*0.3527;//2800;
    changeInfoData[index].pos_info_data.xCondition=NONE;
    changeInfoData[index].pos_info_data.yCondition=LOW;

    changeInfoData[index].distance=0;
    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=STRAIGHT;
    changeInfoData[index].speed=20;

    index++;
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    //8直進する
    /*
    changeInfoData[index].pos_info_data.potision.yPosition=3900*2*0.3527;
    //changeInfoData[index].pos_info_data.potision.yPosition=3291;//3096
    changeInfoData[index].pos_info_data.xCondition=NONE;
    changeInfoData[index].pos_info_data.yCondition=LOW;

    changeInfoData[index].distance=0;
    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=STRAIGHT;
    changeInfoData[index].speed=10;
*/
    //カーブ
    changeInfoData[index].direction_data.direction=90;//190;
    changeInfoData[index].direction_data.condition=LOW;

    changeInfoData[index].judge=JUDGE_DIR;
    changeInfoData[index].section_act=CURVE;
    changeInfoData[index].speed=40;

    index++;
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    //9旋回する
/*
    changeInfoData[index].direction_data.direction=89;
    changeInfoData[index].direction_data.condition=LOW;

    changeInfoData[index].distance=0;
    changeInfoData[index].judge=JUDGE_DIR;
    changeInfoData[index].section_act=TURN;
    changeInfoData[index].speed=0;//10;
*/

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    //9ラインに向かって直進する
    changeInfoData[index].vData.v=65;
    //changeInfoData[index].rgb_data.condition=LOW;
    changeInfoData[index].vData.condition=LOW; 
    changeInfoData[index].judge=JUDGE_V;
    changeInfoData[index].section_act=STRAIGHT;
    changeInfoData[index].speed=15;

    index++;
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    //10
    //カーブ
    changeInfoData[index].direction_data.direction=45;//190;
    changeInfoData[index].direction_data.condition=LOW;

    changeInfoData[index].judge=JUDGE_DIR;
    changeInfoData[index].section_act=CURVE;
    changeInfoData[index].speed=40;

    index++; 
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    //11直進する
    /*
    changeInfoData[index].pos_info_data.potision.xPosition=330*2*0.3527;
    //changeInfoData[index].pos_info_data.potision.yPosition=3291;//3096
    changeInfoData[index].pos_info_data.xCondition=LOW;
    changeInfoData[index].pos_info_data.yCondition=NONE;
    changeInfoData[index].distance=0;
    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=STRAIGHT;
    changeInfoData[index].speed=0;//20;

    index++;*/
    //カーブ
    changeInfoData[index].direction_data.direction=0;//190;
    changeInfoData[index].direction_data.condition=LOW;

    changeInfoData[index].judge=JUDGE_DIR;
    changeInfoData[index].section_act=CURVE;
    changeInfoData[index].speed=40;

    index++; 

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    //12旋回する
    /*
    changeInfoData[index].direction_data.direction=165;
    changeInfoData[index].direction_data.condition=HIGH;
    changeInfoData[index].distance=0;
    changeInfoData[index].judge=JUDGE_DIR;
    changeInfoData[index].section_act=TURN;
    changeInfoData[index].speed=0;//20;

    index++; 
*/
    //カーブ
    changeInfoData[index].direction_data.direction=-145;//190;
    changeInfoData[index].direction_data.condition=LOW;

    changeInfoData[index].judge=JUDGE_DIR;
    changeInfoData[index].section_act=CURVE;
    changeInfoData[index].speed=40;

    index++; 
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    //13//ラインに向かって直進する
    changeInfoData[index].vData.v=80;
    //changeInfoData[index].rgb_data.condition=LOW;
    changeInfoData[index].vData.condition=LOW; 
    changeInfoData[index].judge=JUDGE_V;
    changeInfoData[index].section_act=STRAIGHT;
    changeInfoData[index].speed=30;

    index++;
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    //14ライントレースする
    changeInfoData[index].pos_info_data.potision.yPosition=2680;//2876
    changeInfoData[index].pos_info_data.xCondition=NONE;
    changeInfoData[index].pos_info_data.yCondition=LOW;

    changeInfoData[index].distance=0;
    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=LINE_TRACE;
    changeInfoData[index].speed=10;

    index++;
    //15ライントレースする
    changeInfoData[index].pos_info_data.potision.xPosition=200;
    changeInfoData[index].pos_info_data.potision.yPosition=2600;//2876
    changeInfoData[index].pos_info_data.xCondition=NONE;
    changeInfoData[index].pos_info_data.yCondition=LOW;
    changeInfoData[index].distance=0;
    changeInfoData[index].judge=JUDGE_POS;
    changeInfoData[index].section_act=LINE_TRACE;
    changeInfoData[index].speed=10;

    index++;


    //16ライントレースする
    changeInfoData[index].sData.s=80;
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



