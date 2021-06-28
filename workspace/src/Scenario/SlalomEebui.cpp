#include "../../include/Scenario/SlalomEebui.h"
int8 SlalomEebui::Run(scene_num)　{
    //引数のエラーチェック
    if(scene_num==NULL){
        return SYS_PARAM;
    }

    //エラー格納変数
    int8 check_value=SYS_NG;

    // 情報クラスのインスタンス化
    SlEbActionInfomation ActionInfomation;
    SlEbCurveInfomation CurveInfomation;
    SlEbPidInfomation PidInfomation;
    SlEbPositionCorrectionInfomation PositionCorrectionInfomation;

    // 情報構造体のインスタンス化
    ChangeInfo changeInfo;
    DirectionData directionData;
    CurveData curveData;
    PIDData pidData;
    PositionCorrectionData positioncorrectionData;

    //構造体の初期化
    memset(&changeInfo,0,sizeof(ChangeInfo));
    memset(&directionData,0,sizeof(DirectionData));
    memset(&curveData,0,sizeof(CurveData));
    memset(&pidData,0,sizeof(PIDData));
    memset(&positioncorrectionData,0,sizeof(PositionCorrectionData));

    //情報クラスから行動情報取得
    check_value=ActionInfomation.getter(scene_num,&changeInfos,&directionData);
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

//
//更新タスクでの処理
//
int8 SlalomEebui::SceneChenge(int16* scene_num){
    //引数のエラーチェック
    if(scene_num==NULL){
        return SYS_PARAM;
    }
    int8 retChk=SYS_NG;

    // 情報クラスのインスタンス化
    ChangeInfo changeInfo;
    //構造体の初期化
    memset(&changeInfo,0,sizeof(ChangeInfo));

    //スラロームイーブイの切り替え情報クラスをインスタンス化
    SlEbActionInfomation ActionInfomation;
    //切り替え情報から情報取得
    retChk=ActionInfomation.getter(&scene_num,&changeInfo);

    //切り替え判定情報から処理選択
    switch(changeInfo.judge){
        //シーン切り替え判定がrgb値の場合
        case JUDGE_RGB:
            RGBData currgbData;
            memset(&currgbData,0,sizeof(RGBData));
        //シングルトンのセンサ管理からインスタンスのポインタを取得
            SensorManager &senserManage=SensorManager::getInstance();
        //rgbの現在時点最新状態を取得
            senserManage.rgb_Getter(&currgbData);
        //rgb値を目標値と現在値を比較
            retChk=ColorJudge(currgbData.rgb_data,changeInfo.rgb_data);
            if(retChk==SYS_OK){
                *scene_num++;
            }
        break;
        //シーン切り替え判定が座標場合
        case JUDGE_POS:
            PositionData curpositionData;
            memset(&curposition,0,sizeof(PositionData));
        //シングルトンの自己位置推定からインスタンスのポインタを取得
            CarPosition　&carPosition=CarPosition::getInstance();
        //座標の現在時点最新状態を取得
            carPosition.getPos(&curpositionData);
         //XYを判断する場合
            if(changeInfo.PosInfoData.xCondition<2&&changeInfo.PosInfoData.yCondition<2){
                retChk=XPositionJudge(curpositionData.PosInfoData.position.xPosition,
                                      changeInfo.PosInfoData.position.xPosition,
                                      changeInfo.PosInfoData.xCondition);
                if(retChk!=SYS_OK){
                    break;
                }
                retChk=YPositionJudge(curpositionData.PosInfoData.position.yPosition,
                                      changeInfo.PosInfoData.position.yPosition,
                                      changeInfo.PosInfoData.yCondition);
                if(retChk==SYS_OK){
                    *scene_num++;
                }
                break;
            }
        
        //Xだけを判断する場合
            if(changeInfo.PosInfoData.xCondition<2){
                retChk=XPositionJudge(curpositionData.PosInfoData.position.xPosition,
                                      changeInfo.PosInfoData.position.xPosition),
                                      changeInfo.PosInfoData.xCondition;
                if(retChk==SYS_OK){
                    *scene_num++;
                }
                break;
            }

        //Yだけを判断する場合
            if(changeInfo.PosInfoData.yCondition<2){
                retChk=YPositionJudge(curpositionData.PosInfoData.position.yPosition,
                                      changeInfo.PosInfoData.position.yPosition,
                                      changeInfo.PosInfoData.yCondition);
                if(retChk==SYS_OK){
                    *scene_num++;
                }
            }
        break;

        //シーン切り替え判定が距離の場合
        case JUDGE_DIS:
            uint16 curdistanceData=0;
        //シングルトンのセンサ管理からインスタンスのポインタを取得
            SensorManager &senserManage=SensorManager::getInstance();
        //超音波での距離の現在時点最新情報を取得
            senserManage.distanceGetter(&curdistanceData);
            retChk=DistanceJudge(curdistanceData,changeInfo.distance);
            if(retChk==SYS_OK){
                *scene_num++;
            }
        break;

        //シーン切り替え判定が向きの場合
        case JUDGE_DIR:
            DirectionData curdirectionData;
            memset(&curdirectionData,0,sizeof(DirectionData));
        //シングルトンの自己位置推定からインスタンスのポインタを取得
            CarPosition　&carPosition=CarPosition::getInstance();
            CarPosition.getDir(&curdirectionData.direction);
            retChk=directionJudge(curdirectionData.direction,
                                  changeInfo.direction_data.direction,
                                  changeInfo.direction_data.condition);
            if(retChk==SYS_OK){
                *scene_num++;
            }
        break;
    }

    //スラロームイーブイのシーンの終了かの確認
    //シーンの分岐のために超音波の距離を取得
    //距離で分岐シナリオを分ける
    //変化させる超音波の距離を定義に作る現在10
    //定義に変える-2と-3
    if(scene_num>TIMEATTACK_END){
        uint8 changedistance;
        SensorManager &sonicSenser=SensorManager::getInstance();
        sonicSenser.get_Distance();
        sonicSenser.distance_Getter(&changedistance);
        if(changedistance<10){
            *scene_num=-2
        }
        else{
            *scene_num=-3
        }
    }



    return SYS_OK;
}

//
//コードがネストで逝ってしまいそうなので臨時で作成（検討する必要がある）
//

//rgbの判定
//引数：現在のrgb値、目標のrgb値、(現在と目標の差分範囲の指定値)
//戻り値：切り替え条件を満たしていればSYS_OK
//        切り替え条件を満たしていなければSYS_NG
int8 TimeAttack::ColorJudge(RGBData cur_rgbdata,RGBData change_rgbdata){
    int8 resultr=0;
    int8 resultg=0;
    int8 resultb=0;
    //目標のrgb-現在のrgbの差分を計算
    resultr=cur_rgbdata.r-change_rgbdata.r;
    resultg=cur_rgbdata.g-change_rgbdata.g;
    resultb=cur_rgbdata.b-change_rgbdata.b;
    /*rgbを範囲指定する場合に使用（間違って作った）
    if(resultr>0&&resultg>0&&resultb>0){
        if(condition==HIGH){
            return SYS_OK;
        }
        else{
            return SYS_NG;
        }
    }

    if(resultr<0&&resultg<0&&resultb<0){
        if(condition==LOW){
            return SYS_OK;
        }
        else{
            return SYS_NG;
        }
    }
    */

    if(resultr==0&&resultg==0&&resultb==0){
        return SYS_OK;
    }

    return SYS_NG;
}

//X座標の判定
//引数：現在のX座標値、目標のX座標値、現在と目標の差分範囲の指定値
//戻り値：切り替え条件を満たしていればSYS_OK
//        切り替え条件を満たしていなければSYS_NG
int8 TimeAttack::XPositionJudge(float cur_xpositionData,float change_xpositionData,int8 condition){
    float resultx=0f;
    resultx=change_xpositionData-cur_xpositionData;
    if(resultx>0){
        if(condition==HIGH){
            return SYS_OK;
        }
        return SYS_NG;
    }
    if(resultx<0){
        if(condition==LOW){
            return SYS_OK;
        }
        return SYS_NG;        
    }
    if(resultx==0){
        if(condition==NONE){
            return SYS_OK;
        }
        return SYS_NG;        
    }
    return SYS_NG;
}

//Y座標の判定
//引数：現在のY座標値、目標のY座標値、現在と目標の差分範囲の指定値
//戻り値：切り替え条件を満たしていればSYS_OK
//        切り替え条件を満たしていなければSYS_NG
int8 TimeAttack::YPositionJudge(float cur_ypositionData,float cur_ypositionData,int8 condition){
    float resulty=0f;
    resulty=change_ypositionData-cur_ypositionData;
    if(resulty>0){
        if(condition==HIGH){
            return SYS_OK;
        }
        return SYS_NG;
    }
    if(resulty<0){
        if(condition==LOW){
            return SYS_OK;
        }
        return SYS_NG;        
    }
    if(resulty==0){
        if(condition==NONE){
            return SYS_OK;
        }
        return SYS_NG;        
    }
    return SYS_NG;
}


//距離の判定
//引数：現在の距離値、目標の距離値
//戻り値：切り替え条件を満たしていればSYS_OK
//        切り替え条件を満たしていなければSYS_NG
int8 TimeAttack::DistanceJudge(uint16 cur_distanceData,uint16 change_distanceData){
    uint16 resultdistance=0f;
    resultdistance=change_distanceData-cur_distanceData;
    /*距離を範囲指定する場合に使用（間違って作った）
    if(resultdistance>0){
        if(condition==HIGH){
            return SYS_OK;
        }
        return SYS_NG;
    }
    if(resultdistance<0){
        if(condition==LOW){
            return SYS_OK;
        }
        return SYS_NG;        
    }
    */
    if(resultdistance==0){
        return SYS_OK;
    }
    return SYS_NG;
}

//向きの判定
//引数：現在の向き値、目標の向き値、現在と目標の差分範囲の指定値 
//マイナスの値を入れるとバグるので注意
//戻り値：切り替え条件を満たしていればSYS_OK
//        切り替え条件を満たしていなければSYS_NG
int8 TimeAttack::directionJudge(float cur_directionData,float change_directionData,int8 condition){
    float resultdirection=0f;
    resultdirection=change_directionData-cur_directionData;
    if(resultdirection>0){
        if(condition==HIGH){
            return SYS_OK;
        }
        return SYS_NG;
    }
    if(resultdirection<0){
        if(condition==LOW){
            return SYS_OK;
        }
        return SYS_NG;        
    }
    if(resultdirection==0){
        if(condition==NONE){
            return SYS_OK;
        }
        return SYS_NG;        
    }
    return SYS_NG;
}