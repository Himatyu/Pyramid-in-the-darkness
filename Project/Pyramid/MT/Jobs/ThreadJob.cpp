/**
* @file		ThreadJob.cpp
* @brief	�񓯊��I�u�W�F�N�g�X�V�̎���
* @author	S.OIKAWA
* @date		2016.4.30
*/

//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include "ThreadJob.h"
#include "IExecuteable.h"
#include"Estd.h"
//-----------------------------------------------------------
// define 
//-----------------------------------------------------------
namespace Pyramid
{
	namespace MT
	{
		namespace Jobs
		{
			//-----------------------------------------------------------
			// Job
			//-----------------------------------------------------------
			void ThreadJob::Job()
			{
				Utility::Estd::for_each(
					m_pJobs,
					[](auto&_) {_->Execution(); });
				m_pJobs.clear();
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------