//ScenarioControl
//シナリオコントロールクラス
//
#include "../../include/Scenario/ScenarioControl.h"

ScenarioControl::ScenarioControl(){}
ScenarioControl::~ScenarioControl(){}

//run
//実行
//
int8 ScenarioControl::run(){
    int8 retChk = SYS_NG; //戻り値格納変数

    SceneControl *sceneControl;

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

//updateScenario
//シナリオの更新
//
int8 ScenarioControl::updateScenario(){
    int8 retChk = SYS_NG; //戻り値格納変数

    //インスタンス化
    SceneControl *sceneControl;
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

    //シーン番号の確認
    if(sceneNum == NEXT_BLACKY){   //次のシーンはブラッキー
        scenarioState = SLALOM_BLACKY;
        return SYS_OK;
    }

    if(sceneNum == NEXT_EIFIE){    //次のシーンはエーフィ
        scenarioState = SLALOM_EIFIE;
        return SYS_OK;
    }

    if(sceneNum == FINISH){        //シナリオ内の全シーン終了
        if(scenarioState == SLALOM_EIFIE||scenarioState == SLALOM_BLACKY){
            scenarioState = GARAGE;
        }
        else{
            scenarioState++;
            return SYS_OK;
        }
    }
    return SYS_NG;
}

//シナリオ番号のゲッタ
int8 ScenarioControl::scenarioGetter(int16* scenario_state){
    /* 引数チェック */
    if( scenario_state == NULL ){
        return SYS_PARAM;
    }
    *scenario_state = scenarioState;
    return SYS_OK;
}

//