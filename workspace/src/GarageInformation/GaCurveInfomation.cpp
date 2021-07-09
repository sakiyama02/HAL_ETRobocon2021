//GaCurveInfomation
//ガレージカーブインフォメーション
//

#include "../../include/GarageInformation/GaCurveInfomation.h"

GaCurveInfomation::GaCurveInfomation(){
    memset(curveData,0,sizeof(CurveData)*TIMEATTACK_NUM);
    int16 index = 0;

//template
/*
    curveData[index].radius=0;
    curveData[index].dirction=0;

    index++;
*/

}

GaCurveInfomation::~GaCurveInfomation(){
    delete(curveData);
}

int8 GaCurveInfomation::getter(int16 scene_num,CurveData* curve_data){
    
    memcpy(curve_data,&curveData[scene_num],sizeof(CurveData));

    return SYS_OK;
}