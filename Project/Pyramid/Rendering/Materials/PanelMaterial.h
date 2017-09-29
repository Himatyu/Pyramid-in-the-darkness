/**
* @file		PanelMaterial.h
* @brief
* @author
* @date
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"Material.h"
#include "../Color.h"
#include "../Shaders/PanelShader.h"
#include<d3dx9.h>
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
			/// 
			/// </summary>
			class PanelMaterial : 
				public Material
			{
			public:
#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				PanelMaterial();
				~PanelMaterial() = default;

				PanelMaterial(const PanelMaterial&) = default;
				PanelMaterial(PanelMaterial&&) = default;

				PanelMaterial& operator=(const PanelMaterial&) = default;
				PanelMaterial& operator=(PanelMaterial&&) = default;
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
				PROPERTY(m_pTexture, pTexture, IDirect3DTexture9*);
				PROPERTY_REF(m_Diffuse, Diffuse, Color);

#pragma endregion
			private:
#pragma region value
	//-----------------------------------------------------------
	// val
	//-----------------------------------------------------------
				Shaders::PanelShader	m_Shader;
				IDirect3DTexture9*		m_pTexture = nullptr;
				Color					m_Diffuse;
#pragma endregion
			};
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------