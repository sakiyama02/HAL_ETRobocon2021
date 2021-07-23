//GaPositionCorrectionInfomation
//ガレージポジションコレクションインフォメーション
//
#pragma once
#include "../System/System.h"

class GaPositionCorrectionInfomation{
    private:
        PositionCorrectionData *positionCorrectionData = new PositionCorrectionData[GARAGE_NUM];
    public:
        GaPositionCorrectionInfomation();

        ~GaPositionCorrectionInfomation();

        //getter
        //ゲッター
        //引数      int16_t        シーン番号
        //          ChengeInfo*     切り替え情報
        //          DirectionData*  方向情報
        //戻り値    int8_t          エラーチェック        
        int8 getter(int16,PositionCorrectionData*);

};