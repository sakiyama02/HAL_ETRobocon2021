//TiPositionCorrectionInfomation
//タイムアタックポジションコレクションインフォメーション
//
#include "../System/System.h"

class TiPositionCorrectionInfomation{
    private:
    public:
        TiPositionCorrectionInfomation();

        ~TiPositionCorrectionInfomation();

        //getter
        //ゲッター
        //引数      int16_t                     シーン番号
        //          PositionCorrectionData*     
        //戻り値    int8_t                      エラーチェック
        int8_t getter(int16,PositinCorrectionData*);
}