/**
* @file		Shader.h
* @brief	シェーダの基本インターフェースを提供
* @author	S.OIKAWA
* @date		2016.11.1
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include<string>
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
		namespace Shaders
		{
			/// <summary>
			/// シェーダの基本インターフェース
			/// </summary>
			class Shader
			{
			public:
#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				Shader(std::string filePath);
				virtual ~Shader();

				Shader(const Shader&);
				Shader(Shader&&) = default;

				Shader& operator=(const Shader&) = default;
				Shader& operator=(Shader&&) = default;
#pragma endregion

#pragma region function
				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------
				virtual void Begin() = 0;
				virtual void Eed() = 0;

				/// <summary>
				/// M(W)VPをデバイスに送信する.
				/// VPはレイヤーに依存する
				/// </summary>
				virtual void SetMatrix();
				
				/// <summary>
				/// RebderContextのライト情報をセットする
				/// </summary>
				void SetLight();

#pragma endregion

#pragma region property
				//-----------------------------------------------------------
				// property
				//-----------------------------------------------------------
				PROPERTY(m_pMatrix, pMatrix, D3DXMATRIX*);
				PROPERTY(m_pEffect, pEffect, LPD3DXEFFECT);
				PROPERTY_REF(m_FilePath, FilePath, std::string);
				PROPERTY_CR_R_ONLY(m_FilePath, FilePath, std::string);
#pragma endregion
			protected:
#pragma region value
				//-----------------------------------------------------------
				// val
				//-----------------------------------------------------------
				LPD3DXEFFECT			m_pEffect = nullptr;
				D3DXHANDLE				m_hMVP;
				D3DXMATRIX*				m_pMatrix;
				std::string				m_FilePath;
#pragma endregion
			};
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------