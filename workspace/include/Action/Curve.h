///
/// curve.h
/// カーブ動作のクラスヘッダ

#include "../System/System.h"
#include "Action.h"

class Curve:public Action{
private:
public:

    Curve();
    ~Curve();

    int8 run(int32 speed,PIDData pid_data,float angle,CurveData curve_data);

};
