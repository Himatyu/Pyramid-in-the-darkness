/**
* @file		ColorChannel.h
* @brief	レンダリングで使用する色情報を提供
* @author	S.OIKAWA
* @date		2016.10.26
*/
#pragma once

//-----------------------------------------------------------
// include 
//-----------------------------------------------------------
#include"../../Resource/Texture/DirectXTextureFileFromInMemory.h"
#include<array>
#include<string>
//-----------------------------------------------------------
// define 
//-----------------------------------------------------------

namespace Pyramid
{
	namespace Rendering
	{
		namespace Materials
		{
			using ColorValue = std::array<float, 4>;
			using spTextures = 
				std::vector<
					std::shared_ptr<Resources::Texture::DirectXTextureFileFromInMemory>>;
			/// <summary>
			/// レンダリングで使用する色情報
			/// </summary>
			class ColorChannel final
			{
			public:
				//-----------------------------------------------------------
				// defaults 
				//-----------------------------------------------------------
				ColorChannel();
				~ColorChannel();

				ColorChannel(const ColorChannel&);
				ColorChannel(ColorChannel&&) = default;

				ColorChannel&operator=(const ColorChannel&) = default;
				ColorChannel&operator=(ColorChannel&&) = default;

				
				//-----------------------------------------------------------
				// PROPERTY
				//-----------------------------------------------------------
				PROPERTY_REF(m_Color, Value, ColorValue);
				PROPERTY_REF(m_Textures, Textures, spTextures);
				PROPERTY_REF(m_TextureNames, TextureNames, std::vector<std::string>);
				PROPERTY_REF(m_UseTextureIndex, UseTextureIndex, UINT);

				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------

				/// <summary>
				/// テクスチャの取得
				/// </summary>
				IDirect3DTexture9* GetTexture(const UINT index);

				//-----------------------------------------------------------
				// val
				//-----------------------------------------------------------
			private:
				ColorValue						m_Color;
				spTextures						m_Textures;
				std::vector<std::string>		m_TextureNames;
				UINT							m_UseTextureIndex;
			};
		}
	}
}

//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------