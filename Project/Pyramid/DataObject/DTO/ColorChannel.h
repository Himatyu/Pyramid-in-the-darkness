/**
* @file		ColorChannel.h
* @brief		�J���[�`�����l��Dto��
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
		/// �ėp�̐F���DTO
		/// </summary>
		class ColorChannel final
		{
		public:
			PROPERTY_REF(m_Value, Value, float4);
			PROPERTY_REF(m_Textures, Textures, std::vector<ColorChannelTextureData>);

		private:
			float4									m_Value;//�������݂ɂ����g��Ȃ��̂ŁA�ėp���d����float4
			std::vector<ColorChannelTextureData>	m_Textures;
		};
	}
}
//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------