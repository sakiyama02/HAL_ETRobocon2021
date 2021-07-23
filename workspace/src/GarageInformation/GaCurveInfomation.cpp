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
    curveData[index].radius=0;
    curveData[index].dirction=CURVE_LEFT;

    index++;

}

GaCurveInfomation::~GaCurveInfomation(){
    delete(curveData);
}

int8 GaCurveInfomation::getter(int16 scene_num,CurveData* curve_data){
    
    memcpy(curve_data,&curveData[scene_num],sizeof(CurveData));

    return SYS_OK;
}