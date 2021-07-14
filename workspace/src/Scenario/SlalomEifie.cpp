#include "../../include/Scenario/SlalomEifie.h"
SlalomEifie::SlalomEifie(){}
SlalomEifie::~SlalomEifie(){}
//メインタスクでの処理
int8 SlalomEifie::run(int16 scene_num) {


    //スラロームエーフィにシーンが一つもない場合正常終了
    if(SLALOMEIFIE_NUM==0){
        return SYS_OK;
    }

    //エラー格納変数
    int8 retChk=SYS_NG;

    // 情報クラスのインスタンス化
    SlEfActionInfomation ActionInfomation;
    SlEfCurveInfomation CurveInfomation;
    SlEfpidInfomation PidInfomation;
    SlEfPositionCorrectionInfomation PositionCorrectionInfomation;

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
    retChk=ActionInfomation.getter(scene_num,&changeInfo);
    retChk=CurveInfomation.getter(scene_num,&curveData);
    retChk=PidInfomation.getter(scene_num,&pidData);
    retChk=PositionCorrectionInfomation.getter(scene_num,&positioncorrectionData);

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
            check_value=positionCorrection.colorFixSetter(
                positioncorrectionData);
        break;

        //座標値による補正の場合
        case JUDGE_POS:
        //補正クラスのインスタンス取得
            PositionCorrection &positionCorrection=
            PositionCorrection::getinstance();
        //補正クラスに目標値と補正値をセット後タスク起動
            check_value=positionCorrection.lineFixSetter(
                positioncorrectionData);
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
            check_value=positionCorrection.directionFixSetter(
                positioncorrectionData);
        break;
        //一応
        default:
        break;
    }
#endif
Action *action;
    //動作の選択
    switch(changeInfo.section_act){
        //ライントレース
        case LINE_TRACE:
        //コンストラクタ引数：
        //構造体ChangeInfo内のspeedと構造体PIDData
            action=new LineTrace;
        break;

        //直進
        //コンストラクタ引数：構造体ChangeInfo内のspeed
        case STRAIGHT:
            action=new Straight;
        break;

        //カーブ
        //コンストラクタ引数：
        //構造体ChangeInfo内のspeedとCurveData構造体
        case CURVE:
            action=new Curve;
        break;

        //ラインカーブ
        //コンストラクタ引数：
        //構造体ChangeInfo内のspeedとCurveData構造体とカーブ構造体
        case LINE_CURVE:
            action=new Curve;
        break;

        //旋回
        //コンストラクタ引数：
        //構造体ChangeInfo内のspeedとDirectionData構造体
        case TURN:
            action=new Turn;
        break;

        //アーム動作
        //構造体ChangeInfo内のspeed
        case ARM_ACTION:
            action=new ArmAction;
        break;

        //一応
        default:
        break;
    }
    retChk=action->run(changeInfo.speed,pidData,changeInfo.direction_data.direction,curveData);
    //動的メモリの開放
    delete action;
    return retChk;
}

//
//更新タスクでの処理
//
int8 SlalomEifie::sceneChenge(int16* scene_num){
    //引数のエラーチェック
    if(scene_num==NULL){
        return SYS_PARAM;
    }
    if(SLALOMEIFIE_NUM==0){
        *scene_num=-1;
        return SYS_OK;
    }
    int8 retChk=SYS_NG;
    RGBData currgbData; 
    uint16 curdistanceData=0;
    // 情報クラスのインスタンス化
    ChangeInfo changeInfo;
    PositionData curpositionData;
    DirectionData curdirectionData;
    //シングルトンのセンサ管理からインスタンスのポインタを取得
    SensorManager &senserManage=SensorManager::getInstance();
    //シングルトンの自己位置推定からインスタンスのポインタを取得
    CarPosition &carPosition=CarPosition::getInstance();
    //構造体の初期化
    memset(&changeInfo,0,sizeof(ChangeInfo));

    //スラロームエーフィの切り替え情報クラスをインスタンス化
    SlEfActionInfomation ActionInfomation;
    //切り替え情報から情報取得
    retChk=ActionInfomation.getter(*scene_num,&changeInfo);

    //切り替え判定情報から処理選択
    switch(changeInfo.judge){
        //シーン切り替え判定がrgb値の場合
        case JUDGE_RGB:
            memset(&currgbData,0,sizeof(RGBData));
        //rgbの現在時点最新状態を取得
            senserManage.rgbGetter(&currgbData);
        //rgb値を目標値と現在値を比較
            retChk=colorJudge(currgbData,changeInfo.rgb_data,changeInfo.rgb_data.condition);
            if(retChk==SYS_OK){
                *scene_num+=1;
            }
        break;
        //シーン切り替え判定が座標場合
        case JUDGE_POS:
            memset(&curpositionData,0,sizeof(PositionData));
        //座標の現在時点最新状態を取得
            carPosition.getPos(&curpositionData);
         //XYを判断する場合
            if(changeInfo.pos_info_data.xCondition<2&&changeInfo.pos_info_data.yCondition<2){
                retChk=xPositionJudge(curpositionData.xPosition,
                                      changeInfo.pos_info_data.potision.xPosition,
                                      changeInfo.pos_info_data.xCondition);
                if(retChk!=SYS_OK){
                    break;
                }
                retChk=yPositionJudge(curpositionData.yPosition,
                                      changeInfo.pos_info_data.potision.yPosition,
                                      changeInfo.pos_info_data.yCondition);
                if(retChk==SYS_OK){
                    *scene_num+=1;
                }
                break;
            }
        
        //Xだけを判断する場合
            if(changeInfo.pos_info_data.xCondition<2){
                retChk=xPositionJudge(curpositionData.xPosition,
                                      changeInfo.pos_info_data.potision.xPosition,
                                      changeInfo.pos_info_data.xCondition);
                if(retChk==SYS_OK){
                    *scene_num+=1;
                }
                break;
            }

        //Yだけを判断する場合
            if(changeInfo.pos_info_data.yCondition<2){
                retChk=yPositionJudge(curpositionData.yPosition,
                                      changeInfo.pos_info_data.potision.yPosition,
                                      changeInfo.pos_info_data.yCondition);
                if(retChk==SYS_OK){
                    *scene_num+=1;
                }
            }
        break;

        //シーン切り替え判定が距離の場合
        case JUDGE_DIS:

        //超音波での距離の現在時点最新情報を取得
            senserManage.distanceGetter(&curdistanceData);
            retChk=distanceJudge(curdistanceData,changeInfo.distance);
            if(retChk==SYS_OK){
                *scene_num+=1;
            }
        break;

        //シーン切り替え判定が向きの場合
        case JUDGE_DIR:
            memset(&curdirectionData,0,sizeof(DirectionData));
            carPosition.getDir(&curdirectionData.direction);
            retChk=directionJudge(curdirectionData.direction,
                                  changeInfo.direction_data.direction,
                                  changeInfo.direction_data.condition);
            if(retChk==SYS_OK){
                *scene_num+=1;
            }
        break;
    }

    //スラロームエーフィのシーンの終了かの確認
    //仮でSlalomEifieENDを定義
    //-1を定義に作る
    if(*scene_num>SLALOMEIFIE_NUM-1){
        *scene_num=-1;
    }
    return retChk;
}

//
//コードがネストで逝ってしまいそうなので臨時で作成（検討する必要がある）
//

//rgbの判定
//引数：現在のrgb値、目標のrgb値、(現在と目標の差分範囲の指定値)
//戻り値：切り替え条件を満たしていればSYS_OK
//        切り替え条件を満たしていなければSYS_NG
int8 SlalomEifie::colorJudge(RGBData cur_rgbdata,RGBData change_rgbdata,Range condition){
    int8 resultr=0;
    int8 resultg=0;
    int8 resultb=0;
    //目標のrgb-現在のrgbの差分を計算
    resultr=cur_rgbdata.r-change_rgbdata.r;
    resultg=cur_rgbdata.g-change_rgbdata.g;
    resultb=cur_rgbdata.b-change_rgbdata.b;
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

    if(resultr==0&&resultg==0&&resultb==0){
        return SYS_OK;
    }

    return SYS_NG;
}

//X座標の判定
//引数：現在のX座標値、目標のX座標値、現在と目標の差分範囲の指定値
//戻り値：切り替え条件を満たしていればSYS_OK
//        切り替え条件を満たしていなければSYS_NG
int8 SlalomEifie::xPositionJudge(float cur_xpositionData,float change_xpositionData,Range condition){
    float resultx=0;
    resultx=cur_xpositionData-change_xpositionData;
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
int8 SlalomEifie::yPositionJudge(float cur_ypositionData,float change_ypositionData,Range condition){
    float resulty=0;
    resulty=cur_ypositionData-change_ypositionData;
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
int8 SlalomEifie::distanceJudge(uint16 cur_distanceData,uint16 change_distanceData){
    int16 resultdistance=0;
    resultdistance=cur_distanceData-change_distanceData;
    if(resultdistance<0){
        return SYS_OK;        
    }
    /*距離を範囲指定する場合に使用（間違って作った）
    if(resultdistance>0){
        if(condition==HIGH){
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
int8 SlalomEifie::directionJudge(float cur_directionData,float change_directionData,Range condition){
    float resultdirection=0;
    resultdirection=cur_directionData-change_directionData;
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