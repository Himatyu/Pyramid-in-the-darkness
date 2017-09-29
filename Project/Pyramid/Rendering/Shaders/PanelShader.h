/**
* @file		PanelShader.h
* @brief
* @author
* @date
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"Shader.h"

#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Rendering
	{
		namespace Materials
		{
			class PanelMaterial;
		}
	}
}
#pragma endregion

namespace Pyramid
{
	namespace Rendering
	{
		namespace Shaders
		{
			class PanelShader :
				public Shader
			{
			public:
#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				PanelShader(Materials::PanelMaterial*);
				~PanelShader() = default;

				PanelShader(const PanelShader&) = default;
				PanelShader(PanelShader&&) = default;

				PanelShader& operator=(const PanelShader&) = default;
				PanelShader& operator=(PanelShader&&) = default;
#pragma endregion

#pragma region function
				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------

				/// <summary>
				/// シェーダパスを開始する
				/// </summary>
				void Begin() override;

				/// <summary>
				/// シェーダパスを終了する
				/// </summary>
				void Eed() override;

				/// <summary>
				/// デバイスにデータを送信する
				/// </summary>
				void PushDate();
#pragma endregion

#pragma region property
	//-----------------------------------------------------------
	// property
	//-----------------------------------------------------------

#pragma endregion
			private:
#pragma region value
	//-----------------------------------------------------------
	// val
	//-----------------------------------------------------------
				Materials::PanelMaterial*		m_pMaterial;
				D3DXHANDLE						m_hDiffuse;
				D3DXHANDLE						m_hTexture;
#pragma endregion
			};
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------