/**
* @file		FbxInnerMesh.h
* @brief	FBXインナーメッシュデシリアライズ提供
* @author	S.OIKAWA
* @date		2016.10.15
*/
#pragma once

//-----------------------------------------------------------
// include 
//-----------------------------------------------------------
#include"../FileDataObjectChild.h"
#include"../DTO/DTOAccess.h"
#include"../DTO/FbxInnerMesh.h"
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
		class FbxInnerMesh final :
			public DTO::DTOAccess<DTO::FbxInnerMesh>,
			public FileDataObjectChild,
			public IDeserializable
		{
		public:
			FbxInnerMesh(std::fstream& _parentStream);
			~FbxInnerMesh();

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
