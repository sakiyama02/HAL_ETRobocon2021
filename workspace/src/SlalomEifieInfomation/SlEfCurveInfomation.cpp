//SlEfCurveInfomation
//スラロームエーフィカーブインフォメーション
//

#include "../../include/SlalomEifieInfomation/SlEfCurveInfomation.h"

SlEfCurveInfomation::SlEfCurveInfomation(){
    memset(curveData,0,sizeof(CurveData)*SLALOMEIFIE_NUM);
    int16 index = 0;

//template
/*
    //カーブで使用する数値設定
    //radius  :半径を設定
    //dirction:回転
    curveData[index].radius=0f;

    //どちらの方向にカーブするかの設定
    //dirction:回転方向の指定(CURVE_LEFT,CURVE_RIGHT)
    curveData[index].dirction=CURVE_LEFT;

    index++;
*/
/*
    index=1;
    //index=0;
    curveData[index].radius=365*0.3527-20;
    curveData[index].dirction=CURVE_RIGHT;


    index=3;
    //index=2;
    curveData[index].radius=224*0.3527;
    curveData[index].dirction=CURVE_RIGHT;

    index=4;
    //index=3;
    curveData[index].radius=233*0.3527;
    curveData[index].dirction=CURVE_LEFT;
*/
    //4
    index=0;//3;
    curveData[index].radius=100;
    curveData[index].dirction=CURVE_RIGHT;
    //5
    index++;
    curveData[index].radius=220;
    curveData[index].dirction=CURVE_RIGHT;
    //6
    index++;
    curveData[index].radius=140;
    curveData[index].dirction=CURVE_LEFT;
    //8
    index=7;
    curveData[index].radius=120;//140;
    curveData[index].dirction=CURVE_LEFT;

    //10
    index=9;
    curveData[index].radius=225;
    curveData[index].dirction=CURVE_LEFT;

    //11
    index=10;
    curveData[index].radius=50;
    curveData[index].dirction=CURVE_LEFT;

    //12
    index=11;
    curveData[index].radius=40;
    curveData[index].dirction=CURVE_LEFT;
}

SlEfCurveInfomation::~SlEfCurveInfomation(){
    delete(curveData);
}

int8 SlEfCurveInfomation::getter(int16 scene_num,CurveData* curve_data){
    
    memcpy(curve_data,&curveData[scene_num],sizeof(CurveData));

    return SYS_OK;
}


