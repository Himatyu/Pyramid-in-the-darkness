/**
* @file		FbxTextureFile.h
* @brief		Fbx�Ɏg�p����Ă���e�N�X�`���t�@�C���̃V���A���C�Y���
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
		/// FbxTextureFile���V���A���C�Y����.
		/// �P�̂ł̃V���A���C�Y�͍l���Ȃ�
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
			/// �V���A���C�Y
			/// </summary>
			void Serialize() override;
		};

	}
}
//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------
