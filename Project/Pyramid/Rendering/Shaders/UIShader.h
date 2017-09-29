/**
* @file		UIShader.h
* @brief	UIのShader
* @author	S.OIKAWA
* @date		2017.05.26
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"Shader.h"
#include<string>

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
			class UIMaterial;
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
			/// <summary>
			///UIのShader
			///基本的に半透明
			/// </summary>
			class UIShader : 
				public Shader
			{
			public:
#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				UIShader(Materials::UIMaterial* _pMat,::std::string _path);
				~UIShader() = default;

				UIShader(const UIShader&) = default;
				UIShader(UIShader&&) = default;

				UIShader& operator=(const UIShader&) = default;
				UIShader& operator=(UIShader&&) = default;
#pragma endregion

#pragma region function
				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------

				void SetData();

				/// <summary>
				/// 行列をデバイスに送信する.
				/// </summary>
				void SetMatrix()override;

				/// <summary>
				/// シェーダパスを開始する
				/// </summary>
				void Begin() override;

				/// <summary>
				/// シェーダパスを終了する
				/// </summary>
				void Eed() override;
#pragma endregion

#pragma region property
	//-----------------------------------------------------------
	// property
	//-----------------------------------------------------------

#pragma endregion

#pragma region value
	//-----------------------------------------------------------
	// val
	//-----------------------------------------------------------
			private:
				Materials::UIMaterial*		m_pMaterial;
				D3DXHANDLE					m_hDiffuse;
				D3DXHANDLE					m_hTexture;
				D3DXHANDLE					m_hUV;
				D3DXHANDLE					m_hWorld;
				D3DXHANDLE					m_hProjection;

#pragma endregion
			};
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------