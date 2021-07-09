//GapidInfomation
//ガレージPIDカーブインフォメーション
//

#include "../../include/GarageInformation/GaPidInfomation.h"

GaPidInfomation::GaPidInfomation(){
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

GaPidInfomation::~GaPidInfomation(){
    delete(pidData);
}

int8 GaPidInfomation::getter(int16 scene_num,PIDData* pid_data){
    
    memcpy(pid_data,&pidData[scene_num],sizeof(PIDData));

    return SYS_OK;
}