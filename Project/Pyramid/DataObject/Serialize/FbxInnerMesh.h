/**
* @file		FbxInnerMesh.h
* @brief	FBXインナーメッシュシリアライズ提供
* @author	S.OIKAWA
* @date		2016.10.15
*/
#pragma once

//-----------------------------------------------------------
// include 
//-----------------------------------------------------------
#include"ISerializable.h"
#include"../FileDataObjectChild.h"
#include"../DTO/DTOAccess.h"
#include"../DTO/FbxInnerMesh.h"

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
		class FbxInnerMesh final :
			public DTO::DTOAccess<DTO::FbxInnerMesh>,
			public FileDataObjectChild,
			public ISerializable
		{
		public:
			FbxInnerMesh(std::fstream& _parentStream);
			~FbxInnerMesh();

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
