/**
	  * @file		DOColorChannel.h
	  * @brief		カラーチャンネルデータオブジェクト
	  * @author		S.OIKAWA
	  * @date		2016.10.15
	  */

#pragma once
//-----------------------------------------------------------
// include 
//-----------------------------------------------------------
#include"FileDateObject.h"
#include"DateType.h"
#include"IDeserializable.h"
#include"ISerializable.h"
#include"../Macro.h"
#include<vector>
#include<fstream>
#include<string>
class FbxAndBMInterconverter;

namespace DataObject
{
	namespace DTO
	{
		using ColorChannelTextureData = std::pair<std::string, std::vector<char>>;
		class ColorChannel
		{
		public:
			PROPERTY_REF(m_Value, Value, float4);
			PROPERTY_REF(m_Textures,Textures,std::vector<ColorChannelTextureData>);

		private:
			float4						m_Value{0};			//書き込みにしか使わないので、汎用性重視でfloat4
			std::vector<ColorChannelTextureData>	m_Textures;
		};
	}

	namespace POCO
	{
		namespace Serialize
		{
			/// <summary>
			/// 書き出し用のカラーチャンネルデータオブジェクト.
			/// これ単体では扱わず、Fbxのシリアライズの一環として使用すること.
			/// </summary>
			class ColorChannel :
				public FileDateObjectChild,
				public ISerializable
			{
				friend class FbxAndBMInterconverter;
			public:
				ColorChannel(std::fstream& _parentStream);
				~ColorChannel();

				/// <summary>
				/// カラーチャンネルの書き出し.
				/// すでに開いたストリームに対して書き込む.
				/// 開いていない場合何もしない.
				/// </summary>
				void Serialize() override;

				PROPERTY_REF(m_Color, Color, DTO::ColorChannel);

			private:
				DTO::ColorChannel m_Color;
			};

		}

		namespace Deserialize
		{
			/// <summary>
			/// 書き出し用のカラーチャンネルデータオブジェクト.
			/// これ単体では扱わず、Fbxのシリアライズの一環として使用すること.
			/// </summary>
			class ColorChannel :
				public FileDateObjectChild,
				public IDeserializable
			{
				friend class FbxAndBMInterconverter;
			public:
				ColorChannel(std::fstream& _parentStream);
				~ColorChannel();

				/// <summary>
				/// カラーチャンネルの書き出し.
				/// すでに開いたストリームに対して書き込む.
				/// 開いていない場合何もしない.
				/// </summary>
				void Deserialize() override;

				PROPERTY_REF(m_Color, Color, DTO::ColorChannel);

			private:
				DTO::ColorChannel m_Color;
			};
		}

	}

}




//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------