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
#include"../Serialize/FbxInnerMesh.h"
#include<algorithm>
#include<iostream>
#include<string>
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
		FbxFile::FbxFile(::std::string filePath) :
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
		// Serialize
		//-----------------------------------------------------------
		void FbxFile::Serialize()
		{
			m_FileStream.open(m_FilePath, ios::out | ios::binary | ios::trunc);

			if (m_FileStream.fail())
			{
				return;
			}

			size_t MeshArraySize = m_Dto.Meshs.size();
			m_FileStream.write((char*)&MeshArraySize, sizeof(size_t));

			for(auto& _ : m_Dto.Meshs)
			{
				auto pMesh = new FbxInnerMesh(m_FileStream);
				pMesh->Dto = std::move(_);
				pMesh->Serialize();
				SAFE_DELETE(pMesh);
			}

			m_FileStream.close();
		}
	}
}

//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------