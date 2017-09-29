/**
* @file		window.h
* @brief	Windowクラス
* @author	S.OIKAWA
* @date		2016/4/18
*/
#pragma once

//-----------------------------------------------------------
// include 
//-----------------------------------------------------------
#include<Windows.h>
#include<tchar.h>
#include<stdlib.h>

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Blueprint
	{
		/// <summary>
		/// Windowクラス
		/// プロシージャをオーバーライドすることで独自のWindowクラスを生成可能
		/// </summary>
		class Window
		{
		public:
			//-----------------------------------------------------------
			// defaults 
			//-----------------------------------------------------------
			Window();
			virtual ~Window();

			//-----------------------------------------------------------
			// function 
			//-----------------------------------------------------------
				/// <summary>
				/// 非フルスクリーンのウィンド作成
				/// </summary>
			void Create
			(
				LPCTSTR		_windowName,
				int			_width = CW_USEDEFAULT,
				int			_height = CW_USEDEFAULT,
				DWORD		_style = WS_OVERLAPPEDWINDOW,
				DWORD		_exStyle = 0,
				int			_x = CW_USEDEFAULT,
				int			_y = CW_USEDEFAULT,
				HWND		_hwndParent = NULL,
				HMENU		_hMenu = NULL,
				LPVOID		_pParam = NULL
			);

			/// <summary>
			/// フルスクリーンウィンド作成
			/// </summary>
			void CreateFullScreen(LPCTSTR	_windowName);

			/// <summary>
			/// メッセージが届いていればディスパッチする
			/// </summary>
			bool MessageProc();

			/// <summary>
			/// 初期化
			/// </summary>
			virtual bool InitInstance();

			/// <summary>
			/// 終了処理
			/// </summary>
			virtual int ExitInstance();

			/// <summary>
			/// ウィンドウハンドル取得
			/// </summary>
			HWND GetHwnd() const;

			/// <summary>
			/// ハンドル取得オペレータ
			/// </summary>
			operator HWND() const;

			/// <summary>
			/// ウィンドウの表示
			/// </summary>
			bool Show(int nCmdShow);

			/// <summary>
			/// ウィンドウ更新
			/// </summary>
			void Update();

			/// <summary>
			/// メッセージボックス表示
			/// </summary>
			int MessageBox(LPCTSTR pszText,
				LPCTSTR pszCaption = NULL,
				UINT nType = MB_OK);

			/// <summary>
			/// ウィンドウ サイズ取得
			/// </summary>
			bool GetClientRect(LPRECT pRect);

		protected:
			/// <summary>
			/// イベントを処理する
			/// </summary>
			virtual LRESULT WndProc(UINT uMsg, WPARAM wParam, LPARAM lParam);

			/// <summary>
			/// デフォルトプロージャ
			/// </summary>
			virtual LRESULT DefWindowProc(UINT uMsg, WPARAM wParam, LPARAM lParam);

			/// <summary>
			/// ウィンドウ生成イベント
			/// </summary>
			virtual int OnCreate(LPCREATESTRUCT pcs);

			/// <summary>
			/// ファイルドロップイベント
			/// </summary>
			virtual void OnDropFiles(HDROP hDropInfo);

			/// <summary>
			/// 破棄イベント
			/// </summary>
			virtual void OnDestroy();

			/// <summary>
			/// ウィンドウクラス登録
			/// </summary>
			void RegisterClass();

		private:
			/// <summary>
			/// 派生プロージャにメッセージを配布
			/// </summary>
			static LRESULT CALLBACK WndRootProc(HWND hWnd,
				UINT uMsg,
				WPARAM wParam, 
				LPARAM lParam);

		private:
			MSG			m_Msg;				//!< メッセージ
			RECT		m_ClientRect;		//!< クライアントサイズ
			DWORD		m_ExStyle;			//!< 拡張スタイル
			DWORD		m_Style;			//!< ウィンドウスタイル
			ATOM		m_Atom;				//!< 生成返却値
			HWND		m_Wnd;				//!< ウィンドウハンドル
			HINSTANCE	m_Instance;			//!< ウィンドウインスタンス
			HMENU		m_Menu;				//!< メニューハンドルまたは子ウィンドウ ID
			LPCTSTR		m_ClassName;		//!< 登録クラス名
			LPCTSTR		m_WindowName;		//!< ウィンドウ名
			LPVOID		m_Param;			//!< ウィンドウハンドル	
			bool		m_fullScreen;		//!< フルスクリーンモード？

		};
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------