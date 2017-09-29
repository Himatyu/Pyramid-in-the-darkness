#pragma once

#include"FileDateObject.h"
#include"DateType.h"
#include"IDeserializable.h"
#include"ISerializable.h"
#include"DOFbxMateria.h"
#include"../AABB.h"

#include<vector>
#include<string>

class FbxAndBMInterconverter;
namespace DataObject
{
	namespace DTO
	{
		class FbxInnerMesh
		{
		public:
			PROPERTY_REF(m_IndexCount, IndexCount, size_t);
			PROPERTY_REF(m_VertexCount, VertexCount, size_t);
			PROPERTY_REF(m_PolygonCount, PolygonCount, size_t);

			PROPERTY_REF(m_SizeArray, SizeArray, std::vector<size_t>);
			PROPERTY_REF(m_VertexArray, VertexArray, std::vector<float3>);
			PROPERTY_REF(m_IndexArray, IndexArray, std::vector<int>);
			PROPERTY_REF(m_NormalArray, NormalArray, std::vector<float3>);
			PROPERTY_REF(m_UVNameArray, UVNameArray, std::vector<std::string>);
			PROPERTY_REF(m_UVArrays, UVArrays, std::vector<std::vector<float2>>);
			PROPERTY_REF(m_MaterialArray, MaterialArray, std::vector<FbxMaterial>);
			PROPERTY_REF(m_Volume, Volume, AABB);

		private:

			size_t						m_IndexCount = 0;
			size_t						m_VertexCount = 0;
			size_t						m_PolygonCount = 0;
			//Header
			std::vector<size_t>						m_SizeArray;

			//Footer
			std::vector<float3>						m_VertexArray;
			std::vector<int>						m_IndexArray;
			std::vector<float3>						m_NormalArray;
			std::vector<std::string>				m_UVNameArray;
			std::vector<std::vector<float2>>		m_UVArrays;
			std::vector<FbxMaterial>				m_MaterialArray;
			AABB									m_Volume;

			//FileData
			//
			//HeaderSize
			//
			//Header : 	FooterDataSizeList 
			//		VertexArraySize
			//		IndexArraySize
			//		NormalArraySize
			//		UVNameArraySize
			//		UVArraysSize
			//		MaterialArraySize
			//Footer :	DateList
			//		VertexArray
			//		IndexArray
			//		NormalArray
			//		UVNameArray
			//		UVArrays;
			//		MaterialArray
		};

	}

	namespace POCO
	{
		namespace Serialize
		{
			/// <summary>
			/// FBXファイルのシリアライズを行う
			/// </summary>
			class FbxInnerMesh :
				public FileDateObjectChild,
				public ISerializable
			{
				friend class FbxAndBMInterconverter;
			public:
				FbxInnerMesh(std::fstream& _parentStream);
				~FbxInnerMesh();

				/// <summary>
				/// シリアライズ
				/// </summary>
				void Serialize() override;

				PROPERTY_REF(m_Mesh, Mesh, DTO::FbxInnerMesh);

			private:
				DTO::FbxInnerMesh						m_Mesh;
			};
		}

		namespace Deserialize
		{
			/// <summary>
			/// FBXファイルのデシリアライズを行う
			/// </summary>
			class FbxInnerMesh :
				public FileDateObjectChild,
				public IDeserializable
			{
				friend class FbxAndBMInterconverter;
			public:
				FbxInnerMesh(std::fstream& _parentStream);
				~FbxInnerMesh();

				/// <summary>
				/// デシリアライズ
				/// </summary>
				void Deserialize() override;


				PROPERTY_REF(m_Mesh, Mesh, DTO::FbxInnerMesh);

			private:
				DTO::FbxInnerMesh						m_Mesh;
			};
		}
	}
}
