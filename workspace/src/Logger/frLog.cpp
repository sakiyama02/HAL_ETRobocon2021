/* ------------------------------------------------------------------------- */
/* コンパイルスイッチ														 */
/* ------------------------------------------------------------------------- */
//#define __BLUETOOTH_DEBUG__
 
#include "../../include/Logger/frLog.h"			/* ログヘッダ				 */
#include <stdio.h>								/* 基本入出力				 */
#include <string.h>								/* 文字列操作系				 */
#include <stdlib.h>								/* 初期化系					 */
#include <stdarg.h>								/* 可変長引数操作系			 */

/* ------------------------------------------------------------------------- */
/* 定数定義																	 */
/* ------------------------------------------------------------------------- */
#define LOG_KEY_DELETE		(       0x7F )		/* Deleteキー				 */
#define LOG_KEY_BACKSPACE	(       0x08 )		/* Backspaceキー			 */
#define LOG_KEY_ENTER_CR	(       0x0D )		/* エンターキー(1)			 */
#define LOG_KEY_ENTER_LF	(       0x0A )		/* エンターキー(2)			 */
#define LOG_KEY_SPACE		(       0x20 )		/* スペースキー				 */
#define LOG_KEY_HYPHEN		(       0x2D )		/* -キー					 */

#define LOG_FLG_ON			(       0x01 )		/* フラグＯＮ				 */
#define LOG_FLG_OFF			(       0x00 )		/* フラグＯＦＦ				 */


/* ------------------------------------------------------------------------- */
/* 構造体定義																 */
/* ------------------------------------------------------------------------- */
typedef struct _LogLink {						/* ＩＤ・コマンドリンク構造体*/
	const SCHR* strings;						/* コマンド文字列			 */
	const ULNG id;								/* コマンドに対応するＩＤ	 */
} LOGLINK;

/* ------------------------------------------------------------------------- */
/* ■■■ public ■■■														 */
/* ------------------------------------------------------------------------- */
/* 関数名	: frLog::frLog													 */
/* 機能名	: ログ制御：コンストラクタ										 */
/* 機能概要	: 初回インスタンス生成時にコールされます						 */
/* 引数		: void			: なし											 */
/* 戻り値	: void			: なし											 */
/* ------------------------------------------------------------------------- */
frLog& frLog::GetInstance(void)
{
	static frLog obj;
	return obj;
}

/* ------------------------------------------------------------------------- */
/* 関数名	: frLog::LOG													 */
/* 機能名	: ログ制御：ログ出力											 */
/* 機能概要	: 設定に応じて、ログ出力を行います。							 */
/* 			  コンパイルスイッチに応じてBluetooth / モニタへ出力を分けてます */
/* 引数		: ULNG	:id 	:[I N] 識別ＩＤ 								 */
/* 戻り値	: void			: なし											 */
/* ------------------------------------------------------------------------- */
#ifdef __LOG_DEBUG_MODE__
void frLog::LOG( SINT id, const SCHR* message,... )
{
	char    str[LOG_MAX_BUF];					/* ログバッファ				 */
	SINT    iIndex = 0;							/* index					 */
	SINT    iMax   = 0;							/* バッファ最大長			 */
	va_list args;								/* 可変長ポインタ			 */
	
	/* 指定カ所のログが出力モードになっていない場合は何もしない */
	if(( _logmode & id ) != id ) {
		/* エラーログは強制出力の為、例外措置 */
		if( id != LOG_ID_ERR ) {
			return;
		}
	}
	
	/* ログ出力 */
	memset( &str[0], 0, sizeof( str ));
	va_start( args, message );
	vsprintf( str, message, args );
	va_end( args );
	
#ifdef __BLUETOOTH_DEBUG__
	/* Bluetoothインスタンス取得 */
	frBluetooth& bt= frBluetooth::GetInstance();
	for( iMax = ( strlen( str ) - 1 ); iIndex < iMax; iIndex ++ ) {
		bt.Send( str[iIndex] );
	}
#else  /* __BLUETOOTH_DEBUG__ */
	printf("%s\n", str);
	//fflush(stdout);
#endif  /* __BLUETOOTH_DEBUG__ */
	
	return;
}
#else
void frLog::LOG() {}
#endif


/* ------------------------------------------------------------------------- */
/* 関数名	: frLog::SetLog													 */
/* 機能名	: ログ制御：ログコマンドプール									 */
/* 機能概要	: ターミナルからコマンド入力・プールします。					 */
/* 			: Enterキー押下で、プールされたコマンドを解析、処理を実行します。*/
/* 引数		: char			: code	: [I N]入力コード(1文字)				 */
/* 戻り値	: void			: なし											 */
/* ------------------------------------------------------------------------- */
void frLog::SetLog( SCHR code )
{
	ULNG ulLength = 0;							/* 文字で津長				 */

	/* Enterキー入力時はコマンド解析 */
	if (code == LOG_KEY_ENTER_LF) {
		CommandAnaryze();
		return;
	}

	/* コードが最大値の場合は処理しない */
	if (strlen(_buf) >= LOG_MAX_BUF) {
		return;
	}

	/* Backspaceキー押下時は１文字削除 */
	if (code == LOG_KEY_BACKSPACE) {
		ulLength = strlen(_buf);
		if (ulLength > 0) {
			_buf[ulLength - 1] = NULL;
		}
		return;
	}

	/* 文字列コマンドの場合は１文字追加 */
	if ((code >= 'a') && (code <= 'z')) {
		_buf[strlen(_buf)] = code;
		return;
	}

	/* その他コード解析 */
	switch (code) {
	case LOG_KEY_SPACE:							/* スペースキー				 */
	case LOG_KEY_HYPHEN:						/* -キー					 */
		_buf[strlen(_buf)] = code;				/* １文字追加				 */
		break;
	}
	return;
}

/* ------------------------------------------------------------------------- */
/* ■■■ private ■■■													 */
/* ------------------------------------------------------------------------- */
/* 関数名	: frLog::frLog													 */
/* 機能名	: ログ制御：コンストラクタ										 */
/* 機能概要	: 初回インスタンス生成時にコールされます						 */
/* 引数		: void			: なし											 */
/* 戻り値	: void			: なし											 */
/* ------------------------------------------------------------------------- */
frLog::frLog()
{
	memset(&_buf[0], 0, sizeof(_buf));
	_logmode = 0x00000000;
}

/* ------------------------------------------------------------------------- */
/* 関数名	: frLog::~frLog													 */
/* 機能名	: ログ制御：デストラクタ										 */
/* 機能概要	: staticクラスの為、コールされることは無い						 */
/* 引数		: void			: なし											 */
/* 戻り値	: void			: なし											 */
/* ------------------------------------------------------------------------- */
frLog::~frLog()
{

}

/* ------------------------------------------------------------------------- */
/* 関数名	: frLog::CommandAnaryze											 */
/* 機能名	: ログ制御：コマンド解析										 */
/* 機能概要	: ターミナルから入力されたコマンドを解析し、必要な値を設定します.*/
/*			: コマンド入力ミスの場合、無効とみなし、バッファを全初期化します.*/
/* 引数		: void			: なし											 */
/* 戻り値	: void			: なし											 */
/* ------------------------------------------------------------------------- */
void frLog::CommandAnaryze( void )
{
	ULNG  ulLogMode = _logmode;					/* ログモード				 */
	ULNG  ulLength  = 0;						/* 文字列長					 */
	SINT  iRet      = 0;						/* strcmp戻り値				 */
	SINT  iNow      = 0;						/* 検索位置					 */
	SINT  iFlg = LOG_FLG_OFF;					/* フラグ					 */
	const LOGLINK link[] = {					/* コマンド・ＩＤ対比表		 */
		{ LOG_CMD_MOTOR   , LOG_ID_MOTOR   },	/* モーター関連				 */
		{ LOG_CMD_FIX    , LOG_ID_FIX    },		/* 修正関連				 */
		{ LOG_CMD_SONIC   , LOG_ID_SONIC   },	/* 超音波関連				 */
		{ LOG_CMD_COORDINATE , LOG_ID_COORDINATE },	/* 座標関連			 */
		{ LOG_CMD_COLOR   , LOG_ID_COLOR   },	/* カラーセンサー関連		 */
		{ LOG_CMD_PID     , LOG_ID_PID    },	/* PID関連		 */
		{ LOG_CMD_TRACE   , LOG_ID_TRACE   },	/* トレースログ関連			 */
		{ LOG_CMD_SECTION , LOG_ID_SECTION },	/* 区間用 */
		{ LOG_CMD_INFO	  , LOG_ID_INFO		},	/* Information系のデータ用 */
		{ LOG_CMD_NEWDELETE, LOG_ID_NEWDELETE },
		{ LOG_CMD_BRIGHT  , LOG_ID_BRIGHT }
	};
	
	/* コマンド取得 -------------------------------------------------------- */
	/* log onモード				 */
	iRet = strncmp( &_buf[0], LOG_CMD_LOGON, strlen( LOG_CMD_LOGON ));
	if( iRet == 0 ) {
		iNow += strlen(LOG_CMD_LOGON );
		iFlg = LOG_FLG_ON;
	} else {
		/* log OFFモード			 */
		iRet = strncmp(&_buf[0], LOG_CMD_LOGOFF, strlen(LOG_CMD_LOGOFF ));
		if (iRet == 0) {
			iNow += strlen(LOG_CMD_LOGOFF );
			iFlg = LOG_FLG_OFF;
		} else {
			/* コマンドミスの場合は何もしない */
			goto end;
		}
	}
	
	/* 文字列終端までループ ------------------------------------------------ */
	while( iNow < strlen( _buf )) {
		/* -が出るまでループ */
		if( _buf[iNow] == LOG_KEY_SPACE ) {
			iNow ++;
			continue;
		} else if( _buf[iNow] != LOG_KEY_HYPHEN ) {
			/* -から開始されない場合、コマンドミスと識別して終了 */
			goto end;
		}
		/* -発見、文字列に対応したコマンドを処理 */
		iNow ++;
		if( iNow >= sizeof( _buf )) {
			goto end;
		}
		
		/* ログ種別を解析・設定 -------------------------------------------- */
		for( int iIndex = 0; iIndex < ( sizeof( link ) / sizeof( link[0] )); iIndex ++ ) {
			iRet = strncmp( &_buf[iNow], link[iIndex].strings, strlen( link[iIndex].strings ));
			if( iRet == 0 ) {
				FlgSet( link[iIndex].id, &ulLogMode, iFlg );
				iNow = iNow + strlen(link[iIndex].strings);
				break;
			}
		}
	}
	
	/* バッファを初期化して終了 */
	_logmode = ulLogMode;
end:
	memset( &_buf[0], 0, sizeof( _buf ));
	return;
	
}

/* ------------------------------------------------------------------------- */
/* 関数名	: frLog::FlgSet													 */
/* 機能名	: ログ制御：出力フラグ設定										 */
/* 機能概要	: 各種コマンドの出力ＯＮ／ＯＦＦフラグ制御を行います。			 */
/* 引数		: const SINT	: flg	: [I N]入力コード(1文字)				 */
/* 引数		: char			: code	: [I N]入力コード(1文字)				 */
/* 戻り値	: void			: なし											 */
/* ------------------------------------------------------------------------- */
void frLog::FlgSet( const SINT flg, ULNG* log, SINT id )
{
	if( id == LOG_FLG_ON ) {
		*log |= flg;
	} else {
		*log &= ~flg;
	}
}

/* ------------------------------------------------------------------------- */
/*              Copyright HAL Collage of Technology & Design                 */
/* ------------------------------------------------------------------------- */

