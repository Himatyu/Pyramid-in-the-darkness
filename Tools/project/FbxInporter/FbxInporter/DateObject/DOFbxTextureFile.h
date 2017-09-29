/**
	  * @file		DOFbxTextureFile.h
	  * @brief		Fbxに使用されているテクスチャファイルのDTO,POCOを提供
	  * @author		S.OIKAWA
	  * @date		2016.10.18
	  */
#pragma once

//-----------------------------------------------------------
// include 
//-----------------------------------------------------------
#include"IDeserializable.h"
#include"ISerializable.h"
#include"FileDateObject.h"
#include"../Macro.h"
#include<string>
#include<vector>
//-----------------------------------------------------------
// define 
//-----------------------------------------------------------
namespace DataObject
{
	namespace DTO
	{
		class FbxTextureFile
		{
		public:
			PROPERTY_REF(m_TextureData, TextureData, std::vector<char>);
			PROPERTY_REF(m_FileName, FileName, std::string);

		private:
			std::vector<char>	m_TextureData;
			std::string			m_FileName;
		};
	}

	namespace POCO
	{
		namespace Serialize 
		{
			class FbxTextureFile :
				public FileDateObjectChild,
				public ISerializable
			{
			public:
				FbxTextureFile(std::fstream& _parentStream);
				~FbxTextureFile();

				void Serialize() override;

				PROPERTY_REF(m_TextureFile, TextureFile,DTO::FbxTextureFile);
			private:
				DTO::FbxTextureFile m_TextureFile;
			};

		}

		namespace Deserialize
		{
			class FbxTextureFile :
				public FileDateObjectChild,
				public IDeserializable
			{
			public:
				FbxTextureFile(std::fstream& _parentStream);
				~FbxTextureFile();

				void Deserialize() override;

				PROPERTY_REF(m_TextureFile, TextureFile, DTO::FbxTextureFile);
			private:
				DTO::FbxTextureFile m_TextureFile;
			};
		}
	}
}
