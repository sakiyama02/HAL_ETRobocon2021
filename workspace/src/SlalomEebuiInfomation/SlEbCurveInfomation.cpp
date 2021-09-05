//SlEbCurveInfomation
//スラロームイーブイカーブインフォメーション
//

#include "../../include/SlalomEebuiInfomation/SlEbCurveInfomation.h"

SlEbCurveInfomation::SlEbCurveInfomation(){
    memset(curveData,0,sizeof(CurveData)*SLALOMEEBUI_NUM);
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
    //11
    index=10;
    curveData[index].radius=200;//300;
    curveData[index].dirction=CURVE_RIGHT;

    index++;
    //12
    curveData[index].radius=250;//225;
    curveData[index].dirction=CURVE_LEFT;

    index++;
    //13
    curveData[index].radius=175;//100;//250;
    curveData[index].dirction=CURVE_LEFT;

    index++;

    //14
    curveData[index].radius=150;//80;//60;//250;
    curveData[index].dirction=CURVE_LEFT;

    index++;
    
    //15
    curveData[index].radius=205;//215;//235;
    curveData[index].dirction=CURVE_RIGHT;

    index++;

    //16
    curveData[index].radius=123;//100;//80;
    curveData[index].dirction=CURVE_RIGHT;

    index++;

    //17
    curveData[index].radius=75;
    curveData[index].dirction=CURVE_RIGHT;

    index++;

    //18
    curveData[index].radius=130;//60;//250;
    curveData[index].dirction=CURVE_LEFT;

    index++;

}

SlEbCurveInfomation::~SlEbCurveInfomation(){
    delete(curveData);
}

int8 SlEbCurveInfomation::getter(int16 scene_num,CurveData* curve_data){
    
    memcpy(curve_data,&curveData[scene_num],sizeof(CurveData));

    return SYS_OK;
}