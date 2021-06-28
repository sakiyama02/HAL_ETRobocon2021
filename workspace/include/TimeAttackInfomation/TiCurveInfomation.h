//TiCurveInfomation
//タイムアタックカーブインフォメーション
//
#include "../System/System.h"

class TiCurveInfomation{
    private:
    public:
        TiCurveInfomation();

        ~TiCurveInfomation();

        //getter
        //ゲッター
        //引数      int16_t     シーン番号
        //          CurveData*  カーブ情報
        //戻り値    int8_t       エラーチェック
        int8_t getter(int16_t,CurveData*);
}