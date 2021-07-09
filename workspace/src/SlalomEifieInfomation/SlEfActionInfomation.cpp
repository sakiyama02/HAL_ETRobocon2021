//SlEfActionInfomation
//スラロームエーフィアクションインフォメーション
//

#include "../../include/SlalomEifieInfomation/SlEfActionInfomation.h"

SlEfActionInfomation::SlEfActionInfomation(){
    memset(changeInfoData,0,sizeof(ChangeInfo) * TIMEATTACK_NUM);
    int16 index = 0;

//template
/*
    changeInfoData[index].rgb_data.r=0;
    changeInfoData[index].rgb_data.g=0;
    changeInfoData[index].rgb_data.b=0;
    changeInfoData[index].rgb_data.condition=0;

    changeInfoData[index].pos_info_data.potision.xPosition=0;
    changeInfoData[index].pos_info_data.potision.yPosition-0;
    changeInfoData[index].pos_info_data.xCondition=0;
    changeInfoData[index].pos_info_data.yCondition=0;

    changeInfoData[index].direction_data.direction=0;
    changeInfoData[index].direction_data.condition=0;

    changeInfoData[index].distance=0;
    changeInfoData[index].judge=0;
    changeInfoData[index].section_act=0;
    changeInfoData[index].speed=0;

    index++;
*/
}

SlEfActionInfomation::~SlEfActionInfomation(){
    delete(changeInfoData);
}

int8 SlEfActionInfomation::getter(int16 scene_num,ChangeInfo* change_info){
    
    memcpy(change_info,&changeInfoData[scene_num],sizeof(ChangeInfo));

    return SYS_OK;
}