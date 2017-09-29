/**
* @file		JobExecuterBase.cpp
* @brief	�^�X�N���s�@�\�x�[�X�̋@�\��
* @author	S.OIKAWA
* @date		2016.11.24
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"JobExecuterBase.h"
#include"../Order/TaskLine.h"
#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace MT
	{
		namespace Worker
		{
			//-----------------------------------------------------------
			// dtor
			//-----------------------------------------------------------
			JobExecuterBase::JobExecuterBase():
				m_ThreadSystem(ThreadSystem::Instantiate())
			{
			}
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------

