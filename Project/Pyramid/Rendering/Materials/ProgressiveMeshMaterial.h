/**
* @file		ProgressiveMeshMaterial.h
* @brief	低レベルモデル用のマテリアル
* @author	S.OIKAWA
* @date		2017.02.05
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"../Materials/Material.h"
#include"../Shaders/ProgressiveMeshShader.h"
#include"../Color.h"
#include"../Common/Defines.h"
#include"../../Resource/ResourceType.h"
#include<array>
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
			/// 低レベルモデル用のマテリアル
			/// </summary>
			class ProgressiveMeshMaterial :
				public Material
			{
			public:
#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				ProgressiveMeshMaterial();
				~ProgressiveMeshMaterial() = default;

				ProgressiveMeshMaterial(const ProgressiveMeshMaterial&) = default;
				ProgressiveMeshMaterial(ProgressiveMeshMaterial&&) = default;

				ProgressiveMeshMaterial& operator=(const ProgressiveMeshMaterial&) = default;
				ProgressiveMeshMaterial& operator=(ProgressiveMeshMaterial&&) = default;
#pragma endregion

#pragma region function
				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------
				virtual void SetMateral() override;
				virtual void RiseMateral() override;
				virtual void SetMatrix(D3DXMATRIX&) override;
#pragma endregion

#pragma region property
				//-----------------------------------------------------------
				// property
				//-----------------------------------------------------------
				PROPERTY(m_ArrayUV, ArrayUV, Common::DiagonalUV);
				PROPERTY_REF(m_Color, OverlapColor, Color);
				PROPERTY_REF(m_Texture, Texture, Resources::TextureDx);

#pragma endregion
			private:
#pragma region value
				//-----------------------------------------------------------
				// val
				//-----------------------------------------------------------
				Shaders::ProgressiveMeshShader			m_Shader;
				Common::DiagonalUV						m_ArrayUV;
				Color									m_Color;
				Resources::TextureDx					m_Texture;
#pragma endregion
			};
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------