/**
* @file		ColorChannel.h
* @brief		�J���[�`�����l���̃f�V���A���C�Y
* @author		S.OIKAWA
* @date		2016.10.15
*/

#pragma once
//-----------------------------------------------------------
// include 
//-----------------------------------------------------------
#include"IDeserializable.h"
#include"../DTO/DTOAccess.h"
#include"../DTO/ColorChannel.h"
#include"../FileDataObjectChild.h"

#include<vector>
#include<fstream>
#include<string>

//-----------------------------------------------------------
// define 
//-----------------------------------------------------------
namespace DataObject
{
	namespace Deserialize
	{
		/// <summary>
		/// �����o���p�̃J���[�`�����l���f�[�^�I�u�W�F�N�g.
		/// ����P�̂ł͈��킸�AFbx�̃V���A���C�Y�̈�Ƃ��Ďg�p���邱��.
		/// </summary>
		class ColorChannel final :
			public DTO::DTOAccess<DTO::ColorChannel>,
			public FileDataObjectChild,
			public IDeserializable
		{
		public:
			ColorChannel(std::fstream& _parentStream);
			~ColorChannel();

			/// <summary>
			/// �J���[�`�����l���̏����o��.
			/// ���łɊJ�����X�g���[���ɑ΂��ď�������.
			/// �J���Ă��Ȃ��ꍇ�������Ȃ�.
			/// </summary>
			void Deserialize() override;
		};
	}
}
//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------