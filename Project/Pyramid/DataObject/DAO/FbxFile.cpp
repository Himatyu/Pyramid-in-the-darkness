/**
* @file		FbxFile.cpp
* @brief	FBXファイルのシリアライズを提供
* @author	S.OIKAWA
* @date		2016.10.15
*/

//-----------------------------------------------------------
// include 
//-----------------------------------------------------------
#include"FbxFile.h"
#include"../Deserialize/FbxFile.h"
#include"../Resource/Model/FbxFile.h"
#include"../Rendering/Materials/MeshMaterial.h"
#include"../Rendering/Materials/ColorChannel.h"
#include"Nullable.h"
#include"Builder.h"
#include"Exception.h"
#include<algorithm>
#include<memory>
#include<string>
//-----------------------------------------------------------
// define 
//-----------------------------------------------------------
using namespace std;
namespace DataObject
{
	namespace DAO
	{
		/// <summary>
		/// Deserialize したファイルを Entity に変換する 
		/// </summary>
		class FbxBuilder
			: public ::Utility::Builder<Entity::FbxFile*, Deserialize::FbxFile&>
		{
		public:
			//-----------------------------------------------------------
			// ctor
			//-----------------------------------------------------------
			FbxBuilder(Deserialize::FbxFile& _src)
			{
				Build(_src);
			}

			//-----------------------------------------------------------
			// Build
			//-----------------------------------------------------------
			void Build(Deserialize::FbxFile& _deserializedFile) override
			{
				auto pEntity = new Entity::FbxFile;

				auto& meshs = _deserializedFile.Dto.Meshs;
				for (auto& mesh : meshs)
				{
					auto pMesh = new Pyramid::Resources::Model::FbxInnerMesh;

					pMesh->VertexCount = mesh.VertexCount;
					pMesh->IndexCount = mesh.IndexCount;
					pMesh->PolygonCount = mesh.PolygonCount;

					for (auto& _ : mesh.VertexArray)
					{
						pMesh->VertexArray.emplace_back(D3DXVECTOR3(_.Value));
					}

					pMesh->IndexArray = std::move(mesh.IndexArray);

					for (auto& _ : mesh.NormalArray)
					{
						pMesh->NormalArray.emplace_back(D3DXVECTOR3(_.Value));
					}

					auto mapSize = mesh.UVNameArray.size();
					for (unsigned i = 0; i < mapSize; i++)
					{
						std::vector<D3DXVECTOR2> d3dUV;
						for (auto& _ : mesh.UVArrays[i])
						{
							d3dUV.emplace_back(D3DXVECTOR2(_.Value));
						}
						pMesh->UVs
							.insert(std::move(std::make_pair(mesh.UVNameArray[i], d3dUV)));
					}

					auto TextureCreate = [](
						Pyramid::Rendering::Materials::ColorChannel& _dest,
						DataObject::DTO::ColorChannel& _src)
					{
						for (auto& _ : _src.Textures)
						{
							_dest.TextureNames.push_back(_.first);
							auto spTex =
								 std::make_shared<
									Pyramid::Resources::Texture::DirectXTextureFileFromInMemory>(
										std::move(_));
							_dest.Textures.push_back(spTex);
						}
					};
						
					//HACK 汎用性皆無
					std::string shaderPath;
					std::string shaderTransparentPath;
					if (pMesh->IsHasUV())
					{
						shaderPath = "Assets/Shaders/BasicMesh.bsf";
						shaderTransparentPath = "Assets/Shaders/BasicMeshTransparent.bsf";
					}
					else
					{
						shaderPath = "Assets/Shaders/BasicMeshNonUV.bsf";
						shaderTransparentPath = "Assets/Shaders/BasicMeshNonUVTransparent.bsf";
					}

					for (auto& _ : mesh.MaterialArray)
					{
						auto pMat = 
							new Pyramid::Rendering::Materials::MeshMaterial(
								shaderPath, shaderTransparentPath);
						size_t arraySize = sizeof(float) * 4;

						memmove_s(pMat->Emissive.Value.data(), arraySize, _.Emissive.Value.Value, arraySize);
						memmove_s(pMat->Ambient.Value.data(), arraySize, _.Ambient.Value.Value, arraySize);
						memmove_s(pMat->Diffuse.Value.data(), arraySize, _.Diffuse.Value.Value, arraySize);
						memmove_s(pMat->Specular.Value.data(), arraySize, _.Specular.Value.Value, arraySize);
						memmove_s(pMat->Bump.Value.data(), arraySize, _.Bump.Value.Value, arraySize);

						TextureCreate(pMat->Ambient, _.Ambient);
						TextureCreate(pMat->Diffuse, _.Diffuse);
						TextureCreate(pMat->Emissive, _.Emissive);
						TextureCreate(pMat->Specular, _.Specular);
						TextureCreate(pMat->Bump, _.Bump);

						pMat->Shinness = _.Shinness;
						pMat->Transparency = _.Transparency;
						pMat->Reflectivity = _.Reflectivity;

						pMesh->Materials.emplace_back(pMat);
					}
					
					pMesh->Volume = mesh.Volume;

					pEntity->Meshs.emplace_back(pMesh);
				}
				m_Built = ::Utility::Nullable<Entity::FbxFile*>(pEntity);
			}
		};

		//-----------------------------------------------------------
		// From
		//-----------------------------------------------------------
		Entity::FbxFile* FbxFile::From(std::string _filePath)
		{
			//値が変わらないのであればVOとしてバッファを持つ別のクラスが行うべき
			Deserialize::FbxFile deserialize(_filePath);
			deserialize.Deserialize();

			FbxBuilder builder(deserialize);
			if (builder.Built == nullptr)
			{
				___THROW_EXCEPTION_POINT(::Utility::Exception, "FbxEntityの生成");
			}

			return builder.Built.Value;
		}
	}
}

//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------

