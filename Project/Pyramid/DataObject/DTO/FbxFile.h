/**
* @file		FbxFile.h
* @brief	FBX�t�@�C��Dto��
* @author	S.OIKAWA
* @date		2016.10.15
*/
#pragma once
//-----------------------------------------------------------
// include 
//-----------------------------------------------------------
#include"FbxInnerMesh.h"
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
		/// FbxFile��DTO
		/// </summary>
		class FbxFile final
		{
		public:
			PROPERTY_REF(m_Meshs, Meshs, std::vector<FbxInnerMesh>);
			PROPERTY_REF(m_FilePath, FilePath, std::string);
		private:
			std::vector<FbxInnerMesh>			m_Meshs;
			std::string							m_FilePath;
		};
	}
}

//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------