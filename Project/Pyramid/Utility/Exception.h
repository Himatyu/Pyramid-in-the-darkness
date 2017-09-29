/**
* @file		Exception.h
* @brief	例外処理
* @author　	S/OIKAWA
* @date		2016/4/22
*/
#pragma once
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include<exception>
#include<string>
#include"Macro.h"

//-----------------------------------------------------------
// define
//-----------------------------------------------------------

namespace Utility
{
	/// <summary>
	/// 発生箇所を取得し例外を投げる
	/// </summary>
#define ___THROW_EXCEPTION(EXCEPTION_TYPE, message) \
  throw EXCEPTION_TYPE( __FILE__, __func__, __LINE__,message) 

/// <summary>
/// 発生箇所を取得し例外ポインタを投げる
/// </summary>
#define ___THROW_EXCEPTION_POINT(EXCEPTION_TYPE, message) \
  throw new EXCEPTION_TYPE( __FILE__, __func__, __LINE__,message) 

//-----------------------------------------------------------
// define
//-----------------------------------------------------------

/// <summary>
/// 例外クラス.
/// 基本はマクロを使う.
/// </summary>
	class Exception :
		public std::exception
	{
	public:
		//-----------------------------------------------------------
		// ctor.dtor
		//-----------------------------------------------------------
			/// <summary>
			/// 発生箇所の特定を行わない例外
			/// </summary>
			/// <param name="_msg">メッセージ</param>
		explicit Exception(const std::string& _msg = "Unknown exception");

		/// <summary>
		/// 発生箇所情報を受取る例外
		/// </summary>
		/// <param name="_file">発生ファイル</param>
		/// <param name="_func">発生関数</param>
		/// <param name="_line">発生ライン</param>
		/// <param name="_msg">メッセージ</param>
		Exception
			(
				const char* _file,
				const char* _func,
				const int _line,
				const std::string& _msg = "Unknown exception"
				);

		/// <summary>
		/// デストラクタ
		/// </summary>
		virtual ~Exception() = default;

		//-----------------------------------------------------------
		// default
		//-----------------------------------------------------------

		Exception(const Exception&) = default;
		Exception(Exception&&) = default;

		Exception& operator=(const Exception&) = default;
		Exception& operator=(Exception&&) = default;

		//-----------------------------------------------------------
		// function
		//-----------------------------------------------------------
			/// <summary>
			/// 例外内容取得
			/// </summary>
			/// <returns>例外内容</returns>
		virtual const char* what() const noexcept override { return m_Msg.c_str(); }

		//-----------------------------------------------------------
		// property
		//-----------------------------------------------------------
		PROPERTY_CR_R_ONLY(m_Msg, Msg, std::string);
		PROPERTY_CR_R_ONLY(m_Filename, Filename, std::string);
		PROPERTY_CR_R_ONLY(m_FunctionName, FunctionName, std::string);
		PROPERTY_CR_R_ONLY(m_ExceptionDetailBuffer, Detail, std::string);
		PROPERTY_CR_R_ONLY(m_Line, Line, int);

	private:
		//-----------------------------------------------------------
		// Val
		//-----------------------------------------------------------
			/// <summary>
			/// 例外内容
			/// </summary>
		std::string m_Msg;

		/// <summary>
		/// 発生したファイル
		/// </summary>
		std::string m_Filename;

		/// <summary>
		/// 発生した関数
		/// </summary>
		std::string m_FunctionName;

		/// <summary>
		/// 内容と発生箇所
		/// </summary>
		std::string m_ExceptionDetailBuffer;

		/// <summary>
		/// 発生行数
		/// </summary>
		int			m_Line;

	};

}
//-----------------------------------------------------------
//　EOF
//-----------------------------------------------------------




