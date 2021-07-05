#include "../../include/PositionCorrection/PositionCorrection.h"
int8 PositionCorrection::FixSetter(PositionCorrectionData positionCorrection_Data){
    #ifdef CORRECTIONDATA_ON
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
        //現在実行中のタスクOFF
    } 
    //メンバ構造体に引数で取得した最新状態の構造体をセット
    memcpy(&prePositionCorrectionData,&positionCorrection_Data,sizeof(PositionCorrectionData));
    //補正を起動する
    switch(prePositionCorrectionData.correctionCondition){
        //
        case JUDGE_RGB:
            //ここでタスクON
        break;
        case JUDGE_POS:
            //ここでタスクON
        break;
        case JUDGE_DIR:
            //ここでタスクON
            //自己位置推定のフラグが消えるまで送信メソッドで送信する
        break;
        default:
        break;
    }
    #endif
}

int8 PositionCorrection::colorFix(){
    #ifdef CORRECTIONDATA_ON
    int8 retChk = SYS_NG;
    //タスクを空くと
    taskState=STATE＿ACT;
    //センサ管理をインスタンスポインタを取得
    SensorManager &sensorManager=SensorManager::getinstance();
    //センサ管理から取得したrgb値を保持する構造体
    RGBData curRGBData;
    memset(&curRGBData,0,sizeof(RGBData));
    //センサ管理からrgb値を取得
    retChk=sensorManager.rgbGetter(&curRGBData);
    //引数のエラーチェック
    if(retChk==SYS_NG){
        return retChk;
    }
    //rgbの目標値と現在値を比較
    retChk=colorJudge(curRGBData,prePositionCorrectionData.correctionRGB
    ,prePositionCorrectionData.correctionRGB.condition);
    if(retChk==SYS_NG){
        //条件を満たしていない場合処理を行わずに終了
        //更新なしで送信
        return 
    }

    #endif
}

int8 PositionCorrection::lineFix(){
    #ifdef CORRECTIONDATA_ON
    #endif
}

int8 PositionCorrection::directionFix(){
    #ifdef CORRECTIONDATA_ON
    #endif
}


//
//ここから下は切り替え処理と同一
//

//rgbの判定
//引数：現在のrgb値、目標のrgb値、(現在と目標の差分範囲の指定値)
//戻り値：切り替え条件を満たしていればSYS_OK
//        切り替え条件を満たしていなければSYS_NG
int8 PositionCorrection::colorJudge(RGBData cur_rgbdata,RGBData change_rgbdata,int8 condition){

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
int8 PositionCorrection::xPositionJudge(float cur_xpositionData,float change_xpositionData,int8 condition){
    float resultx=0;
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
int8 PositionCorrection::yPositionJudge(float cur_ypositionData,float change_ypositionData,int8 condition){
    float resulty=0;
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

//向きの判定
//引数：現在の向き値、目標の向き値、現在と目標の差分範囲の指定値 
//マイナスの値を入れるとバグるので注意
//戻り値：切り替え条件を満たしていればSYS_OK
//        切り替え条件を満たしていなければSYS_NG
int8 PositionCorrection::directionJudge(float cur_directionData,float change_directionData,int8 condition){
    float resultdirection=0;
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