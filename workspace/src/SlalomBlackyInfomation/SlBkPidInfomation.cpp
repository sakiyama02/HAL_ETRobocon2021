//SlBkpidInfomation
//スラロームブラッキーPIDカーブインフォメーション
//

#include "../../include/SlalomBlackyInfomation/SlBkPidInfomation.h"

int8 getter(int16 scene_num,PIDData* pid_data){
    
    pid_data = pidData[scene_num];

    return SYS_OK;
}