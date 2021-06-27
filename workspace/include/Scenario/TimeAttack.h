#include "../System/System.h"

//
//TimeAttack.h
//ライントレースのシーン制御クラス
//基底クラスSceneControl継承先
class TimeAttack : public SceneControl{
    public:
    TimeAttack();
    ~TimeAttack();
    init8_t SceneChenge(init16_t);
    init8_t Run(init16_t);
}