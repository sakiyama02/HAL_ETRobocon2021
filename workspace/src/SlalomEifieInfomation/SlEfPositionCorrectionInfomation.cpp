//SlEfPositionCorrectionInfomation
//スラロームエーフィポジションコレクションインフォメーション
//

#include "../../include/SlalomEifieInfomation/SlEfPositionCorrectionInfomation.h"

int8 getter(int16 scene_num,PositinCorrectionData* positioncorrection_data){
    
    positioncorrection_data=positionCorrectionData[scene_num];

    return SYS_OK;
}