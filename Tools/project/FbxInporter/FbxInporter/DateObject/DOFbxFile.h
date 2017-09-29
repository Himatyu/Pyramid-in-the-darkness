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
#include"FileDateObject.h"
#include"DateType.h"
#include"DOFbxMateria.h"
#include"FbxInnerMesh.h"
#include"IDeserializable.h"
#include"ISerializable.h"

#include<vector>
#include<string>

class FbxAndBMInterconverter;
namespace DataObject
{
	namespace DTO
	{
		class FbxFile
		{
		public :
			PROPERTY_REF(m_Meshs, Meshs, std::vector<FbxInnerMesh>);
		private:
			::std::vector<FbxInnerMesh>			m_Meshs;
		};
	}

	namespace POCO
	{
		namespace Serialize
		{
			/// <summary>
			/// FBX�t�@�C���̃V���A���C�Y���s��
			/// </summary>
			class FbxFile :
				public FileDateObjectRoot,
				public ISerializable
			{
				friend class FbxAndBMInterconverter;
			public:
				FbxFile(::std::string filePath);
				~FbxFile();

				/// <summary>
				/// �V���A���C�Y
				/// </summary>
				void Serialize() override;

				/// <summary>
				/// ���W�X�P�[�����O
				/// </summary>
				void Scaleing(float _scale);

				PROPERTY_REF(m_File, File, DTO::FbxFile);

			private:
				DTO::FbxFile			m_File;
			};
		}

		namespace Deserialize
		{
			/// <summary>
			/// FBX�t�@�C���̃f�V���A���C�Y���s��
			/// </summary>
			class FbxFile :
				public FileDateObjectRoot,
				public IDeserializable
			{
				friend class FbxAndBMInterconverter;
			public:
				FbxFile(std::string filePath);
				~FbxFile();

				/// <summary>
				/// �f�V���A���C�Y
				/// </summary>
				void Deserialize() override;

				PROPERTY_REF(m_File, File, DTO::FbxFile);

			private:
				DTO::FbxFile			m_File;
			};
		}
	}
}

//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------