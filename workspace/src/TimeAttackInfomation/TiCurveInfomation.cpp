//TiCurveInfomation
//タイムアタックカーブインフォメーション
//

#include "../../include/TimeAttackInfomation/TiCurveInfomation.h"

TiCurveInfomation::TiCurveInfomation(){
    memset(curveData,0,sizeof(CurveData)*TIMEATTACK_NUM);
    int16 index = 0;

//template
/*
    curveData[index].radius=0f;
    curveData[index].dirction=0f;

    index++;
*/
}

TiCurveInfomation::~TiCurveInfomation(){
    free(curveData);
}

int8 TiCurveInfomation::getter(int16 scene_num,CurveData* curve_data){
    
    curve_data=&curveData[scene_num];

    return SYS_OK;
}