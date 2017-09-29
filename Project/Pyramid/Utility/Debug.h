/**
* @file		Debug.h
* @brief	デバック機能を提供する
* @author	S.OIKAWA
* @date		2016/4/22
*/
#pragma once
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include<string>
#include<unordered_map>
#include"Macro.h"
#include"singleton.h"

//-----------------------------------------------------------
// define
//-----------------------------------------------------------


namespace Utility
{
	/// <summary>
	/// 前方定義
	/// </summary>
	class TextFile;

	/// <summary>
	/// ログ出力ディレクトリ
	/// </summary>
#ifdef _DEBUG
	const std::string g_FileDirectory("DebugOutput/");
#else
	const std::string g_FileDirectory("OutputLog/");
#endif // !_DEBUG


#ifdef _DEBUG

	/// <summary>
	/// リリース時に呼び出しごと消える関数
	/// </summary>
#define ___D_CALL(function,...)\
		Debug::Instance().function(__VA_ARGS__);

	/// <summary>
	/// リリース時に呼び出しごと消えるログ
	/// </summary>
#define	___D_LOG(_msg) \
		::Utility::Debug::Instantiate().Log(_msg);

#define ___DEBUG_CALL(...) __VA_ARGS__
#define ___DEBUG_DEFINE(...) __VA_ARGS__
#else

#define	___D_CALL(function,...)
#define	___D_LOG(_msg)

#define ___DEBUG_CALL(...)
#define ___DEBUG_DEFINE(...)

#endif // !_DEBUG

	/// <summary>
	/// リリース時にも残るログ
	/// </summary>
#define ___LOG(_msg) \
		::Utility::Debug::Instantiate().Log(_msg);

/// <summary>
/// デバックサポートクラス
/// </summary>
	class Debug :
		public Singleton<Debug>
	{
	public:
		//-----------------------------------------------------------
		// ctor.dtor
		//-----------------------------------------------------------
		Debug(const Debug& other) = delete;
		Debug(Debug && other) = delete;

		/// <summary>
		/// デストラクタ
		/// </summary>
		virtual ~Debug();

		/// <summary>
		/// コンストラクタ
		/// </summary>
		Debug();

	public:
		//-----------------------------------------------------------
		// operaotor
		//-----------------------------------------------------------
		Debug& operator=(const Debug& other) = delete;
		Debug& operator=(Debug&& other) = delete;

		//-----------------------------------------------------------
		// function
		//-----------------------------------------------------------

		/// <summary>
		/// 出力.
		/// 基本はlog.textに出力、他のファイルに出力したい場合にファイル名を指定する
		/// </summary>
		/// <param name="_msg">ログメッセージ</param>
		/// <param name="_mapKey">ファイルキー</param>
		void Log(const std::string& _msg, std::string _mapKey = std::string("Log"));

		/// <summary>
		/// デバックコンソールを使用する
		/// </summary>
		/// <param name="_posX">X座標</param>
		/// <param name="_posY">Y座標</param>
		/// <param name="_width">横幅</param>
		/// <param name="_height">縦幅</param>
		void UseDebugConsole(int _posX = 1000, int _posY = 400, int _width = 500, int _height = 400);

		/// <summary>
		/// デバックテキスト描画
		/// </summary>
		/// <param name="_msg">内容</param>
		/// <param name="_posX">X座標</param>
		/// <param name="_posY">y座標</param>
		/// <param name="_prosesName">プロセス名</param>
		void DrawText
			(std::string _msg,
				int _posX = 20,
				int _posY = 20,
				std::string _prosesName = "Pyramid"
				);

		//-----------------------------------------------------------
		// property
		//-----------------------------------------------------------
		PROPERTY(m_UseMSDebugString, MSDebugOutput, bool);
		PROPERTY(m_UseOutputLog, OutputLog, bool);
		PROPERTY_R_ONLY(m_UseDebugConsole, DebugConsole, bool);
		PROPERTY_R_ONLY(m_Directory, Directory, std::string);

		//-----------------------------------------------------------
		// Val
		//-----------------------------------------------------------
	private:
		using FileMap = std::unordered_map < std::string, TextFile* >;
		/// <summary>
		/// ファイルマップ
		/// </summary>
		FileMap m_FileMap;

		/// <summary>
		/// 出力ディレクトリ
		/// </summary>
		const std::string m_Directory;

		/// <summary>
		/// コンソールハンドル
		/// </summary>
		int  m_hConsole;

		/// <summary>
		/// VSのデバックウィンドに表示
		/// </summary>
		bool m_UseMSDebugString;

		/// <summary>
		/// ログファイルに出力
		/// </summary>
		bool m_UseOutputLog;

		/// <summary>
		/// コンソールにログ出力
		/// </summary>
		bool m_UseDebugConsole;

		/// <summary>
		/// 標準出力ハンドル
		/// </summary>
		HANDLE m_StdOutput;

		/// <summary>
		/// コンソールウィンドウハンドル
		/// </summary>
		HWND	m_DebugConsoleWinddowHandel;

		/// <summary>
		/// 標準出力先
		/// </summary>
		FILE*	m_pStdOut;
	};
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------


