#include"FbxInnerMesh.h"
#include"../AABB.h"
#include<algorithm>
#include<array>
using namespace std;
namespace DataObject
{
	namespace POCO
	{
		namespace Serialize
		{
			FbxInnerMesh::FbxInnerMesh(std::fstream & _parentStream):
				FileDateObjectChild(_parentStream)
			{
			}
			FbxInnerMesh::~FbxInnerMesh()
			{
			}
			void FbxInnerMesh::Serialize()
			{
				m_Mesh.SizeArray.push_back(m_Mesh.VertexCount);
				m_Mesh.SizeArray.push_back(m_Mesh.IndexCount);
				m_Mesh.SizeArray.push_back(m_Mesh.PolygonCount);

				m_Mesh.SizeArray.push_back(m_Mesh.VertexArray.size());
				m_Mesh.SizeArray.push_back(m_Mesh.IndexArray.size());
				m_Mesh.SizeArray.push_back(m_Mesh.NormalArray.size());
				m_Mesh.SizeArray.push_back(m_Mesh.UVNameArray.size());
				m_Mesh.SizeArray.push_back(m_Mesh.UVArrays.size());

				if(!m_Mesh.MaterialArray.size())
				{
					m_Mesh.SizeArray.push_back(1);
				}
				else
				{
					m_Mesh.SizeArray.push_back(m_Mesh.MaterialArray.size());
				}

				size_t headerSize = m_Mesh.SizeArray.size();
				Write(&headerSize, sizeof(size_t));
				Write(m_Mesh.SizeArray.data(), sizeof(size_t) *	m_Mesh.SizeArray.size());

				Write(m_Mesh.VertexArray.data(), sizeof(float3) * m_Mesh.VertexArray.size());
				Write(m_Mesh.IndexArray.data(), sizeof(int) *		m_Mesh.IndexArray.size());
				Write(m_Mesh.NormalArray.data(), sizeof(float3) * m_Mesh.NormalArray.size());

				for (auto& _ : m_Mesh.UVNameArray)
				{
					size_t nameSize = _.size();
					Write(&nameSize, sizeof(size_t));
					Write(_.data(), sizeof(char)*nameSize);
				}

				for (auto& _ : m_Mesh.UVArrays)
				{
					size_t arraySize = _.size();
					Write(&arraySize, sizeof(size_t));
					Write(_.data(), sizeof(float2) * _.size());
				}

				for (auto& _ : m_Mesh.MaterialArray)
				{
					auto pMat = new FbxMaterial(rootStream);
					pMat->Material = std::move(_);
					pMat->Serialize();
					SAFE_DELETE(pMat);
				}

				//最低一つは必要なのでダミーをもたせる
				if (!m_Mesh.MaterialArray.size())
				{
					auto pMat = new FbxMaterial(rootStream);
					pMat->Serialize();
					SAFE_DELETE(pMat);
				}

				auto& vecMax = m_Mesh.Volume.m_Max;
				auto& vecMin = m_Mesh.Volume.m_Min;
				std::array<float, 6> volumArray	=
				{ vecMax.x,vecMax.y,vecMax.z,
					vecMin.x,vecMin.y,vecMin.z };

				Write(volumArray.data(), sizeof(float) * 6);
			}
		}

		namespace Deserialize
		{
			FbxInnerMesh::FbxInnerMesh(std::fstream & _parentStream) :
				FileDateObjectChild(_parentStream)
			{
			}
			FbxInnerMesh::~FbxInnerMesh()
			{
			}
			void FbxInnerMesh::Deserialize()
			{
				size_t headerSize;
				Read(&headerSize, sizeof(size_t));

				m_Mesh.SizeArray.resize(headerSize);
				Read(m_Mesh.SizeArray.data(), sizeof(size_t) * headerSize);

				m_Mesh.VertexCount = m_Mesh.SizeArray[0];
				m_Mesh.IndexCount = m_Mesh.SizeArray[1];
				m_Mesh.PolygonCount = m_Mesh.SizeArray[2];

				m_Mesh.VertexArray.resize(m_Mesh.SizeArray[3]);
				m_Mesh.IndexArray.resize(m_Mesh.SizeArray[4]);
				m_Mesh.NormalArray.resize(m_Mesh.SizeArray[5]);
				m_Mesh.UVNameArray.resize(m_Mesh.SizeArray[6]);
				m_Mesh.UVArrays.resize(m_Mesh.SizeArray[7]);
				m_Mesh.MaterialArray.resize(m_Mesh.SizeArray[8]);

				Read(m_Mesh.VertexArray.data(), sizeof(float3) *	m_Mesh.VertexArray.size());
				Read(m_Mesh.IndexArray.data(), sizeof(int) *		m_Mesh.IndexArray.size());
				Read(m_Mesh.NormalArray.data(), sizeof(float3) *	m_Mesh.NormalArray.size());

				for (auto& __ : m_Mesh.UVNameArray)
				{
					size_t nameSize;
					Read(&nameSize, sizeof(size_t));

					__.resize(nameSize);
					Read(__.data(), sizeof(char)*nameSize);
				}

				for (auto& __ : m_Mesh.UVArrays)
				{
					size_t arraySize;
					Read(&arraySize, sizeof(size_t));

					__.resize(arraySize);
					Read(__.data(), sizeof(float2) * arraySize);
				}

				for (auto& _ : m_Mesh.MaterialArray)
				{
					auto pMat = new FbxMaterial(rootStream);
					pMat->Deserialize();
					_ = std::move(pMat->Material);
					SAFE_DELETE(pMat);
				}

				std::array<float, 6> volumArray;
				Read(volumArray.data(), sizeof(float) *	6);

				m_Mesh.Volume.m_Max = { volumArray[0],volumArray[1], volumArray[2] };
				m_Mesh.Volume.m_Min = { volumArray [3],volumArray[4], volumArray[5]};
			}

		}
	}
}