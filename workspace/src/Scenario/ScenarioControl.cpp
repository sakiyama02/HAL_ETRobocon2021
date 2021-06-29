//ScenarioControl
//シナリオコントロールクラス
//
#include "../../include/Scenario/ScenarioControl.h"

//run
//実行
//
int8 ScenarioControl::run(){
    int8 retChk = SYS_NG; //戻り値格納変数

    SceneControl *sceneControl;

    switch (scenario_state)
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

    retChk = sceneControl -> run(scene_num);
    return retChk;
}

//updateScenario
//シナリオの更新
//
int8 ScenarioControl::updateScenario(){
    int8 retChk = SYS_NG; //戻り値格納変数

    //インスタンス化
    SceneControl sceneControl;

    //シーンの更新
    retChk = sceneControl.SceneChenge(&scene_num);
    if(retChk != SYS_OK){
        return SYS_NG;
    }

    //シーン番号の確認
    if(scene_num == NEXT_BLACKY){   //次のシーンはブラッキー
        scenario_state = SLALOM_BLACKY;
        return SYS_OK;
    }

    if(scene_num == NEXT_EIFIE){    //次のシーンはエーフィ
        scenario_state = SLALOM_EIFIE;
        return SYS_OK;
    }

    if(scene_num == FINISH){        //シナリオ内の全シーン終了
        if(scenario_state > SLALOM_EEBUI){
            scenario_state = GARAGE;
        }
        if(scenario_state == GARAGE){
            return SYS_OK;
        }
        else{
            scenario_state++;
            return SYS_OK;
        }
    }
    return SYS_NG;
}