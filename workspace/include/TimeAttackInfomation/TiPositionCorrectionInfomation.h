//TiPositionCorrectionInfomation
//タイムアタックポジションコレクションインフォメーション
//
#pragma once
#include "../System/System.h"

class TiPositionCorrectionInfomation{
    private:
        PositionCorrectionData *positionCorrectionData = new PositionCorrectionData[TIMEATTACK_NUM];
    public:
        TiPositionCorrectionInfomation();

        ~TiPositionCorrectionInfomation();

        //getter
        //ゲッター
        //引数      int16_t                     シーン番号
        //          PositionCorrectionData*     
        //戻り値    int8_t                      エラーチェック
        int8 getter(int16,PositionCorrectionData*);
};