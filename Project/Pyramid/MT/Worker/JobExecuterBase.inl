/**
* @file		JobExecuterBase.inl
* @brief	タスク実行機能ベースの機能提供
* @author	S.OIKAWA
* @date		2016.11.25
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"JobExecuterBase.h"
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------

#pragma endregion

/// <summary>
/// ディスパッチ.
/// オーダーが又はジョブがない場合何もしない
/// </summary>
template<class JobType, class OrderData>
inline void
JobExecuterBase::JobDispatch(
	std::vector<JobType>& _job,
	OrderData& _order)
{
	auto& mtSystem = ThreadSystem::Instantiate();
	size_t threadCount = mtSystem.CommonThreadCount();
	size_t orderCount = _order.size();

	if (!orderCount || !threadCount)
	{
		return;
	}

	if (orderCount <= threadCount)
	{
		auto it = _order.begin();
		for (unsigned i = 0; i < _order.size(); i++)
		{
			_job[i]->pJobs.push_back(*(it++));
		}
		return;
	}

	int threadPerJob = orderCount / threadCount;
	auto it = _order.begin();
	for (unsigned i = 0; i < threadCount; i++)
	{
		for (int j = 0; j < threadPerJob; j++)
		{
			_job[i]->pJobs.push_back(*(it++));
		}
		orderCount -= threadPerJob;
	}
	//必ずorderCount < threadCountになる
	if (orderCount>0)
	{
		for (unsigned i = 0; i < orderCount; i++)
		{
			_job[i]->pJobs.emplace_back(*it++);
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------