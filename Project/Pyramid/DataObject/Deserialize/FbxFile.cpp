/**
* @file		FbxFile.cpp
* @brief	FBXファイルのデシリアライズを提供
* @author	S.OIKAWA
* @date		2016.10.15
*/

//-----------------------------------------------------------
// include 
//-----------------------------------------------------------
#include"FbxFile.h"
#include"../Deserialize/FbxInnerMesh.h"
#include<algorithm>
#include<iostream>
#include<string>
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
		FbxFile::FbxFile(std::string filePath) :
			FileDataObjectRoot(filePath)
		{
			m_Dto.FilePath = filePath;
		}

		//-----------------------------------------------------------
		// dtor
		//-----------------------------------------------------------
		FbxFile::~FbxFile()
		{
		}

		//-----------------------------------------------------------
		// Deserialize
		//-----------------------------------------------------------
		void FbxFile::Deserialize()
		{
			m_FileStream.open(m_FilePath, ios::in | ios::binary);

			if (m_FileStream.fail())
			{
				return;
			}

			size_t MeshArraySize;
			m_FileStream.read((char*)&MeshArraySize, sizeof(size_t));
			m_Dto.Meshs.resize(MeshArraySize);

			for (auto& _ : m_Dto.Meshs)
			{
				auto pMesh = new FbxInnerMesh(m_FileStream);
				pMesh->Deserialize();
				_ = std::move(pMesh->Dto);
				SAFE_DELETE(pMesh);
			}
		}
	}
}

//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------