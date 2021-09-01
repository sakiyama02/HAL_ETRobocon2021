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
#include "workspace/include/Logger/frLog.h"
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
    frLog &msg = frLog::GetInstance();
    char command[] = {"logon -section -trace \n"};
    
    uint16 index = 0;
    for (index = 0; index < (sizeof(command) / sizeof(command[0])); index++)
    {
        msg.SetLog(command[index]);
    }
    ev3_sensor_config(EV3_PORT_1, TOUCH_SENSOR);
    /* 動的に生成するインスタンスの初期化 */
    user_system_create();
    //フライング
    while (1)
    {
        if (ev3_touch_sensor_is_pressed(EV3_PORT_1) == 1)
        {
            msg.LOG(LOG_ID_ERR, "押されたやで");
            break;
        }
        tslp_tsk(10 * 1000U);
    }
    act_tsk(MAIN_TASK);
    sta_cyc(TRAPEZOIDAL_PERIOD);
    ext_tsk();
}
/* メインタスク */
void main_task(intptr_t unused)
{
    frLog &msg = frLog::GetInstance();
    ScenarioControl &scenariocontrol = ScenarioControl::getInstance();
    int8 retChk = SYS_NG;
    //実行
    retChk = scenariocontrol.run();
    if( retChk != SYS_OK ){
        msg.LOG(LOG_ID_ERR, "main_task scenariocontrol.run エラー");
    }
    act_tsk(UPDATA_TASK);
    ext_tsk();
}
/* 更新タスク */
void updata_task(intptr_t unused)
{
    frLog &msg = frLog::GetInstance();
    int8 retChk = SYS_NG;
    int16 senarioState = 0;
    CarPosition &carposition = CarPosition::getInstance();
    ScenarioControl &scenariocontrol = ScenarioControl::getInstance();
    //シングルトンのセンサ管理からインスタンスのポインタを取得
    SensorManager &senserManage=SensorManager::getInstance();
#ifdef CORRECTIONDATA_ON
    //補正クラスのインスタンス取得
    PositionCorrection &positionCorrection=
    PositionCorrection::getInstance();
    JudgeType controltask=JUDGE_NONE;
    Range movetask=NONE;
    positionCorrection.controltaskgetter(&controltask);
    positionCorrection.movetaskgetter(&movetask);
    switch(controltask){
        case JUDGE_RGB:
            if(movetask==HIGH){
                sta_cyc(COLORFIX_PERIOD);
                break;
            }
            if(movetask==LOW){
                stp_cyc(COLORFIX_PERIOD);
                break;
            }
            if(movetask==NONE){
                break;
            }
        break;
        case JUDGE_POS:
            if(movetask==HIGH){
                sta_cyc(LINEFIX_PERIOD);
                break;
            }
            if(movetask==LOW){
                stp_cyc(LINEFIX_PERIOD);
                break;
            }
            if(movetask==NONE){
                break;
            }
        break;
        case JUDGE_DIR:
            if(movetask==HIGH){
                sta_cyc(DIRECTIONFIX_PERIOD);
                break;
            }
            if(movetask==LOW){
                stp_cyc(DIRECTIONFIX_PERIOD);
                break;
            }
            if(movetask==NONE){
                break;
            }        
        break;
        case JUDGE_SEND:
            if(movetask==HIGH){
                sta_cyc(SEND_PERIOD);
                break;
            }
            if(movetask==LOW){
                stp_cyc(SEND_PERIOD);
                break;
            }
            if(movetask==NONE){
                break;
            }        
        break;
        case JUDGE_V:
            if(movetask==HIGH){
                sta_cyc(VFIX_PERIOD);
                break;
            }
            if(movetask==LOW){
                stp_cyc(VFIX_PERIOD);
                break;
            }
            if(movetask==NONE){
                break;
            }        
        break;
        case JUDGE_S:
            if(movetask==HIGH){
                sta_cyc(SFIX_PERIOD);
                break;
            }
            if(movetask==LOW){
                stp_cyc(SFIX_PERIOD);
                break;
            }
            if(movetask==NONE){
                break;
            }        
        break;
        case JUDGE_DIS:
            if(movetask==HIGH){
                sta_cyc(DISTANCEFIX_PERIOD);
                break;
            }
            if(movetask==LOW){
                stp_cyc(DISTANCEFIX_PERIOD);
                break;
            }
            if(movetask==NONE){
                break;
            }        
        break;
        default:
        break;
    }
    controltask=JUDGE_NONE;
    movetask=NONE;
    positionCorrection.controltasksetter(controltask);
    positionCorrection.movetasksetter(movetask);
#endif
    retChk=senserManage.getRgb();
    retChk = carposition.update();
    if( retChk != SYS_OK ){
        msg.LOG(LOG_ID_ERR, "updata_task carposition.update エラー");
    }
    //シナリオ制御更新
    retChk = scenariocontrol.updateScenario();
    if( retChk != SYS_OK ){
        //msg.LOG(LOG_ID_ERR, "updata_task scenariocontrol.updateScenario エラー");
    }
    //シナリオ状態取得
    retChk = scenariocontrol.scenarioGetter(&senarioState);
    if( retChk != SYS_OK ){
        msg.LOG(LOG_ID_ERR, "updata_task scenariocontrol.scenarioGetter エラー");
    } 
    //シナリオ終了
    if(senarioState == GARAGE + 1)
    {
        msg.LOG(LOG_ID_ERR, "シナリオすべて終わり");
        act_tsk(END_TASK);
        ext_tsk();
    }

    //unity間通信
    tslp_tsk(9999);
    act_tsk(MAIN_TASK);
    ext_tsk();
}
/* 終了タスク */
void end_task(intptr_t unused)
{
    ter_tsk(MAIN_TASK);
    ter_tsk(UPDATA_TASK);
    frLog &msg = frLog::GetInstance();
    msg.LOG(LOG_ID_ERR,"終了やで");
    user_system_destroy();
    stp_cyc(TRAPEZOIDAL_PERIOD);
    msg.LOG(LOG_ID_ERR,"カウント開始");
    tslp_tsk(6000 * 1000);
    msg.LOG(LOG_ID_ERR,"カウント終了");
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
    frLog &msg = frLog::GetInstance();
    //msg.LOG(LOG_ID_TRACE, "台形だよ");
    int8 retChk = SYS_NG;
    TrapezoidControl &trapezoidcontrol = TrapezoidControl::getInstance();
    //台形制御計算
    retChk = trapezoidcontrol.accelerate();
    if( retChk != SYS_OK ){
        msg.LOG(LOG_ID_ERR, "app trapezoidcontrol.accelerate エラー");
    }
}
//周期タスクスタート:sta_cyc(TRAPEZOIDAL_PERIOD)
/* 色補正タスク */
void colorfix_task(intptr_t unused)
{
    int8 retChk = SYS_NG;
    PositionCorrection &positioncorrection=PositionCorrection::getInstance();
    retChk=positioncorrection.colorFix();
    if( retChk != SYS_OK ){
    }
}

/* 座標補正タスク */
void linefix_task(intptr_t unused)
{
    int8 retChk = SYS_NG;
    //printf("ラインタスク開始");
    PositionCorrection &positioncorrection=PositionCorrection::getInstance();
    retChk=positioncorrection.lineFix();
    if( retChk != SYS_OK ){
    }
}

/* 角度補正タスク */
void directionfix_task(intptr_t unused)
{
    int8 retChk = SYS_NG;
    PositionCorrection &positioncorrection=PositionCorrection::getInstance();
    retChk=positioncorrection.directionFix();
    if( retChk != SYS_OK ){
    }
}

/* 送信補正タスク */
void send_task(intptr_t unused)
{
    int8 retChk = SYS_NG;
    PositionCorrection &positioncorrection=PositionCorrection::getInstance();
    retChk=positioncorrection.send_position();
    if( retChk != SYS_OK ){
    }
}

/* v値補正タスク */
void vfix_task(intptr_t unused)
{
    int8 retChk = SYS_NG;
    PositionCorrection &positioncorrection=PositionCorrection::getInstance();
    retChk=positioncorrection.vFix();
    if( retChk != SYS_OK ){
    }
}

/* s値補正タスク */
void sfix_task(intptr_t unused)
{
    int8 retChk = SYS_NG;
    PositionCorrection &positioncorrection=PositionCorrection::getInstance();
    retChk=positioncorrection.sFix();
    if( retChk != SYS_OK ){
    }
}

/* 距離補正タスク */
void distancefix_task(intptr_t unused)
{
    int8 retChk = SYS_NG;
    PositionCorrection &positioncorrection=PositionCorrection::getInstance();
    retChk=positioncorrection.distanceFix();
    if( retChk != SYS_OK ){
    }
}