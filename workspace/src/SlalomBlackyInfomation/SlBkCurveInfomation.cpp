//SlBkCurveInfomation
//スラロームブラッキーカーブインフォメーション
//

#include "../../include/SlalomBlackyInfomation/SlBkCurveInfomation.h"

SlBkCurveInfomation::SlBkCurveInfomation(){
    memset(curveData,0,sizeof(CurveData)*SLALOMBLACKY_NUM);
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
    //1
    curveData[index].radius=85;//125;//209;//215;
    curveData[index].dirction=CURVE_RIGHT;

    //5
    index=4;

    curveData[index].radius=350;//365;
    curveData[index].dirction=CURVE_RIGHT;

    index++;

}

SlBkCurveInfomation::~SlBkCurveInfomation(){
    delete(curveData);
}

int8 SlBkCurveInfomation::getter(int16 scene_num,CurveData* curve_data){
    
    memcpy(curve_data,&curveData[scene_num],sizeof(CurveData));

    return SYS_OK;
}