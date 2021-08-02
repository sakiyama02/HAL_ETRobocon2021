#include "../../include/PositionCorrection/PositionCorrection.h"
PositionCorrection::PositionCorrection(){
    prePositionCorrectionData.correctionCondition=JUDGE_NONE;
}
PositionCorrection::~PositionCorrection(){}

//メインタスクで呼び出す補正の振り分け及び値の受け渡し
int8 PositionCorrection::fixSetter(PositionCorrectionData positionCorrection_Data){
    #ifdef CORRECTIONDATA_ON
    frLog &msg = frLog::GetInstance();

    //現在のタスクの状態
    //状態：実行中      STATE_ACT
    //    ：実行済み　　STATE_ACTAFTER
    //    : 未送信     STATE_NOTSEND
    //    : 送信待ち   STATE_NOWSEND

    //未送信の場合送信タスクを起動してタスク状態を送信待ちにする
    if(taskState==STATE_NOTSEND){
        controltask=JUDGE_SEND;
        movetask=HIGH;
        taskState=STATE_NOWSEND;
        msg.LOG(LOG_ID_ERR,"数値送信が行われていないのでタスク起動して終了");
        return SYS_OK;
    }

    //送信待ち状態なので新たに処理を行わなようにする
    if(taskState==STATE_NOWSEND){
        msg.LOG(LOG_ID_ERR,"数値送信中なので終了");
        return SYS_OK;
    }

    //補正数値から前回の数値と比較して変化があるかでどうかで
    //シーンが変化したかを判断する
    sceneState=memcmp(&prePositionCorrectionData 
                    ,&positionCorrection_Data
                    ,sizeof(PositionCorrectionData));
    
    //シーンに変化がない場合戻り値で終了した事を知らせる
    if(sceneState==0){
        //msg.LOG(LOG_ID_ERR,"シーン変化なしで終了");
        return SYS_NG;
    }

    //シーンの変化があるので現在稼働しているタスクを
    //次のタスクを稼働させるために停止
    
    if(taskState==STATE_ACT){
        //msg.LOG(LOG_ID_ERR,"シーン変化してタスクがONのため現在起動中のタスク終了");
        switch(prePositionCorrectionData.correctionCondition){
            case JUDGE_RGB:
            controltask=JUDGE_RGB;
            movetask=LOW;
            break;
            case JUDGE_POS:
            controltask=JUDGE_POS;
            movetask=LOW;
            break;
            case JUDGE_DIR:
            controltask=JUDGE_DIR;
            movetask=LOW;
            break;
            case JUDGE_V:
            controltask=JUDGE_V;
            movetask=LOW;
            break;
            case JUDGE_S:
            controltask=JUDGE_S;
            movetask=LOW;
            break;
            case JUDGE_DIS:
            controltask=JUDGE_DIS;
            movetask=LOW;
            default:
            break;
        }
        taskState=STATE_ACTAFTER;
        return SYS_OK;
    } 

    //メンバ構造体に引数で取得した最新状態の構造体をセット
    memcpy(&prePositionCorrectionData,&positionCorrection_Data
            ,sizeof(PositionCorrectionData));
    //補正を起動する
    switch(prePositionCorrectionData.correctionCondition){
        case JUDGE_RGB:
            msg.LOG(LOG_ID_ERR,"色補正開始");
            controltask=JUDGE_RGB;
            movetask=HIGH;
        break;
        case JUDGE_POS:
            msg.LOG(LOG_ID_ERR,"座標補正開始");
            controltask=JUDGE_POS;
            movetask=HIGH;
        break;
        case JUDGE_DIR:
            msg.LOG(LOG_ID_ERR,"向き補正開始");
            controltask=JUDGE_DIR;
            movetask=HIGH;
        break;
        case JUDGE_V:
            msg.LOG(LOG_ID_ERR,"v補正開始");
            controltask=JUDGE_V;
            movetask=HIGH;
        break;
        case JUDGE_S:
            msg.LOG(LOG_ID_ERR,"s補正開始");
            controltask=JUDGE_S;
            movetask=HIGH;
        break;
        case JUDGE_DIS:
            msg.LOG(LOG_ID_ERR,"距離補正開始");
            controltask=JUDGE_DIS;
            movetask=HIGH;
        break;
        default:
        break;
    }
    return SYS_OK;
    #endif
}

//周期タスクで呼び出す色補正
int8 PositionCorrection::colorFix(){
    #ifdef CORRECTIONDATA_ON
    frLog &msg = frLog::GetInstance();
    int8 retChk = SYS_NG;
    //タスク状態を実行中にする
    taskState=STATE_ACT;

    //センサ管理をインスタンスポインタを取得
    SensorManager &sensorManager=SensorManager::getInstance();
    //自己位置推定をインスタンスポインタを取得
    CarPosition &carPosition=CarPosition::getInstance();

    //センサ管理から取得したrgb値を保持する構造体
    RGBData curRGBData;
    memset(&curRGBData,0,sizeof(RGBData));

    //センサ管理からrgb値を取得
    retChk=sensorManager.rgbGetter(&curRGBData);
    //引数のエラーチェック
    if(retChk==SYS_NG){
        return SYS_PARAM;
    }
   //msg.LOG(LOG_ID_ERR,"R:%d,G:%d,B:%d",curRGBData.r,curRGBData.g,curRGBData.b);

    //rgbの目標値と現在値を比較
    retChk=colorJudge(curRGBData
                ,prePositionCorrectionData.correctionRGB
                ,prePositionCorrectionData.correctionRGB.condition);
    if(retChk!=SYS_OK){
        //条件を満たしていない場合処理を行わずに終了
        //更新なしで送信
        msg.LOG(LOG_ID_ERR,"カラーが目標に達しなかったため終了");
        return SYS_OK;
    }

    //自己位置推定に値をセットするタイミングを確認する必要がある
    //calcstateが1の場合自己位置推定内で計算中になる為数値をセット
    //せずに次の補正が呼び出されるタイミングで送信タスクを呼び出す
    //ためにタスク状態を未送信に設定
    if(carPosition.calcstate==1){
        msg.LOG(LOG_ID_ERR,"自己位置推定が計算中のため終了");
        taskState=STATE_NOTSEND;
        ext_tsk();
        return SYS_OK;
    }

    retChk=posSetter(prePositionCorrectionData.correctionValue);
    if(retChk!=SYS_OK){
        //エラーチェック
        return SYS_NG;
    }

    retChk=dirSetter(prePositionCorrectionData.correctionValueDirection);
    if(retChk!=SYS_OK){
        //エラーチェック
        return SYS_NG;
    }

    //タスク状態を実行終了
    taskState=STATE_ACTAFTER;
    controltask=JUDGE_RGB;
    movetask=LOW;
    ext_tsk();
    //自身でタスクをスリーブする
    return SYS_OK;

    #endif
}

//周期タスクで呼び出す座標補正
int8 PositionCorrection::lineFix(){
    #ifdef CORRECTIONDATA_ON
    frLog &msg = frLog::GetInstance();
    int8 retChk = SYS_NG;
    taskState=STATE_ACT;
    //自己位置推定をインスタンスポインタを取得
    CarPosition &carPosition=CarPosition::getInstance();
    PositionData curPositionData;
    memset(&curPositionData,0,sizeof(PositionData));
    //現在の座標を自己位置推定から取得
    retChk=carPosition.getPos(&curPositionData);
    //引数のエラーチェック
    if(retChk==SYS_NG){
        return retChk;
    }
    switch(1){
        default:
        //XYを判断する場合
        if(prePositionCorrectionData.correctionPosition.xCondition<2&&
            prePositionCorrectionData.correctionPosition.yCondition<2){
            retChk=xPositionJudge(curPositionData.xPosition,
                                prePositionCorrectionData.correctionPosition.potision.xPosition,
                                prePositionCorrectionData.correctionPosition.xCondition);
            if(retChk!=SYS_OK){
                break;
            }
            retChk=yPositionJudge(curPositionData.yPosition,
                                prePositionCorrectionData.correctionPosition.potision.yPosition,
                                prePositionCorrectionData.correctionPosition.yCondition);
            break;
        }
        //Xだけを判断する場合
        if(prePositionCorrectionData.correctionPosition.xCondition<2){
            retChk=xPositionJudge(curPositionData.xPosition,
                                prePositionCorrectionData.correctionPosition.potision.xPosition,
                                prePositionCorrectionData.correctionPosition.xCondition);
            break;
        }
        //Yだけを判断する場合
        if(prePositionCorrectionData.correctionPosition.yCondition<2){
            retChk=yPositionJudge(curPositionData.yPosition,
                                prePositionCorrectionData.correctionPosition.potision.yPosition,
                                prePositionCorrectionData.correctionPosition.yCondition);
        }
        break;
    }

    if(retChk!=SYS_OK){
        //条件を満たしていない場合処理を行わずに終了
        //更新なしで送信
        //msg.LOG(LOG_ID_ERR,"座標が目標に達しなかったため終了");
        return SYS_NG;
    }

    //自己位置推定に値をセットするタイミングを確認する必要がある
    //calcstateが1の場合自己位置推定内で計算中になる為数値をセット
    //せずに次の補正が呼び出されるタイミングで送信タスクを呼び出す
    //ためにタスク状態を未送信に設定
    if(carPosition.calcstate==1){
        msg.LOG(LOG_ID_ERR,"自己位置推定が計算中のため終了");
        taskState=STATE_NOTSEND;
        ext_tsk();
        return SYS_OK;
    }

    retChk=posSetter(prePositionCorrectionData.correctionValue);
    if(retChk!=SYS_OK){
        //エラーチェック
        return SYS_NG;
    }
    retChk=dirSetter(prePositionCorrectionData.correctionValueDirection);
    if(retChk!=SYS_OK){
        //エラーチェック
        return SYS_NG;
    }

    //タスク実行終了
    taskState=STATE_ACTAFTER;
    //msg.LOG(LOG_ID_ERR,"セット終了");
    controltask=JUDGE_POS;
    movetask=LOW;
    //自身でタスクをスリーブする
    ext_tsk();
    #endif
    return SYS_OK;
}

//周期タスクで呼び出す向き補正
int8 PositionCorrection::directionFix(){
    #ifdef CORRECTIONDATA_ON
    frLog &msg = frLog::GetInstance();
    int8 retChk = SYS_NG;
    taskState=STATE_ACT;
    //自己位置推定をインスタンスポインタを取得
    CarPosition &carPosition=CarPosition::getInstance();
    DirectionData curDirectionData;
    memset(&curDirectionData,0,sizeof(DirectionData));
    //現在の向きを自己位置推定から取得
    retChk=carPosition.getDir(&curDirectionData.direction);
    //引数のエラーチェック
    if(retChk==SYS_NG){
        return SYS_NG;
    }
    //向きの目標値と現在値を比較
    retChk=directionJudge(curDirectionData.direction
                ,prePositionCorrectionData.correctionDirection.direction
                ,prePositionCorrectionData.correctionDirection.condition);
    if(retChk!=SYS_OK){
        //条件を満たしていない場合処理を行わずに終了
        //更新なしで送信
        //msg.LOG(LOG_ID_ERR,"向きが目標に達しなかったため終了");
        return SYS_OK;
    }

    //自己位置推定に値をセットするタイミングを確認する必要がある
    //calcstateが1の場合自己位置推定内で計算中になる為数値をセット
    //せずに次の補正が呼び出されるタイミングで送信タスクを呼び出す
    //ためにタスク状態を未送信に設定
    if(carPosition.calcstate==1){
        msg.LOG(LOG_ID_ERR,"自己位置推定が計算中のため終了");

        taskState=STATE_NOTSEND;
        
        ext_tsk();
        return SYS_OK;
    }

    retChk=posSetter(prePositionCorrectionData.correctionValue);
    
    if(retChk!=SYS_OK){
        //エラーチェック
        return SYS_NG;
    }

    retChk=dirSetter(prePositionCorrectionData.correctionValueDirection);
    if(retChk!=SYS_OK){
        //エラーチェック
        return SYS_NG;
    }

    //タスク実行終了
    taskState=STATE_ACTAFTER;
    controltask=JUDGE_DIR;
    movetask=LOW;
    ext_tsk();
    //自身でタスクをスリーブする
    #endif
    return SYS_OK;
}

//周期タスクで呼び出すV値補正
int8 PositionCorrection::vFix(){
    #ifdef CORRECTIONDATA_ON
    frLog &msg = frLog::GetInstance();
    int8 retChk = SYS_NG;
    //タスク状態を実行中にする
    taskState=STATE_ACT;

    //センサ管理をインスタンスポインタを取得
    SensorManager &sensorManager=SensorManager::getInstance();
    //自己位置推定をインスタンスポインタを取得
    CarPosition &carPosition=CarPosition::getInstance();

    //センサ管理から取得したv値を保持する構造体
    VData curVData;
    memset(&curVData,0,sizeof(VData));

    //センサ管理からrgb値を取得
    retChk=sensorManager.hsvGetter(&curVData.v);
    //引数のエラーチェック
    if(retChk==SYS_NG){
        return SYS_PARAM;
    }
   //msg.LOG(LOG_ID_ERR,"R:%d,G:%d,B:%d",curRGBData.r,curRGBData.g,curRGBData.b);

    //rgbの目標値と現在値を比較
    retChk=vJudge(curVData.v
                ,prePositionCorrectionData.correctionV.v
                ,prePositionCorrectionData.correctionV.condition);
    if(retChk!=SYS_OK){
        //条件を満たしていない場合処理を行わずに終了
        //更新なしで送信
        msg.LOG(LOG_ID_ERR,"vが目標に達しなかったため終了");
        return SYS_OK;
    }

    //自己位置推定に値をセットするタイミングを確認する必要がある
    //calcstateが1の場合自己位置推定内で計算中になる為数値をセット
    //せずに次の補正が呼び出されるタイミングで送信タスクを呼び出す
    //ためにタスク状態を未送信に設定
    if(carPosition.calcstate==1){
        msg.LOG(LOG_ID_ERR,"自己位置推定が計算中のため終了");
        taskState=STATE_NOTSEND;
        ext_tsk();
        return SYS_OK;
    }

    retChk=posSetter(prePositionCorrectionData.correctionValue);
    if(retChk!=SYS_OK){
        //エラーチェック
        return SYS_NG;
    }

    retChk=dirSetter(prePositionCorrectionData.correctionValueDirection);
    if(retChk!=SYS_OK){
        //エラーチェック
        return SYS_NG;
    }

    //タスク状態を実行終了
    taskState=STATE_ACTAFTER;
    controltask=JUDGE_V;
    movetask=LOW;
    ext_tsk();
    //自身でタスクをスリーブする
    return SYS_OK;

    #endif
}

//周期タスクで呼び出すs値補正
int8 PositionCorrection::sFix(){
    #ifdef CORRECTIONDATA_ON
    frLog &msg = frLog::GetInstance();
    int8 retChk = SYS_NG;
    //タスク状態を実行中にする
    taskState=STATE_ACT;

    //センサ管理をインスタンスポインタを取得
    SensorManager &sensorManager=SensorManager::getInstance();
    //自己位置推定をインスタンスポインタを取得
    CarPosition &carPosition=CarPosition::getInstance();

    //センサ管理から取得したv値を保持する構造体
    SData curSData;
    memset(&curSData,0,sizeof(VData));

    //センサ管理からrgb値を取得
    retChk=sensorManager.saturationGetter(&curSData.s);
    //引数のエラーチェック
    if(retChk==SYS_NG){
        return SYS_PARAM;
    }
   //msg.LOG(LOG_ID_ERR,"R:%d,G:%d,B:%d",curRGBData.r,curRGBData.g,curRGBData.b);

    //rgbの目標値と現在値を比較
    retChk=sJudge(curSData.s
                ,prePositionCorrectionData.correctionS.s
                ,prePositionCorrectionData.correctionS.condition);
    if(retChk!=SYS_OK){
        //条件を満たしていない場合処理を行わずに終了
        //更新なしで送信
        msg.LOG(LOG_ID_ERR,"sが目標に達しなかったため終了");
        return SYS_OK;
    }

    //自己位置推定に値をセットするタイミングを確認する必要がある
    //calcstateが1の場合自己位置推定内で計算中になる為数値をセット
    //せずに次の補正が呼び出されるタイミングで送信タスクを呼び出す
    //ためにタスク状態を未送信に設定
    if(carPosition.calcstate==1){
        msg.LOG(LOG_ID_ERR,"自己位置推定が計算中のため終了");
        taskState=STATE_NOTSEND;
        ext_tsk();
        return SYS_OK;
    }

    retChk=posSetter(prePositionCorrectionData.correctionValue);
    if(retChk!=SYS_OK){
        //エラーチェック
        return SYS_NG;
    }

    retChk=dirSetter(prePositionCorrectionData.correctionValueDirection);
    if(retChk!=SYS_OK){
        //エラーチェック
        return SYS_NG;
    }

    //タスク状態を実行終了
    taskState=STATE_ACTAFTER;
    controltask=JUDGE_S;
    movetask=LOW;
    ext_tsk();
    //自身でタスクをスリーブする
    return SYS_OK;

    #endif
}


//周期タスクで呼び出す色補正
int8 PositionCorrection::distanceFix(){
    #ifdef CORRECTIONDATA_ON
    frLog &msg = frLog::GetInstance();
    int8 retChk = SYS_NG;
    //タスク状態を実行中にする
    taskState=STATE_ACT;

    //センサ管理をインスタンスポインタを取得
    SensorManager &sensorManager=SensorManager::getInstance();
    //自己位置推定をインスタンスポインタを取得
    CarPosition &carPosition=CarPosition::getInstance();

    //センサ管理から取得したrgb値を保持する構造体
    uint16 curdistance;
    memset(&curdistance,0,sizeof(uint8));

    //センサ管理からrgb値を取得
    retChk=sensorManager.distanceGetter(&curdistance);
    //引数のエラーチェック
    if(retChk==SYS_NG){
        return SYS_PARAM;
    }
   //msg.LOG(LOG_ID_ERR,"R:%d,G:%d,B:%d",curRGBData.r,curRGBData.g,curRGBData.b);

    //rgbの目標値と現在値を比較
    retChk=distanceJudge(curdistance
                ,prePositionCorrectionData.distance);
    if(retChk!=SYS_OK){
        //条件を満たしていない場合処理を行わずに終了
        //更新なしで送信
        msg.LOG(LOG_ID_ERR,"距離が目標に達しなかったため終了");
        return SYS_OK;
    }

    //自己位置推定に値をセットするタイミングを確認する必要がある
    //calcstateが1の場合自己位置推定内で計算中になる為数値をセット
    //せずに次の補正が呼び出されるタイミングで送信タスクを呼び出す
    //ためにタスク状態を未送信に設定
    if(carPosition.calcstate==1){
        msg.LOG(LOG_ID_ERR,"自己位置推定が計算中のため終了");
        taskState=STATE_NOTSEND;
        ext_tsk();
        return SYS_OK;
    }

    retChk=posSetter(prePositionCorrectionData.correctionValue);
    if(retChk!=SYS_OK){
        //エラーチェック
        return SYS_NG;
    }

    retChk=dirSetter(prePositionCorrectionData.correctionValueDirection);
    if(retChk!=SYS_OK){
        //エラーチェック
        return SYS_NG;
    }

    //タスク状態を実行終了
    taskState=STATE_ACTAFTER;
    controltask=JUDGE_DIS;
    movetask=LOW;
    ext_tsk();
    //自身でタスクをスリーブする
    return SYS_OK;

    #endif
}


//自己位置推定の計算中に値を変更されないように
//変更中に値を変えようとした場合のみ使用する
//基本的に値を自己位置推定に渡すだけのメソッド
int8 PositionCorrection::send_position(){
    #ifdef CORRECTIONDATA_ON
    //frLog &msg = frLog::GetInstance();
    int8 retChk=SYS_NG;
    //自己位置推定をインスタンスポインタを取得
    CarPosition &carPosition=CarPosition::getInstance();
    //自己位置推定に値をセットするタイミングを確認する必要がある
    //calcstateが1の場合自己位置推定内で計算中になる為数値をセット
    //せずに次の補正が呼び出されるタイミングで送信タスクを呼び出す
    //ためにタスク状態を未送信に設定
    if(carPosition.calcstate==1){
        taskState=STATE_NOTSEND;
        ext_tsk();
        return SYS_OK;
    }
    
    retChk=posSetter(prePositionCorrectionData.correctionValue);
    
    if(retChk!=SYS_OK){
        //エラーチェック
        return SYS_NG;
    }

    retChk=dirSetter(prePositionCorrectionData.correctionValueDirection);
    if(retChk!=SYS_OK){
        //エラーチェック
        return SYS_NG;
    }

    //タスク実行終了
    taskState=STATE_ACTAFTER;
    controltask=JUDGE_SEND;
    movetask=LOW;
    ext_tsk();
    #endif
    return SYS_OK;
}


//
//appで使用するタスク状態変更getter
//
int8 PositionCorrection::controltaskgetter(JudgeType *control_task){
    #ifdef CORRECTIONDATA_ON
    *control_task=controltask;
    #endif
    return SYS_OK;
}

int8 PositionCorrection::movetaskgetter(Range *move_task){
    #ifdef CORRECTIONDATA_ON
    *move_task=movetask;
    #endif
    return SYS_OK;
}

//
//appで使用するタスク状態変更setter
//
int8 PositionCorrection::controltasksetter(JudgeType control_task){
    #ifdef CORRECTIONDATA_ON
    controltask=control_task;
    #endif
    return SYS_OK;
}

int8 PositionCorrection::movetasksetter(Range move_task){
    #ifdef CORRECTIONDATA_ON
    movetask=move_task;
    #endif
    return SYS_OK;
}


//
//ここから下は切り替え処理と同一
//

//rgbの判定
//引数：現在のrgb値、目標のrgb値、(現在と目標の差分範囲の指定値)
//戻り値：切り替え条件を満たしていればSYS_OK
//        切り替え条件を満たしていなければSYS_NG
int8 PositionCorrection::colorJudge(RGBData cur_rgbdata,RGBData change_rgbdata,Range condition){

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
int8 PositionCorrection::xPositionJudge(float cur_xpositionData,float change_xpositionData,Range condition){
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
int8 PositionCorrection::yPositionJudge(float cur_ypositionData,float change_ypositionData,Range condition){
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

//向きの判定
//引数：現在の向き値、目標の向き値、現在と目標の差分範囲の指定値 
//マイナスの値を入れるとバグるので注意
//戻り値：切り替え条件を満たしていればSYS_OK
//        切り替え条件を満たしていなければSYS_NG
int8 PositionCorrection::directionJudge(float cur_directionData,float change_directionData,Range condition){
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

//距離の判定
//引数：現在の距離値、目標の距離値
//戻り値：切り替え条件を満たしていればSYS_OK
//        切り替え条件を満たしていなければSYS_NG
int8 PositionCorrection::distanceJudge(uint16 cur_distanceData,uint16 change_distanceData){
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

//v値の判定
int8 PositionCorrection::vJudge(uint16 cur_vData,uint16 change_vData,Range condition){
    int16 resultv=0;
    resultv=cur_vData-change_vData;
    if(resultv>0){
        if(condition==HIGH){
            return SYS_OK;
        }
        return SYS_NG;
    }
    if(resultv<0){
        if(condition==LOW){
            return SYS_OK;
        }
        return SYS_NG;        
    }
    if(resultv==0){
        if(condition==NONE){
            return SYS_OK;
        }
        return SYS_NG;        
    }
    return SYS_NG;
}

//s値の判定
int8 PositionCorrection::sJudge(uint16 cur_sData,uint16 change_sData,Range condition){
    int16 results=0;
    results=cur_sData-change_sData;
    if(results>0){
        if(condition==HIGH){
            return SYS_OK;
        }
        return SYS_NG;
    }
    if(results<0){
        if(condition==LOW){
            return SYS_OK;
        }
        return SYS_NG;        
    }
    if(results==0){
        if(condition==NONE){
            return SYS_OK;
        }
        return SYS_NG;        
    }
    return SYS_NG;
}

//座標を自己位置推定にセット
int8 PositionCorrection::posSetter(PosInfoData target_pos){
     //自己位置推定をインスタンスポインタを取得
    CarPosition &carPosition=CarPosition::getInstance();
    int8 retChk = SYS_OK;
    switch(1){
        default:
        //XYを判断する場合
        if(target_pos.xCondition<2&&target_pos.yCondition<2){
            retChk=carPosition.xsetPos(target_pos.potision.xPosition);
            if(retChk!=SYS_OK){
                break;
            }
            retChk=carPosition.ysetPos(target_pos.potision.yPosition);
            break;
        }
        //Xだけを判断する場合
        if(target_pos.xCondition<2){
            retChk=carPosition.xsetPos(target_pos.potision.xPosition);
            if(retChk!=SYS_OK){
                break;
            }
            break;
        }
        //Yだけを判断する場合
        if(target_pos.yCondition<2){
            retChk=carPosition.ysetPos(target_pos.potision.yPosition);
            if(retChk!=SYS_OK){
                break;
            }
        }
        break;
    }
    if(retChk!=SYS_OK){
        //エラーチェック
        return SYS_NG;
    }
    return SYS_OK;
}

//座標を自己位置推定にセット
int8 PositionCorrection::dirSetter(DirectionData target_dir){
     //自己位置推定をインスタンスポインタを取得
    CarPosition &carPosition=CarPosition::getInstance();
    int8 retChk = SYS_OK;
    if(target_dir.condition<2){
         retChk=carPosition.setDir(target_dir.direction);
    }
    if(retChk!=SYS_OK){
        //エラーチェック
        return SYS_NG;
    }
    return SYS_OK;
}