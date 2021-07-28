//
//ScenarioControl.h
//シナリオコントロールクラス
#pragma once
#include "../System/System.h"
#include "../../include/Scenario/SceneControl.h"
#include "../../include/Scenario/Garage.h"
#include "../../include/Scenario/ScenarioControl.h"
#include "../../include/Scenario/SlalomBlacky.h"
#include "../../include/Scenario/SlalomEebui.h"
#include "../../include/Scenario/SlalomEifie.h"
#include "../../include/Scenario/TimeAttack.h"
#include "../../include/Control/PidControl.h"

#define START           0
#define TIME_ATACK      1
#define SLALOM_EEBUI    2
#define SLALOM_BLACKY   3
#define SLALOM_EIFIE    4
#define GARAGE          5
#define FINISH          -1
#define NEXT_BLACKY     -2
#define NEXT_EIFIE      -3

class ScenarioControl{
    private:
        int16 scenarioState=TIME_ATACK;
        int16 sceneNum=START;
    public:
        ScenarioControl();

        ~ScenarioControl();

        //実行
        //引数   -
        //戻り値 init8_t エラーチェック 

        int8 run();

        //シナリオの更新
        //引数   -
        //戻り値 init8_t エラーチェック
        int8 updateScenario();

        int8 scenarioGetter(int16* scenario_state);
    static ScenarioControl &getInstance()
    {
        static ScenarioControl scenarioControl;
        return scenarioControl;
    }
};
