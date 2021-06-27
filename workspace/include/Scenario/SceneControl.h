#include "../System/System.h"
//
//SceneControl.h
//シーンコントロールクラス
//基底クラス

class SceneControl{
    private:
    public:
        virtual SceneControl();

        virtual ~SceneControl();

        //シーンの切り替え
        //引数   init16_t シーン番号[IN]
        //戻り値 init8_t エラーチェック
        virtual init8_t SceneChenge(&init16_t)=0;

        //実行
        //引数   init16_t シーン番号[IN]
        //戻り値 init8_t エラーチェック
        virtual init8_t Run(init16_t)=0;
}