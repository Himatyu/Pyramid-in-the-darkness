/**
* @file	TimerServer.cpp
* @brief	タイムサーバー実装
* @author S.OIKAWA
* @date	2016/07/26
*/

//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"Exception.h"
#include "TimerServer.h"
#include "TimerClient.h"
//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Utility
{
	double TimerServer::DeltaTime = 0;
	double TimerServer::TimeScale = 1.0;

	//-----------------------------------------------------------
	// ctor
	//-----------------------------------------------------------
	TimerServer::TimerServer()
	{
		//HAKC Instanceで投げるのも無駄な気がする
		LARGE_INTEGER flag;
		if (QueryPerformanceCounter(&flag) == 0)
		{
			___THROW_EXCEPTION_POINT(Exception, "高分解能パフォーマンスカウンタが使用できません");
		}

		QueryPerformanceCounter(&mBegin);
		QueryPerformanceFrequency(&mFreq);

		mClients.reserve(1024);
	}

	//-----------------------------------------------------------
	// Updata
	//-----------------------------------------------------------
	void TimerServer::Updata()
	{
		TimersUpdata();

		QueryPerformanceCounter(&mEnd);
		mFreamDistance.QuadPart = mEnd.QuadPart - mBegin.QuadPart;
		DeltaTime = ((double)mFreamDistance.QuadPart / mFreq.QuadPart) * TimeScale;
		QueryPerformanceCounter(&mBegin);
	}

	//-----------------------------------------------------------
	// TimersUpdata
	//-----------------------------------------------------------
	void TimerServer::TimersUpdata()
	{
		for (auto& it : mClients)
		{
			it->Updata();
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------
