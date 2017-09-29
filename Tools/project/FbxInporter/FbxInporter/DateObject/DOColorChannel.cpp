/**
	  * @file		DOColorChannel.cpp
	  * @brief		カラーチャンネルデータオブジェクト
	  * @author		S.OIKAWA
	  * @date		2016.10.15
	  */

//-----------------------------------------------------------
// include 
//-----------------------------------------------------------
#include "DOColorChannel.h"

//-----------------------------------------------------------
// define 
//-----------------------------------------------------------

namespace DataObject
{
	namespace POCO
	{
		namespace Serialize
		{
			//-----------------------------------------------------------
			// ctor 
			//-----------------------------------------------------------
			ColorChannel::ColorChannel(std::fstream& _parentStream) :
				FileDateObjectChild(_parentStream)
			{
			}

			//-----------------------------------------------------------
			// dtor 
			//-----------------------------------------------------------
			ColorChannel::~ColorChannel()
			{
			}

			//-----------------------------------------------------------
			// Serialize 
			//-----------------------------------------------------------
			void ColorChannel::Serialize()
			{	
				Write(&m_Color.Value.Value, sizeof(float) * 4);

				size_t dataListSize = m_Color.Textures.size();
				Write(&dataListSize, sizeof(size_t));

				for (auto& _ : m_Color.Textures)
				{
					size_t fileNameSize = _.first.size();
					Write(&fileNameSize, sizeof(size_t));
					Write(_.first.data(), sizeof(char) * fileNameSize);

					size_t textureDataSize = _.second.size();
					Write(&textureDataSize, sizeof(size_t));
					Write(_.second.data(), sizeof(char) * textureDataSize);
				}
			}
		}

		namespace Deserialize
		{
			//-----------------------------------------------------------
			// ctor 
			//-----------------------------------------------------------
			ColorChannel::ColorChannel(std::fstream& _parentStream):
				FileDateObjectChild(_parentStream)
			{
			}

			//-----------------------------------------------------------
			// dtor 
			//-----------------------------------------------------------
			ColorChannel::~ColorChannel()
			{
			}

			//-----------------------------------------------------------
			// Deserialize 
			//-----------------------------------------------------------
			void ColorChannel::Deserialize()
			{
				Read(m_Color.Value.Value, sizeof(float) * 4);

				size_t dataListSize;
				Read(&dataListSize, sizeof(size_t));

				m_Color.Textures.resize(dataListSize);
				for (auto& _ : m_Color.Textures)
				{
					size_t fileNameSize;
					Read(&fileNameSize, sizeof(size_t));
					_.first.resize(fileNameSize);
					Read(_.first.data(), sizeof(char)*fileNameSize);

					size_t textureDataSize;
					Read(&textureDataSize, sizeof(size_t));
					_.second.resize(textureDataSize);
					Read(_.second.data(), sizeof(char)*textureDataSize);
				}
			}
		}
	}
}
//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------