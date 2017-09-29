/**
* @file		ColorChannel.h
* @brief	�J���[�`�����l���V���A���C�Y��
* @author	S.OIKAWA
* @date		2016.10.15
*/

#pragma once

//-----------------------------------------------------------
// include 
//-----------------------------------------------------------
#include"ISerializable.h"
#include"../FileDataObjectChild.h"
#include"../DTO/DTOAccess.h"
#include"../DTO/ColorChannel.h"

//-----------------------------------------------------------
// define 
//-----------------------------------------------------------
namespace DataObject
{
	namespace Serialize
	{
		/// <summary>
		/// �����o���p�̃J���[�`�����l���f�[�^�I�u�W�F�N�g.
		/// ����P�̂ł͈��킸�AFbx�̃V���A���C�Y�̈�Ƃ��Ďg�p���邱��.
		/// </summary>
		class ColorChannel final :
			public DTO::DTOAccess<DTO::ColorChannel>,
			public FileDataObjectChild,
			public ISerializable
		{
		public:
			ColorChannel(std::fstream& _parentStream);
			~ColorChannel();

			/// <summary>
			/// �J���[�`�����l���̏����o��.
			/// ���łɊJ�����X�g���[���ɑ΂��ď�������.
			/// �J���Ă��Ȃ��ꍇ�������Ȃ�.
			/// </summary>
			void Serialize() override;
		};
	}
}
//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------