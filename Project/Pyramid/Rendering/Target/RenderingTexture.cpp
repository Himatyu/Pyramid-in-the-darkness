/**
* @file		RenderingTexture.h
* @brief	レンダリングターゲットとしてのテクスチャ
* @author	S.OIKAWA
* @date		2016.12.28
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"RenderingTexture.h"
#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Rendering
	{
		namespace Target
		{
			//-----------------------------------------------------------
			// Create
			//-----------------------------------------------------------
			void RenderingTexture::Create(
				UINT _width,
				UINT _height,
				D3DFORMAT _format,
				D3DPOOL _pool,
				D3DFORMAT _bufferFormat,
				D3DMULTISAMPLE_TYPE _bufferMultiSample)
			{
				auto pDevice = Rendering::Graphics::Instantiate().Device;
				if (FAILED(
					D3DXCreateTexture(
						pDevice,
						_width,
						_height,
						0,
						D3DUSAGE_RENDERTARGET,
						_format,
						_pool,
						&m_pTexture)))
				{
					___THROW_EXCEPTION_POINT(Utility::Exception, "テクスチャの作成に失敗しました");
					return;
				}

				D3DSURFACE_DESC desc;
				m_pTexture->GetLevelDesc(0, &desc);
				if (FAILED(pDevice->CreateDepthStencilSurface(desc.Width, desc.Height,
					D3DFMT_D16, _bufferMultiSample, 0, true, &m_pDepthStencil, NULL)))
				{
					___THROW_EXCEPTION_POINT(Utility::Exception, "テクスチャ用のZバッファ作成に失敗しました");
					return;
				}
			}

			//-----------------------------------------------------------
			// SetTarget
			//-----------------------------------------------------------
			void RenderingTexture::SetTarget()
			{
				auto pDevice = Rendering::Graphics::Instantiate().Device;
				LPDIRECT3DSURFACE9 pSurf = NULL;

				m_pTexture->GetSurfaceLevel(0, &pSurf);
				pDevice->SetRenderTarget(0, pSurf);
				pDevice->SetDepthStencilSurface(m_pDepthStencil);

				SAFE_RELEASE(pSurf);
			}

			//-----------------------------------------------------------
			// Clear
			//-----------------------------------------------------------
			void RenderingTexture::Clear()
			{
				auto pDevice = Rendering::Graphics::Instantiate().Device;

				LPDIRECT3DSURFACE9 pBackBuffer = nullptr;
				LPDIRECT3DSURFACE9 pZBuffer = nullptr;
				pDevice->GetRenderTarget(0, &pBackBuffer);
				pDevice->GetDepthStencilSurface(&pZBuffer);

				SetTarget();
				auto s = pDevice->Clear
					(0, NULL,
						D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER,
						D3DCOLOR_XRGB(60, 60, 0),
						1.0f, 0
						);

				pDevice->SetRenderTarget(0, 0);
				pDevice->SetDepthStencilSurface(pZBuffer);

				SAFE_RELEASE(pBackBuffer);
				SAFE_RELEASE(pZBuffer);
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------