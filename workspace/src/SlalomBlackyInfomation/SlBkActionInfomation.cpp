//SlBkActionInfomation
//スラロームブラッキーアクションインフォメーション
//

#include "../../include/SlalomBlackyInfomation/SlBkActionInfomation.h"

int8 getter(int16 scene_num,ChangeInfo* change_info){
    
    change_info=changeInfoData[scene_num];

    return SYS_OK;
}