//GapidInfomation
//ガレージPIDカーブインフォメーション
//

#include "../../include/GarageInformation/GaPidInfomation.h"

GaPidInfomation::GaPidInfomation(){
    memset(pidData,0,sizeof(PIDData)*GARAGE_NUM);
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
//10
    pidData[9].pGain=0.01f;
    pidData[9].iGain=0.0f;
    pidData[9].dGain=0.0f;
    pidData[9].targetVal=28;

//19
    pidData[18].pGain=0.05f;
    pidData[18].iGain=0.04f;
    pidData[18].dGain=0.0f;
    pidData[18].targetVal=19;
//20
    pidData[19].pGain=0.05f;
    pidData[19].iGain=0.05f;
    pidData[19].dGain=0.0f;
    pidData[19].targetVal=110;
//19
    pidData[20].pGain=0.05f;
    pidData[20].iGain=0.04f;
    pidData[20].dGain=0.0f;
    pidData[20].targetVal=19;
}

GaPidInfomation::~GaPidInfomation(){
    delete(pidData);
}

int8 GaPidInfomation::getter(int16 scene_num,PIDData* pid_data){
    
    memcpy(pid_data,&pidData[scene_num],sizeof(PIDData));

    return SYS_OK;
}
