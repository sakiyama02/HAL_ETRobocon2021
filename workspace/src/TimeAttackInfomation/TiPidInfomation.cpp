//TiPidInfomation
//タイムアタックPIDインフォメーション
//

#include "../../include/TimeAttackInfomation/TiPidInfomation.h"

TiPidInfomation::TiPidInfomation(){
    memset(pidData,0,sizeof(PIDData)*TIMEATTACK_NUM);
    int16 index = 0;

//template
/*
    pidData[index].pGain=0;
    pidData[index].iGain=0;
    pidData[index].dGain=0;
    pidData[index].targetVal=0;

    index++;
*/    
}

TiPidInfomation::~TiPidInfomation(){
    delete(pidData);
}

int8 TiPidInfomation::getter(int16 scene_num,PIDData* pid_data){
    
    pid_data = &pidData[scene_num];

    return SYS_OK;
}