/**
* @file		FbxFile.h
* @brief	FBX�t�@�C����Dao��
* @author	S.OIKAWA
* @date		2016.10.15
*/
#pragma once

//-----------------------------------------------------------
// include 
//-----------------------------------------------------------
#include"../Entity/FbxFile.h"
#include"DaoBase.h"
#include<string>

//-----------------------------------------------------------
// define 
//-----------------------------------------------------------
namespace DataObject
{
	namespace DAO
	{
		/// <summary>
		/// BM��ǂݍ���Entity���쐬����
		/// </summary>
		class FbxFile final :
			public DaoBase<std::string, Entity::FbxFile*>
		{
		public:
			/// <summary>
			/// Entity���쐬����
			/// </summary>
			Entity::FbxFile* From(std::string _filePath) override;
		};
	}
}
//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------