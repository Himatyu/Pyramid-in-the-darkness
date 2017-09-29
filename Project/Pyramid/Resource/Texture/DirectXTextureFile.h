/**
* @file		DirectXTextureFile.h
* @brief	DirectXテクスチャを扱う
* @author	S.OIKAWA
* @date		2016.08.21
*/
#pragma once

//-----------------------------------------------------------
// include 
//-----------------------------------------------------------
#include<d3d9.h>
#include<d3dx9.h>
#include "ITextureFile.h"

//-----------------------------------------------------------
// define 
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Resources
	{
		namespace Texture
		{
			/// <summary>
			/// DirectX形式のテクスチャを扱う.
			/// </summary>
			class DirectXTextureFile :
				public ITextureFile
			{
			public:

				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				DirectXTextureFile() = default;
				virtual ~DirectXTextureFile();

				DirectXTextureFile(const DirectXTextureFile&) = default;
				DirectXTextureFile(DirectXTextureFile&&) = default;

				DirectXTextureFile&operator=(const DirectXTextureFile&) = default;
				DirectXTextureFile&operator=(DirectXTextureFile&&) = default;

				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------

				/// <summary>
				/// ファイル読み込み.
				/// </summary>
				/// <param name="_path">ファイルパス</param>
				/// <returns>読み込み成功是非</returns>
				void Read(std::string _path) override;

				/// <summary>
				/// 情報を破棄する.
				/// </summary>
				void Discard() override;

				//-----------------------------------------------------------
				// operator
				//-----------------------------------------------------------
				PROPERTY(m_ImageInfo, Info, D3DXIMAGE_INFO);
				PROPERTY(m_ColorKey, ColorKey, D3DCOLOR);
				PROPERTY(m_Usage, Usage, DWORD);
				PROPERTY(m_Filter, Filter, DWORD);
				PROPERTY(m_MipFilter, MipFilter, DWORD);
				PROPERTY(m_MipLevels, MipLevels, UINT);
				PROPERTY(m_Format, Format, D3DFORMAT);
				PROPERTY(m_Pool, Pool, D3DPOOL);
				PROPERTY(m_pTexture, pTexture, IDirect3DTexture9*);

			protected:
				//-----------------------------------------------------------
				// Val
				//-----------------------------------------------------------
				D3DXIMAGE_INFO		m_ImageInfo;					//画像情報
				D3DCOLOR			m_ColorKey = 0;					//完全に透明にする色
				DWORD				m_Usage = 0;					//テクスチャの性質・確保するメモリの場所
				DWORD				m_Filter = D3DX_DEFAULT;		//イメージのフィルタリング方法
				DWORD				m_MipFilter = D3DX_DEFAULT;		//ミップマップに対して行われるフィルタリング法
				UINT				m_MipLevels = 1;				//ミップマップレベル
				D3DFORMAT			m_Format = D3DFMT_A8R8G8B8;		//ピクセルフォーマット
				D3DPOOL				m_Pool = D3DPOOL_DEFAULT;		//テクスチャを格納するメモリの位置と管理
				IDirect3DTexture9*	m_pTexture = nullptr;			//テクスチャポインタ	

			};
		}
	}
}
//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------