/**
* @file		UIMaterial.h
* @brief	UIマテリアル
* @author	S.OIKAWA
* @date		2017.05.26
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"Material.h"
#include "../Shaders/UIShader.h"
#include "../Color.h"
#include<string>
#include"../Resource/API/Texture.h"
#include"../Resource/ResourceType.h"
#include"../Resource/Texture/DirectXTextureFile.h"
#include"../Common/TextureAnimUV.h"
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------

#pragma endregion

namespace Pyramid
{
	namespace Rendering
	{
		namespace Materials
		{
			/// <summary>
			/// UIマテリアル
			/// </summary>
			class UIMaterial final : 
				public Material
			{
			public:
#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				UIMaterial(::std::string _path);
				~UIMaterial() = default;

				UIMaterial(const UIMaterial&) = default;
				UIMaterial(UIMaterial&&) = default;

				UIMaterial& operator=(const UIMaterial&) = default;
				UIMaterial& operator=(UIMaterial&&) = default;
#pragma endregion

#pragma region function
				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------

				void SetMateral() override;
				void RiseMateral() override;
				void SetMatrix(D3DXMATRIX&) override;

#pragma endregion

#pragma region property
	//-----------------------------------------------------------
	// property
	//-----------------------------------------------------------
				PROPERTY(m_pArrayUV, pArrayUV, Common::DiagonalUV);
				PROPERTY(m_pColor, pColor, Color*);
				PROPERTY_REF(m_Texture, Texture,
					Resources::TextureDx);
#pragma endregion

#pragma region value
			private:
				//-----------------------------------------------------------
				// val
				//-----------------------------------------------------------
				std::array<float, 4>					m_pArrayUV;
				Color*									m_pColor;
				Resources::TextureDx					m_Texture;
				Shaders::UIShader						m_Shader;
#pragma endregion
			};
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------