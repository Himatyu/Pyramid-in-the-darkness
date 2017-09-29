/**
* @file		DirectXTextureFileFromInMemory.cpp
* @brief	�o�b�t�@����DirectX�̃e�N�X�`���𐶐�����@�\��
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
					___THROW_EXCEPTION_POINT(::Utility::Exception, m_Cache.first + " �摜���̎擾�Ɏ��s");
				}

				if (0 == m_ImageInfo.Height*m_ImageInfo.Width)
				{
					___THROW_EXCEPTION_POINT(::Utility::Exception, m_Cache.first + " �T�C�Y��0�̃e�N�X�`����ǂݍ���");
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
					___THROW_EXCEPTION_POINT(::Utility::Exception, m_Cache.first + " :�e�N�X�`���������s");
				}
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------
