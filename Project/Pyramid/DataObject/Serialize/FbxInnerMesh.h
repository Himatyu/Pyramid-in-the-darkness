/**
* @file		FbxInnerMesh.h
* @brief	FBX�C���i�[���b�V���V���A���C�Y��
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
		/// FBX�t�@�C���̃V���A���C�Y���s��
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
			/// �V���A���C�Y
			/// </summary>
			void Serialize() override;
		};
	}
}
//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------
