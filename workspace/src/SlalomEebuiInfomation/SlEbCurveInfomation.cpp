//SlEbCurveInfomation
//スラロームイーブイカーブインフォメーション
//

#include "../../include/SlalomEebuiInfomation/SlEbCurveInfomation.h"

int8 getter(int16 scene_num,CurveData* curve_data){
    curveDATA = new CurveData[TIMEATTACK_NUM];
    memset(curveData,0,sizeof(CurveData)*TIMEATTACK_NUM);
    int8 index = 0;

    curveData[index].radius=0f;
    curveData[index].dirction=0f;

    curve_data=curveData[scene_num];

    return SYS_OK;
}