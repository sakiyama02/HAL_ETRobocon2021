//SlEfpidInfomation
//スラロームエーフィPIDカーブインフォメーション
//
#pragma once
#include "../System/System.h"

class SlEfpidInfomation{
    private:
        PIDData *pidData = new PIDData[SLALOMEIFIE_NUM];
    public:
        SlEfpidInfomation();

        ~SlEfpidInfomation();

        //getter
        //ゲッター
        //引数      int16_t        シーン番号
        //          ChengeInfo*     切り替え情報
        //          DirectionData*  方向情報
        //戻り値    int8_t          エラーチェック        
        int8 getter(int16,PIDData*);

};