//SlBkCurveInfomation
//スラロームブラッキーカーブインフォメーション
//

#include "../../include/SlalomBlackyInfomation/SlBkCurveInfomation.h"

SlBkCurveInfomation::SlBkCurveInfomation(){
    memset(curveData,0,sizeof(CurveData)*SLALOMBLACKY_NUM);
    int16 index = 0;

//template
/*
    curveData[index].radius=0;
    curveData[index].dirction=0;

    index++;
*/

}

SlBkCurveInfomation::~SlBkCurveInfomation(){
    delete(curveData);
}

int8 SlBkCurveInfomation::getter(int16 scene_num,CurveData* curve_data){
    
    memcpy(curve_data,&curveData[scene_num],sizeof(CurveData));

    return SYS_OK;
}