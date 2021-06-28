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
        virtual int8 sceneChenge(&int16)=0;

        //実行
        //引数   init16_t シーン番号[IN]
        //戻り値 init8_t エラーチェック
        virtual int8 run(int16)=0;

        int8 colorJudge(RGBData,RGBData)=0;
        int8 xPositionJudge(float,float,int8)=0;
        int8 yPositionJudge(float,float,int8)=0;
        int8 distanceJudge(uint16,uint16)=0;
        int8 directionJudge(float,float,int8)=0;
}