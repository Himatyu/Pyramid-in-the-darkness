/**
* @file		MeshShader.h
* @brief	基本シェーダ
* @author	S.OIKAWA
* @date		2016.11.1
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include<d3d9.h>
#include<d3dx9.h>
#include<array>
#include<string>
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
			class MeshMaterial;
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
			/// Meshに使用するシェーダ
			/// </summary>
			class MeshShader final
				: public Shader
			{
			public:
#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				MeshShader(Materials::MeshMaterial*,std::string);
				~MeshShader() = default;

				MeshShader(const MeshShader&);
				MeshShader(MeshShader&&) = default;

				MeshShader& operator=(const MeshShader&) = default;
				MeshShader& operator=(MeshShader&&) = default;
#pragma endregion

#pragma region function
				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------

				/// <summary>
				/// マテリアルの色情報をデバイスに送る
				/// </summary>
				void SetColorFromMaterial();

				/// <summary>
				/// テクスチャをデバイスに送信する
				/// </summary>
				void SetTextureFromMaterial();

				/// <summary>
				/// シェーダパスを開始する
				/// </summary>
				void Begin() override;

				/// <summary>
				/// シェーダパスを終了する
				/// </summary>
				void Eed() override;

			private:
				void InitHandele();
#pragma endregion

#pragma region value
				//-----------------------------------------------------------
				// val
				//-----------------------------------------------------------
				std::array<float, 23>			m_ColorChunk;
				Materials::MeshMaterial*		m_pMaterial;
				D3DXHANDLE						m_hColorChunk;
				D3DXHANDLE						m_hTexDiffuse;
				D3DXHANDLE						m_hTexEmissive;
				D3DXHANDLE						m_hTexSpecular;
				D3DXHANDLE						m_hTexBump;

#pragma endregion
			};
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------