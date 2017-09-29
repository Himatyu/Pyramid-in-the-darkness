/**
* @file	    Graphics.h
* @brief    DirectXのデバイスを扱うクラス
* @author   S.OIKAWA
* @date		2016/4/18
*/
#pragma once

//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include<d3d9.h>
#include<d3dx9.h>
#include<memory>
#include"singleton.h"
#include"Target/Screen.h"
//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Rendering
	{
		/// <summary>
		/// DirectXのデバイスを扱うクラス
		/// </summary>
		class Graphics final :
			public Utility::Singleton<Graphics>
		{
		public:
			//-----------------------------------------------------------
			// default
			//-----------------------------------------------------------
			Graphics() = default;
			~Graphics();

			Graphics(const Graphics&) = default;
			Graphics(Graphics&&) = default;

			Graphics&operator=(const Graphics&) = default;
			Graphics&operator=(Graphics&&) = default;

			//-----------------------------------------------------------
			// function
			//-----------------------------------------------------------

			/// <summary>
			/// クラス生成
			/// </summary>
			void Create(HWND _hWnd,
					int _Width = CW_USEDEFAULT,
					int _Height = CW_USEDEFAULT,
					bool _Window = true);

			/// <summary>
			/// 開放
			/// </summary>
			void Release();

		private:

			/// <summary>
			/// 初期化
			/// </summary>
			bool Initialize(HWND _hWnd, int _Width, int _Height, bool _Window);

			/// <summary>
			/// 終了処理
			/// </summary>
			void Finalize();

			//-----------------------------------------------------------
			// property
			//-----------------------------------------------------------	
		public:
			PROPERTY_R_ONLY(m_Width, Width, int);
			PROPERTY_R_ONLY(m_Height, Height, int);
			PROPERTY_R_ONLY(m_BackScreen, BackScreen, Target::Screen);
			PROPERTY_CR_R_ONLY(m_pDevice, Device, LPDIRECT3DDEVICE9);
			PROPERTY_CR_R_ONLY(m_D3DPP, PresentParameters, D3DPRESENT_PARAMETERS);

			//-----------------------------------------------------------
			// Val
			//-----------------------------------------------------------
		private:
			D3DPRESENT_PARAMETERS		m_D3DPP;						// PRESENT PARAMETERS
			D3DDISPLAYMODE				m_DespMax;						// 最大画面サイズ

			HWND						m_hWnd;							// ウィンドウ ハンドル
			int							m_Width;						// 表示領域幅
			int							m_Height;						// 表示領域高さ

			LPDIRECT3D9					m_pD3D;							// Direct3D9 オブジェクト
			LPDIRECT3DDEVICE9			m_pDevice;						// Direct3DDevice9 オブジェクト
			Target::Screen				m_BackScreen;
		};
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------