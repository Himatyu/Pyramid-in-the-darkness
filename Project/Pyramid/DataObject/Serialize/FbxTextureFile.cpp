/**
* @file		FbxTextureFile.cpp
* @brief	FbxTextureFile‚ÌDTO‚ð’ñ‹Ÿ
* @author	S.OIKAWA
* @date		2016.10.15
*/
#include "FbxTextureFile.h"

//-----------------------------------------------------------
// define 
//-----------------------------------------------------------
namespace DataObject
{
	namespace Serialize
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
		// Serialize
		//-----------------------------------------------------------
		void FbxTextureFile::Serialize()
		{
			auto nameSize = m_Dto.FileName.size();
			Write(&nameSize, sizeof(size_t));
			Write(m_Dto.FileName.data(), nameSize);

			auto fileSize = m_Dto.TextureData.size();
			Write(&fileSize, sizeof(size_t));
			Write(m_Dto.TextureData.data(), fileSize);
		}
	}
}

//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------
