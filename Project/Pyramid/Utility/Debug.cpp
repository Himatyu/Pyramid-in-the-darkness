/**
* @file		Debug.cpp
* @brief	デバッククラスの実装
* @author	S.OIKAWA
* @date		2016/4/22
*/

//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include <windows.h>
#include <tchar.h>
#include <io.h>
#include <Fcntl.h>
#include<direct.h>
#include<iostream>

#include "Debug.h"
#include "TextFile.h"

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Utility
{
	//-----------------------------------------------------------
	//　ctor
	//-----------------------------------------------------------
	Debug::Debug() :
		m_UseMSDebugString(true),
		m_UseOutputLog(true),
		m_UseDebugConsole(false),
		m_Directory(g_FileDirectory),
		m_pStdOut(nullptr)
	{
		//ディレクトリ作成
		_mkdir(g_FileDirectory.c_str());

#ifdef _DEBUG
		Log("Debug");
#else
		Log("Release");
#endif // _DEBUG
		Log("");
	}

	//-----------------------------------------------------------
	//　dtor
	//-----------------------------------------------------------
	Debug::~Debug()
	{

		for (auto& it : m_FileMap)
		{
			(*it.second).Write(it.second->FilePath);
			delete it.second;
		}

		if (m_pStdOut)
		{
			::fclose(m_pStdOut);
			m_pStdOut = nullptr;
		}

		if (m_UseDebugConsole)
		{
			FreeConsole();
			m_UseDebugConsole = false;
		}
	}

	//-----------------------------------------------------------
	//　Log
	//-----------------------------------------------------------
	void Debug::Log(const std::string& _msg, std::string _mapKey)
	{
		if (m_UseMSDebugString)
		{
#ifdef UNICODE
			std::wstring dest;
			wchar_t *wcs = new wchar_t[_msg.length() + 1];
			mbstowcs(wcs, _msg.c_str(), _msg.length() + 1);
			dest = wcs;
			delete[] wcs;
			OutputDebugString(dest.c_str());
			OutputDebugString("\n");
#else
			OutputDebugString(_msg.c_str());
			OutputDebugString("\n");
#endif
		}

		if (m_UseDebugConsole)
		{
			std::cout << _msg << std::endl;
		}

		if (m_UseOutputLog)
		{
			auto it = m_FileMap.find(_mapKey);
			if (it != m_FileMap.end())
			{
				(*(*it).second).Buffer += _msg + "\n";
				return;
			}
			auto pFile = new TextFile(m_Directory + _mapKey + ".txt");

			m_FileMap[_mapKey] = pFile;
			(*pFile).Buffer += _msg + "\n";
		}

	}

	//-----------------------------------------------------------
	//　UseDebugConsole
	//-----------------------------------------------------------
	void Debug::UseDebugConsole(int _posX, int _posY, int _width, int _height)
	{
		if (m_UseDebugConsole || !AllocConsole())
		{
			return;
		}

		//使用状態に
		m_UseDebugConsole = true;

		//ハンドル取得
		m_StdOutput = ::GetStdHandle(STD_OUTPUT_HANDLE);

		// カーソルを消す
		CONSOLE_CURSOR_INFO cursorInfo;						// カーソル情報構造体
		::GetConsoleCursorInfo(m_StdOutput, &cursorInfo);	// カーソル情報を取得
		cursorInfo.bVisible = FALSE;						// カーソル情報を変更
		::SetConsoleCursorInfo(m_StdOutput, &cursorInfo);	// カーソル情報を設定
		::SetConsoleTitle("DebugConsole");					// タイトル変更

		//位置・サイズ変更
		m_DebugConsoleWinddowHandel = ::GetConsoleWindow();
		HMENU hMenu = ::GetSystemMenu(m_DebugConsoleWinddowHandel, FALSE);
		::MoveWindow
			(m_DebugConsoleWinddowHandel, _posX, _posY, _width, _height, FALSE);

		// 閉じる/最大化を無効化
		//::RemoveMenu(hMenu, SC_CLOSE, MF_BYCOMMAND);
		::RemoveMenu(hMenu, SC_MAXIMIZE, MF_BYCOMMAND);

		// 標準出力先の変更
		freopen_s(&m_pStdOut, "CON", "w", stdout);

	}

	//-----------------------------------------------------------
	// DrawText
	//-----------------------------------------------------------
	void Debug::DrawText(std::string _msg, int _posX, int _posY, std::string _prosesName)
	{
		auto hwnd = FindWindow(_prosesName.c_str(), nullptr);
		auto hdc = GetDC(hwnd);

		RECT rect;
		rect.left = _posX;
		rect.top = _posY;
		rect.right = 200;
		rect.bottom = 200;

		::DrawText(hdc, _msg.c_str(), -1, &rect, DT_LEFT | DT_WORDBREAK);
		ReleaseDC(hwnd, hdc);

	}
}
//-----------------------------------------------------------
//　EOF
//-----------------------------------------------------------