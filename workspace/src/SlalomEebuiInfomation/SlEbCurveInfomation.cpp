//SlEbCurveInfomation
//スラロームイーブイカーブインフォメーション
//

#include "../../include/SlalomEebuiInfomation/SlEbCurveInfomation.h"

SlEbCurveInfomation::SlEbCurveInfomation(){
    memset(curveData,0,sizeof(CurveData)*TIMEATTACK_NUM);
    int16 index = 0;

//template
/*
    curveData[index].radius=0f;
    curveData[index].dirction=0f;

    index++;
*/

}

SlEbCurveInfomation::~SlEbCurveInfomation(){
    free(curveData);
}

int8 SlEbCurveInfomation::getter(int16 scene_num,CurveData* curve_data){
    
    curve_data=&curveData[scene_num];

    return SYS_OK;
}