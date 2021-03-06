/**
* @file		FbxFile.h
* @brief	FBXファイルのDao提供
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
		/// BMを読み込みEntityを作成する
		/// </summary>
		class FbxFile final :
			public DaoBase<std::string, Entity::FbxFile*>
		{
		public:
			/// <summary>
			/// Entityを作成する
			/// </summary>
			Entity::FbxFile* From(std::string _filePath) override;
		};
	}
}
//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------