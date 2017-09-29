/**
* @file		DirectXTextureFile.cpp
* @brief	DirectXテクスチャファイルの実装
* @author	S.OIKAWA
* @date		2016.08.21
*/

//-----------------------------------------------------------
// include 
//-----------------------------------------------------------
#include "DirectXTextureFile.h"
#include"../Rendering/Graphics.h"

namespace Pyramid
{
	namespace Resources
	{
		namespace Texture
		{

			using namespace Blueprint;
			//-----------------------------------------------------------
			// dtor
			//-----------------------------------------------------------
			DirectXTextureFile::~DirectXTextureFile()
			{
				Discard();
			}

			//-----------------------------------------------------------
			// Read 
			//-----------------------------------------------------------
			void DirectXTextureFile::Read(std::string _path)
			{
				SetFilePathInfo(_path);
				auto pDevice = Rendering::Graphics::Instantiate().Device;

				if (FAILED(D3DXGetImageInfoFromFile(_path.c_str(), &m_ImageInfo)))
				{
					___THROW_EXCEPTION_POINT(::Utility::Exception, _path + " 画像情報の取得に失敗");
				}

				if (0 == m_ImageInfo.Height*m_ImageInfo.Width)
				{
					___THROW_EXCEPTION_POINT(::Utility::Exception, _path + " サイズが0のテクスチャを読み込み");
				}

				if (FAILED(
					D3DXCreateTextureFromFileEx
					(
						pDevice,
						_path.c_str(),
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
					___THROW_EXCEPTION_POINT(::Utility::Exception, _path + " :テクスチャ生成失敗");
				}
			}

			//-----------------------------------------------------------
			// Discard
			//-----------------------------------------------------------
			void DirectXTextureFile::Discard()
			{
				SAFE_RELEASE(m_pTexture);
			}
		}
	}
}

//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------