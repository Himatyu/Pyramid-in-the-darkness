/**
* @file		DelayEvent.cpp
* @brief	’x‰„Õ“ËƒCƒxƒ“ƒg
* @author	S.OIKAWA
* @date		2017.05.10
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"DelayEvent.h"
#include"ICollidee.h"
#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Collision
	{
		namespace Detail
		{

			//-----------------------------------------------------------
			// DelayEvent
			//-----------------------------------------------------------
			DelayEvent::DelayEvent(
				ICollidee * _pReceive,
				HitResult & m_Param,
				DelayEventType m_EventType):
				m_pReceive(_pReceive),
				m_Param(m_Param),
				m_EventType(m_EventType)
			{
			}

			//-----------------------------------------------------------
			// CallEvent
			//-----------------------------------------------------------
			void DelayEvent::CallEvent()
			{
				switch (m_EventType)
				{
				case DelayEventType::Enter:
					m_pReceive->OnCollisionEnter(m_Param);
					return;
				case DelayEventType::Stay:
					m_pReceive->OnCollisionStay(m_Param);
					return;
				case DelayEventType::Exit:
					m_pReceive->OnCollisionExit(m_Param);
					return;
				}
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------