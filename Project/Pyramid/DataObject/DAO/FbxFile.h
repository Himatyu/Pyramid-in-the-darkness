/**
* @file		FbxFile.h
* @brief	FBXƒtƒ@ƒCƒ‹‚ÌDao’ñ‹Ÿ
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
		/// BM‚ğ“Ç‚İ‚İEntity‚ğì¬‚·‚é
		/// </summary>
		class FbxFile final :
			public DaoBase<std::string, Entity::FbxFile*>
		{
		public:
			/// <summary>
			/// Entity‚ğì¬‚·‚é
			/// </summary>
			Entity::FbxFile* From(std::string _filePath) override;
		};
	}
}
//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------