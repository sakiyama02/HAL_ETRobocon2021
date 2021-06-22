

#include <cstdint>
#include <string.h>
#include <memory>
#include <string>
#include "ev3api.h"

#define SYS_OK 0    //正常終了
#define SYS_NG 1    //異常終了
#define SYS_PARAM 2 //引数エラー

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
JUDGE_RGB,
JUDGE_POS,
JUDGE_DIS,
JUDGE_DIR,
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
	int8 r;
	int8 g;
	int8 b;
}RGB;

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

// 座標の構造体
typedef struct PositionTAG {
	float xPosition;
	float yPosition;
	Range xCondition;
	Range yCondition;
}Position;

// 切り替え用情報
typedef struct ChangeInfo_Tag {	
	RGB　rgb_data;		            // 切り替え用のRGB値
	Position position_data;		    // 切り替え用の座標
	DirectionData direction_data;	// 切り替え用の機体の向き
	int8 distance;		            // 切り替え用の超音波距離
	int8 judge;		                // 切り替え値の判定		例：ポジションの切り替えを行いたいなら、JUDGE_POSを入れる			
	int8 section_act;	        	// シーンの動作を入れる		例：ライントレースのシーンなら、LINE_TRACEを入れる			
	int32 speed;		            // このシーン時の目標速度					
}ChangeInfo;