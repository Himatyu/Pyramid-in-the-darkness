/**
* @file		FbxFile.h
* @brief	FBXファイルのシリアライズを提供
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
			/// FBXファイルのシリアライズを行う
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
				/// シリアライズ
				/// </summary>
				void Serialize() override;

				/// <summary>
				/// 座標スケーリング
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
			/// FBXファイルのデシリアライズを行う
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
				/// デシリアライズ
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