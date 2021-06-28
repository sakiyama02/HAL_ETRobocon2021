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
        virtual int8 SceneChenge(&int16)=0;

        //実行
        //引数   init16_t シーン番号[IN]
        //戻り値 init8_t エラーチェック
        virtual int8 Run(int16)=0;

        int8 ColorJudge(RGBData,RGBData)=0;
        int8 XPositionJudge(float,float,int8)=0;
        int8 YPositionJudge(float,float,int8)=0;
        int8 DistanceJudge(uint16,uint16)=0;
        int8 DirectionJudge(float,float,int8)=0;
}