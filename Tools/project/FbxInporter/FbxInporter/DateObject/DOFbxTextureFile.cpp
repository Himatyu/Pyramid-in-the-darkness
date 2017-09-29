#include "DOFbxTextureFile.h"


namespace DataObject
{
	namespace POCO
	{
		namespace Serialize
		{
			FbxTextureFile::FbxTextureFile(std::fstream & _parentStream) :
				FileDateObjectChild(_parentStream)
			{
			}

			FbxTextureFile::~FbxTextureFile()
			{
			}

			void FbxTextureFile::Serialize()
			{
				auto nameSize = m_TextureFile.FileName.size();
				Write(&nameSize, sizeof(size_t));
				Write(m_TextureFile.FileName.data(), nameSize);

				auto fileSize = m_TextureFile.TextureData.size();
				Write(&fileSize, sizeof(size_t));
				Write(m_TextureFile.TextureData.data(), fileSize);
			}
		}
		namespace Deserialize
		{

			FbxTextureFile::FbxTextureFile(std::fstream & _parentStream) :
				FileDateObjectChild(_parentStream)
			{
			}

			FbxTextureFile::~FbxTextureFile()
			{
			}

			void FbxTextureFile::Deserialize()
			{
				size_t nameSize;
				Read(&nameSize, sizeof(size_t));
				m_TextureFile.FileName.resize(nameSize);
				Read(m_TextureFile.FileName.data(), sizeof(char) * nameSize);

				size_t fileSize;
				Read(&fileSize, sizeof(size_t));
				m_TextureFile.TextureData.resize(fileSize);
				Read(m_TextureFile.TextureData.data(), fileSize);
			}
		}
	}
}

//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------
