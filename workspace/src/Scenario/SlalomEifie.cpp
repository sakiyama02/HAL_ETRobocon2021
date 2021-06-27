#include "../../include/Scenario/SlalomEifie.h"
int8 SlalomEifie::Run(scene_num)　{
    //エラー格納変数
    int8 check_value=SYS_NG;

    // 情報クラスのインスタンス化
    SlEfActionInfomation ActionInfomation;
    SlEfCurveInfomation CurveInfomation;
    SlEfPidInfomation PidInfomation;
    SlEfPositionCorrectionInfomation PositionCorrectionInfomation;

    // 情報構造体のインスタンス化
    ChangeInfo changeInfo;
    DirectionData directionData;
    CurveData curveData;
    PIDData pidData;
    PositionCorrectionData positioncorrectionData;

    //情報クラスから行動情報取得
    check_value=ActionInfomation.getter(scene_num,&ChangeInfo,&directionData);
    check_value=CurveInfomation.getter(scene_num,&curveData);
    check_value=PidInfomation.getter(scene_num,&pidData);
    check_value=PositionCorrectionInfomation.getter(scene_num,&positioncorrectionData);

//補正のオンの場合CORRECTIONDATA_ONを定義
#ifdef CORRECTIONDATA_ON
    //補正構造体のJudgeTypeを確認して補正を使用又はどの補正を使用するか取得
    //distanceは補正で使用しないので補正なしとしている
    //座標補正値が同一の場合タスク起動せず終了
    swich (positioncorrectionData.CorrectionCondition){
        //rgb値による補正の場合
        case JUDGE_RGB:
        //補正クラスのインスタンス取得
            PositionCorrection &positionCorrection=
            PositionCorrection::getinstance();
        //補正クラスに目標値と補正値をセット後タスク起動
            check_value=positionCorrection.ColorFixSetter(
                positioncorrectionData.correctionValue,
                positioncorrectionData.correctionRGB);
        break;

        //座標値による補正の場合
        case JUDGE_POS:
        //補正クラスのインスタンス取得
            PositionCorrection &positionCorrection=
            PositionCorrection::getinstance();
        //補正クラスに目標値と補正値をセット後タスク起動
            check_value=positionCorrection.LineFixSetter(
                positioncorrectionData.correctionValue,
                positioncorrectionData.correctionPosition);
        break;

        //距離による補正現在は補正なし
        case JUDGE_DIS:
        break;

        //向きによる補正の場合
        case JUDGE_DIR:
        //補正クラスのインスタンス取得
            PositionCorrection &positionCorrection=
            PositionCorrection::getinstance();
        //補正クラスに目標値と補正値をセット後タスク起動
            check_value=positionCorrection.DirectionFixSetter(
                positioncorrectionData.correctionValue,
                positioncorrectionData.correctionDirection);
        break;
        //一応
        default:
        break;
    }
#endif
    //動作の選択
    switch(changeInfo.section_act){
        //ライントレース
        case LINE_TRACE:
        //コンストラクタ引数：
        //構造体ChangeInfo内のspeedと構造体PIDData
            LineTrace lineTrace(changeInfo.speed,pidData);
            check_value=lineTrace.run();

        break;

        //直進
        //コンストラクタ引数：構造体ChangeInfo内のspeed
        case STRAIGHT:
            Straight straight(changeInfo.speed);
            check_value=straight.run();
        break;

        //カーブ
        //コンストラクタ引数：
        //構造体ChangeInfo内のspeedとCurveData構造体
        case CURVE:
            Curve curve(changeInfo.speed,curveData);
            check_value=curve.run();
        break;

        //ラインカーブ
        //コンストラクタ引数：
        //構造体ChangeInfo内のspeedとCurveData構造体とカーブ構造体
        case LINE_CURVE:
            Curve curve(changeInfo.speed,curveData,pidData);
            check_value=curverun();
        break;

        //旋回
        //コンストラクタ引数：
        //構造体ChangeInfo内のspeedとDirectionData構造体
        case TURN:
            Turn turn(changeInfo.speed,directionData);
            check_value=turn.run();
        break;

        //アーム動作
        //構造体ChangeInfo内のspeed
        case ARM_ACTION:
            ArmAction armAction(changeInfo.speed);
            check_value=armAction.run();
        break;

        //一応
        default:
        break;
    }
    return SYS_OK;
}