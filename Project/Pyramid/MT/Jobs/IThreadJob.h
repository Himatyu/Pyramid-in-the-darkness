/**
* @file		IThreadJob.h
* @brief	�X���b�h�Ŏ��s����W���u�C���^�[�t�F�[�X
* @author	S.OIKAWA
* @date		2016.4.29
*/
#pragma once
//-----------------------------------------------------------
// define
//-----------------------------------------------------------

namespace Pyramid
{
	namespace MT
	{
		namespace Jobs
		{
			/// <summary>
			/// �X���b�h��������W���u
			/// ����ȊO��pJobs�̃v���p�e�B��p�ӂ���K�v������
			/// </summary>
			__interface IThreadJob
			{
				void Job();
			};
			
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------

