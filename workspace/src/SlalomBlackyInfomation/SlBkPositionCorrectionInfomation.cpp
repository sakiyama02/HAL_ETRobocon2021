//SlBkPositionCorrectionInfomation
//スラロームブラッキーポジションコレクションインフォメーション
//

#include "../../include/SlalomBlackyInfomation/SlBkPositionCorrectionInfomation.h"

int8 getter(int16 scene_num,PositinCorrectionData* positioncorrection_data){
    
    positioncorrection_data=positionCorrectionData[scene_num];

    return SYS_OK;
}