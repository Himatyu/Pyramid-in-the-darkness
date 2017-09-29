/**
* @file		FbxFile.cpp
* @brief	FBXファイルのEntity
* @author	S.OIKAWA
* @date		2016.10.15
*/

//-----------------------------------------------------------
// include 
//-----------------------------------------------------------
#include"FbxFile.h"
#include"../Rendering/Graphics.h"
#include"../Resource/Model/FbxFile.h"
#include"../Rendering/Buffer.h"
#include"../Rendering/Materials/MeshMaterial.h"
#include"../Rendering/Materials/ColorChannel.h"
#include<algorithm>
#include<iostream>
#include<string>
#include"Estd.h"
//-----------------------------------------------------------
// define 
//-----------------------------------------------------------
namespace DataObject
{
	namespace Entity
	{
		namespace Fbx
		{
			DWORD FVF_VERTEX_3D = (D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_TEX1);
			DWORD FVF_VERTEX_3D_NON_UV =(D3DFVF_XYZ | D3DFVF_NORMAL );

		}
	}
}
using namespace std;

namespace DataObject
{
	namespace Entity
	{
		//-----------------------------------------------------------
		// dtor
		//-----------------------------------------------------------
		FbxFile::~FbxFile()
		{
			Utility::Estd::for_each(
				m_Meshs, 
				[](auto& _) {SAFE_DELETE(_); });
		}

		//-----------------------------------------------------------
		// InitializeUseDaveice
		//-----------------------------------------------------------
		void FbxFile::InitializeUseDaveice()
		{
			LoadTexture();
			CreateRenderingBuffer();
			CreateDeclaration();
		}


		//-----------------------------------------------------------
		// SetMatrix
		//-----------------------------------------------------------
		void FbxFile::SetMatrix(D3DXMATRIX& _mat)
		{
			for (auto& _ : m_Meshs)
			{
				for (auto& pMat : _->Materials)
				{
					pMat->SetMatrix(_mat);
				}
			}
		}

		//-----------------------------------------------------------
		// LoadTexture
		//-----------------------------------------------------------
		void FbxFile::LoadTexture()
		{
			auto TextureCreate =
				[](Pyramid::Rendering::Materials::ColorChannel& _color)
			{
				for (auto& tex : _color.Textures)
				{
					tex->CreateTexture();
				}
			};

			for (auto& mesh : m_Meshs)
			{
				for (auto& _ : mesh->Materials)
				{
					TextureCreate(_->Ambient);
					TextureCreate(_->Bump);
					TextureCreate(_->Diffuse);
					TextureCreate(_->Emissive);
					TextureCreate(_->Specular);
				}
			}

		}

		//-----------------------------------------------------------
		// CreateRenderingBuffer
		//-----------------------------------------------------------
		void FbxFile::CreateRenderingBuffer()
		{
			auto pDevice = Pyramid::Rendering::Graphics::Instantiate().Device;

			//HACK DRY違反
			for (auto& mesh : m_Meshs)
			{
				mesh->VertexBuffer.Count = mesh->VertexCount;
				if (mesh->IsHasUV())
				{
					mesh->VertexBuffer.TypeSize = sizeof(Fbx::Mesh_Vertex);

					mesh->VertexBuffer.Create(
						mesh->VertexCount * sizeof(Fbx::Mesh_Vertex),
						D3DUSAGE_WRITEONLY,
						Fbx::FVF_VERTEX_3D,
						D3DPOOL_MANAGED,
						&(mesh->VertexBuffer.Data),
						NULL);

					mesh->IndexBuffer.Create(
						mesh->IndexCount * sizeof(int),
						D3DUSAGE_WRITEONLY,
						D3DFMT_INDEX32,
						D3DPOOL_MANAGED,
						&mesh->IndexBuffer.Data,
						NULL);

					//ロック
					Fbx::Mesh_Vertex* vertex;
					int*		index;

					mesh->VertexBuffer.Data->Lock(0, 0, (void**)&vertex, 0);
					mesh->IndexBuffer.Data->Lock(0, 0, (void**)&index, 0);

					//書き込み
					auto& uv = (*mesh->UVs.begin()).second;
					for (unsigned i = 0; i < mesh->VertexCount; i++)
					{
						vertex[i].pos = mesh->VertexArray[i];
						vertex[i].normal = mesh->NormalArray[i];
						vertex[i].uv = uv[i];
					}

					for (unsigned i = 0; i < mesh->IndexCount; i++)
					{
						index[i] = mesh->IndexArray[i];
					}

					//アンロック
					mesh->VertexBuffer.Data->Unlock();
					mesh->IndexBuffer.Data->Unlock();

				}
				else
				{
					
					mesh->VertexBuffer.TypeSize = sizeof(Fbx::Mesh_Vertex_NonHasUV);

					mesh->VertexBuffer.Create(
						mesh->VertexCount * sizeof(Fbx::Mesh_Vertex_NonHasUV),
						D3DUSAGE_WRITEONLY,
						Fbx::FVF_VERTEX_3D_NON_UV,
						D3DPOOL_MANAGED,
						&(mesh->VertexBuffer.Data),
						NULL);

					mesh->IndexBuffer.Create(
						mesh->IndexCount * sizeof(int),
						D3DUSAGE_WRITEONLY,
						D3DFMT_INDEX32,
						D3DPOOL_MANAGED,
						&mesh->IndexBuffer.Data,
						NULL);

					//ロック
					Fbx::Mesh_Vertex_NonHasUV* vertex;
					int*		index;

					mesh->VertexBuffer.Data->Lock(0, 0, (void**)&vertex, 0);
					mesh->IndexBuffer.Data->Lock(0, 0, (void**)&index, 0);

					//書き込み
					for (unsigned i = 0; i < mesh->VertexCount; i++)
					{
						vertex[i].pos = mesh->VertexArray[i];
						vertex[i].normal = mesh->NormalArray[i];
					}

					for (unsigned i = 0; i < mesh->IndexCount; i++)
					{
						index[i] = mesh->IndexArray[i];
					}

					//アンロック
					mesh->VertexBuffer.Data->Unlock();
					mesh->IndexBuffer.Data->Unlock();
				}
			}

		}

		//-----------------------------------------------------------
		// CreateDeclaration
		//-----------------------------------------------------------
		void FbxFile::CreateDeclaration()
		{
			auto pDevice = Pyramid::Rendering::Graphics::Instantiate().Device;

			D3DVERTEXELEMENT9 vertexElem[] = {
				{ 0, 0              , D3DDECLTYPE_FLOAT3  , D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_POSITION, 0 }, // 頂点座標
				{ 0, sizeof(D3DXVECTOR3) , D3DDECLTYPE_FLOAT3  , D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_NORMAL, 0 }, // 法線
				{ 0, sizeof(D3DXVECTOR3) * 2 , D3DDECLTYPE_FLOAT2  , D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_TEXCOORD, 0 }, // テクスチャUV		
				D3DDECL_END()
			};

			D3DVERTEXELEMENT9 vertexElem_NonUV[] = {
				{ 0, 0              , D3DDECLTYPE_FLOAT3  , D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_POSITION, 0 }, // 頂点座標
				{ 0, sizeof(D3DXVECTOR3) , D3DDECLTYPE_FLOAT3  , D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_NORMAL, 0 }, // 法線
				D3DDECL_END()
			};

			for (auto& mesh : m_Meshs)
			{
				if (mesh->IsHasUV())
				{
					pDevice->CreateVertexDeclaration(vertexElem, &mesh->Declaration);
				}
				else
				{
					pDevice->CreateVertexDeclaration(vertexElem_NonUV, &mesh->Declaration);
				}
			}

		}
	}
}
//
//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------