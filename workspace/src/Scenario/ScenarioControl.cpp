//ScenarioControl
//シナリオコントロールクラス
//
#include "../../include/Scenario/ScenarioControl.h"

ScenarioControl::ScenarioControl(){}
ScenarioControl::~ScenarioControl(){}

/* -------------------------------------------------------------------------- */
/* 関数名       ：run                                                          */
/* 機能名       ：実行                                                         */
/* 機能概要     ：現在のシナリオ情報を使ってシナリオ実行                         */
/* 引数         ：void                                                        */
/* 戻り値       ：int8、エラー通知                                             */
/* 作成日       ：7月23日、鶴野祥大                                            */
/* -------------------------------------------------------------------------- */
int8 ScenarioControl::run(){
    int8 retChk = SYS_NG; //戻り値格納変数

    SceneControl *sceneControl=NULL;

    switch (scenarioState)
    {
    case TIME_ATACK:
        //タイムアタック
        sceneControl = new TimeAttack;
        break;
    
    case SLALOM_EEBUI:
        //スラロームイーブイ
        sceneControl = new SlalomEebui;
        break;

    case SLALOM_BLACKY:
        //スラロームブラッキー
        sceneControl = new SlalomBlacky;
        break;

    case SLALOM_EIFIE:
        //スラロームエーフィ
        sceneControl = new SlalomEifie;
        break;

    case GARAGE:
        //ガレージ
        sceneControl = new Garage;
        break;
    
    default:
        break;
    }

    retChk = sceneControl -> run(sceneNum);
    //動的メモリの開放
    delete sceneControl;
    return retChk;
}

/* -------------------------------------------------------------------------- */
/* 関数名       ：updateScenario                                               */
/* 機能名       ：更新                                                         */
/* 機能概要     ：シナリオ情報更新の確認して更新                                 */
/* 引数         ：void                                                        */
/* 戻り値       ：int8、エラー通知                                             */
/* 作成日       ：7月23日、鶴野祥大                                            */
/* -------------------------------------------------------------------------- */
int8 ScenarioControl::updateScenario(){
    int8 retChk = SYS_NG; //戻り値格納変数
    PidControl &pidControl      = PidControl::getInstance();

    SceneControl *sceneControl=NULL;
    switch (scenarioState){
        case TIME_ATACK:
            //タイムアタック
            sceneControl = new TimeAttack;
            break;
        
        case SLALOM_EEBUI:
            //スラロームイーブイ
            sceneControl = new SlalomEebui;
            break;

        case SLALOM_BLACKY:
            //スラロームブラッキー
            sceneControl = new SlalomBlacky;
            break;

        case SLALOM_EIFIE:
            //スラロームエーフィ
            sceneControl = new SlalomEifie;
            break;

        case GARAGE:
            //ガレージ
            sceneControl = new Garage;
            break;
        
        default:
            break;
    }

    //シーンの更新
    retChk = sceneControl->sceneChenge(&sceneNum);
    //動的メモリの開放
    delete sceneControl;
    if(retChk != SYS_OK){
        return SYS_NG;
    }
    pidControl.initIntegral();

    //シーン番号の確認
    if(sceneNum == NEXT_BLACKY){   //次のシーンはブラッキー
        scenarioState = SLALOM_BLACKY;
        sceneNum=START;
        return SYS_OK;
    }

    if(sceneNum == NEXT_EIFIE){    //次のシーンはエーフィ
        scenarioState = SLALOM_EIFIE;
        sceneNum=START;
        return SYS_OK;
    }

    if(sceneNum == FINISH){        //シナリオ内の全シーン終了
        if(scenarioState == SLALOM_EIFIE||scenarioState == SLALOM_BLACKY){
            scenarioState = GARAGE;
            sceneNum=START;
        }
        else{
            scenarioState++;
            sceneNum=START;
            return SYS_OK;
        }
    }
    return SYS_NG;
}

/* -------------------------------------------------------------------------- */
/* 関数名       ：scenarioGetter                                               */
/* 機能名       ：シナリオ情報の取得                                            */
/* 機能概要     ：シナリオ情報をシーン制御に受け渡す                            */
/* 引数         ：int16*、scenario_state、シナリオ状態                         */
/* 戻り値       ：int8、エラー通知                                             */
/* 作成日       ：7月23日、鶴野祥大                                            */
/* -------------------------------------------------------------------------- */
int8 ScenarioControl::scenarioGetter(int16* scenario_state){
    /* 引数チェック */
    if( scenario_state == NULL ){
        return SYS_PARAM;
    }
    *scenario_state = scenarioState;
    return SYS_OK;
}

