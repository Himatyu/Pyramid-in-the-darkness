/**
* @file		ProgressiveMeshShader.h
* @brief	�჌�x���p�̃��f�����ւ���r���{�[�h�̃V�F�[�_�[
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
			/// �჌�x���p�̃��f�����ւ���r���{�[�h�̃V�F�[�_�[
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