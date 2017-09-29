/**
* @file		TimerServer.cpp
* @brief	ÉtÉåÅ[ÉÄä¥äoÇ∆éûä‘î{ó¶ÇèäéùÇ∑ÇÈ
* @author	S.OIKAWA
* @date		2016.11.26
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"TimerServer.h"
#include"Constant.h"
#include"../Common/Constant.h"

#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
using namespace std::chrono;
using namespace std::literals::chrono_literals;
namespace Pyramid
{
	namespace Common
	{
		float TimerServer::DeltaTime = 0;
		float TimerServer::TimeScale = 1.0;

		//-----------------------------------------------------------
		// ctor
		//-----------------------------------------------------------
		TimerServer::TimerServer()
		{
			m_Start = system_clock::now();
			Order(&TimerServer::Updata,
				Common::Constant::MTUpdataGrupName,
				Constant::TimerServerMTUpdataLineID);
		}

		//-----------------------------------------------------------
		// dtor
		//-----------------------------------------------------------
		TimerServer::~TimerServer()
		{
			OrderCancel(OrderList[0]);
		}

		//-----------------------------------------------------------
		// Updata
		//-----------------------------------------------------------
		void TimerServer::Updata()
		{
			m_End = system_clock::now();
			auto elapsed = m_End - m_Start;
			DeltaTime = 
				static_cast<float>(
					duration_cast<duration<double, std::ratio<1, 1>>>(elapsed)
				.count() * TimeScale);
			m_Start = system_clock::now();
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------