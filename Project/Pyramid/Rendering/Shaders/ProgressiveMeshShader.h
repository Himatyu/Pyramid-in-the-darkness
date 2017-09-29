/**
* @file		ProgressiveMeshShader.h
* @brief	低レベル用のモデルを代替するビルボードのシェーダー
* @author	S.OIKAWA
* @date		2017.02.05
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
			class ProgressiveMeshMaterial;
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
			/// 低レベル用のモデルを代替するビルボードのシェーダー
			/// </summary>
			class ProgressiveMeshShader :
				public Shader
			{
			public:
#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				ProgressiveMeshShader(Materials::ProgressiveMeshMaterial*);
				~ProgressiveMeshShader();

				ProgressiveMeshShader(const ProgressiveMeshShader&) = default;
				ProgressiveMeshShader(ProgressiveMeshShader&&) = default;

				ProgressiveMeshShader& operator=(const ProgressiveMeshShader&) = default;
				ProgressiveMeshShader& operator=(ProgressiveMeshShader&&) = default;
#pragma endregion

#pragma region function
				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------
				/// <summary>
				/// UV、テクスチャ、デフューズをデバイスに送信
				/// </summary>
				void SetData();

				/// <summary>
				/// M(W)VPIをデバイスに送信する.
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
			private:
#pragma region value
				//-----------------------------------------------------------
				// val
				//-----------------------------------------------------------
				Materials::ProgressiveMeshMaterial*		m_pMaterial;

				D3DXHANDLE						m_hIMVP;
				D3DXHANDLE						m_hUV;
				D3DXHANDLE						m_hDiffuse;
				D3DXHANDLE						m_hTexDecal;

				D3DXMATRIX**					m_pMatMVP;
#pragma endregion
			};
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------