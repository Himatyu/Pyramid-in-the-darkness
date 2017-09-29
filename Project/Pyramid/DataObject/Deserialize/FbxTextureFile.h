/**
* @file		FbxTextureFile.h
* @brief	Fbxに使用されているテクスチャファイルのデシリアライスを提供
* @author	S.OIKAWA
* @date		2016.10.18
*/
#pragma once

//-----------------------------------------------------------
// include 
//-----------------------------------------------------------
#include"IDeserializable.h"
#include"../FileDataObjectChild.h"
#include"../DTO/DTOAccess.h"
#include"../DTO/FbxTextureFile.h"

#include<fstream>
//-----------------------------------------------------------
// define 
//-----------------------------------------------------------
namespace DataObject
{
	namespace Deserialize
	{
		/// <summary>
		/// FbxTextureFileをデシリアライズする.
		/// 単体でのデシリアライズは考えない
		/// </summary>
		class FbxTextureFile final :
			public DTO::DTOAccess<DTO::FbxTextureFile>,
			public FileDataObjectChild,
			public IDeserializable
		{
		public:
			FbxTextureFile(std::fstream& _parentStream);
			~FbxTextureFile();

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
