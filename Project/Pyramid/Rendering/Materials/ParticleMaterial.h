/**
* @file		ParticleMateral.cpp
* @brief	パーティクルマテリアル
* @author	S.OIKAWA
* @date		2016.09.12
*/

#pragma once
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include "Material.h"
#include "../Color.h"
#include "../Shaders/ParticleShader.h"
#include"../Resource/API/Texture.h"
#include"../Resource/ResourceType.h"
#include"../Resource/Texture/DirectXTextureFile.h"
#include"../Common/TextureAnimUV.h"
#include<array>
//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Rendering
	{
		namespace Materials
		{
			/// <summary>
			/// パーティクルのマテリアル
			/// </summary>
			class ParticleMateral final :
				public Material
			{
			public:
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				ParticleMateral();
				virtual ~ParticleMateral();

				ParticleMateral(const ParticleMateral&) = default;
				ParticleMateral(ParticleMateral&&) = default;

				ParticleMateral&operator=(const ParticleMateral&) = default;
				ParticleMateral&operator=(ParticleMateral&&) = default;

				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------
				virtual void SetMateral() override;
				virtual void RiseMateral() override;
				virtual void SetMatrix(D3DXMATRIX&) override;

				PROPERTY(m_pArrayUV, pArrayUV, Common::DiagonalUV);
				PROPERTY(m_pColor, pColor, Color*);
				PROPERTY_REF(m_Texture, Texture,
					Resources::TextureDx);

			private:
				//-----------------------------------------------------------
				// val
				//-----------------------------------------------------------
				std::array<float, 4>					m_pArrayUV;
				Color*									m_pColor;
				Shaders::ParticleShader					m_Shader;
				Resources::TextureDx					m_Texture;
			};
		}

	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------
