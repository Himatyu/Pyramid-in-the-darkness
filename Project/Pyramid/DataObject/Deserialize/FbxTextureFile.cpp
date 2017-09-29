/**
* @file		FbxTextureFile.cpp
* @brief	FbxTextureFile‚ÌDTO‚ð’ñ‹Ÿ
* @author	S.OIKAWA
* @date		2016.10.15
*/

//-----------------------------------------------------------
//include 
//-----------------------------------------------------------
#include "FbxTextureFile.h"

//-----------------------------------------------------------
// define 
//-----------------------------------------------------------
namespace DataObject
{
	namespace Deserialize
	{

		//-----------------------------------------------------------
		// ctor
		//-----------------------------------------------------------
		FbxTextureFile::FbxTextureFile(std::fstream & _parentStream) :
			FileDataObjectChild(_parentStream)
		{
		}

		//-----------------------------------------------------------
		// dtor
		//-----------------------------------------------------------
		FbxTextureFile::~FbxTextureFile()
		{
		}

		//-----------------------------------------------------------
		// Deserialize
		//-----------------------------------------------------------
		void FbxTextureFile::Deserialize()
		{
			size_t nameSize;
			Read(&nameSize, sizeof(size_t));
			m_Dto.FileName.resize(nameSize);
			Read(m_Dto.FileName.data(), sizeof(char) * nameSize);

			size_t fileSize;
			Read(&fileSize, sizeof(size_t));
			m_Dto.TextureData.resize(fileSize);
			Read(m_Dto.TextureData.data(), fileSize);
		}
	}
}

//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------
