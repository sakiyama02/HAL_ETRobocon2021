//SlEbActionInfomation
//スラロームイーブイアクションインフォメーション
//
#include "../System/System.h"

class SlEbActionInfomation{
    private:
        changeInfoData = new ChangeInfo[TIMEATTACK_NUM];
    public:
        SlEbActionInfomation();

        ~SlEbActionInfomation();

        //getter
        //ゲッター
        //引数      int16_t        シーン番号
        //          ChengeInfo*     切り替え情報
        //          DirectionData*  方向情報
        //戻り値    int8_t          エラーチェック        
        int8 getter(int16,ChangeInfo*);

};