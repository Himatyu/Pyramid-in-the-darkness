/**
* @file		FbxFile.h
* @brief	FBXファイルのデシリアライズを提供
* @author	S.OIKAWA
* @date		2016.10.15
*/
#pragma once
//-----------------------------------------------------------
// include 
//-----------------------------------------------------------
#include"../FileDataObjectRoot.h"
#include"../DTO/FbxFile.h"
#include"../DTO/DTOAccess.h"
#include"IDeserializable.h"
#include<string>

//-----------------------------------------------------------
// define 
//-----------------------------------------------------------
namespace DataObject
{
	namespace Deserialize
	{
		/// <summary>
		/// FBXファイルのデシリアライズを行う
		/// </summary>
		class FbxFile final :
			public DTO::DTOAccess<DTO::FbxFile>,
			public FileDataObjectRoot,
			public IDeserializable
		{
		public:
			FbxFile(std::string filePath);
			~FbxFile();

			/// <summary>
			/// デシリアライズ
			/// </summary>
			void Deserialize() override;
		};
	}
}

//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------