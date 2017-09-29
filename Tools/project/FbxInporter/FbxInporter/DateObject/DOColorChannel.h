/**
	  * @file		DOColorChannel.h
	  * @brief		�J���[�`�����l���f�[�^�I�u�W�F�N�g
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
			float4						m_Value{0};			//�������݂ɂ����g��Ȃ��̂ŁA�ėp���d����float4
			std::vector<ColorChannelTextureData>	m_Textures;
		};
	}

	namespace POCO
	{
		namespace Serialize
		{
			/// <summary>
			/// �����o���p�̃J���[�`�����l���f�[�^�I�u�W�F�N�g.
			/// ����P�̂ł͈��킸�AFbx�̃V���A���C�Y�̈�Ƃ��Ďg�p���邱��.
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
				/// �J���[�`�����l���̏����o��.
				/// ���łɊJ�����X�g���[���ɑ΂��ď�������.
				/// �J���Ă��Ȃ��ꍇ�������Ȃ�.
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
			/// �����o���p�̃J���[�`�����l���f�[�^�I�u�W�F�N�g.
			/// ����P�̂ł͈��킸�AFbx�̃V���A���C�Y�̈�Ƃ��Ďg�p���邱��.
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
				/// �J���[�`�����l���̏����o��.
				/// ���łɊJ�����X�g���[���ɑ΂��ď�������.
				/// �J���Ă��Ȃ��ꍇ�������Ȃ�.
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