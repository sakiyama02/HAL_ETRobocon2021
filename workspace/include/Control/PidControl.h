//
//  PidControl.h
//  PID制御クラス
//

#include "../System/System.h"
#include "../Sensor/SensorManager.h"

//周期
#define DELTA_TIME 0.01f

class PidControl
{
private:
    //偏差
    float   eDeviation;
    //偏差の積み上げ
    float stackIntegral;
    //モーターパワー格納変数
    int32 motorPow;
public:
    PidControl();
    ~PidControl();
    static PidControl &getInstance()        // インスタンスの生成 
    {
        static PidControl PidControl_;      
        return PidControl_;
    }

    //
    // -setting     PID操作量を計算
    // -argu        現在のモーターパワー
    //              PIDのゲイン値,目標値
    // -return      SYS_OK 正常終了
    // -return      SYS_PARAM 引数エラー
    // -return      SYS_NG 異常終了

    int8 calcPid(int32*,PIDData*);

    //
    // -setting     モーターパワー格納
    // -argu        モーターパワー
    // -return      SYS_OK 正常終了
    // -return      SYS_PARAM 引数エラー
    // -return      SYS_NG 異常終了

    int8 getPow(int32*);

};