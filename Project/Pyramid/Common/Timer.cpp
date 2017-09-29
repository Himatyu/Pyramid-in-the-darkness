/**
* @file		Timer.cpp
* @brief
* @author
* @date
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"Timer.h"
#include"TimerServer.h"
#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Common
	{
		//-----------------------------------------------------------
		// ctor
		//-----------------------------------------------------------
		Timer::Timer(double _time, bool _isActive, bool _isOnce):
			m_Rest(_time),
			m_SetTime(_time),
			m_IsActive(_isActive),
			m_IsOnce(_isOnce),
			m_IsElapsed(false)
		{
			Order(&Timer::Updata,"Updata",2);
		}

		//-----------------------------------------------------------
		// dtor
		//-----------------------------------------------------------
		Timer::~Timer()
		{
			OrderCancel(OrderList[0]);
		}

		//-----------------------------------------------------------
		// Reset
		//-----------------------------------------------------------
		void Timer::Reset(double newTime)
		{
			m_IsElapsed = false;
			if (newTime == -1)
			{
				m_Rest = m_SetTime;
				return;
			}
			m_SetTime = m_Rest = newTime;
			
		}

		//-----------------------------------------------------------
		// Updata
		//-----------------------------------------------------------
		void Timer::Updata()
		{
			if (!m_IsActive)
			{
				return;
			}
			if (m_IsElapsed)
			{
				if (IsOnce)
				{
					return;
				}
				m_IsActive = true;
				Reset(m_SetTime);
				return;
			}
			m_Rest -= TimerServer::DeltaTime;
			if (m_Rest <= 0)
			{
				m_IsElapsed = true;
			}
		}

		//-----------------------------------------------------------
		// SetTimeNotify
		//-----------------------------------------------------------
		void Timer::SetTimeNotify()
		{
			m_Rest = m_SetTime;
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------