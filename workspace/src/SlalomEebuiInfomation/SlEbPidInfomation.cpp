//SlEbpidInfomation
//スラロームイーブイPIDカーブインフォメーション
//

#include "../../include/SlalomEebuiInfomation/SlEbPidInfomation.h"

SlEbpidInfomation::SlEbpidInfomation(){
    memset(pidData,0,sizeof(PIDData)*SLALOMEEBUI_NUM);
    int16 index = 0;

//template
/*
    //pidゲイン値の設定
    //p:p値の設定
    //i:i値の設定
    //d:d値の設定
    pidData[index].pGain=0f;
    pidData[index].iGain=0f;
    pidData[index].dGain=0f;

    //v値の設定
    pidData[index].targetVal=0f;

    index++;
*/    
    pidData[index].pGain=0;
    pidData[index].iGain=0;
    pidData[index].dGain=0;
    pidData[index].targetVal=0;

    index++;

}

SlEbpidInfomation::~SlEbpidInfomation(){
    delete(pidData);
}

int8 SlEbpidInfomation::getter(int16 scene_num,PIDData* pid_data){
    
    memcpy(pid_data,&pidData[scene_num],sizeof(PIDData));

    return SYS_OK;
}