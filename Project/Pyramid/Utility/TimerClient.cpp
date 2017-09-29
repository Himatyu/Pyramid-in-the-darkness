/**
* @file		TimerClient.cpp	
* @brief		タイマー実装
* @author		S.OIKAWA
* @date		2016/07/26
*/

//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"TimerServer.h"
#include "TimerClient.h"

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Utility
{
	//-----------------------------------------------------------
	// ctor
	//-----------------------------------------------------------
	TimerClient::TimerClient()
	{
		auto& server = TimerServer::Instantiate();
		server.mClients.push_back(this);
	}

	//-----------------------------------------------------------
	// dtor
	//-----------------------------------------------------------
	TimerClient::~TimerClient()
	{
		auto& server = TimerServer::Instantiate();
		auto& vec = server.mClients;
		auto it = find(vec.begin(), vec.end(), this);
		vec.erase(it);
	}

	//-----------------------------------------------------------
	// Updata
	//-----------------------------------------------------------
	void TimerClient::Updata()
	{
		if (!mIsActive)
		{
			return;
		}

		if (mIsTimeUP)
		{
			SetActive(mIsReset);
		}

		mNow -= TimerServer::DeltaTime;
		if (mNow < 0)
		{
			mIsTimeUP = true;
		}
	}

	//-----------------------------------------------------------
	// SetActive
	//-----------------------------------------------------------
	void TimerClient::SetActive(const bool flag)
	{
		if (flag)
		{
			Init(mTime);
		}
		mIsActive = flag;
	}

	//-----------------------------------------------------------
	// Init
	//-----------------------------------------------------------
	void TimerClient::Init(const double time, const bool reset, bool active)
	{
		mIsActive = active;
		mTime = mNow = time;
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------
