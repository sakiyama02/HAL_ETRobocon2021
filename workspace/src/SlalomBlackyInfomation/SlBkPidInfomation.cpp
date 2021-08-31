//SlBkpidInfomation
//スラロームブラッキーPIDカーブインフォメーション
//

#include "../../include/SlalomBlackyInfomation/SlBkPidInfomation.h"

SlBkpidInfomation::SlBkpidInfomation(){
    memset(pidData,0,sizeof(PIDData)*SLALOMBLACKY_NUM);
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
//15
    index = 14;
    pidData[index].pGain=0.3f;
    pidData[index].iGain=0;//0.2f
    pidData[index].dGain=0;//0.05
    pidData[index].targetVal=80;

    index++;
//16←ないほうがいいかも
    pidData[index].pGain=0.3f;
    pidData[index].iGain=0;//0.2f
    pidData[index].dGain=0;//0.05
    pidData[index].targetVal=80;

    index++;


}

SlBkpidInfomation::~SlBkpidInfomation(){
    delete(pidData);
}

int8 SlBkpidInfomation::getter(int16 scene_num,PIDData* pid_data){
    
    memcpy(pid_data,&pidData[scene_num],sizeof(PIDData));

    return SYS_OK;
}

