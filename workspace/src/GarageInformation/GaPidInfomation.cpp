//GapidInfomation
//ガレージPIDカーブインフォメーション
//

#include "../../include/GarageInformation/GaPidInfomation.h"

int8 getter(int16 scene_num,PIDData* pid_data){
    pidData = new PIDData[TIMEATTACK_NUM];
    memset(pidData,0,sizeof(PIDData)*TIMEATTACK_NUM);
    int8 index = 0;

    pidData[index].pGain=0f;
    pidData[index].iGain=0f;
    pidData[index].dGain=0f;
    pidData[index].targetVal=0f;

    pid_data = pidData[scene_num];

    return SYS_OK;
}