/**
* @file		RendringPriority.h
* @brief	�����_�����O���̃v���C�I���e�B
* @author	S.OIKAWA
* @date		2016.12.13
*/

#pragma once
//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Rendering
	{
		/// <summary>
		/// �����_�����O���̃v���C�I���e�B
		/// </summary>
		enum RendringPriority : UINT
		{
			Background = 1000,		//�X�J�C�{�b�N�X�Ƃ�
			Geometry = 2000,		//�s�����I�u�W�F�N�g
			Transparent = 4000,	//�������I�u�W�F�N�g
			Overlay = 6000			//ui�Ȃ�
		};
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------