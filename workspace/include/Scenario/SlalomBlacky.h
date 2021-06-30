#include "../System/System.h"

//
//SlalomBlacky.h
//ライントレースのシーン制御クラス
//基底クラスSceneControl継承先
class SlalomBlacky : public SceneControl{
    public:

    SlalomBlacky();
    ~SlalomBlacky();
    int8 sceneChenge(&int16);
    int8 run(int16);
    int8 colorJudge(RGBData,RGBData,int8);
    int8 xPositionJudge(float,float,int8);
    int8 yPositionJudge(float,float,int8);
    int8 distanceJudge(uint16,uint16);
    int8 directionJudge(float,float,int8);
};