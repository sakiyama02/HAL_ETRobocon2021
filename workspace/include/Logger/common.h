#ifndef __COMMON__
#define __COMMON__
/*	-----------------------------------------------------------------------	 */
/*	common.h																 */
/*	標準定義																 */
/*	型名のtypedef宣言の集まり												 */
/*	-----------------------------------------------------------------------	 */
/*	番号	更新履歴								日付		氏名		 */
/*	-----------------------------------------------------------------------	 */
/*	000000	新規作成								2018/06/05	松浦侑矢	 */
/*	-----------------------------------------------------------------------	 */

#define FUNC_OK			(                 1 )	/*  関数正常終了			 */
#define FUNC_ERR		(                -1 )	/*  関数異常終了			 */
#define SYS_ERR			(                -2 )	/*  システム不具合エラー	 */
#define PARAM_ERR		(                -3 )	/*  引数エラー				 */
#define HW_ERR			(                -4 )	/*  ハードウェアエラー		 */
#define RETRY_ERR		(                -5 )	/*  再取得エラー			 */

/*	-----------------------------------------------------------------------	 */
/*	typedef宣言																 */
/*	-----------------------------------------------------------------------	 */
typedef char			SCHR;					/*	char型					 */
typedef unsigned char	UCHR;					/*	unsigned char型			 */
typedef short			SSHT;					/*	short型					 */
typedef unsigned short	USHT;					/*	unsigned short型		 */
typedef long			SLNG;					/*	long型					 */
typedef unsigned long	ULNG;					/*	unsigned long型			 */
typedef int				SINT;					/*	int型					 */
typedef unsigned int	UINT;					/*	unsigned int型			 */
typedef	float			FLOT;					/*	float型					 */
typedef	double			DBLE;					/*	double型				 */

/*	-----------------------------------------------------------------------	 */
/*				Copyright HAL College of Technology & Design				 */
/*	-----------------------------------------------------------------------	 */
#endif

