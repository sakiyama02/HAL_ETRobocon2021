//TiCurveInfomation
//タイムアタックカーブインフォメーション
//
#pragma once
#include "../System/System.h"

class TiCurveInfomation{
    private:
        CurveData *curveData = new CurveData[TIMEATTACK_NUM];
    public:
        TiCurveInfomation();

        ~TiCurveInfomation();

        //getter
        //ゲッター
        //引数      int16_t     シーン番号
        //          CurveData*  カーブ情報
        //戻り値    int8_t       エラーチェック
        int8 getter(int16,CurveData*);
};