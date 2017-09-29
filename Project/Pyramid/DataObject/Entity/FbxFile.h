/**
* @file		FbxFile.h
* @brief	FBX�t�@�C����Entity���
* @author	S.OIKAWA
* @date		2016.10.15
*/
#pragma once
//-----------------------------------------------------------
// include 
//-----------------------------------------------------------
#include<vector>
#include<string>
#include"../Resource/Model/IModelFile.h"
//-----------------------------------------------------------
// define 
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Resources
	{
		namespace Model
		{
			class FbxInnerMesh;
		}
	}
}

namespace DataObject
{
	namespace Entity
	{
		namespace Fbx
		{
			/// <summary>
			/// ���b�V��
			/// </summary>
			struct Mesh_Vertex
			{
				D3DXVECTOR3 pos;
				D3DXVECTOR3 normal;
				D3DXVECTOR2 uv;
			};

			/// <summary>
			/// UV�������Ȃ����b�V��
			/// </summary>
			struct Mesh_Vertex_NonHasUV
			{
				D3DXVECTOR3 pos;
				D3DXVECTOR3 normal;
			};
		}

		using InnerMeshs = 
			std::vector<Pyramid::Resources::Model::FbxInnerMesh*>;

		/// <summary>
		/// Fbx�̋@�\�񋟂����\�[�X�ɑ΂��čs��
		/// </summary>
		class FbxFile final :
			public Pyramid::Resources::Model::IModelFile
		{
		public:
			//-----------------------------------------------------------
			// defaults
			//-----------------------------------------------------------
			FbxFile() = default;
			~FbxFile();

			FbxFile(const FbxFile&) = default;
			FbxFile(FbxFile&&) = default;

			FbxFile&operator=(const FbxFile&) = default;
			FbxFile&operator=(FbxFile&&) = default;

			//-----------------------------------------------------------
			// function
			//-----------------------------------------------------------

			/// <summary>
			/// �}�e���A����o�b�t�@�������s��
			/// Texture�����Ȃǂ̃f�o�C�X���g�p���鏈���������ōs��
			/// </summary>
			void InitializeUseDaveice() override;

			/// <summary>
			/// �s���ݒ肷��
			/// </summary>
			void SetMatrix(D3DXMATRIX&) override;

		private:
			void LoadTexture();
			void CreateRenderingBuffer();
			void CreateDeclaration();
		public:
			//-----------------------------------------------------------
			// property
			//-----------------------------------------------------------
			PROPERTY_REF(m_Meshs, Meshs, InnerMeshs);

		private:
			InnerMeshs				m_Meshs;
		};
	}
}
//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------