//ScenarioControl
//シナリオコントロールクラス
//
#include "../../include/Scenario/ScenarioControl.h"

//Run
//実行
//
int8_t ScenarioControl::Run(){
    int8_t retChk = SYS_NG; //戻り値格納変数

    switch (scenario_state)
    {
    case TIME_ATACK:
        TimeAtack timeAtack;
        //タイムアタック
        break;
    
    case SLALOM_EEBUI:
        SlalomEebui slalomEebui;
        //スラロームイーブイ
        break;

    case SLALOM_BLACKY:
        SlalomBlacky slalomBlacky;
        //スラロームブラッキー
        break;

    case SLALOM_EIFIE:
        SlalomEifie slalomEifie;
        //スラロームエーフィ
        break;

    case GARAGE:
        Garage garage;
        //ガレージ
        break;
    
    default:
        break;
    }
    return retChk;
}

int8_t ScenarioControl::updateScenario(){
    int8_t retChk = SYS_NG; //戻り値格納変数

    //インスタンス化
    SceneControl sceneControl;

    //シーンの更新
    retChk = sceneControl.SceneChenge(scene_num);
    if(retChk != 0){
        return retChk;
    }

    //シーン番号の確認
    if(scene_num == NEXT_BLACKY){   //次のシーンはブラッキー
        scenario_state = SLALOM_BLACKY;
    }

    if(scene_num == NEXT_EIFIE){    //次のシーンはエーフィ
        scenario_state = SLALOM_EIFIE;
    }

    if(scene_num == FINISH){        //シナリオ内の全シーン終了
        if(scenario_state > SLALOM_EEBUI){
            scenario_state = GARAGE;
        }
        else{
            scenario_state++;
        }
    }
    return SYS_OK;
}