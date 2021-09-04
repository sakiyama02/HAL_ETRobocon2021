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
//12
    pidData[11].pGain=0.03f;
    pidData[11].iGain=0.0005f;
    pidData[11].dGain=0.01f;
    pidData[11].targetVal=48;

//22
    pidData[22].pGain=0.03f;
    pidData[22].iGain=0.0005f;
    pidData[22].dGain=0.01f;
    pidData[22].targetVal=28;
//23
    pidData[23].pGain=0.03f;
    pidData[23].iGain=0.0005f;
    pidData[23].dGain=0.02f;
    pidData[23].targetVal=90;

//24
    pidData[24].pGain=0.03f;
    pidData[24].iGain=0.0005f;
    pidData[24].dGain=0.02f;
    pidData[24].targetVal=28;
    
}

GaPidInfomation::~GaPidInfomation(){
    delete(pidData);
}

int8 GaPidInfomation::getter(int16 scene_num,PIDData* pid_data){
    
    memcpy(pid_data,&pidData[scene_num],sizeof(PIDData));

    return SYS_OK;
}