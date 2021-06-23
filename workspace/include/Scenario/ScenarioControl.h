#include "../System/System.h"
//
//ScenarioControl.h
//シナリオコントロールクラス

class ScenarioControl{
    private:
    public:
        ScenarioControl();

        ~ScenarioControl();

        //実行
        //引数   -
        //戻り値 init8_t エラーチェック 
        init8_t Run();

        //シナリオの更新
        //引数   -
        //戻り値 init8_t エラーチェック
        init8_t updateScenario();
}
