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
    pidData[11].pGain=0.03f;
    pidData[11].iGain=0.0005f;
    pidData[11].dGain=0.01f;
    pidData[11].targetVal=48;

//21
    pidData[20].pGain=0.03f;
    pidData[20].iGain=0.0005f;
    pidData[20].dGain=0.01f;
    pidData[20].targetVal=30;
//20
    pidData[21].pGain=0.15f;
    pidData[21].iGain=0.20f;
    pidData[21].dGain=0.03f;
    pidData[21].targetVal=90;
//23
    pidData[22].pGain=0.02f;
    pidData[22].iGain=0.00f;
    pidData[22].dGain=0.0f;
    pidData[22].targetVal=28;
}

GaPidInfomation::~GaPidInfomation(){
    delete(pidData);
}

int8 GaPidInfomation::getter(int16 scene_num,PIDData* pid_data){
    
    memcpy(pid_data,&pidData[scene_num],sizeof(PIDData));

    return SYS_OK;
}