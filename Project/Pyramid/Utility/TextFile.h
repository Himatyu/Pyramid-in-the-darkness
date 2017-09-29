/**
* @file		TextFile.h
* @brief	テキストファイルクラス
* @author	S.OIKAWA
* @date		2016/4/22
*/
#pragma once
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"File.h"
#include"Macro.h"
//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Utility
{
	/// <summary>
	/// テキストファイル入出力クラス
	/// </summary>
	class TextFile :
		public File
	{
	public:
		//-----------------------------------------------------------
		// ctor.dtor
		//-----------------------------------------------------------
			/// <summary>
			/// コンストラクタ
			/// </summary>
		TextFile() = default;

		/// <summary>
		/// コンストラクタ
		/// </summary>
		/// <param name="_Filename">ファイル名</param>
		explicit TextFile(std::string _Filename);

		/// <summary>
		/// デストラクタ
		/// </summary>
		virtual ~TextFile() = default;

		//-----------------------------------------------------------
		// default
		//-----------------------------------------------------------
		TextFile(const TextFile&) = default;
		TextFile(TextFile&&) = default;

		TextFile& operator=(const TextFile&) = default;
		TextFile& operator=(TextFile&&) = default;

		//-----------------------------------------------------------
		// function
		//-----------------------------------------------------------

			/// <summary>
			/// textファイル読み込み
			/// </summary>
		void Read(std::string) override;

		/// <summary>
		/// textファイル書き込み
		/// </summary>
		void Write(std::string) override;

		//-----------------------------------------------------------
		//　property
		//-----------------------------------------------------------
		PROPERTY_REF(m_Buffer, Buffer, std::string);


		//-----------------------------------------------------------
		// Val
		//-----------------------------------------------------------
			/// <summary>
			/// バッファ
			/// </summary>
		std::string m_Buffer;
	};
}
//-----------------------------------------------------------
//　EOF
//-----------------------------------------------------------