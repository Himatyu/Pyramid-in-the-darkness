/**
* @file		FbxInnerMesh.cpp
* @brief	FBXインナーメッシュデシリアライズ
* @author	S.OIKAWA
* @date		2016.10.15
*/

//-----------------------------------------------------------
// include 
//-----------------------------------------------------------
#include"FbxInnerMesh.h"
#include"FbxMateria.h"
#include<algorithm>
#include<array>

//-----------------------------------------------------------
// define 
//-----------------------------------------------------------
using namespace std;
namespace DataObject
{
	namespace Deserialize
	{
		//-----------------------------------------------------------
		// ctor
		//-----------------------------------------------------------
		FbxInnerMesh::FbxInnerMesh(std::fstream & _parentStream) :
			FileDataObjectChild(_parentStream)
		{
		}

		//-----------------------------------------------------------
		// dtor
		//-----------------------------------------------------------
		FbxInnerMesh::~FbxInnerMesh()
		{
		}

		//-----------------------------------------------------------
		// Deserialize
		//-----------------------------------------------------------
		void FbxInnerMesh::Deserialize()
		{
			size_t headerSize;
			Read(&headerSize, sizeof(size_t));

			m_Dto.SizeArray.resize(headerSize);
			Read(m_Dto.SizeArray.data(), sizeof(size_t) * (headerSize));

			m_Dto.VertexCount = m_Dto.SizeArray[0];
			m_Dto.IndexCount = m_Dto.SizeArray[1];
			m_Dto.PolygonCount = m_Dto.SizeArray[2];

			m_Dto.VertexArray.resize(m_Dto.SizeArray[3]);
			m_Dto.IndexArray.resize(m_Dto.SizeArray[4]);
			m_Dto.NormalArray.resize(m_Dto.SizeArray[5]);
			m_Dto.UVNameArray.resize(m_Dto.SizeArray[6]);
			m_Dto.UVArrays.resize(m_Dto.SizeArray[7]);
			m_Dto.MaterialArray.resize(m_Dto.SizeArray[8]);

			Read(m_Dto.VertexArray.data(), sizeof(float3) *	m_Dto.VertexArray.size());
			Read(m_Dto.IndexArray.data(), sizeof(int) *		m_Dto.IndexArray.size());
			Read(m_Dto.NormalArray.data(), sizeof(float3) *	m_Dto.NormalArray.size());

			for (auto& __ : m_Dto.UVNameArray)
			{
				size_t nameSize;
				Read(&nameSize, sizeof(size_t));

				__.resize(nameSize);
				Read(__.data(), sizeof(char)*nameSize);
			}

			for (auto& __ : m_Dto.UVArrays)
			{
				size_t arraySize;
				Read(&arraySize, sizeof(size_t));

				__.resize(arraySize);
				Read(__.data(), sizeof(float2) * arraySize);
			}

			for (auto& _ : m_Dto.MaterialArray)
			{
				auto pMat = new FbxMaterial(m_RootStream);
				pMat->Deserialize();
				_ = std::move(pMat->Dto);
				SAFE_DELETE(pMat);
			}

			std::array<float, 6> volumArray;
			Read(volumArray.data(), sizeof(float) * 6);

			m_Dto.Volume.Max =
				Utility::Vector3( volumArray[0],volumArray[1], volumArray[2] );
			m_Dto.Volume.Min =
				Utility::Vector3( volumArray[3],volumArray[4], volumArray[5] );
		}
	}
}

//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------