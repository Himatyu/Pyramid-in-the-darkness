/**
* @file		FbxFile.cpp
* @brief	FBXファイルのシリアライズを提供
* @author	S.OIKAWA
* @date		2016.10.15
*/

//-----------------------------------------------------------
// include 
//-----------------------------------------------------------
#include"../Macro.h"
#include"DOFbxFile.h"
#include<algorithm>
#include<iostream>
#include<string>
//-----------------------------------------------------------
// define 
//-----------------------------------------------------------
using namespace std;
namespace DataObject
{
	namespace POCO
	{
		namespace Serialize
		{

			FbxFile::FbxFile(::std::string filePath) :
				FileDateObjectRoot(filePath)
			{
			}
			FbxFile::~FbxFile()
			{

			}
			void FbxFile::Serialize()
			{
				fileStream.open(fileName, ios::out | ios::binary | ios::trunc);

				if (fileStream.fail())
				{
					return;
				}

				size_t MeshArraySize = m_File.Meshs.size();
				fileStream.write((char*)&MeshArraySize, sizeof(size_t));

				for(auto& _ : m_File.Meshs)
				{
					auto poco_pMesh = new FbxInnerMesh(fileStream);
					poco_pMesh->Mesh = std::move(_);
					poco_pMesh->Serialize();
					SAFE_DELETE(poco_pMesh);
				}

				fileStream.close();
			}
			void FbxFile::Scaleing(float _scale)
			{
				for (auto& mesh : m_File.Meshs)
				{
					for (auto& _ : mesh.VertexArray)
					{
						_.x *= _scale;
						_.y *= _scale;
						_.z *= _scale;
					}
					mesh.Volume.m_Max.x *= _scale;
					mesh.Volume.m_Max.y *= _scale;
					mesh.Volume.m_Max.z *= _scale;
					mesh.Volume.m_Min.x *= _scale;
					mesh.Volume.m_Min.y *= _scale;
					mesh.Volume.m_Min.z *= _scale;
				}
			}
		}


		namespace Deserialize
		{
			FbxFile::FbxFile(std::string filePath) :
				FileDateObjectRoot(filePath)
			{
			}

			FbxFile::~FbxFile()
			{
			}

			void FbxFile::Deserialize()
			{
				fileStream.open(fileName, ios::in | ios::binary);

				if (fileStream.fail())
				{
					return;
				}

				size_t MeshArraySize;
				fileStream.read((char*)&MeshArraySize, sizeof(size_t));
				m_File.Meshs.resize(MeshArraySize);

				for (auto& _ : m_File.Meshs)
				{
					auto poco_pMesh = new FbxInnerMesh(fileStream);
					poco_pMesh->Deserialize();
					_ = std::move(poco_pMesh->Mesh);
					SAFE_DELETE(poco_pMesh);
				}
			}
		}
	 }
}

//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------