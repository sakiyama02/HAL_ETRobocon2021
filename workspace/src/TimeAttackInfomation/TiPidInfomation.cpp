//TiPidInfomation
//タイムアタックPIDインフォメーション
//

#include "../../include/TimeAttackInfomation/TiPidInfomation.h"

TiPidInfomation::TiPidInfomation(){
    memset(pidData,0,sizeof(PIDData)*TIMEATTACK_NUM);
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
#define target 85

/*
    index=0;
    pidData[index].pGain=0.2f;
    pidData[index].iGain=0.3f;
    pidData[index].dGain=0.0f;
    pidData[index].targetVal=target;
    */
   // 2
    index=1;
    pidData[index].pGain=0.2f;
    pidData[index].iGain=0.2f;
    pidData[index].dGain=0.05f;
    pidData[index].targetVal=target;

    // 第一カーブ
    index=2;
    pidData[index].pGain=0.3f;
    pidData[index].iGain=0.4f;
    pidData[index].dGain=0.05f;
    pidData[index].targetVal=target;

    index=3;
    pidData[index].pGain=0.3f;
    pidData[index].iGain=0.35f;
    pidData[index].dGain=0.05f;
    pidData[index].targetVal=target;
    // 第二カーブ
    index=4;
    pidData[index].pGain=0.3f;
    pidData[index].iGain=0.4f;
    pidData[index].dGain=0.05f;
    pidData[index].targetVal=target;

    index=5;
    pidData[index].pGain=0.3f;
    pidData[index].iGain=0.4f;
    pidData[index].dGain=0.05f;
    pidData[index].targetVal=target;
    // 第三カーブ
    index=6;
    pidData[index].pGain=0.3f;
    pidData[index].iGain=0.4f;
    pidData[index].dGain=0.05f;
    pidData[index].targetVal=target;

    index=7;
    pidData[index].pGain=0.2f;
    pidData[index].iGain=0.25f;
    pidData[index].dGain=0.05f;
    pidData[index].targetVal=target;

    index=8;
    pidData[index].pGain=0.4f;
    pidData[index].iGain=0.45f;
    pidData[index].dGain=0.05f;
    pidData[index].targetVal=target;

    index=9;
    pidData[index].pGain=0.4f;
    pidData[index].iGain=0.45f;
    pidData[index].dGain=0.05f;
    pidData[index].targetVal=target;

    index=10;
    pidData[index].pGain=0.4f;
    pidData[index].iGain=0.45f;
    pidData[index].dGain=0.05f;
    pidData[index].targetVal=target;

    index=11;
    pidData[index].pGain=0.4f;
    pidData[index].iGain=0.45f;
    pidData[index].dGain=0.05f;
    pidData[index].targetVal=target;

    index=12;
    pidData[index].pGain=0.4f;
    pidData[index].iGain=0.35f;
    pidData[index].dGain=0.03f;
    pidData[index].targetVal=target;
    
    index=13;
    pidData[index].pGain=0.3f;
    pidData[index].iGain=0.25f;
    pidData[index].dGain=0.05f;
    pidData[index].targetVal=target;

    index=14;
    pidData[index].pGain=0.4f;
    pidData[index].iGain=0.4f;
    pidData[index].dGain=0.05f;
    pidData[index].targetVal=target;

    index=15;
    pidData[index].pGain=0.3f;
    pidData[index].iGain=0.25f;
    pidData[index].dGain=0.05f;
    pidData[index].targetVal=target;

    index=16;
    pidData[index].pGain=0.3f;
    pidData[index].iGain=0.25f;
    pidData[index].dGain=0.05f;
    pidData[index].targetVal=130;

    index=17;
    pidData[index].pGain=0.4f;
    pidData[index].iGain=0.4f;
    pidData[index].dGain=0.05f;
    pidData[index].targetVal=target;

    index=18;
    pidData[index].pGain=0.3f;
    pidData[index].iGain=0.25f;
    pidData[index].dGain=0.05f;
    pidData[index].targetVal=122;
    
}

TiPidInfomation::~TiPidInfomation(){
    delete(pidData);
}

int8 TiPidInfomation::getter(int16 scene_num,PIDData* pid_data){
    
    memcpy(pid_data,&pidData[scene_num],sizeof(PIDData));
    return SYS_OK;
}