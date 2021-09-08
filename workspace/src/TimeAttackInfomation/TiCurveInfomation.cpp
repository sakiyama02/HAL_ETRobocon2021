//TiCurveInfomation
//タイムアタックカーブインフォメーション
//

#include "../../include/TimeAttackInfomation/TiCurveInfomation.h"

TiCurveInfomation::TiCurveInfomation(){
    memset(curveData,0,sizeof(CurveData)*TIMEATTACK_NUM);
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

    index=2;
    curveData[index].radius=423.24;
    curveData[index].dirction=CURVE_LEFT;

    index=5;
    curveData[index].radius=201;
    curveData[index].dirction=CURVE_LEFT;

    index=7;
    curveData[index].radius=220.4375;
    curveData[index].dirction=CURVE_RIGHT;

    index=9;
    curveData[index].radius=182.6987;
    curveData[index].dirction=CURVE_RIGHT;

    index=11;
    curveData[index].radius=288.1559-123;
    curveData[index].dirction=CURVE_LEFT;

    index=12;
    curveData[index].radius=224.6699+50;
    curveData[index].dirction=CURVE_RIGHT;
}

TiCurveInfomation::~TiCurveInfomation(){
    delete(curveData);
}

int8 TiCurveInfomation::getter(int16 scene_num,CurveData* curve_data){
    memcpy(curve_data,&curveData[scene_num],sizeof(CurveData));

    return SYS_OK;
}