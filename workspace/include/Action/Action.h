///
/// Action.h
/// 動作クラス　（基底クラス）
///
#include "../System/System.h"

class Action {
private:


public:
    Action();
    virtual ~Action();

    virtual int8 run(int32 speed,PIDData pid_data,float angle,CurveData curve_data);

};