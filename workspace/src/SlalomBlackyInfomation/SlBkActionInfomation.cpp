//SlBkActionInfomation
//スラロームブラッキーアクションインフォメーション
//

#include "../../include/SlalomBlackyInfomation/SlBkActionInfomation.h"

SlBkActionInfomation(){
    memset(changeInfoData,0,sizeof(ChangeInfo) * TIMEATTACK_NUM);
    int16 index = 0;

//template
/*
    changeInfoData[index].rgb_data.r=0f;
    changeInfoData[index].rgb_data.g=0f;
    changeInfoData[index].rgb_data.b=0f;
    changeInfoData[index].rgb_data.condition=0f;

    changeInfoData[index].pos_info_data.potision=0f;
    changeInfoData[index].pos_info_data.xCondition=0f;
    changeInfoData[index].pos_info_data.yCondition=0f;

    changeInfoData[index].direction_data.direction=0f;
    changeInfoData[index].direction_data.condition=0f;

    changeInfoData[index].distance=0f;
    changeInfoData[index].judge=0f;
    changeInfoData[index].section_act=0f;
    changeInfoData[index].speed=0f;

    index++;
*/
}

int8 getter(int16 scene_num,ChangeInfo* change_info){
    
    change_info=changeInfoData[scene_num];

    return SYS_OK;
}