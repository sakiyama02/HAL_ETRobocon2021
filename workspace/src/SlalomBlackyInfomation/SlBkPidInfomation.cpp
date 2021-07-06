//SlBkpidInfomation
//スラロームブラッキーPIDカーブインフォメーション
//

#include "../../include/SlalomBlackyInfomation/SlBkPidInfomation.h"

SlBkpidInfomation::SlBkpidInfomation(){
    memset(pidData,0,sizeof(PIDData)*TIMEATTACK_NUM);
    int16 index = 0;

//template
/*
    pidData[index].pGain=0f;
    pidData[index].iGain=0f;
    pidData[index].dGain=0f;
    pidData[index].targetVal=0f;

    index++;
*/    

}

SlBkpidInfomation::~SlBkpidInfomation(){
    delete(pidData);
}

int8 SlBkpidInfomation::getter(int16 scene_num,PIDData* pid_data){
    
    pid_data = &pidData[scene_num];

    return SYS_OK;
}