/**
* @file		ColorChannel.h
* @brief		カラーチャンネルDto提供
* @author		S.OIKAWA
* @date		2016.10.15
*/

#pragma once
//-----------------------------------------------------------
// include 
//-----------------------------------------------------------
#include"../DateType.h"
#include<vector>
#include<string>
#include<fstream>

//-----------------------------------------------------------
// define 
//-----------------------------------------------------------
namespace DataObject
{
	namespace DTO
	{
		using ColorChannelTextureData = std::pair<std::string, std::vector<char>>;

		/// <summary>
		/// 汎用の色情報DTO
		/// </summary>
		class ColorChannel final
		{
		public:
			PROPERTY_REF(m_Value, Value, float4);
			PROPERTY_REF(m_Textures, Textures, std::vector<ColorChannelTextureData>);

		private:
			float4									m_Value;//書き込みにしか使わないので、汎用性重視でfloat4
			std::vector<ColorChannelTextureData>	m_Textures;
		};
	}
}
//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------