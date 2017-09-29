/**
* @file		FbxInnerMesh.h
* @brief	FBXインナーメッシュDto提供
* @author	S.OIKAWA
* @date		2016.10.15
*/
#pragma once
//-----------------------------------------------------------
// include 
//-----------------------------------------------------------
#include"../DateType.h"
#include"FbxMateria.h"
#include"DTOAccess.h"
#include"../Common/Diagram/AABB.h"
#include<vector>
#include<string>

//-----------------------------------------------------------
// define 
//-----------------------------------------------------------
namespace DataObject
{
	namespace DTO
	{
		/// <summary>
		/// Fbxの内部メッシュDTO
		/// </summary>
		class FbxInnerMesh final
		{
		public:
			PROPERTY_REF(m_SizeArray, SizeArray, std::vector<size_t>);

			PROPERTY_REF(m_IndexCount, IndexCount, size_t);
			PROPERTY_REF(m_VertexCount, VertexCount, size_t);
			PROPERTY_REF(m_PolygonCount, PolygonCount, size_t);

			PROPERTY_REF(m_VertexArray, VertexArray, std::vector<float3>);
			PROPERTY_REF(m_IndexArray, IndexArray, std::vector<int>);
			PROPERTY_REF(m_NormalArray, NormalArray, std::vector<float3>);
			PROPERTY_REF(m_UVNameArray, UVNameArray, std::vector<std::string>);
			PROPERTY_REF(m_UVArrays, UVArrays, std::vector<std::vector<float2>>);
			PROPERTY_REF(m_MaterialArray, MaterialArray, std::vector<FbxMaterial>);

			PROPERTY_REF(m_Volume, Volume, Pyramid::Common::Diagram::AABB);

		private:

			std::vector<size_t>						m_SizeArray;

			size_t m_IndexCount = 0;
			size_t m_VertexCount = 0;
			size_t m_PolygonCount = 0;

			std::vector<float3>						m_VertexArray;
			std::vector<int>						m_IndexArray;
			std::vector<float3>						m_NormalArray;
			std::vector<std::string>				m_UVNameArray;
			std::vector<std::vector<float2>>		m_UVArrays;
			std::vector<FbxMaterial>				m_MaterialArray;

			Pyramid::Common::Diagram::AABB					m_Volume;
		};

	}
}

//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------