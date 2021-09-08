//SlEfpidInfomation
//スラロームエーフィPIDカーブインフォメーション
//

#include "../../include/SlalomEifieInfomation/SlEfPidInfomation.h"

SlEfpidInfomation::SlEfpidInfomation(){
    memset(pidData,0,sizeof(PIDData)*SLALOMEIFIE_NUM);
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
//14←ないほうがいいかも
    index=13;//14;//15;
    pidData[index].pGain=0.3f;
    pidData[index].iGain=0.01;//0.2f
    pidData[index].dGain=0.03;//0.05
    pidData[index].targetVal=80;

//15
    index=14;
    pidData[index].pGain=0.03f;
    pidData[index].iGain=0.001;//0.2f
    pidData[index].dGain=0.03;//0.05
    pidData[index].targetVal=80;

    index++;

}

SlEfpidInfomation::~SlEfpidInfomation(){
    delete(pidData);
}

int8 SlEfpidInfomation::getter(int16 scene_num,PIDData* pid_data){
    
    memcpy(pid_data,&pidData[scene_num],sizeof(PIDData));

    return SYS_OK;
}



