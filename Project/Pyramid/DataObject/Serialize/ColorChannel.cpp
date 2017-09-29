/**
	  * @file		ColorChannel.cpp
	  * @brief		カラーチャンネルシリアライズ
	  * @author		S.OIKAWA
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
	namespace Serialize
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
		// Serialize 
		//-----------------------------------------------------------
		void ColorChannel::Serialize()
		{
			Write(&m_Dto.Value.Value, sizeof(float) * 4);

			size_t dataListSize = m_Dto.Textures.size();
			Write(&dataListSize, sizeof(size_t));

			for (auto& _ : m_Dto.Textures)
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
}
//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------