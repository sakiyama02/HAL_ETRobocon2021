/**
 ******************************************************************************
 ** ファイル名 : app.c
 **
 ** 概要 : 二輪差動型ライントレースロボットのTOPPERS/HRP3用Cサンプルプログラム
 **
 ** 注記 : sample_c4 (sample_c3にBluetooth通信リモートスタート機能を追加)
 ******************************************************************************
 **/

#include "ev3api.h"
#include "app.h"
#include "etroboc_ext.h"
#include "workspace/include/Scenario/ScenarioControl.h"
#include "workspace/include/CarData/CarPosition.h"
#include "workspace/include/Control/TrapezoidControl.h"
#include "workspace/include/System/System.h"
//#include "workspace/include/Logger/Logger.h"
#include "workspace/include/Steering/Steering.h"
#include "workspace/include/Sensor/SensorManager.h"
//#include "workspace/include/Calculation/BrightCalc.h"


#if defined(BUILD_MODULE)
#include "module_cfg.h"
#else
#include "kernel_cfg.h"
#endif
bool flag = false;

/**
 * EV3システム生成
 * モーター設定
 */
static void user_system_create()
{
    Steering &steering = Steering::getInstance();
    steering.init();
    SensorManager &sensorManager = SensorManager::getInstance();
    sensorManager.initSensor();
}

/**
 * EV3システム破棄
 */
static void user_system_destroy()
{
    Steering &steering = Steering::getInstance();
    MotorPower power = {0,0};
    steering.rotateWheel(power);
    steering.deletePort();
}

/*  スタート処理タスク */
void start_task(intptr_t unused)
{

    char command[] = {"logon -section  \n"};
    //
    ev3_sensor_config(EV3_PORT_1, TOUCH_SENSOR);
    /* 動的に生成するインスタンスの初期化 */
    user_system_create();
    //
    act_tsk(MAIN_TASK);
    act_tsk(UPDATA_TASK);
    sta_cyc(TRAPEZOIDAL_PERIOD);
    ext_tsk();
}

/* メインタスク */
void main_task(intptr_t unused)
{
    //frLog &msg = frLog::GetInstance();
    //msg.LOG(LOG_ID_TRACE, "メインタスクスタート");
    ScenarioControl &scenariocontrol = ScenarioControl::getInstance();

    int8 retChk = SYS_NG;
    //実行
    retChk = scenariocontrol.run();
    if( retChk != SYS_OK ){
        //ログ
    }

    ext_tsk();
    //tslp_tsk();

    //msg.LOG(LOG_ID_TRACE, "メインタスクend");
}

/* 更新タスク */
void updata_task(intptr_t unused)
{
    int8 retChk = SYS_NG;
    int16 senarioState = 0;
    CarPosition &carposition = CarPosition::getInstance();
    ScenarioControl &scenariocontrol = ScenarioControl::getInstance();

    //シナリオ状態取得
    retChk = scenariocontrol.scenarioGetter(&senarioState);
    if( retChk != SYS_OK ){
        //ログ
    }  
    //シナリオ終了
    
    if(senarioState == GARAGE + 1)
    {
        act_tsk(END_TASK);
        ext_tsk();
    }

    
    retChk = carposition.update();
    if( retChk != SYS_OK ){
        //ログ
    }

    //シナリオ制御更新
    retChk = scenariocontrol.updateScenario();
    if( retChk != SYS_OK ){
        //ログ
    }

    //unity間通信
    tslp_tsk(9999);
    act_tsk(MAIN_TASK);

}

/* 終了タスク */
void end_task(intptr_t unused)
{
    user_system_destroy();
    stp_cyc(TRAPEZOIDAL_PERIOD);
    // msg.LOG(LOG_ID_ERR,"カウント開始");
    tslp_tsk(3300 * 1000);
    // msg.LOG(LOG_ID_ERR,"カウント終了");
    ETRoboc_notifyCompletedToSimulator();
    ext_tsk();

}

/* Bluetoothタスク */ 
void bt_task(intptr_t unused)
{
    //frLog &msg = frLog::GetInstance();
    //msg.LOG(LOG_ID_TRACE, "Bluetoothスタート");
    while (true)
    {
        tslp_tsk(100);
    }
    //msg.LOG(LOG_ID_TRACE, "Bluetoothエンド");
    ext_tsk();
}

/* 周期タスク処理 */

/* 台形制御タスク */
void trapezoidal_task(intptr_t unused)
{
    int8 retChk = SYS_NG;
    TrapezoidControl &trapezoidcontrol = TrapezoidControl::getInstance();
    //台形制御計算
    trapezoidcontrol.accelerate();
    if( retChk != SYS_OK ){
        //ログ
    }
}
//周期タスクスタート:sta_cyc(TRAPEZOIDAL_PERIOD)

/* 補正タスク */
void correction_task(intptr_t unused)
{
    int8 retChk = SYS_NG;
}

