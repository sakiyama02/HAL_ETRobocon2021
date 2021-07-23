#pragma once
#include "../System/System.h"
//
//SceneControl.h
//シーンコントロールクラス
//基底クラス

class SceneControl{
    private:
    public:
        SceneControl();

        virtual ~SceneControl();

        //シーンの切り替え
        //引数   init16_t シーン番号[IN]
        //戻り値 init8_t エラーチェック
        virtual int8 sceneChenge(int16*)=0;

        //実行
        //引数   init16_t シーン番号[IN]
        //戻り値 init8_t エラーチェック
        virtual int8 run(int16)=0;

};