/**
* @file		Macro.h
* @brief	マクロ定義ヘッダ
* @author	S.OIKAWA
* @date		2016.02.19
*/
#pragma once

#include <crtdbg.h>
#include <windows.h>
#include <tchar.h>
#include<stdio.h>
#include<mutex>

//-----------------------------------------------------------
// アクセスプロパティ
//-----------------------------------------------------------
/** @def PROPERTY
* 読み書き可能なプロパティ。値渡し
*/
#define PROPERTY(var,propertyName,type) 	\
		void Seter_##propertyName(type _val) { var = _val;} \
		type Geter_##propertyName() const {return var;} \
		__declspec(property(get = Geter_##propertyName, put = Seter_##propertyName)) type propertyName

/** @def PROPERTY_Ref
* 読み書き可能なプロパティ。参照渡し
*/
#define PROPERTY_REF(var,propertyName,type) 	\
		void Seter_##propertyName(const type& _val){ var = _val;} \
		type& Geter_##propertyName() {return var;} \
		__declspec(property(get = Geter_##propertyName, put =Seter_##propertyName)) type propertyName

/** @def PROPERTY_MOVE
* 読み書き可能なプロパティ。右辺値渡し
*/
#define PROPERTY_MOVE(var,propertyName,type) 	\
		void Seter_##propertyName(const type& _val){ var = std::move(_val);} \
		type&& Geter_##propertyName() {return std::move(var);} \
		__declspec(property(get = Geter_##propertyName, put =Seter_##propertyName)) type propertyName

/** @def PROPERTY_Static_Ref
* 読み書き可能な静的プロパティ。参照渡し
*/
#define PROPERTY_STATIC_REF(var,propertyName,type) 	\
		static void Seter_##propertyName(const type& _val){ var = _val;} \
		static type& Geter_##propertyName() {return var;} \
		__declspec(property(get = Geter_##propertyName, put =Seter_##propertyName)) static type propertyName

/** @def THREAD_SAFE_PROPERTY
* 読み書き可能なプロパティ。値渡し,スレッドセーフ
*/
#define THREAD_SAFE_PROPERTY(var,propertyName,type,mtx) 	\
		void Seter_##propertyName(type _val){ ::std::lock_guard<::std::mutex> lk(mtx); var = _val;} \
		type Geter_##propertyName() {::std::lock_guard<::std::mutex> lk(mtx); return var;} \
		__declspec(property(get = Geter_##propertyName, put = Seter_##propertyName)) type propertyName

/** @def THREAD_SAFE_REF_PROPERTY
* 読み書き可能なプロパティ。参照渡し,スレッドセーフ
*/
#define THREAD_SAFE_REF_PROPERTY(var,propertyName,type,mtx) 	\
		void Seter_##propertyName(const type& _val){ std::lock_guard<std::mutex> lk(mtx); var = _val;} \
		type& Geter_##propertyName() {std::lock_guard<std::mutex> lk(mtx); return var;} \
		__declspec(property(get = Geter_##propertyName, put = Seter_##propertyName)) type propertyName

/** @def PROPERTY_R_ONLY
* 読み専用なプロパティ。値渡し
*/
#define PROPERTY_R_ONLY(var,propertyName,type) 	\
		type Geter_##propertyName() const{return var;} \
		__declspec(property(get = Geter_##propertyName)) type propertyName

/** @def PROPERTY_REF_R_ONLY
* 読み専用なプロパティ。参照返し
*/
#define PROPERTY_REF_R_ONLY(var,propertyName,type) 	\
		type& Geter_##propertyName() {return var;} \
		__declspec(property(get = Geter_##propertyName)) type propertyName

/** @def PROPERTY_CR_R_ONLY
* 読み専用なプロパティ。コンスト参照返し
*/
#define PROPERTY_CR_R_ONLY(var,propertyName,type) 	\
		const type& Geter_##propertyName() const {return var;} \
		__declspec(property(get = Geter_##propertyName)) type propertyName

/** @def THREAD_SAFE_PROPERTY
* 読み専用なプロパティ。値渡し,スレッドセーフ
*/
#define THREAD_SAFE_PROPERTY_R_ONLY(var,propertyName,type,mtx) 	\
		type Geter_##propertyName() {std::lock_guard<std::mutex> lk(mtx); return var;} \
		__declspec(property(get = Geter_##propertyName)) type propertyName


/** @def PROPERTY_Static_Ref
* 読み書き可能な静的プロパティ。参照渡し
*/
#define PROPERTY_STATIC_R_ONLY(var,propertyName,type) 	\
		static type& Geter_##propertyName() {return var;} \
		__declspec(property(get = Geter_##propertyName)) static type propertyName

/** @def PROPERTY_W_ONLY
* 書き専用なプロパティ。値渡し
*/
#define PROPERTY_W_ONLY(var,propertyName,type) 	\
		void Seter_##propertyName(type _val){ var = _val;} \
		__declspec(property(put = Seter_##propertyName)) type propertyName

/** @def PROPERTY_REF_W_ONLY
* 書き専用なプロパティ。コンスト参照
*/
#define PROPERTY_REF_W_ONLY(var,propertyName,type) 	\
		void Seter_##propertyName(type& _val){ var = _val;} \
		__declspec(property(put = Seter_##propertyName)) type propertyName

/** @def PROPERTY_W_ONLY
* 書き専用なプロパティ。コンスト参照
*/
#define PROPERTY_CR_W_ONLY(var,propertyName,type) 	\
		void Seter_##propertyName(const type& _val){ var = _val;} \
		__declspec(property(put = Seter_##propertyName)) type propertyName

/** @def THREAD_SAFE_PROPERTY
* 書き専用なプロパティ。値渡し,スレッドセーフ
*/
#define THREAD_SAFE_PROPERTY_W_ONLY(var,propertyName,type,mtx) 	\
		void Seter_##propertyName(type _val){ std::lock_guard<std::mutex> lk(mtx); var = _val;} \
		__declspec(property(put = Seter_##propertyName)) type propertyName

/** @def PROPERTY_HOOKABLE
* 読み書き可能なプロパティ。値渡し
* フックできるが副作用の無いように留意.
*/
#define PROPERTY_HOOKABLE(var,propertyName,type,hook) 	\
		void Seter_##propertyName(type _val) { var = _val;hook();} \
		type Geter_##propertyName() const {return var;} \
		__declspec(property(get = Geter_##propertyName, put = Seter_##propertyName)) type propertyName

/** @def PROPERTY_REF_HOOKABLE
* 読み書き可能なプロパティ.参照渡し
* フックできるが副作用の無いように留意.
*/
#define PROPERTY_REF_HOOKABLE(var,propertyName,type,hook) 	\
		void Seter_##propertyName(const type& _val) { var = _val;hook();} \
		type& Geter_##propertyName() {return var;} \
		__declspec(property(get = Geter_##propertyName, put = Seter_##propertyName)) type propertyName


//-----------------------------------------------------------
// String変換マクロ
//-----------------------------------------------------------
/** @def ___GET_THIS_NAME
* ディスポインタから形名取得
*/
#define ___GET_THIS_NAME(pthis)					\
		 std::string(typeid(*pthis).name())

/** @def ___TYPE_TO_STRING
*	型をstringに変換
*/
#define ___TYPE_TO_STRING(type)					\
		std::string(typeid(type).name())

/** @def ___CODE_TO_STRING
* コードを文字化
*/
#define ___CODE_TO_STRING(_code)				\
		std::string(#_code)

//-----------------------------------------------------------
// ASSERT
//-----------------------------------------------------------

//!< 多重宣言マクロ 警告無視
#pragma warning ( disable : 4005 )
//!< 警告Lv3 警告無視
#pragma warning ( disable : 4996 )

/**
@def _ASSERT_EXPR
@brief exprの条件が満たされなかったら、第2引数に渡したメッセージをデバッグレポートウィンドウに表記するマクロ
@param [in]expr 条件(否定)
@param [in]msg メッセージ
@note 例：_ASSERT_EXPR( isClear == true, _T("メッセージ") );
*/
#ifdef _DEBUG
#define _ASSERT_EXPR(expr, msg) \
	(void) ((!!(expr)) || \
	(1 != _CrtDbgReportW(_CRT_ASSERT, _CRT_WIDE(__FILE__), __LINE__, NULL, msg)) || \
	(_CrtDbgBreak(), 0))
#else
#    define _ASSERT_EXPR(expr, msg) {}// 空実装
#endif


#ifdef _DEBUG
#ifndef _ASSERT
#define _ASSERT(expr) _ASSERT_EXPR((expr), NULL)
#endif
#else
#    define _ASSERT(expr) {}// 空実装
#endif

#ifdef _DEBUG
#ifndef _ASSERTE
#define _ASSERTE(expr) _ASSERT_EXPR((expr), _CRT_WIDE(#expr))
#endif
#else
#    define _ASSERTE(expr) {}// 空実装
#endif

/**
@def SET_TITLE
@brief タイトルバーに文字セット
@param [in] str 表示文字列フォーマット
@param [in] ... 引数
@return 無し
*/
#define SET_TITLE(processName,str , ...)	\
		{								\
			TCHAR c[2048];					\
			_stprintf( c, str, __VA_ARGS__ ); \
			SetWindowText(FindWindow(processName,NULL),c); \
		}
#ifdef _DEBUG
#else
//#define SET_TITLE(str , ...) {}
#endif // !_DEBUG


//-----------------------------------------------------------
// メモリ関係
//-----------------------------------------------------------

/** @def ON_SEARCH_LEAK
* メモリリーク検出
*/
#ifdef _DEBUG
#define ON_SEARCH_LEAK _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF) 
#else
#define  ON_SEARCH_LEAK
#endif // !_DEBUG

/** @def ON_BREAK_ALLOC
* メモリ確保時ブレイク
*/
#ifdef _DEBUG
#define ON_BREAK_ALLOC(no) _CrtSetBreakAlloc(no)
#else
#define  ON_BREAK_ALLOC
#endif

/** @def SAFE_RELEASE
* 多重開放防止
*/
#ifndef SAFE_RELEASE
#define SAFE_RELEASE(ptr)			if(ptr){ ptr->Release(); ptr=nullptr; }
#endif
/** @def SAFE_DELETE
* 多重開放防止
*/
#ifndef SAFE_DELETE
#define SAFE_DELETE(ptr)			if(ptr){ delete ptr; ptr=nullptr; }
#endif
/** @def SAFE_DELETE_ARRAY
* 多重開放防止
*/
#ifndef SAFE_DELETE_ARRAY
#define SAFE_DELETE_ARRAY(ptr)		if(ptr){ delete[] ptr; ptr=nullptr; }
#endif

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------