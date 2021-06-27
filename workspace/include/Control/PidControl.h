//
//  Pidcontrol.h
//  PID制御クラス
//

#include "../System/System.h"
#include "../Sensor/SensorManager.h"

class Pidcontrol
{
private:
    //前回の偏差
    int32 prevDeviation;

public:
    Pidcontrol();

    ~Pidcontrol();

    //
    // -setting     PID操作量を計算

    int8 calcPid();

};