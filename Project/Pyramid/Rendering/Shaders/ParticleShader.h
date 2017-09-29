/**
* @file		ParticleShader.h
* @brief	�p�[�e�B�N���p�̃V�F�[�_
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
			/// �p�[�e�B�N���Ɏg�p����V�F�[�_
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
				/// UV�A�e�N�X�`���A�f�t���[�Y���f�o�C�X�ɑ��M
				/// </summary>
				void SetData();

				/// <summary>
				/// M(W)VPI���f�o�C�X�ɑ��M����.
				/// </summary>
				void SetMatrix()override;

				/// <summary>
				/// �V�F�[�_�p�X���J�n����
				/// </summary>
				void Begin() override;

				/// <summary>
				/// �V�F�[�_�p�X���I������
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
