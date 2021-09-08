#pragma once
#include <cstdint>
#include <string.h>
#include <memory>
#include <string>
#include "../Logger/frLog.h"
#include "ev3api.h"
#define CORRECTIONDATA_ON
#define SYS_OK 0    //正常終了
#define SYS_NG 1    //異常終了
#define SYS_PARAM 2 //引数エラー
#define TIMEATTACK_NUM 20 
#define SLALOMEEBUI_NUM 21
#define SLALOMEIFIE_NUM 16
#define SLALOMBLACKY_NUM 16
#define GARAGE_NUM 26

#define CAR_WIDTH 134.22f      //車体の幅(mm)
#define CAR_WHEEL_WIDTH 90.33f //車輪の直径(mm)

// integer 8bit
using int8 = int8_t;

// integer 16bit
using int16 = int16_t;

// integer 32bit
using int32 = int32_t;

// integer 64bit
using int64 = int64_t;

// unsigned integer 8bit
using uint8 = uint8_t;

// unsigned integer 16bit
using uint16 = uint16_t;

// unsigned integer 32bit
using uint32 = uint32_t;

// unsigned integer 64bit
using uint64 = uint64_t;

// int pointer
using intptr = intptr_t;

// uint pointer
using uintptr = uintptr_t;

/* 列挙型の定義 */
// 切り替え判定種別
enum JudgeType
{
JUDGE_NONE,
JUDGE_RGB,
JUDGE_POS,
JUDGE_DIS,
JUDGE_DIR,
JUDGE_V,
JUDGE_S,
JUDGE_SEND,//補正限定使用
};

//モーターポート番号
enum MotorPort
{
  MOTOR_ARM,   //アームモーター
  MOTOR_RIGHT, //右輪モーター
  MOTOR_LEFT,  //左輪モーター
  MOTOR_TAIL,  //尻尾モーター
};

enum SensorPort
{
  SENSOR_TOUCH, //タッチセンサー
  SENSOR_COLOR, //カラーセンサー
  SENSOR_SONAR, //超音波センサー
  SENSOR_GYRO,  //ジャイロセンサー
};

// 判定用条件
enum Range
{
HIGH,
LOW,
NONE,
};

// 動作種別
enum ActionType
{
LINE_TRACE,
STRAIGHT,
CURVE,
LINE_CURVE,
TURN,
ARM_ACTION,
ARMDOWN_ACTION,
};

// カーブの進行方向
enum CurveType
{
CURVE_LEFT,
CURVE_RIGHT,
};

/* 構造体定義 */
// RGBの構造体
typedef struct RGB_TAG {	
	uint16 r;
	uint16 g;
	uint16 b;
	Range condition;
}RGBData;

// 方向情報の構造体
typedef struct Direction_TAG{	
	float direction;
	Range condition;
}DirectionData;

//カーブ情報の構造体
typedef struct CurveData_TAG{	
	float radius;
	CurveType dirction;
}CurveData;

//v値情報の構造体
typedef struct V_TAG{
	uint16 v;
	Range condition;
}VData;

//s値情報の構造体
typedef struct S_TAG{
	uint16 s;
	Range condition;
}SData;


// 座標の構造体
typedef struct Position_TAG{
	float xPosition;
	float yPosition;
}PositionData;

// 座標情報の構造体
typedef struct PositionTAG {
	PositionData potision;
	Range xCondition;
	Range yCondition;
}PosInfoData;

// モータパワー
typedef struct MotorPower_TAG{	
	int32 rightPower;
	int32 leftPower;
}MotorPower;

 // モータ角度
typedef struct MotorAngle_TAG{	
	int32 rightAngle;
	int32 leftAngle;
}MotorAngle;

// 左右の車輪の移動量を格納
typedef struct WheelDist_s
{
  float leftMove;  //左輪移動量
  float rightMove; //右輪移動量
} WheelDist;


// 切り替え用情報
typedef struct ChangeInfo_Tag {	
	RGBData rgb_data;		            // 切り替え用のRGB値
	PosInfoData pos_info_data;		    // 切り替え用の座標
	DirectionData direction_data;	// 切り替え用の機体の向き
	uint8 distance;		            // 切り替え用の超音波距離
	VData vData;					//切り替え用のv値
	SData sData;					//切り替え用のs値
	JudgeType judge;		                // 切り替え値の判定		例：ポジションの切り替えを行いたいなら、JUDGE_POSを入れる			
	ActionType section_act;	        	// シーンの動作を入れる		例：ライントレースのシーンなら、LINE_TRACEを入れる			
	int32 speed;		            // このシーン時の目標速度					
}ChangeInfo;

typedef struct PositionCorrection_TAG{	
	PosInfoData correctionValue;
	DirectionData correctionValueDirection;
	PosInfoData correctionPosition;
	RGBData correctionRGB;
	VData correctionV;
	SData correctionS;
	DirectionData correctionDirection;
	uint8 distance;
	JudgeType correctionCondition;
}PositionCorrectionData;

typedef struct PIDData_Tag
{
	float pGain; //比例ゲイン	
	float iGain; //積分ゲイン	
	float dGain; //微分ゲイン	
	float targetVal; //目標値	
}PIDData;