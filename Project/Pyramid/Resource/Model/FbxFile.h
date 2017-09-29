/**
* @file		FbxFile.h
* @brief	Fbxファイル
* @author	S.OIKAWA
* @date		2016.09.12
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include<d3dx9.h>
#include<string>
#include<vector>
#include<memory>
#include<unordered_map>
#include"IModelFile.h"
#include "../IResource.h"
#include"../DataObject/Entity/FbxFile.h"
#include"../Rendering/Buffer.h"
#include"../Includer/CommonIncluder.h"
#include"../Common/Diagram/AABB.h"
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
	namespace Resources
	{
		namespace Model
		{
			class FbxInnerMesh;

			using ModelUVMap =
				std::unordered_map<std::string, std::vector<D3DXVECTOR2>>;

			using MeshMaterialArray =
				std::vector<Rendering::Materials::MeshMaterial*>;
#pragma endregion

			/// <summary>
			/// ゲームに使用するFbxのリソース
			/// </summary>
			class FbxFile final :
				public IModelFile
			{
			public:
#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				FbxFile() = default;
				~FbxFile();

				FbxFile(const FbxFile&) = default;
				FbxFile(FbxFile&&) = default;

				FbxFile& operator=(const FbxFile&) = default;
				FbxFile& operator=(FbxFile&&) = default;
#pragma endregion

#pragma region function
				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------

				/// <summary>
				/// ファイル読み込み.
				/// </summary>
				/// <param name="_path">ファイルパス</param>
				/// <returns>読み込み成功判定</returns>
				void Read(std::string _path) override;

				/// <summary>
				/// デバイス依存のデータ作成.
				/// </summary>
				void InitializeUseDaveice() override;

				/// <summary>
				/// 情報を破棄する.
				/// </summary>
				void Discard() override;

				/// <summary>
				/// ワールド行列を設定
				/// </summary>
				void SetMatrix(D3DXMATRIX&);

#pragma endregion

#pragma region property
				//-----------------------------------------------------------
				// property
				//-----------------------------------------------------------
			public:
				PROPERTY_REF(m_pEntity->Meshs, Meshs, std::vector<FbxInnerMesh*>);

#pragma endregion

#pragma region value
				//-----------------------------------------------------------
				// val
				//-----------------------------------------------------------
				DataObject::Entity::FbxFile*	m_pEntity;

#pragma endregion
			};

			/// <summary>
			/// Fbxファイル内にあるメッシュをリスト保持
			/// </summary>
			class FbxInnerMesh final
			{
			public:

				//-----------------------------------------------------------
				// defaults 
				//-----------------------------------------------------------

				FbxInnerMesh() = default;
				~FbxInnerMesh();

				FbxInnerMesh(const FbxInnerMesh&) = default;
				FbxInnerMesh(FbxInnerMesh&&) = default;

				FbxInnerMesh&operator=(const FbxInnerMesh&) = default;
				FbxInnerMesh&operator=(FbxInnerMesh&&) = default;

				//-----------------------------------------------------------
				// function 
				//-----------------------------------------------------------
				bool IsHasUV();

				//-----------------------------------------------------------
				// property 
				//-----------------------------------------------------------
				PROPERTY_REF(m_IndexCount, IndexCount, size_t);
				PROPERTY_REF(m_VertexCount, VertexCount, size_t);
				PROPERTY_REF(m_PolygonCount, PolygonCount, size_t);

				PROPERTY_REF(m_VertexArray, VertexArray, std::vector<D3DXVECTOR3>);
				PROPERTY_REF(m_IndexArray, IndexArray, std::vector<int>);
				PROPERTY_REF(m_NormalArray, NormalArray, std::vector<D3DXVECTOR3>);

				PROPERTY_REF(m_UVs, UVs, ModelUVMap);
				PROPERTY_REF(m_Materials, Materials, MeshMaterialArray);

				PROPERTY_REF(m_VertexBuffer, VertexBuffer, Rendering::DirectXVertexBuffer);
				PROPERTY_REF(m_IndexBuffer, IndexBuffer, Rendering::DirectXIndexBuffer);
				PROPERTY_REF(m_Declaration, Declaration, LPDIRECT3DVERTEXDECLARATION9);

				PROPERTY_REF(m_Volume, Volume, Common::Diagram::AABB);
				//-----------------------------------------------------------
				// val
				//-----------------------------------------------------------
			private:

				std::vector<D3DXVECTOR3> m_VertexArray;
				std::vector<int>		 m_IndexArray;
				std::vector<D3DXVECTOR3> m_NormalArray;

				ModelUVMap m_UVs;

				size_t m_IndexCount = 0;
				size_t m_VertexCount = 0;
				size_t m_PolygonCount = 0;

				MeshMaterialArray m_Materials;

				Rendering::DirectXVertexBuffer  m_VertexBuffer;
				Rendering::DirectXIndexBuffer	m_IndexBuffer;
				LPDIRECT3DVERTEXDECLARATION9	m_Declaration = nullptr;

				Common::Diagram::AABB			m_Volume;
			};
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------