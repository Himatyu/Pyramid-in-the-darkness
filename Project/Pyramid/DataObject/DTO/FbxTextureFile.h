/**
* @file		FbxTextureFile.h
* @brief		Fbx�Ɏg�p����Ă���e�N�X�`���t�@�C����DTO��
* @author		S.OIKAWA
* @date		2016.10.18
*/
#pragma once

//-----------------------------------------------------------
// include 
//-----------------------------------------------------------
#include<string>
#include<vector>

//-----------------------------------------------------------
// define 
//-----------------------------------------------------------
namespace DataObject
{
	namespace DTO
	{
		/// <summary>
		/// TextureFile��DTO
		/// </summary>
		class FbxTextureFile final
		{
		public:
			PROPERTY_REF(m_TextureData, TextureData, std::vector<char>);
			PROPERTY_REF(m_FilePath, FileName, std::string);

		private:
			std::vector<char>	m_TextureData;
			std::string			m_FilePath;
		};
	}
}
//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------