//TiPidInfomation
//タイムアタックPIDインフォメーション
//

#include "../../include/TimeAttackInfomation/TiPidInfomation.h"

int8 getter(int16 scene_num,PIDData* pid_data){
    
    pid_data = pidData[scene_num];

    return SYS_OK;
}