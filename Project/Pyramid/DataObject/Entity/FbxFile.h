/**
* @file		FbxFile.h
* @brief	FBXファイルのEntityを提供
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
			/// メッシュ
			/// </summary>
			struct Mesh_Vertex
			{
				D3DXVECTOR3 pos;
				D3DXVECTOR3 normal;
				D3DXVECTOR2 uv;
			};

			/// <summary>
			/// UVを持たないメッシュ
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
		/// Fbxの機能提供をリソースに対して行う
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
			/// マテリアルやバッファ生成を行う
			/// Texture生成などのデバイスを使用する処理をここで行う
			/// </summary>
			void InitializeUseDaveice() override;

			/// <summary>
			/// 行列を設定する
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