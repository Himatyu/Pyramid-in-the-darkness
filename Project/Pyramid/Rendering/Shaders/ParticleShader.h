/**
* @file		ParticleShader.h
* @brief	パーティクル用のシェーダ
* @author	S.OIKAWA
* @date		2016.12.1
*/
#pragma once

//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"Shader.h"
//-----------------------------------------------------------
//  define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Rendering
	{
		namespace Materials
		{
			class ParticleMateral;
		}
	}
}
namespace Pyramid
{
	namespace Rendering
	{
		namespace Shaders
		{
			/// <summary>
			/// パーティクルに使用するシェーダ
			/// </summary>
			class ParticleShader : 
				public Shader
			{
			public:

				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				ParticleShader(Materials::ParticleMateral*);
				~ParticleShader();

				ParticleShader(const ParticleShader&) = default;
				ParticleShader(ParticleShader&&) = default;

				ParticleShader&operator=(const ParticleShader&) = default;
				ParticleShader&operator=(ParticleShader&&) = default;

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

				//-----------------------------------------------------------
				// val
				//-----------------------------------------------------------
			private:
				Materials::ParticleMateral*		m_pMaterial;
				D3DXHANDLE						m_hIMVP;
				D3DXHANDLE						m_hUV;
				D3DXHANDLE						m_hDiffuse;
				D3DXHANDLE						m_hTexDecal;

				D3DXMATRIX**					m_pMatMVP;
			};
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------
