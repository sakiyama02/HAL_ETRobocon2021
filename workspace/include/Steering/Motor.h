#pragma once
#include "../System/System.h"

class Motor {
private:
	MotorPort portNum;

public:
	///
	/// @fn Motor ();
	/// @brief コンストラクタ
	///
	Motor();

	///
	/// @fn ~Motor ();
	/// @brief デストラクタ
	///
	~Motor();

	///
	/// @fn int8 init(motorPort port, motor_type_t type);
	/// @brief ポート設定
	/// @param port モーターポート
	/// @param type モータータイプ
	/// @retval SYS_OK 正常終了
	/// @retval SYS_PARAM 引数エラー
	/// @retval SYS_NG 異常終了
	///
	int8 init(MotorPort port, motor_type_t type);

	///
	/// @fn int8 getCounts (int32* motorAngle);
	/// @brief モーターの回転角度を取得
	/// @param motorAngle 回転角度
	/// @retval SYS_OK 正常終了
	/// @retval SYS_PARAM 引数エラー
	/// @retval SYS_NG 異常終了
	///
	int8 getCounts(int32 *motorAngle);

	///
	/// @fn int8 getPWM (int32* motorPower)
	/// @brief モーターパワーを取得
	/// @param motorPower 指定角度
	/// @retval SYS_OK 正常終了
	/// @retval SYS_PARAM 引数エラー
	/// @retval SYS_NG 異常終了
	///
	int8 getPWM(int32 *motorPower);

	///
	/// @fn int8 resetCounts ()
	/// @brief モーターの回転角度を初期化する
	/// @retval SYS_OK 正常終了
	/// @retval SYS_PARAM 引数エラー
	/// @retval SYS_NG 異常終了
	///
	int8 resetCounts();

	///
	/// @fn int8 setCounts (int32 motorAngle, int32 motorPower)
	/// @brief 指定した角度でモーターを回す。
	/// @param motorAngle 指定角度
	/// @param motorPower 指定パワー
	/// @retval SYS_OK 正常終了
	/// @retval SYS_PARAM 引数エラー
	/// @retval SYS_NG 異常終了
	///
	int8 setCounts(int32 motorAngle, int32 motorPower);

	///
	/// @fn int8 setCounts (int32 motorPower)
	/// @brief 指定した角度でモーターを回す。
	/// @param motorPower 指定パワー
	/// @retval SYS_OK 正常終了
	/// @retval SYS_PARAM 引数エラー
	/// @retval SYS_NG 異常終了
	///
	int8 setPWM(int32 motorPower);

	///
	/// @fn int8 stop (bool brake);
	/// @brief モーターを止める
	/// @retval SYS_OK 正常終了
	/// @retval SYS_PARAM 引数エラー
	/// @retval SYS_NG 異常終了
	///
	int8 stop(bool brake);
};