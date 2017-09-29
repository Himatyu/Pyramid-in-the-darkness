/**
* @file		JobExecuter.h
* @brief	�W���u�����s����
* @author	S.OIKAWA
* @date		2016.11.25
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"IOrderedJobExecutable.h"
#include"../MT/Order/TaskContainer.h"
#include"../MT/Worker/JobExecuterBase.h"
#include<vector>
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace MT
	{
		namespace Jobs
		{
			class ThreadJob;
		}
	}
}
#pragma endregion

namespace Pyramid
{
	namespace MT
	{
		namespace Worker
		{
			/// <summary>
			/// �W���u�����s����
			/// </summary>
			class JobExecuter final :
				public JobExecuterBase
			{
			public:
#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				JobExecuter(Order::TaskContainer&);
				~JobExecuter();

				JobExecuter(const JobExecuter&) = default;
				JobExecuter(JobExecuter&&) = default;

				JobExecuter& operator=(const JobExecuter&) = default;
				JobExecuter& operator=(JobExecuter&&) = default;
#pragma endregion

#pragma region function
				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------
				/// <summary>
				/// �^�X�N�����s����
				/// </summary>
				void Execution() override;

			private:
				void ExecuteThisThread() override;
#pragma endregion

#pragma region property
	//-----------------------------------------------------------
	// property
	//-----------------------------------------------------------

#pragma endregion
			private:
#pragma region value
	//-----------------------------------------------------------
	// val
	//-----------------------------------------------------------
				std::vector<Jobs::ThreadJob*>	m_Jobs;
				Order::TaskContainer&			m_Container;

#pragma endregion
			};
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------