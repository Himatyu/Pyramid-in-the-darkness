/**
* @file		FbxInnerMesh.cpp
* @brief	FBXインナーメッシュシリアライズ
* @author	S.OIKAWA
* @date		2016.10.15
*/

//-----------------------------------------------------------
// include 
//-----------------------------------------------------------
#include"FbxInnerMesh.h"
#include"../Serialize/FbxMateria.h"
#include<algorithm>
#include<array>

//-----------------------------------------------------------
// define 
//-----------------------------------------------------------
using namespace std;
namespace DataObject
{
	namespace Serialize
	{
		//-----------------------------------------------------------
		// ctor
		//-----------------------------------------------------------
		FbxInnerMesh::FbxInnerMesh(std::fstream & _parentStream):
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
		// Serialize
		//-----------------------------------------------------------
		void FbxInnerMesh::Serialize()
		{
			m_Dto.SizeArray.push_back(m_Dto.VertexCount);
			m_Dto.SizeArray.push_back(m_Dto.IndexCount);
			m_Dto.SizeArray.push_back(m_Dto.PolygonCount);

			m_Dto.SizeArray.push_back(m_Dto.VertexArray.size());
			m_Dto.SizeArray.push_back(m_Dto.IndexArray.size());
			m_Dto.SizeArray.push_back(m_Dto.NormalArray.size());
			m_Dto.SizeArray.push_back(m_Dto.UVNameArray.size());
			m_Dto.SizeArray.push_back(m_Dto.UVArrays.size());
			m_Dto.SizeArray.push_back(m_Dto.MaterialArray.size());

			size_t headerSize = m_Dto.SizeArray.size();
			Write(&headerSize, sizeof(size_t));
			Write(m_Dto.SizeArray.data(), sizeof(size_t) *		m_Dto.SizeArray.size());
			Write(m_Dto.VertexArray.data(), sizeof(float3) *	m_Dto.VertexArray.size());
			Write(m_Dto.IndexArray.data(), sizeof(int) *		m_Dto.IndexArray.size());
			Write(m_Dto.NormalArray.data(), sizeof(float3) *	m_Dto.NormalArray.size());

			for (auto& _ : m_Dto.UVNameArray)
			{
				size_t nameSize = _.size();
				Write(&nameSize, sizeof(size_t));
				Write(_.data(), sizeof(char)*nameSize);
			}

			for (auto& _ : m_Dto.UVArrays)
			{
				size_t arraySize = _.size();
				Write(&arraySize, sizeof(size_t));
				Write(_.data(), sizeof(float2) * _.size());
			}

			for (auto& _ : m_Dto.MaterialArray)
			{
				auto pMat = new FbxMaterial(m_RootStream);
				pMat->Dto = std::move(_);
				pMat->Serialize();
				SAFE_DELETE(pMat);
			}

			auto& vecMax = m_Dto.Volume.Max;
			auto& vecMin = m_Dto.Volume.Min;
			std::array<float, 6> volumArray =
			{ vecMax.X,vecMax.Y,vecMax.Z,
				vecMin.X,vecMin.Y,vecMin.Z };

			Write(volumArray.data(), sizeof(float) * 6);
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------