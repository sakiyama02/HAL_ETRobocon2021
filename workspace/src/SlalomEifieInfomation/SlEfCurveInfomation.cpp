//SlEfCurveInfomation
//スラロームエーフィカーブインフォメーション
//

#include "../../include/SlalomEifieInfomation/SlEfCurveInfomation.h"

SlEfCurveInfomation::SlEfCurveInfomation(){
    memset(curveData,0,sizeof(CurveData)*SLALOMEIFIE_NUM);
    int16 index = 0;

//template
/*
    curveData[index].radius=0;
    curveData[index].dirction=0;

    index++;
*/

}

SlEfCurveInfomation::~SlEfCurveInfomation(){
    delete(curveData);
}

int8 SlEfCurveInfomation::getter(int16 scene_num,CurveData* curve_data){
    
    memcpy(curve_data,&curveData[scene_num],sizeof(CurveData));

    return SYS_OK;
}