/**
* @file		DOColorChannel.cpp
* @brief	カラーチャンネルのデシリアライズ
* @author	S.OIKAWA
* @date		2016.10.15
*/

//-----------------------------------------------------------
// include 
//-----------------------------------------------------------
#include "ColorChannel.h"

//-----------------------------------------------------------
// define 
//-----------------------------------------------------------

namespace DataObject
{
	namespace Deserialize
	{
		//-----------------------------------------------------------
		// ctor 
		//-----------------------------------------------------------
		ColorChannel::ColorChannel(std::fstream& _parentStream) :
			FileDataObjectChild(_parentStream)
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
			Read(m_Dto.Value.Value, sizeof(float) * 4);

			size_t dataListSize;
			Read(&dataListSize, sizeof(size_t));

			m_Dto.Textures.resize(dataListSize);
			for (auto& _ : m_Dto.Textures)
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
//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------