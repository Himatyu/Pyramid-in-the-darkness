/**
* @file		FbxTextureFile.h
* @brief	Fbx�Ɏg�p����Ă���e�N�X�`���t�@�C���̃f�V���A���C�X���
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
		/// FbxTextureFile���f�V���A���C�Y����.
		/// �P�̂ł̃f�V���A���C�Y�͍l���Ȃ�
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
			/// �f�V���A���C�Y
			/// </summary>
			void Deserialize() override;
		};
	}
}
//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------
