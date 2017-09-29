/**
* @file			Graphics.cpp
* @brief		DirectXのデバイスを扱うクラス
* @author		S.OIKAWA
* @date			2016/4/18
*/

//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include <windows.h>
#include <tchar.h>
#include "Graphics.h"
#include "Target\Screen.h"

//-----------------------------------------------------------
// define 
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Rendering
	{
		//-----------------------------------------------------------
		// dtor 
		//-----------------------------------------------------------
		Graphics::~Graphics()
		{
			Release();
		}

		//-----------------------------------------------------------
		// イニシャライズ
		//-----------------------------------------------------------
		bool Graphics::Initialize(HWND _hWnd, int _Width, int _Height, bool _Window)
		{
			if (NULL == (m_pD3D = Direct3DCreate9(D3D_SDK_VERSION)))
			{
				___THROW_EXCEPTION_POINT(::Utility::Exception, "DirectX3Dオブジェクト生成失敗");
			}

			m_Height = _Height;
			m_Width = _Width;

			ZeroMemory(&m_D3DPP, sizeof(D3DPRESENT_PARAMETERS));
			m_D3DPP.Windowed = _Window;
			m_D3DPP.SwapEffect = D3DSWAPEFFECT_DISCARD;
			m_D3DPP.EnableAutoDepthStencil = true;
			m_D3DPP.AutoDepthStencilFormat = D3DFMT_D24S8;

			if (_Window)
			{
				m_D3DPP.BackBufferWidth = (UINT)m_Width;						// ゲーム画面サイズ
				m_D3DPP.BackBufferHeight = (UINT)m_Height;
				m_D3DPP.BackBufferFormat = D3DFMT_UNKNOWN;						// バックバッファ
				m_D3DPP.FullScreen_RefreshRateInHz = 0;							// リフレッシュレート
				m_D3DPP.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;	// インターバル
			}
			else
			{
				D3DDISPLAYMODE    d3dspMode;
				m_pD3D->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &d3dspMode);

				m_D3DPP.BackBufferWidth = d3dspMode.Width;						// ゲーム画面サイズ
				m_D3DPP.BackBufferHeight = d3dspMode.Height;

				m_D3DPP.BackBufferFormat = d3dspMode.Format;					// バックバッファ
				m_D3DPP.BackBufferCount = 1;
				m_D3DPP.FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT;	// リフレッシュレート
				m_D3DPP.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;		// インターバル
			}

			//デバイス生成
			if (FAILED(m_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, _hWnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &m_D3DPP, &m_pDevice))) //ハード:ハード
				if (FAILED(m_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, _hWnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &m_D3DPP, &m_pDevice))) //ハード:ソフト
					if (FAILED(m_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_REF, _hWnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &m_D3DPP, &m_pDevice))) //ソフト:ハード
						if (FAILED(m_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_REF, _hWnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &m_D3DPP, &m_pDevice))) //ソフト:ソフト
						{
							___THROW_EXCEPTION_POINT(::Utility::Exception, "デバイス生成失敗");
						}

			m_BackScreen.GetBackBuffer();

			return true;
		}

		//-----------------------------------------------------------
		// 終了処理 
		//-----------------------------------------------------------
		void Graphics::Finalize()
		{
		}

		//-----------------------------------------------------------
		// デバイス作製
		//-----------------------------------------------------------
		void Graphics::Create(HWND _hWnd, int _Width, int _Height, bool _Window)
		{
			Initialize(_hWnd, _Width, _Height, _Window);
		}

		//-----------------------------------------------------------
		// 開放
		//-----------------------------------------------------------
		void Graphics::Release()
		{
			SAFE_RELEASE(m_pDevice);
			SAFE_RELEASE(m_pD3D);
		}
	}
}

//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------




