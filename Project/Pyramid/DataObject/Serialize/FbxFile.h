/**
* @file		FbxFile.h
* @brief	FBXファイルのシリアライズを提供
* @author	S.OIKAWA
* @date		2016.10.15
*/
#pragma once
//-----------------------------------------------------------
// include 
//-----------------------------------------------------------
#include"../FileDataObjectRoot.h"
#include"../DTO/DTOAccess.h"
#include"../DTO/FbxFile.h"
#include"ISerializable.h"

//-----------------------------------------------------------
// define 
//-----------------------------------------------------------
namespace DataObject
{
	namespace Serialize
	{
		/// <summary>
		/// FBXファイルのシリアライズを行う
		/// </summary>
		class FbxFile final :
			public DTO::DTOAccess<DTO::FbxFile>,
			public FileDataObjectRoot,
			public ISerializable
		{
		public:
			FbxFile(::std::string filePath);
			~FbxFile();

			/// <summary>
			/// シリアライズ
			/// </summary>
			void Serialize() override;
		};
	}
}

//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------