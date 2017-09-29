/**
* @file		FbxTextureFile.h
* @brief		Fbxに使用されているテクスチャファイルのシリアライズを提供
* @author		S.OIKAWA
* @date		2016.10.18
*/
#pragma once

//-----------------------------------------------------------
// include 
//-----------------------------------------------------------
#include"ISerializable.h"
#include"../FileDataObjectChild.h"
#include"../DTO/DTOAccess.h"
#include"../DTO/FbxTextureFile.h"

//-----------------------------------------------------------
// define 
//-----------------------------------------------------------
namespace DataObject
{
	namespace Serialize 
	{
		/// <summary>
		/// FbxTextureFileをシリアライズする.
		/// 単体でのシリアライズは考えない
		/// </summary>
		class FbxTextureFile final :
			public DTO::DTOAccess<DTO::FbxTextureFile>,
			public FileDataObjectChild,
			public ISerializable
		{
		public:
			FbxTextureFile(std::fstream& _parentStream);
			~FbxTextureFile();

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
