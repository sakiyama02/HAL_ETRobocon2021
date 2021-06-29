//
//ScenarioControl.h
//シナリオコントロールクラス
#include "../System/System.h"

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
        int16 scenario_state;
        int16 scene_num;
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

}
