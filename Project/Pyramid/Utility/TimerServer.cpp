/**
* @file	TimerServer.cpp
* @brief	�^�C���T�[�o�[����
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
		//HAKC Instance�œ�����̂����ʂȋC������
		LARGE_INTEGER flag;
		if (QueryPerformanceCounter(&flag) == 0)
		{
			___THROW_EXCEPTION_POINT(Exception, "������\�p�t�H�[�}���X�J�E���^���g�p�ł��܂���");
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
