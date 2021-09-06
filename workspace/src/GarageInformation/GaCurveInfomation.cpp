//GaCurveInfomation
//ガレージカーブインフォメーション
//

#include "../../include/GarageInformation/GaCurveInfomation.h"

GaCurveInfomation::GaCurveInfomation(){
    memset(curveData,0,sizeof(CurveData)*GARAGE_NUM);
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
index++;
//2
index++;
//3
index++;
//4
index++;
//5
index++;
//6
index++;
//7
index++;
//8
index++;
//9
index++;
//10
index++;
//11
index++;
//12
index++;
//13
index++;
//14
index++;
//15
    curveData[index].radius=230;
    curveData[index].dirction=CURVE_LEFT;

    index++;

//16
    curveData[index].radius=210;
    curveData[index].dirction=CURVE_RIGHT;

    index++;

//17
    curveData[index].radius=400;
    curveData[index].dirction=CURVE_RIGHT;
    index++;

}

GaCurveInfomation::~GaCurveInfomation(){
    delete(curveData);
}

int8 GaCurveInfomation::getter(int16 scene_num,CurveData* curve_data){
    
    memcpy(curve_data,&curveData[scene_num],sizeof(CurveData));

    return SYS_OK;
}