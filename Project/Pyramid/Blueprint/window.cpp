/**
* @file		window.cpp
* @brief	Windowクラス
* @author	S.OIKAWA
* @date		2016/4/16
*/

//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"window.h"
#include"Constant.h"
//-----------------------------------------------------------
//define 
//-----------------------------------------------------------
using Pyramid::Blueprint::Constant;
namespace Pyramid
{
	namespace Blueprint
	{
		//-----------------------------------------------------------
		// ctor 
		//-----------------------------------------------------------
		Window::Window() :
			m_ExStyle(0),
			m_Style(0),
			m_Atom(0),
			m_Wnd(0),
			m_Instance(0),
			m_Menu(0),
			m_ClassName(Constant::ClassName),
			m_WindowName(0),
			m_Param(0),
			m_fullScreen(false),
			m_ClientRect({ CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT })
		{
			m_Instance = (HINSTANCE)::GetModuleHandle(NULL);
		}

		//-----------------------------------------------------------
		// デストラクタ
		//-----------------------------------------------------------
		Window::~Window()
		{
			if (m_Wnd)
			{
				//ウィンドウハンドルの破棄
				::RemoveProp(m_Wnd, Constant::ClientProc);
				::DestroyWindow(m_Wnd);
			}
			if (m_Atom)
			{
				//クラス登録解除
				::UnregisterClass(m_ClassName, m_Instance);
				m_Atom = NULL;
			}
		}

		//-----------------------------------------------------------
		// ルートプロシージャ
		//-----------------------------------------------------------
		LRESULT CALLBACK Window::WndRootProc(HWND hWnd,
			UINT uMsg,
			WPARAM wParam, 
			LPARAM lParam)
		{
			Window* pWnd = (Window*)::GetProp(hWnd, Constant::ClientProc);
			if (pWnd)	// インスタンス毎のプロシージャ処理
				return pWnd->WndProc(uMsg, wParam, lParam);

			// ダイアログの場合、FALSEを返す
			if (::GetWindowLong(hWnd, DWL_DLGPROC))
				return FALSE;
			// デフォルトウィンドウプロシージャを呼び出す
			return ::DefWindowProc(hWnd, uMsg, wParam, lParam);
		}

		//-----------------------------------------------------------
		// GetClientRect 
		//-----------------------------------------------------------
		bool Window::GetClientRect(LPRECT pRect)
		{
			return ::GetClientRect(m_Wnd, pRect) != FALSE;
		}

		//-----------------------------------------------------------
		// ウィンドウプロシージャ
		//-----------------------------------------------------------
		LRESULT Window::WndProc(UINT uMsg, WPARAM wParam, LPARAM lParam)
		{
			switch (uMsg)
			{
			case WM_CREATE:
				return OnCreate((LPCREATESTRUCT)lParam);

			case WM_DROPFILES:
				OnDropFiles((HDROP)wParam);
				return 0;

			case WM_CLOSE:
			case WM_DESTROY:
				OnDestroy();
				break;

			default:
				break;
			}
			return DefWindowProc(uMsg, wParam, lParam);
		}

		//-----------------------------------------------------------
		// デフォルトウィンドウプロシージャ
		//-----------------------------------------------------------
		LRESULT Window::DefWindowProc(UINT uMsg, WPARAM wParam, LPARAM lParam)
		{
			return ::DefWindowProc(m_Wnd, uMsg, wParam, lParam);
		}

		//-----------------------------------------------------------
		// 生成イベント
		//-----------------------------------------------------------
		int Window::OnCreate(LPCREATESTRUCT pcs)
		{
			return 0;
		}

		//-----------------------------------------------------------
		// ファイルドロップイベント
		//-----------------------------------------------------------
		void Window::OnDropFiles(HDROP hDropInfo)
		{
			DefWindowProc(WM_DROPFILES, (WPARAM)hDropInfo, 0);
		}

		//-----------------------------------------------------------
		// 終了イベント
		//-----------------------------------------------------------
		void Window::OnDestroy()
		{
			// アプリケーション終了
			::PostQuitMessage(0);
		}

		//-----------------------------------------------------------
		// クラス登録
		//-----------------------------------------------------------
		void Window::RegisterClass()
		{
			if (!m_Atom)
			{
				WNDCLASSEX wcex;
				ZeroMemory(&wcex, sizeof(WNDCLASSEX));
				wcex.cbSize = sizeof(wcex);
				wcex.lpszClassName = m_ClassName;							// クラス名
				wcex.lpfnWndProc = WndRootProc;								// ウィンドウプロシージャ
				wcex.style = CS_VREDRAW | CS_HREDRAW;						// 占有指定
				wcex.hInstance = m_Instance;								// インスタンス
				wcex.hCursor = ::LoadCursor(NULL, IDC_ARROW);				// デフォルト カーソル
				wcex.hIcon = ::LoadIcon(NULL, IDI_APPLICATION);				// デフォルト アイコン
				wcex.hbrBackground = (HBRUSH)::GetStockObject(WHITE_BRUSH); // 背景色
				wcex.hIconSm = ::LoadIcon(NULL, IDI_APPLICATION);			// デフォルト アイコン
				m_Atom = ::RegisterClassEx(&wcex);

				if (!m_Atom)
				{
					___THROW_EXCEPTION_POINT(Utility::Exception, "m_Atomが無効値");
				}
			}
		}

		//-----------------------------------------------------------
		// ウィンドウ生成
		//-----------------------------------------------------------
		void Window::Create
		(
			LPCTSTR		_windowName,
			int			_width, int			_height,
			DWORD		_style, DWORD		_exStyle,
			int			_x, int			_y,
			HWND		_hwndParent,
			HMENU		_hMenu,
			LPVOID		_pParam
		)
		{
			m_Style = _style;
			m_ExStyle = _exStyle;
			m_Menu = _hMenu;
			m_Param = _pParam;

			RECT rc = { 0, 0, _width, _height };
			if (!::AdjustWindowRectEx(&rc, _style,
				_hMenu && !IS_INTRESOURCE(_hMenu), _exStyle))
			{
				___THROW_EXCEPTION_POINT(Utility::Exception, "Adjustに失敗");
			}
			RegisterClass();

			//生成
			HWND hWnd = ::CreateWindowEx(
				_exStyle, m_ClassName, _windowName, _style,
				_x, _y, _width, _height,
				_hwndParent, _hMenu, m_Instance, _pParam
			);

			if (!hWnd)
			{
				___THROW_EXCEPTION_POINT(Utility::Exception, "CreateWindowExに失敗");
			}
			m_Wnd = hWnd;

			//処理登録
			::SetProp(m_Wnd, Constant::ClientProc, (LPVOID)this);
		}

		//-----------------------------------------------------------
		//フルスクリーンウィンドウ生成
		//-----------------------------------------------------------
		void Window::CreateFullScreen
		(
			LPCTSTR	_windowName
		)
		{
			Create(_windowName, CW_USEDEFAULT, CW_USEDEFAULT);
			m_fullScreen = true;
		}

		//-----------------------------------------------------------
		// インスタンス初期化
		//-----------------------------------------------------------
		bool Window::InitInstance()
		{
			return true;
		}

		// ---------------------------------------------------------------------
		// アプリケーション終了時の処理
		// ---------------------------------------------------------------------
		int Window::ExitInstance()
		{
			return m_Msg.wParam;
		}

		//-----------------------------------------------------------
		// GetHwnd
		//-----------------------------------------------------------
		HWND Window::GetHwnd() const
		{
			return (this) ? m_Wnd : NULL;
		}

		//-----------------------------------------------------------
		// operator
		//-----------------------------------------------------------
		Window::operator HWND() const
		{
			return GetHwnd();
		}

		//-----------------------------------------------------------
		// Show 
		//-----------------------------------------------------------
		bool Window::Show(int nCmdShow)
		{
			return ::ShowWindow(m_Wnd, nCmdShow) != FALSE;
		}

		//-----------------------------------------------------------
		// Update 
		//-----------------------------------------------------------
		void Window::Update()
		{
			::UpdateWindow(m_Wnd);
		}

		//-----------------------------------------------------------
		// メッセージ処理
		//-----------------------------------------------------------
		bool Window::MessageProc()
		{
			//メッセージが届いていればプロシージャにディスパッチする
			if (PeekMessage(&m_Msg, NULL, 0, 0, PM_REMOVE)) {
				if (m_Msg.message == WM_QUIT)
				{
					return false;
				}
				TranslateMessage(&m_Msg);
				DispatchMessage(&m_Msg);
			}

			return true;
		}

	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------