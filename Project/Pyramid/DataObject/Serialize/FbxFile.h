/**
* @file		FbxFile.h
* @brief	FBX�t�@�C���̃V���A���C�Y���
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
		/// FBX�t�@�C���̃V���A���C�Y���s��
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
			/// �V���A���C�Y
			/// </summary>
			void Serialize() override;
		};
	}
}

//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------