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

    index=4;
    curveData[index].radius=185.8729;
    curveData[index].dirction=CURVE_LEFT;

    index=6;
    curveData[index].radius=237.3671;
    curveData[index].dirction=CURVE_RIGHT;

    index=8;
    curveData[index].radius=129.4409f;
    curveData[index].dirction=CURVE_RIGHT;
        
    index=10;
    curveData[index].radius=129.4409f;
    curveData[index].dirction=CURVE_LEFT;
        
    index=12;
    curveData[index].radius=140.0219;
    curveData[index].dirction=CURVE_LEFT;

    index=14;
    curveData[index].radius=183.7567;
    curveData[index].dirction=CURVE_RIGHT;

}

TiCurveInfomation::~TiCurveInfomation(){
    delete(curveData);
}

int8 TiCurveInfomation::getter(int16 scene_num,CurveData* curve_data){
    memcpy(curve_data,&curveData[scene_num],sizeof(CurveData));

    return SYS_OK;
}