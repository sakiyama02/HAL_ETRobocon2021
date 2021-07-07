//GaCurveInfomation
//ガレージカーブインフォメーション
//

#include "../../include/GarageInformation/GaCurveInfomation.h"

GaCurveInfomation::GaCurveInfomation(){
    memset(curveData,0,sizeof(CurveData)*TIMEATTACK_NUM);
    int16 index = 0;

//template
/*
    curveData[index].radius=0f;
    curveData[index].dirction=0f;

    index++;
*/

}

GaCurveInfomation::~GaCurveInfomation(){
    delete(curveData);
}

int8 GaCurveInfomation::getter(int16 scene_num,CurveData* curve_data){
    
    curve_data=&curveData[scene_num];

    return SYS_OK;
}