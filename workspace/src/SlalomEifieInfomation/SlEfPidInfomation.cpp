//SlEfpidInfomation
//スラロームエーフィPIDカーブインフォメーション
//

#include "../../include/SlalomEifieInfomation/SlEfPidInfomation.h"

SlEfpidInfomation::SlEfpidInfomation(){
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

SlEfpidInfomation::~SlEfpidInfomation(){
    delete(pidData);
}

int8 SlEfpidInfomation::getter(int16 scene_num,PIDData* pid_data){
    
    pid_data = &pidData[scene_num];

    return SYS_OK;
}