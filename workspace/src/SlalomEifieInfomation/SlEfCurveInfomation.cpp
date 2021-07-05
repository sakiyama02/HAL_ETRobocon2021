//SlEfCurveInfomation
//スラロームエーフィカーブインフォメーション
//

#include "../../include/SlalomEifieInfomation/SlEfCurveInfomation.h"

SlEfCurveInfomation::SlEfCurveInfomation(){
    memset(curveData,0,sizeof(CurveData)*TIMEATTACK_NUM);
    int16 index = 0;

//template
/*
    curveData[index].radius=0f;
    curveData[index].dirction=0f;

    index++;
*/

}

SlEfCurveInfomation::~SlEfCurveInfomation(){
    free(curveData);
}

int8 SlEfCurveInfomation::getter(int16 scene_num,CurveData* curve_data){
    
    curve_data=&curveData[scene_num];

    return SYS_OK;
}