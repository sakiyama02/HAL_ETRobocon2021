//SlBkpidInfomation
//スラロームブラッキーPIDカーブインフォメーション
//

#include "../../include/SlalomBlackyInfomation/SlBkPidInfomation.h"

SlBkpidInfomation::SlBkpidInfomation(){
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

SlBkpidInfomation::~SlBkpidInfomation(){
    delete(pidData);
}

int8 SlBkpidInfomation::getter(int16 scene_num,PIDData* pid_data){
    
    pid_data = &pidData[scene_num];

    return SYS_OK;
}