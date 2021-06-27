#include "../System/System.h"

//
//TimeAttack.h
//ライントレースのシーン制御クラス
//基底クラスSceneControl継承先
class SlalomBlacky : public SceneControl{
    public:
    TimeAttack();
    ~TimeAttack();
    int8 SceneChenge(&int16);
    int8 Run(int16);
    int8 ColorJudge(RGBData,RGBData);
    int8 XPositionJudge(float,float,int8);
    int8 YPositionJudge(float,float,int8);
    int8 DistanceJudge(uint16,uint16);
    int8 DirectionJudge(float,float,int8);
}