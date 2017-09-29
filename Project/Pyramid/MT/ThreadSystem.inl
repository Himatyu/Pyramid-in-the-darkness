/**
* @file		ThreadSystem.inl
* @brief	ジョブ登録関数提供
* @author	S.OIKAWA
* @date		2016.10.12
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"ThreadSystem.h"
#include"Estd.h"
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------

#pragma endregion

//-----------------------------------------------------------
// JobExecute 
//-----------------------------------------------------------
template<class ChildTaskList>
inline void ThreadSystem::JobExecute(ChildTaskList& _pJobs)
{
	{
		std::unique_lock<std::mutex> lock(m_QueueMutex);

		for (auto& it : _pJobs)
		{
			if (!m_isActive)
			{//無効ならメインスレッドで実行
				it->Job();
				return;
			}
			m_Tasks.emplace(it);
		}
	}
	Utility::Estd::for_each(
		m_Threads,
		[](Thread* _) 
	{
		if (_->isMonopolize || _->isClose)
		{
			return;
		}
		_->IsReady = true;
	});

	//待機状態解除
	Utility::Estd::for_each(
		_pJobs,
		[&](auto& _) {m_QueueCondition.notify_one(); });
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------
