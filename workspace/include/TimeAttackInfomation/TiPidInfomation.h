//TiPidInfomation
//タイムアタックPIDインフォメーション
//
#include "../System/System.h"

class TiPidInfomation{
    private:
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