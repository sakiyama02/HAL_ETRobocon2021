
#include "../System/System.h"
#include "../Action/Action.h"

class LineTrace : public Action {
private:


public:
    LineTrace();
    ~LineTrace();

    int8 run(int32 speed,PIDData pid_data,float angle,CurveData curve_data);
};