#include "../System/System.h"
//
//SceneControl.h
//シーンコントロールクラス

class SceneControl{
    private:
    public:
        SceneContorol();

        ~SceneContorol();

        //シーンの切り替え
        //引数   init16_t シーン番号[IN]
        //戻り値 init8_t エラーチェック
        init8_t SceneChenge(init16_t);

        //実行
        //引数   init16_t シーン番号[IN]
        //戻り値 init8_t エラーチェック
        init8_t Run(init16_t);
}