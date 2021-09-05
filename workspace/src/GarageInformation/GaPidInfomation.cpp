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

//1
index++;
//2
index++;
//3
index++;
//4
index++;
//5
index++;
//6
index++;
//7
index++;
//8
index++;
//9
index++;
//10
index++;
//11
index++;
//12
    pidData[index].pGain=0.03f;
    pidData[index].iGain=0.0005f;
    pidData[index].dGain=0.01f;
    pidData[index].targetVal=48;
    index++;
//13
index++;
//14
index++;
//15
index++;
//16
index++;
//17
index++;
//18
index++;
//19
index++;
//20
index++;
//21
index++;
//22
    pidData[index].pGain=0.03f;
    pidData[index].iGain=0.0005f;
    pidData[index].dGain=0.01f;
    pidData[index].targetVal=28;
    index++;
//23
    pidData[index].pGain=0.03f;
    pidData[index].iGain=0.0005f;
    pidData[index].dGain=0.02f;
    pidData[index].targetVal=90;
    index++;
//24
    pidData[index].pGain=0.03f;
    pidData[index].iGain=0.0005f;
    pidData[index].dGain=0.03f;
    pidData[index].targetVal=28;
    index++;
}

GaPidInfomation::~GaPidInfomation(){
    delete(pidData);
}

int8 GaPidInfomation::getter(int16 scene_num,PIDData* pid_data){
    
    memcpy(pid_data,&pidData[scene_num],sizeof(PIDData));

    return SYS_OK;
}