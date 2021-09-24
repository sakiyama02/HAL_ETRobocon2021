#include "../../include/PositionCorrection/PositionCorrection.h"
PositionCorrection::PositionCorrection(){
    prePositionCorrectionData.correctionCondition=JUDGE_NONE;
}
PositionCorrection::~PositionCorrection(){}
/* -------------------------------------------------------------------------- */
/* 関数名       ：fixSetter                                                   */
/* 機能名       ：補正実行                                                     */
/* 機能概要     ：シーン制御から受け取った補正値を使って、補正タスク動作を行う     */
/*                現在のタスクの状態                                           */
/*                状態：実行中      STATE_ACT                                  */
/*                実行済み　　STATE_ACTAFTER                                   */
/*                未送信     STATE_NOTSEND                                    */
/*                送信待ち   STATE_NOWSEND                                    */
/* 引数         ：PositionCorrectionData、positionCorrection_Data、補正情報    */
/* 戻り値       ：int8、エラー通知                                             */
/* 作成日       ：7月23日、渡部湧也                                            */
/* -------------------------------------------------------------------------- */
int8 PositionCorrection::fixSetter(PositionCorrectionData positionCorrection_Data){
    #ifdef CORRECTIONDATA_ON
    frLog &msg = frLog::GetInstance();

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
            //app側でタスクを停止してもらうために動作タスクと、停止フラグを格納
            controltask=JUDGE_RGB;
            movetask=LOW;
            break;
            case JUDGE_POS:
            //app側でタスクを停止してもらうために動作タスクと、停止フラグを格納
            controltask=JUDGE_POS;
            movetask=LOW;
            break;
            case JUDGE_DIR:
            //app側でタスクを停止してもらうために動作タスクと、停止フラグを格納   
            controltask=JUDGE_DIR;
            movetask=LOW;
            break;
            case JUDGE_V:
            //app側でタスクを停止してもらうために動作タスクと、停止フラグを格納
            controltask=JUDGE_V;
            movetask=LOW;
            break;
            case JUDGE_S:
            //app側でタスクを停止してもらうために動作タスクと、停止フラグを格納            
            controltask=JUDGE_S;
            movetask=LOW;
            break;
            case JUDGE_DIS:
            //app側でタスクを停止してもらうために動作タスクと、停止フラグを格納
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
            //app側でタスクを起動してもらうために動作タスクと、起動フラグを格納
            controltask=JUDGE_RGB;
            movetask=HIGH;
        break;
        case JUDGE_POS:
            msg.LOG(LOG_ID_ERR,"座標補正開始");
            //app側でタスクを起動してもらうために動作タスクと、起動フラグを格納
            controltask=JUDGE_POS;
            movetask=HIGH;
        break;
        case JUDGE_DIR:
            msg.LOG(LOG_ID_ERR,"向き補正開始");
            //app側でタスクを起動してもらうために動作タスクと、起動フラグを格納
            controltask=JUDGE_DIR;
            movetask=HIGH;
        break;
        case JUDGE_V:
            msg.LOG(LOG_ID_ERR,"v補正開始");
            //app側でタスクを起動してもらうために動作タスクと、起動フラグを格納
            controltask=JUDGE_V;
            movetask=HIGH;
        break;
        case JUDGE_S:
            msg.LOG(LOG_ID_ERR,"s補正開始");
            //app側でタスクを起動してもらうために動作タスクと、起動フラグを格納
            controltask=JUDGE_S;
            movetask=HIGH;
        break;
        case JUDGE_DIS:
            msg.LOG(LOG_ID_ERR,"距離補正開始");
            //app側でタスクを起動してもらうために動作タスクと、起動フラグを格納
            controltask=JUDGE_DIS;
            movetask=HIGH;
        break;
        default:
        break;
    }
    return SYS_OK;
    #endif
}

/* -------------------------------------------------------------------------- */
/* 関数名       ：colorFix                                                     */
/* 機能名       ：色補正                                                       */
/* 機能概要     ：補正値を使って補正値を自己位置推定に更新を行う                  */
/*                周期タスクで動作させるメソッドのため周期タスクを使用できる場所  */
/*                で動作させる                                                */
/* 引数         ：void                                                        */
/* 戻り値       ：int8、エラー通知                                             */
/* 作成日       ：7月23日、渡部湧也                                            */
/* -------------------------------------------------------------------------- */
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
    //座標情報を更新
    retChk=posSetter(prePositionCorrectionData.correctionValue);
    if(retChk!=SYS_OK){
        //エラーチェック
        return SYS_NG;
    }
    //向き情報を更新
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

/* -------------------------------------------------------------------------- */
/* 関数名       ：lineFix                                                     */
/* 機能名       ：座標補正                                                     */
/* 機能概要     ：補正値を使って補正値を自己位置推定に更新を行う                  */
/*                周期タスクで動作させるメソッドのため周期タスクを使用できる場所  */
/*                で動作させる                                                */
/* 引数         ：void                                                        */
/* 戻り値       ：int8、エラー通知                                             */
/* 作成日       ：7月23日、渡部湧也                                            */
/* -------------------------------------------------------------------------- */
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
            //戻り値がSYS_OK以外の場合yを確認せずに終了
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
    
    //自己位置推定に座標更新
    retChk=posSetter(prePositionCorrectionData.correctionValue);
    if(retChk!=SYS_OK){
        //エラーチェック
        return SYS_NG;
    }
    //自己位置推定に角度更新
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

/* -------------------------------------------------------------------------- */
/* 関数名       ：directionFix                                                 */
/* 機能名       ：向き補正                                                     */
/* 機能概要     ：補正値を使って補正値を自己位置推定に更新を行う                  */
/*                周期タスクで動作させるメソッドのため周期タスクを使用できる場所  */
/*                で動作させる                                                */
/* 引数         ：void                                                        */
/* 戻り値       ：int8、エラー通知                                             */
/* 作成日       ：7月23日、渡部湧也                                            */
/* -------------------------------------------------------------------------- */
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
        //タスク状態
        taskState=STATE_NOTSEND;
        
        ext_tsk();
        return SYS_OK;
    }
    //自己位置推定に座標更新
    retChk=posSetter(prePositionCorrectionData.correctionValue);
    
    if(retChk!=SYS_OK){
        //エラーチェック
        return SYS_NG;
    }
    //自己位置推定に角度更新
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

/* -------------------------------------------------------------------------- */
/* 関数名       ：vFix                                                         */
/* 機能名       ：V補正                                                        */
/* 機能概要     ：補正値を使って補正値を自己位置推定に更新を行う                   */
/*                周期タスクで動作させるメソッドのため周期タスクを使用できる場所  */
/*                で動作させる                                                */
/* 引数         ：void                                                         */
/* 戻り値       ：int8、エラー通知                                              */
/* 作成日       ：7月23日、渡部湧也                                             */
/* -------------------------------------------------------------------------- */
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
    //自己位置推定に座標更新
    retChk=posSetter(prePositionCorrectionData.correctionValue);
    if(retChk!=SYS_OK){
        //エラーチェック
        return SYS_NG;
    }
    //自己位置推定に角度更新
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

/* -------------------------------------------------------------------------- */
/* 関数名       ：sFix                                                         */
/* 機能名       ：S補正                                                        */
/* 機能概要     ：補正値を使って補正値を自己位置推定に更新を行う                   */
/*                周期タスクで動作させるメソッドのため周期タスクを使用できる場所  */
/*                で動作させる                                                */
/* 引数         ：void                                                         */
/* 戻り値       ：int8、エラー通知                                              */
/* 作成日       ：7月23日、渡部湧也                                             */
/* -------------------------------------------------------------------------- */
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
    //自己位置推定に座標更新
    retChk=posSetter(prePositionCorrectionData.correctionValue);
    if(retChk!=SYS_OK){
        //エラーチェック
        return SYS_NG;
    }
    //自己位置推定に角度更新
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

/* -------------------------------------------------------------------------- */
/* 関数名       ：distanceFix                                                  */
/* 機能名       ：距離補正                                                      */
/* 機能概要     ：補正値を使って補正値を自己位置推定に更新を行う                   */
/*               周期タスクで動作させるメソッドのため周期タスクを使用できる場所     */
/*               で動作させる                                                  */
/* 引数         ：void                                                         */
/* 戻り値       ：int8、エラー通知                                              */
/* 作成日       ：7月23日、渡部湧也                                             */
/* -------------------------------------------------------------------------- */
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
    //自己位置推定に座標更新
    retChk=posSetter(prePositionCorrectionData.correctionValue);
    if(retChk!=SYS_OK){
        //エラーチェック
        return SYS_NG;
    }
    //自己位置推定に角度更新
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

/* -------------------------------------------------------------------------- */
/* 関数名       ：send_position                                                */
/* 機能名       ：臨時自己位置推定更新                                          */
/* 機能概要     ：自己位置推定の計算中に値を変更されないように                    */
/*               変更中に値を変えようとした場合のみ使用する                      */
/*               基本的に値を自己位置推定に渡すだけのメソッド                    */
/*               周期タスクで動作させるメソッドのため周期タスクを使用できる場所   */
/*               で動作させる                                                  */
/* 引数         ：void                                                         */
/* 戻り値       ：int8、エラー通知                                              */
/* 作成日       ：7月23日、渡部湧也                                             */
/* -------------------------------------------------------------------------- */
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


/* -------------------------------------------------------------------------- */
/* 関数名       ：controltaskgetter                                           */
/* 機能名       ：実行中タスク取得         　　　　　　　　　　                 */
/* 機能概要     ：現在実行中補正タスクを取得　　　　　　　　　　　　 　　　　　　 */
/*               現在どのタスクが動いているかはsystem.hのJudgeTypeで指定している*/
/* 引数         ：JudgeType*、取得用変数ポインタ                               */
/* 戻り値       ：int8、エラー通知                                             */
/* 作成日       ：7月23日、渡部湧也                                            */
/* -------------------------------------------------------------------------- */
int8 PositionCorrection::controltaskgetter(JudgeType *control_task){
    #ifdef CORRECTIONDATA_ON
    *control_task=controltask;
    #endif
    return SYS_OK;
}

/* -------------------------------------------------------------------------- */
/* 関数名       ：movetaskgetter                                   　         */
/* 機能名       ：タスク状態変更フラグ取得                                      */
/* 機能概要     ：タスク状態変更フラグを取得　　　      　　　　　　 　　　　　　 */
/*              　タスクの状態変更を指示するフラグであり、                      */
/*              　system.hのRangeで指定する                                   */
/*              　(HIGHで起動、LOWで停止、NONEで変更なし)                      */
/* 引数         ：Range*、取得用変数ポインタ                                   */
/* 戻り値       ：int8、エラー通知                                             */
/* 作成日       ：7月23日、渡部湧也                                            */
/* -------------------------------------------------------------------------- */
int8 PositionCorrection::movetaskgetter(Range *move_task){
    #ifdef CORRECTIONDATA_ON
    *move_task=movetask;
    #endif
    return SYS_OK;
}

/* -------------------------------------------------------------------------- */
/* 関数名       ：controltasksetter                                            */
/* 機能名       ：実行中タスク更新         　　　　　　　　　　　                 */
/* 機能概要     ：現在実行中補正タスクを更新　　　　　　　  　　 　　　 　　　　　　 */
/*               基本的に初期化状態に戻すために使う                              */
/* 引数         ：JudgeType、取得用変数                                         */
/* 戻り値       ：int8、エラー通知                                              */
/* 作成日       ：7月23日、渡部湧也                                             */
/* -------------------------------------------------------------------------- */
int8 PositionCorrection::controltasksetter(JudgeType control_task){
    #ifdef CORRECTIONDATA_ON
    controltask=control_task;
    #endif
    return SYS_OK;
}
/* -------------------------------------------------------------------------- */
/* 関数名       ：movetasksetter                                    　         */
/* 機能名       ：タスク状態変更フラグ更新                                       */
/* 機能概要     ：タスク状態変更フラグを更新　　　      　　　  　　　 　　　　　　 */
/*               基本的に初期化状態に戻すために使う                              */
/* 引数         ：Range*、取得用変数ポインタ                                    */
/* 戻り値       ：int8、エラー通知                                              */
/* 作成日       ：7月23日、渡部湧也                                             */
/* -------------------------------------------------------------------------- */
int8 PositionCorrection::movetasksetter(Range move_task){
    #ifdef CORRECTIONDATA_ON
    movetask=move_task;
    #endif
    return SYS_OK;
}


//
//ここから下は切り替え処理と同一
//

/* -------------------------------------------------------------------------- */
/* 関数名       ：colorJudge                                                   */
/* 機能名       ：rgbの判定                                                    */
/* 機能概要     ：rgb情報をみてアクションのシーン更新確認                         */
/*                rgbの場合すべての値が差分範囲に収まる場合切り替え               */
/* 引数         ：RGBData、cur_rgbdata、現在のrgb値                            */
/*               RGBData、change_rgbdata、目標のrgb値                          */
/*               Range、condition、現在と目標の差分範囲の指定                   */
/* 戻り値       ：int8、切り替え条件を満たしていればSYS_OK                       */
/*                     切り替え条件を満たしていなければSYS_NG                   */
/* 作成日       ：7月23日、渡部湧也                                            */
/* -------------------------------------------------------------------------- */
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

/* -------------------------------------------------------------------------- */
/* 関数名       ：xPositionJudge                                               */
/* 機能名       ：x座標の判定                                                   */
/* 機能概要     ：x座標情報をみてアクションのシーン更新確認                        */
/* 引数         ：float、cur_xpositiondata、現在のx座標                         */
/*               float、change_xpositiondata、目標のx座標                      */
/*               Range、condition、現在と目標の差分範囲の指定                    */
/* 戻り値       ：int8、切り替え条件を満たしていればSYS_OK                       */
//                     切り替え条件を満たしていなければSYS_NG                    */
/* 作成日       ：7月23日、渡部湧也                                             */
/* -------------------------------------------------------------------------- */
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

/* -------------------------------------------------------------------------- */
/* 関数名       ：yPositionJudge                                               */
/* 機能名       ：y座標の判定                                                   */
/* 機能概要     ：y座標情報をみてアクションのシーン更新確認                        */
/* 引数         ：float、cur_ypositiondata、現在のy座標                         */
/*               float、change_ypositiondata、目標のy座標                      */
/*               Range、condition、現在と目標の差分範囲の指定                    */
/* 戻り値       ：int8、切り替え条件を満たしていればSYS_OK                       */
/*                     切り替え条件を満たしていなければSYS_NG                    */
/* 作成日       ：7月23日、渡部湧也                                             */
/* -------------------------------------------------------------------------- */
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

/* -------------------------------------------------------------------------- */
/* 関数名       ：directionJudge                                              */
/* 機能名       ：向きの判定                                                   */
/* 機能概要     ：向き情報をみてアクションのシーン更新確認                       */
/* 引数         ：float、cur_directionData、現在の向き                         */
/*               float、change_directionData、目標の向き                       */
/*               Range、condition、現在と目標の差分範囲の指定                   */
/* 戻り値       ：int8、切り替え条件を満たしていればSYS_OK                      */
/*                     切り替え条件を満たしていなければSYS_NG                   */
/* 作成日       ：7月23日、渡部湧也                                            */
/* -------------------------------------------------------------------------- */
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

/* -------------------------------------------------------------------------- */
/* 関数名       ：distanceJudge                                               */
/* 機能名       ：距離の判定                                                   */
/* 機能概要     ：距離情報をみてアクションのシーン更新確認                       */
/* 引数         ：uint16、cur_distanceData、現在の距離                         */
/*               uint16、change_distanceData、目標の距離                       */
/* 戻り値       ：int8、切り替え条件を満たしていればSYS_OK                      */
/*                     切り替え条件を満たしていなければSYS_NG                   */
/* 作成日       ：7月23日、渡部湧也                                            */
/* -------------------------------------------------------------------------- */
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

/* -------------------------------------------------------------------------- */
/* 関数名       ：vJudge　　　　                                               */
/* 機能名       ：V値の判定                                                    */
/* 機能概要     ：V値情報をみてアクションのシーン更新確認                        */
/* 引数         ：uint16、cur_vData、現在のV値　　　                           */
/*               uint16、change_vData、目標のV値                              */
/*               Range、condition、現在と目標の差分範囲の指定                   */
/* 戻り値       ：int8、切り替え条件を満たしていればSYS_OK                      */
/*                     切り替え条件を満たしていなければSYS_NG                   */
/* 作成日       ：7月23日、渡部湧也                                            */
/* -------------------------------------------------------------------------- */
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

/* -------------------------------------------------------------------------- */
/* 関数名       ：sJudge　　　　                                               */
/* 機能名       ：S値の判定                                                    */
/* 機能概要     ：S値情報をみてアクションのシーン更新確認                        */
/* 引数         ：uint16、cur_sData、現在のS値　　　                           */
/*               uint16、change_sData、目標のS値                              */
/*               Range、condition、現在と目標の差分範囲の指定                   */
/* 戻り値       ：int8、切り替え条件を満たしていればSYS_OK                      */
/*                     切り替え条件を満たしていなければSYS_NG                   */
/* 作成日       ：7月23日、渡部湧也                                            */
/* -------------------------------------------------------------------------- */
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

/* -------------------------------------------------------------------------- */
/* 関数名       ：posSetter                                                   */
/* 機能名       ：座標更新                                                     */
/* 機能概要     ：引数の座標値を自己位置推定に更新する                           */
/*               PosInfoData内にあるx,yconditionを見て更新する要素を確認する　　*/
/* 引数         ：PosInfoData、target_pos、更新する座標情報                     */
/* 戻り値       ：int8、エラー通知                                              */
/* 作成日       ：7月23日、渡部湧也                                             */
/* -------------------------------------------------------------------------- */
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

/* -------------------------------------------------------------------------- */
/* 関数名       ：dirSetter                                                   */
/* 機能名       ：向き更新                                                     */
/* 機能概要     ：引数の角度値を自己位置推定に更新する                           */
/* 引数         ：DirectionData、target_dir、更新する向き情報                   */
/* 戻り値       ：int8、エラー通知                                              */
/* 作成日       ：7月23日、渡部湧也                                             */
/* -------------------------------------------------------------------------- */
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