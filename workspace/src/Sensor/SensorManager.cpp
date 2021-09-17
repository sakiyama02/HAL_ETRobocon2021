//
//  SensorManager.h
//  センサー管理クラス
//

#include "../../include/Sensor/SensorManager.h"

SensorManager::SensorManager(){}
SensorManager::~SensorManager(){}

/* -------------------------------------------------------------------------- */
/* 関数名       ：getRgb                                                       */
/* 機能名       ：RGB取得                                                      */
/* 機能概要     ：カラーセンサークラスからＲＧＢ値を取得する関数を呼び、　           */
/*              :                                             変数のrgbを更新  */
/* 引数         ：なし                                                          */
/* 戻り値       ：int        :    SYS_OK  :   正常終了                          */
/*              :            :   SYS_NG  :   異常終了                          */
/* 作成日       ：2021/07/27         廣兼　聖太    新規作成                      */
/* -------------------------------------------------------------------------- */
int8 SensorManager::getRgb()
{  
    frLog &msg = frLog::GetInstance();
    int8 retChk = SYS_NG;           //戻り値確認変数

    //rgb値取得
    retChk = colorSensor.getRGB(&rgbStorage);
    //戻り値check
    if (retChk != SYS_OK)
    {
        msg.LOG(LOG_ID_ERR, "getRgb colorSensor.getRGB エラー");
        return retChk;
    }
    //msg.LOG(LOG_ID_ERR,"R:%d,G:%d,B:%d",rgbStorage.r,rgbStorage.g,rgbStorage.b);
    return SYS_OK;
}

/* -------------------------------------------------------------------------- */
/* 関数名       ：getDistance                                                  */
/* 機能名       ：距離取得                                                      */
/* 機能概要     ：超音波センサーから距離を取得する関数を呼び、                      */
/*              :                       変数のdistanceStorageを更新             */
/* 引数         ：なし                                                         */
/* 戻り値       ：int        :    SYS_OK  :   正常終了                          */
/*              :            :   SYS_NG  :   異常終了                          */
/* 作成日       ：2021/07/27         廣兼　聖太    新規作成                      */
/* -------------------------------------------------------------------------- */
int8 SensorManager::getDistance()
{
    frLog &msg = frLog::GetInstance();
    int8 retChk = SYS_NG;           //戻り値確認変数

    //距離取得
    retChk = sonicSensor.getDistance(&distanceStorage);
    //戻り値check
    if (retChk != SYS_OK)
    {
        msg.LOG(LOG_ID_ERR, "getDistance sonicSensor.getDistance エラー");
        return retChk;
    }

    return SYS_OK;
}

/* -------------------------------------------------------------------------- */
/* 関数名       ：rgbGetter                                                   */
/* 機能名       ：RGBゲッター                                                  */
/* 機能概要     ：引数で入ってきた構造体ポインタにRGB情報に格納する                */
/* 引数         ：RGBData*   :    rgb_data                                     */
/* 戻り値       ：int        :    SYS_OK  :   正常終了                          */
/*              :            :   SYS_NG  :   異常終了                          */
/*              :           :   SYS_PARAM:   異常引数                          */
/* 作成日       ：2021/07/27         廣兼　聖太    新規作成                      */
/* -------------------------------------------------------------------------- */
int8 SensorManager::rgbGetter(RGBData* rgb_data)
{
    frLog &msg = frLog::GetInstance();
    int8 retChk = SYS_NG;           //戻り値確認変数
    //argument check
    if (rgb_data == NULL)
    {
        msg.LOG(LOG_ID_ERR, "rgbGetter argument エラー");
        return SYS_PARAM;
    }

    retChk = getRgb();
    //戻り値check
    if (retChk != SYS_OK)
    {
        msg.LOG(LOG_ID_ERR, "rgbGetter getRgb エラー");
        return retChk;
    }

    //引数にカラーセンサーの値を格納
    *rgb_data = rgbStorage;

    return SYS_OK;
}

/* -------------------------------------------------------------------------- */
/* 関数名       ：rgbGetter                                                    */
/* 機能名       ：v値ゲッター                                                  */
/* 機能概要     ：引数で入ってきたhsvのv値をv値情報に格納する                     */
/* 引数         ：uint16*   :    v_data                                        */
/* 戻り値       ：int        :    SYS_OK  :   正常終了                          */
/*              :            :   SYS_NG  :   異常終了                          */
/*              :           :   SYS_PARAM:   異常引数                          */
/* 作成日       ：2021/07/27         廣兼　聖太    新規作成                      */
/* -------------------------------------------------------------------------- */
int8 SensorManager::hsvGetter(uint16* v_data)
{    
    frLog &msg = frLog::GetInstance();
    int8 retChk = SYS_NG;           //戻り値確認変数

    //argument check
    if (v_data == NULL)
    {
        msg.LOG(LOG_ID_ERR, "hsvGetter argument エラー");
        return SYS_PARAM;
    }
    
    retChk = getRgb();
    //戻り値check
    if (retChk != SYS_OK)
    {
        msg.LOG(LOG_ID_ERR, "hsvGetter getRgb エラー");
        return retChk;
    }

    //hsvのv値を格納
    if(rgbStorage.r >= rgbStorage.g && rgbStorage.r >= rgbStorage.b)
    {
        *v_data = rgbStorage.r;
    }
    else if(rgbStorage.g >= rgbStorage.r && rgbStorage.g >= rgbStorage.b)
    {
        *v_data = rgbStorage.g;
    }
    else if(rgbStorage.b >= rgbStorage.r && rgbStorage.b >= rgbStorage.g)
    {
        *v_data = rgbStorage.b;
    }

    //目標値入力が％だった場合
    //*v_data = (*v_data / 255) * 100;

    return SYS_OK;
}

/* -------------------------------------------------------------------------- */
/* 関数名       ：saturationGetter                                             */
/* 機能名       ：s値ゲッター                                                  */
/* 機能概要     ：引数で入ってきたhsvのs値をs値情報に格納する                     */
/* 引数         ：uint16*   :    s_data                                        */
/* 戻り値       ：int        :    SYS_OK  :   正常終了                          */
/*              :            :   SYS_NG  :   異常終了                          */
/*              :           :   SYS_PARAM:   異常引数                          */
/* 作成日       ：2021/07/27         廣兼　聖太    新規作成                      */
/* -------------------------------------------------------------------------- */

int8 SensorManager::saturationGetter(uint16* s_data)
{    
    frLog &msg = frLog::GetInstance();
    int8 retChk = SYS_NG;           //戻り値確認変数
    float max_data = 0;
    float min_data = 0;

    //argument check
    if (s_data == NULL)
    {
        msg.LOG(LOG_ID_ERR, "hsvGetter argument エラー");
        return SYS_PARAM;
    }
    
    retChk = getRgb();
    //戻り値check
    if (retChk != SYS_OK)
    {
        msg.LOG(LOG_ID_ERR, "hsvGetter getRgb エラー");
        return retChk;
    }

    //RGBの最大値を取得
    if(rgbStorage.r >= rgbStorage.g && rgbStorage.r >= rgbStorage.b)
    {
        max_data = rgbStorage.r;
    }
    else if(rgbStorage.g >= rgbStorage.r && rgbStorage.g >= rgbStorage.b)
    {
        max_data = rgbStorage.g;
    }
    else if(rgbStorage.b >= rgbStorage.r && rgbStorage.b >= rgbStorage.g)
    {
        max_data = rgbStorage.b;
    }

    //RGBの最小値を取得
    if(rgbStorage.r <= rgbStorage.g && rgbStorage.r <= rgbStorage.b)
    {
        min_data = rgbStorage.r;
    }
    else if(rgbStorage.g <= rgbStorage.r && rgbStorage.g <=rgbStorage.b)
    {
        min_data = rgbStorage.g;
    }
    else if(rgbStorage.b <= rgbStorage.r && rgbStorage.b <= rgbStorage.g)
    {
        min_data = rgbStorage.b;
    }

    *s_data = ((max_data -min_data) / max_data) * 255 ;

    return SYS_OK;
}

/* -------------------------------------------------------------------------- */
/* 関数名       ：distanceGetter                                              */
/* 機能名       ：距離値ゲッター                                                */
/* 機能概要     ：引数で入ってきたポインタに超音波の値情報を超音波変数に格納する     */
/* 引数         ：uint16*   :    distance_data                                  */
/* 戻り値       ：int        :    SYS_OK  :   正常終了                          */
/*              :            :   SYS_NG  :   異常終了                          */
/*              :           :   SYS_PARAM:   異常引数                          */
/* 作成日       ：2021/07/27         廣兼　聖太    新規作成                      */
/* -------------------------------------------------------------------------- */
int8 SensorManager::distanceGetter(uint16* distance_data)
{
    frLog &msg = frLog::GetInstance();
    int8 retChk = SYS_NG;           //戻り値確認変数

    //argument check
    if (distance_data == NULL)
    {
        msg.LOG(LOG_ID_ERR, "distanceGetter argument エラー");
        return SYS_PARAM;
    }

    retChk = getDistance();
    //戻り値check
    if (retChk != SYS_OK)
    {
        msg.LOG(LOG_ID_ERR, "distanceGetter getDistance エラー");
        return retChk;
    }

    
    //超音波センサーの値を格納
    *distance_data = distanceStorage;

     return SYS_OK;
}

/* -------------------------------------------------------------------------- */
/* 関数名       ：distanceGetter                                              */
/* 機能名       ：センサ初期化                                                  */
/* 機能概要     ：センサーのポート設定を行う                                     */
/* 引数         ：なし                                                          */
/* 戻り値       ：int        :    SYS_OK  :   正常終了                          */
/*              :            :   SYS_NG  :   異常終了                          */
/*              :           :   SYS_PARAM:   異常引数                          */
/* 作成日       ：2021/07/27         廣兼　聖太    新規作成                      */
/* -------------------------------------------------------------------------- */
int8 SensorManager::initSensor()
{
    frLog &msg = frLog::GetInstance();
    int8 retChk = SYS_NG;           //戻り値確認変数

    //カラーセンサーのポート設定
    retChk = colorSensor.init();
        if (retChk != SYS_OK)
    {
        msg.LOG(LOG_ID_ERR, "initSensor colorSensor.init エラー");
        return retChk;
    }

    //超音波センサーのポート設定
    retChk = sonicSensor.init();
        if (retChk != SYS_OK)
    {
        msg.LOG(LOG_ID_ERR, "initSensor sonicSensor.init エラー");
        return retChk;
    }

    return SYS_OK;
}