//TiPidInfomation
//タイムアタックPIDインフォメーション
//
#pragma once
#include "../System/System.h"

class TiPidInfomation{
    private:
        PIDData *pidData = new PIDData[TIMEATTACK_NUM];
    public:
        TiPidInfomation();

        ~TiPidInfomation();

        //getter
        //ゲッター
        //引数      int16_t     シーン番号
        //          PIDData*    PID情報
        //戻り値    int8_t      エラーチェック
        int8 getter(int16,PIDData*);
};