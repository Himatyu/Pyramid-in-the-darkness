/**
* @file		File.ｈ
* @brief	ファイルクラス
* @author	S.OIKAWA
* @date		2016/4/22
*/
#pragma once
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include<string>

//-----------------------------------------------------------
// define
//-----------------------------------------------------------

namespace Utility
{
	/// <summary>
	/// ファイルベースクラス.
	/// </summary>
	class File
	{
	public:
		//-----------------------------------------------------------
		// ctor.dtor
		//-----------------------------------------------------------
			/// <summary>
			/// コンストラクタ
			/// </summary>
		File() = default;

		/// <summary>
		/// コンストラクタ
		/// </summary>
		/// <param name="_Filename">ファイル名</param>
		explicit File(std::string& _filePath);

		/// <summary>
		/// デストラクタ
		/// </summary>
		virtual ~File() = default;

		//-----------------------------------------------------------
		// define
		//----------------------------------------------------------
		File(const File&) = default;
		File(File&&) = default;

		File&operator=(const File&) = default;
		File&operator=(File&&) = default;

		//-----------------------------------------------------------
		// function
		//-----------------------------------------------------------
			/// <summary>
			/// ファイル読み込み.
			/// </summary>
			/// <param name="_path">ファイルパス</param>
			/// <returns>読み込み成功判定</returns>
		virtual void Read(std::string _path) = 0 {}


		/// <summary>
		/// 書き込み.
		/// </summary>
		/// <param name="_path">ファイルパス</param>
		/// <returns>書き込み成功是非</returns>
		virtual void Write(std::string _path = "") = 0 {}

	protected:
		/// <summary>
		/// ファイル名とパスをセット.
		/// </summary>
		/// <param name="_path">ファイルパス</param>
		void SetFilePathInfo(std::string _path);

	public:
		//-----------------------------------------------------------
		// property
		//-----------------------------------------------------------
		PROPERTY_CR_R_ONLY(m_FileName, FileName, std::string);
		PROPERTY_CR_R_ONLY(m_FilePath, FilePath, std::string);
		PROPERTY_CR_R_ONLY(m_FileDirectory, FileDirectory, std::string);

	protected:
		//-----------------------------------------------------------
		// Val
		//-----------------------------------------------------------
		std::string m_FileName;
		std::string m_FilePath;
		std::string m_FileDirectory;
	};
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------
