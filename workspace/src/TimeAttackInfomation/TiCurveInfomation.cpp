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
    curveData[index].radius=313.1976;
    curveData[index].dirction=CURVE_LEFT;

    index=4;
    curveData[index].radius=160.8312;
    curveData[index].dirction=CURVE_LEFT;

    index=6;
    curveData[index].radius=210.9146f;
    curveData[index].dirction=CURVE_RIGHT;

    index=8;
    curveData[index].radius=139.6692f;
    curveData[index].dirction=CURVE_RIGHT;
        
    index=10;
    curveData[index].radius=150;
    curveData[index].dirction=CURVE_LEFT;
        
    index=12;
    curveData[index].radius=130.499;
    curveData[index].dirction=CURVE_LEFT;

    index=14;
    curveData[index].radius=225.0226f;
    curveData[index].dirction=CURVE_RIGHT;

}

TiCurveInfomation::~TiCurveInfomation(){
    delete(curveData);
}

int8 TiCurveInfomation::getter(int16 scene_num,CurveData* curve_data){
    memcpy(curve_data,&curveData[scene_num],sizeof(CurveData));

    return SYS_OK;
}