/**
 ******************************************************************************
 ** ファイル名 : app.c
 **
 ** 概要 : 二輪差動型ライントレースロボットのTOPPERS/HRP3用Cサンプルプログラム
 **
 ** 注記 : sample_c4 (sample_c3にBluetooth通信リモートスタート機能を追加)
 ******************************************************************************
 **/

#include "workspace/include/System/System.h"

// ev3_sta_cyc(CYC_TASK);  周期タスクON
// ev3_stp_cyc(CYC_TASK);  周期タスクOFF

/**
 * EV3システム生成
 */
static void user_system_create()
{
    Steering &steering = Steering::getInstance();
    steering.init();
    SensorManager &sensorManager = SensorManager::getInstance();
    sensorManager.init();
}

/**
 * EV3システム破棄
 */
static void user_system_destroy()
{
    Steering &steering = Steering::getInstance();
    MotorPower power = {0, 0};
    steering.rotateWheel(power);
    steering.deletePort();
}

/* メインタスク */
void main_task(intptr_t unused)
{
    frLog &msg = frLog::GetInstance();
    char command[] = {"logon -section  \n"};

    int index = 0;
    for (index = 0; index < (sizeof(command) / sizeof(command[0])); index++)
    {
        msg.SetLog(command[index]);
    }
    ev3_sensor_config(EV3_PORT_1, TOUCH_SENSOR);
    user_system_create();
    while (1)
    {
        if (ev3_touch_sensor_is_pressed(EV3_PORT_1) == 1)
        {
            msg.LOG(LOG_ID_TRACE, "押されたやで");
            break;
        }
        tslp_tsk(10 * 1000U);
    }
    // int16 val = 0;
    // SensorManager &sensorManager  = SensorManager::getInstance();
    
    // while(1){
    //     sensorManager.getDistance(&val);
    //     msg.LOG(LOG_ID_ERR, "%d",val);
    //     tslp_tsk(10 * 1000U);
    // }
    // uint16 bright = 0;
    // BrightCalc brightCalc;
    // brightCalc.run(&bright);
    // while(1){
    //     msg.LOG(LOG_ID_SECTION,"bright: %d", bright);
    //     tslp_tsk(10 * 1000U);
    // }
    msg.LOG(LOG_ID_TRACE, "メインタスクスタート");
    //act_tsk(BT_TASK);
    //sta_cyc(ROBO_CYC);
    act_tsk(ROBO_TASK);
    msg.LOG(LOG_ID_TRACE, "Mainタスクスリープ");
    slp_tsk();
    msg.LOG(LOG_ID_TRACE, "Mainタスクスリープ解除");
    //ter_tsk(ROBO_TASK);
    //stp_cyc(ROBO_CYC);
    ter_tsk(ROBO_TASK);
    ter_tsk(BT_TASK);
    user_system_destroy();
    msg.LOG(LOG_ID_TRACE, "Mainタスクend");
    // msg.LOG(LOG_ID_ERR,"カウント開始");
    tslp_tsk(3300 * 1000);
    // msg.LOG(LOG_ID_ERR,"カウント終了");
    ETRoboc_notifyCompletedToSimulator();
    ext_tsk();
}


void robo_task(intptr_t unused)
{
    frLog &msg = frLog::GetInstance();
    msg.LOG(LOG_ID_TRACE, "ロボタスクスタート");

    while (1)
    {
        int8 retChk = SYS_NG;
        bool flag = false;
        CourseMastering &courseMastering = CourseMastering::getInstance();
        bool courseResult = false;
        retChk = courseMastering.run(&courseResult);
        if (courseResult == true || retChk != SYS_OK)
        {
            break;
        }
        tslp_tsk(9999);
    }

    wup_tsk(MAIN_TASK);
    ext_tsk();
    msg.LOG(LOG_ID_TRACE, "ロボタスクend");
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
    frLog &msg = frLog::GetInstance();
    msg.LOG(LOG_ID_TRACE, "Bluetoothスタート");
    while (true)
    {
        tslp_tsk(100);
    }
    msg.LOG(LOG_ID_TRACE, "Bluetoothエンド");
    ext_tsk();
}