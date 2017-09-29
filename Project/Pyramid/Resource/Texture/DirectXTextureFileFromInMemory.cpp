/**
* @file		DirectXTextureFileFromInMemory.cpp
* @brief	バッファからDirectXのテクスチャを生成する機能提供
* @author	S.OIKAWA
* @date		2016.10.26
*/

//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include "DirectXTextureFileFromInMemory.h"
#include"../Rendering/Graphics.h"

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Resources
	{
		namespace Texture
		{

			//-----------------------------------------------------------
			// ctor
			//-----------------------------------------------------------
			DirectXTextureFileFromInMemory::
				DirectXTextureFileFromInMemory(
					std::pair<std::string, std::vector<char>>&& _data) :
				m_Cache(_data)
			{
			}

			//-----------------------------------------------------------
			// CreateTexture
			//-----------------------------------------------------------
			void DirectXTextureFileFromInMemory::CreateTexture()
			{
				SetFilePathInfo(m_Cache.first);
				auto& buff = m_Cache.second;
				auto pDevice = Rendering::Graphics::Instantiate().Device;

				if (FAILED(D3DXGetImageInfoFromFileInMemory(buff.data(), buff.size(), &m_ImageInfo)))
				{
					___THROW_EXCEPTION_POINT(::Utility::Exception, m_Cache.first + " 画像情報の取得に失敗");
				}

				if (0 == m_ImageInfo.Height*m_ImageInfo.Width)
				{
					___THROW_EXCEPTION_POINT(::Utility::Exception, m_Cache.first + " サイズが0のテクスチャを読み込み");
				}

				if (FAILED(
					D3DXCreateTextureFromFileInMemoryEx
					(
						pDevice,
						buff.data(),
						buff.size(),
						m_ImageInfo.Width,
						m_ImageInfo.Height,
						m_MipLevels,
						m_Usage,
						m_Format,
						m_Pool,
						m_Filter,
						m_MipFilter,
						m_ColorKey,
						&m_ImageInfo,
						NULL,
						&m_pTexture
					)
				))
				{
					___THROW_EXCEPTION_POINT(::Utility::Exception, m_Cache.first + " :テクスチャ生成失敗");
				}
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------
