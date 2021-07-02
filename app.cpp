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
//#include "workspace/include/CouseMastering/CourseMastering.h"
#include "workspace/include/System/System.h"
//#include "workspace/include/Logger/Logger.h"
#include "workspace/include/Steering/Steering.h"
#include "workspace/include/Sensor/SensorManager.h"
//#include "workspace/include/Calculation/BrightCalc.h"

// ev3_sta_cyc(CYC_TASK);  周期タスクON
// ev3_stp_cyc(CYC_TASK);  周期タスクOFF


#if defined(BUILD_MODULE)
#include "module_cfg.h"
#else
//#include "kernel_cfg.h"
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
    Motor motor = Motor();
    steering.deletePort();
}

/* メインタスク */
void main_task(intptr_t unused)
{
    //frLog &msg = frLog::GetInstance();
    char command[] = {"logon -section  \n"};

    /* 
    int index = 0;
    for (index = 0; index < (sizeof(command) / sizeof(command[0])); index++)
    {
        msg.SetLog(command[index]);
    }*/
    ev3_sensor_config(EV3_PORT_1, TOUCH_SENSOR);
    /* 動的に生成するインスタンスの初期化 */
    user_system_create();
    while (1)
    {
        if (ev3_touch_sensor_is_pressed(EV3_PORT_1) == 1)
        {
            //msg.LOG(LOG_ID_TRACE, "押されたやで");
            break;
        }
        tslp_tsk(10 * 1000U);
    }
    //msg.LOG(LOG_ID_TRACE, "メインタスクスタート");
    //act_tsk(BT_TASK);
    /* 周期ハンドラ開始 */ 
    //sta_cyc(ROBO_CYC);
    act_tsk(ROBO_TASK);
    //msg.LOG(LOG_ID_TRACE, "Mainタスクスリープ");
    /* バックボタンが押されるまで待つ */
    slp_tsk();
    //msg.LOG(LOG_ID_TRACE, "Mainタスクスリープ解除");
    //ter_tsk(ROBO_TASK);
    //stp_cyc(ROBO_CYC);
    ter_tsk(ROBO_TASK);
    ter_tsk(BT_TASK);
    /* 生成したオブジェクトの破壊 */
    user_system_destroy();
    //msg.LOG(LOG_ID_TRACE, "Mainタスクend");
    // msg.LOG(LOG_ID_ERR,"カウント開始");
    tslp_tsk(3300 * 1000);
    // msg.LOG(LOG_ID_ERR,"カウント終了");
    ETRoboc_notifyCompletedToSimulator();
    ext_tsk();
}

void robo_task(intptr_t unused)
{
    //frLog &msg = frLog::GetInstance();
    //msg.LOG(LOG_ID_TRACE, "ロボタスクスタート");

    while (1)
    {
        int8 retChk = SYS_NG;
        bool flag = false;

        bool courseResult = false;
        //retChk = courseMastering.run(&courseResult);
        
        
        
        if (courseResult == true || retChk != SYS_OK)
        {
            break;
        }
        tslp_tsk(9999);
    }

    wup_tsk(MAIN_TASK);
    ext_tsk();
    //msg.LOG(LOG_ID_TRACE, "ロボタスクend");
    //ext_tsk();
}

//*****************************************************************************
// 関数名 : bt_task
// 引数 : unused
// 返り値 : なし
// 概要 : Bluetooth通信によるリモートスタート。 Tera Termなどのターミナルソフトから、
//       ASCIIコードで1を送信すると、リモートスタートする。
//*****************************************************************************
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
