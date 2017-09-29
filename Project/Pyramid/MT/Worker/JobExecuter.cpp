/**
* @file		JobExecuter.cpp
* @brief	ƒWƒ‡ƒu‚ðŽÀs‚·‚é
* @author	S.OIKAWA
* @date		2016.11.25
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"JobExecuter.h"
#include"../Order/TaskLine.h"
#include"../Order/TaskOrder.h"
#include"../Jobs/ThreadJob.h"
#include"Estd.h"
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
			// ctor
			//-----------------------------------------------------------
			JobExecuter::JobExecuter(
				Order::TaskContainer & _Container):
				m_Container(_Container)
			{
				auto& mtSystem = ThreadSystem::Instantiate();
				m_Jobs.resize(mtSystem.TheradCount());

				for (auto& _ : m_Jobs)
				{
					_ = new Jobs::ThreadJob;
				}
			}

			//-----------------------------------------------------------
			// dtor
			//-----------------------------------------------------------
			JobExecuter::~JobExecuter()
			{
				Utility::Estd::for_each(m_Jobs, [&](auto& _) {SAFE_DELETE(_); });
			}

			//-----------------------------------------------------------
			// Execution
			//-----------------------------------------------------------
			void JobExecuter::Execution()
			{
				auto& mtSystem = ThreadSystem::Instantiate();
				size_t mtJobsCount = m_Jobs.size();
				size_t threadCount = mtSystem.CommonThreadCount();

				if (!mtSystem.isUseMultiThread() ||
					!mtJobsCount ||
					!threadCount)
				{
					ExecuteThisThread();
					return;
				}

				for (auto& _ : m_Container.pJobLines)
				{
					if (!_->pJobList.size())
					{
						continue;
					}
					JobDispatch(m_Jobs, _->pJobList);
					mtSystem.JobExecute<decltype(m_Jobs)>(m_Jobs);
					mtSystem.Join();
				}
			}

			//-----------------------------------------------------------
			// ExecuteThisThread
			//-----------------------------------------------------------
			void JobExecuter::ExecuteThisThread()
			{
				for (auto& _ : m_Container.pJobLines)
				{
					_->Run();
				}
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------