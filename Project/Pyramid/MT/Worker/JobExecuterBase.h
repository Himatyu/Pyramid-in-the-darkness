/**
* @file		JobExecuterBase.h
* @brief	�^�X�N���s�@�\�x�[�X�̋@�\��
* @author	S.OIKAWA
* @date		2016.11.24
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"IOrderedJobExecutable.h"
#include"../ThreadSystem.h"
#include"../Order/TaskContainer.h"
#include"../Order/TaskLine.h"
#include<vector>
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------

#pragma endregion

namespace Pyramid
{
	namespace MT
	{
		namespace Worker
		{
			/// <summary>
			/// �f�B�X�p�b�`�ƌ��X���b�h���s�̃C���^�[�t�F�[�X���`
			/// </summary>
			class JobExecuterBase :
				public IOrderedJobExecutable
			{
			protected:
#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				JobExecuterBase();
				virtual ~JobExecuterBase() = default;

				JobExecuterBase(const JobExecuterBase&) = default;
				JobExecuterBase(JobExecuterBase&&) = default;

				JobExecuterBase& operator=(const JobExecuterBase&) = default;
				JobExecuterBase& operator=(JobExecuterBase&&) = default;
#pragma endregion

#pragma region function
				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------

				/// <summary>
				/// �^�X�N���W���u�ɐU�蕪����
				/// </summary>
				template<class JobType,class OrderData>
				void JobDispatch(std::vector<JobType>&, OrderData&);

				/// <summary>
				/// �W���u�����݂̃X���b�h�Ŏ��s����
				/// �X���b�h���g���Ȃ������ꍇ�Ɏg�p
				/// </summary>
				virtual void ExecuteThisThread() = 0;
#pragma endregion

#pragma region property
				//-----------------------------------------------------------
				// property
				//-----------------------------------------------------------

#pragma endregion
			protected:
#pragma region value
				//-----------------------------------------------------------
				// val
				//-----------------------------------------------------------
				ThreadSystem&					m_ThreadSystem;
#pragma endregion
			};
#include"JobExecuterBase.inl"

		}
	}
}
	

	//-----------------------------------------------------------
	// EOF
	//-----------------------------------------------------------