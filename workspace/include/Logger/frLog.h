#pragma once
 
#include "../System/System.h"

/* デバッグログ出力 -------------------------------------------------------- */
/* 以下のdefineを有効にするとログが出力されます。                            */
/* Release時には、以下１行をコメント化して下さい。                           */
/* エラーログも出ないので注意                                                */
/* ------------------------------------------------------------------------- */
#define __LOG_DEBUG_MODE__

#ifndef __LOG_DEBUG_MODE__
  #define LOG(a,...) LOG()
#endif

//#include "frBluetooth.h"		
typedef char			SCHR;					/*	char型					 */
typedef unsigned char	UCHR;					/*	unsigned char型			 */
typedef short			SSHT;					/*	short型					 */
typedef unsigned short	USHT;					/*	unsigned short型		 */
typedef long			SLNG;					/*	long型					 */
typedef unsigned long	ULNG;					/*	unsigned long型			 */
typedef int				SINT;					/*	int型					 */
typedef unsigned int	UINT;					/*	unsigned int型			 */
typedef	float			FLOT;					/*	float型					 */
typedef	double			DBLE;					/*	double型				*/
/* ログＩＤ一覧 ------------------------------------------------------------ */
#define LOG_ID_MOTOR		( 0x00000001 )		/* モーター関連				 */
#define LOG_ID_FIX			( 0x00000002 )		/* 修正関連				 */
#define LOG_ID_SONIC		( 0x00000004 )		/* 超音波関連				 */
#define LOG_ID_PID			( 0x00000008 )		/* PID関連					 */
#define LOG_ID_COLOR		( 0x00000010 )		/* カラーセンサー関連		 */
#define LOG_ID_COORDINATE	( 0x00000020 )		/* 座標関連					 */
#define LOG_ID_SECTION		( 0x00000040 )		/* 区間の更新時				 */
#define LOG_ID_INFO			( 0x00000080 )
#define LOG_ID_NEWDELETE    ( 0x00000100 )		/* NewDelete 関連*/
#define LOG_ID_BRIGHT		( 0x00000200 )		/* 明度ログ			 */
#define LOG_ID_TRACE		( 0x20000000 )		/* トレース関連				 */
#define LOG_ID_ERR			( 0x40000000 )		/* エラーログ				 */
#define LOG_ID_TERMINATE	( 0x80000000 )		/* 終端						 */
#define LOG_MAX_BUF			(        256 )		/* ログバッファ最大値		 */

/* ログコマンド一覧 -------------------------------------------------------- */
#define LOG_CMD_LOGON		"logon"				/* ログＯＮコマンド			 */
#define LOG_CMD_LOGOFF		"logoff"			/* 一部ログＯＦＦコマンド	 */
#define LOG_CMD_MOTOR		"motor"				/* モーター識別コード		 */
#define LOG_CMD_FIX			"fix"				/* 修正識別コード			 */
#define LOG_CMD_PID			"pid"				/* PID識別コード			 */
#define LOG_CMD_COORDINATE	"coordinate"		/* 座標関連識別コード		 */
#define LOG_CMD_COLOR		"color"				/* カラーセンサー識別コード	 */
#define LOG_CMD_SONIC		"sonic"				/* 超音波センサー識別コード	 */
#define LOG_CMD_TRACE		"trace"				/* トレースログモード		 */
#define LOG_CMD_SECTION		"section"			/* 区間更新ログ				 */
#define LOG_CMD_INFO		"info"				/* Information系クラスのデータチェック用 */
#define LOG_CMD_NEWDELETE   "newdelete"			/* new_deleteログ*/
#define LOG_CMD_BRIGHT		"bright"			/* 明度ログ */  

/* ------------------------------------------------------------------------- */
/* クラス定義																 */
/* ------------------------------------------------------------------------- */
class frLog{

public:
	void SetLog(SCHR code);
	void LOG(SINT id, const SCHR* log, ...);

	static frLog& GetInstance(void);

private:
	~frLog();
	frLog();
	frLog(const frLog &x) { };
	frLog&operator=(const frLog &) { return *this; };

	void CommandAnaryze( void );
	void FlgSet( const SINT flg, ULNG* log, SINT id );

	ULNG _logmode;
	SCHR _buf[LOG_MAX_BUF];
};
