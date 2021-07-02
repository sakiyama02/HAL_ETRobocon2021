#include "../../include/PositionCorrection/PositionCorrection.h"
int8 PositionCorrection::FixSetter(PositionCorrectionData positionCorrection_Data){
    //現在のタスクの状態を確認
    //状態：実行中      STATE＿ACT
    //    ：実行済み　　STATE＿ACTAFTER
    sceneState=memcmp(&prePositionCorrectionData,&positionCorrection_Data,sizeof(PositionCorrectionData));
    //シーンに変化がない場合戻り値で終了した事を知らせる
    if(sceneState==SYS_OK){
        return ;
    }
    //シーン変化がある場合
    if(taskState==STATE＿ACT){
        //現在実行中のタスク停止
    } 
    //メンバ構造体に引数で取得した最新状態の構造体をセット
    memcpy(&prePositionCorrectionData,&positionCorrection_Data,sizeof(PositionCorrectionData));
    //補正を起動する
    switch(prePositionCorrectionData.correctionCondition){
        //
        case JUDGE_RGB:
            colorFix();
        break;
        case JUDGE_POS:
            lineFix();
        break;
        case JUDGE_DIR:
            directionFix();
        break;
        default:
        break;
    }
}

int8 PositionCorrection::colorFix(){
    
}

int8 PositionCorrection::lineFix(){

}

int8 PositionCorrection::directionFix(){
    
}