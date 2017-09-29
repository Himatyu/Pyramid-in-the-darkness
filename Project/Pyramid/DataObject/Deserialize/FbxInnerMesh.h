/**
* @file		FbxInnerMesh.h
* @brief	FBX�C���i�[���b�V���f�V���A���C�Y��
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
		/// FBX�t�@�C���̃f�V���A���C�Y���s��
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
			/// �f�V���A���C�Y
			/// </summary>
			void Deserialize() override;
		};
	}
}
//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------
