/**
* @file		DirectXTextureFile.cpp
* @brief	DirectX�e�N�X�`���t�@�C���̎���
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
					___THROW_EXCEPTION_POINT(::Utility::Exception, _path + " �摜���̎擾�Ɏ��s");
				}

				if (0 == m_ImageInfo.Height*m_ImageInfo.Width)
				{
					___THROW_EXCEPTION_POINT(::Utility::Exception, _path + " �T�C�Y��0�̃e�N�X�`����ǂݍ���");
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
					___THROW_EXCEPTION_POINT(::Utility::Exception, _path + " :�e�N�X�`���������s");
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