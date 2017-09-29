/**
* @file		MeshShader.h
* @brief	��{�V�F�[�_
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
			/// Mesh�Ɏg�p����V�F�[�_
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
				/// �}�e���A���̐F�����f�o�C�X�ɑ���
				/// </summary>
				void SetColorFromMaterial();

				/// <summary>
				/// �e�N�X�`�����f�o�C�X�ɑ��M����
				/// </summary>
				void SetTextureFromMaterial();

				/// <summary>
				/// �V�F�[�_�p�X���J�n����
				/// </summary>
				void Begin() override;

				/// <summary>
				/// �V�F�[�_�p�X���I������
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