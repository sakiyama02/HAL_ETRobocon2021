//GaCurveInfomation
//ガレージカーブインフォメーション
//

#include "../../include/GarageInformation/GaCurveInfomation.h"

int8 getter(int16 scene_num,CurveData* curve_data){
    
    curve_data=curveData[scene_num];

    return SYS_OK;
}