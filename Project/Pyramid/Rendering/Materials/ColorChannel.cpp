/**
* @file		ColorChannel.cpp
* @brief	カラーチャンネル
* @author	S.OIKAWA
* @date		2016.10.15
*/

//-----------------------------------------------------------
// include 
//-----------------------------------------------------------
#include "ColorChannel.h"
#include"Estd.h"
//-----------------------------------------------------------
// define 
//-----------------------------------------------------------

namespace Pyramid
{
	namespace Rendering
	{
		namespace Materials
		{
			//-----------------------------------------------------------
			// ctor
			//-----------------------------------------------------------
			ColorChannel::ColorChannel():
				m_UseTextureIndex(0),
				m_Color{1}
			{
			}

			//-----------------------------------------------------------
			// ctor
			//-----------------------------------------------------------
			ColorChannel::ColorChannel(const ColorChannel & _other):
				m_Color(_other.m_Color),
				m_UseTextureIndex(_other.m_UseTextureIndex),
				m_Textures(_other.m_Textures),
				m_TextureNames(_other.m_TextureNames)
			{
				
			}

			//-----------------------------------------------------------
			// dtor
			//-----------------------------------------------------------
			ColorChannel::~ColorChannel()
			{
			}
			
			//-----------------------------------------------------------
			// GetTexture
			//-----------------------------------------------------------
			IDirect3DTexture9 * ColorChannel::GetTexture(const UINT _index)
			{
				if (!m_Textures.size() || m_Textures.size() < _index)
				{
					return nullptr;
				}
				return m_Textures[_index]->pTexture;
			}
		}
	}
}
//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------