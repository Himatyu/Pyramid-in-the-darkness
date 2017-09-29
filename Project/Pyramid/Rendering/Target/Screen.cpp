/**
* @file		Screen.cpp
* @brief	バックバッファを保持する
* @author	S.OIKAWA
* @date		2016.12.28
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"Screen.h"
#include"../Graphics.h"
#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------

namespace
{
	//-----------------------------------------------------------
	// GetClaerFlag
	//-----------------------------------------------------------
	DWORD GetClaerFlag()
	{
		auto& backBuffer =
			Pyramid::Rendering::Graphics::Instantiate().PresentParameters;

		switch (backBuffer.AutoDepthStencilFormat)
		{
		case D3DFMT_D24S8:
			return D3DCLEAR_TARGET | D3DCLEAR_STENCIL | D3DCLEAR_ZBUFFER;

		case D3DFMT_D16:
			return D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER;
		default:
			___THROW_EXCEPTION_POINT(Utility::Exception, "不明なバッファの初期化");
		}

	}
}

namespace Pyramid
{
	namespace Rendering
	{
		namespace Target
		{
			//-----------------------------------------------------------
			// dtor
			//-----------------------------------------------------------
			Screen::~Screen()
			{
				SAFE_RELEASE(m_pBackBuffer);
			}

			//-----------------------------------------------------------
			// SetTarget
			//-----------------------------------------------------------
			void Screen::SetTarget()
			{
				auto pDevice = Rendering::Graphics::Instantiate().Device;

				pDevice->SetRenderTarget(0, m_pBackBuffer);
				pDevice->SetDepthStencilSurface(m_pDepthStencil);
			}

			//-----------------------------------------------------------
			// Clear
			//-----------------------------------------------------------
			void Screen::Clear()
			{
				auto pDevice = Rendering::Graphics::Instantiate().Device;

				LPDIRECT3DSURFACE9 pBackBuffer = nullptr;
				LPDIRECT3DSURFACE9 pZBuffer = nullptr;
				pDevice->GetRenderTarget(0, &pBackBuffer);
				pDevice->GetDepthStencilSurface(&pZBuffer);

				SetTarget();
				pDevice->Clear
					(0, NULL,
						GetClaerFlag(),
						D3DCOLOR_XRGB(30, 30, 0),
						1.0f, 0
						);

				pDevice->SetRenderTarget(0, pBackBuffer);
				pDevice->SetDepthStencilSurface(pZBuffer);

				SAFE_RELEASE(pBackBuffer);
				SAFE_RELEASE(pZBuffer);
			}

			//-----------------------------------------------------------
			// GetBackBuffer
			//-----------------------------------------------------------
			void Screen::GetBackBuffer()
			{
				auto pDevice = Rendering::Graphics::Instantiate().Device;

				pDevice->GetRenderTarget(0, &m_pBackBuffer);
				pDevice->GetDepthStencilSurface(&m_pDepthStencil);
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------