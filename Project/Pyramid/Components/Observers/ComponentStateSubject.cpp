/**
* @file		ComponentStateSubject.cpp
* @brief	コンポーネントの状態を通知
* @author	S.OIKAWA
* @date		2016.09.20
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"ComponentStateObserver.h"
#include"ComponentStateSubject.h"
#include"Estd.h"
#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Components
	{
		namespace Observers
		{

			//-----------------------------------------------------------
			// Attach
			//-----------------------------------------------------------
			void ComponentStateSubject::Attach(ComponentStateObserver * _obser)
			{
				if (!_obser)
				{
					return;
				}
				m_Ovservers.push_back(_obser);
			}

			//-----------------------------------------------------------
			// Detach
			//-----------------------------------------------------------
			void ComponentStateSubject::Detach(ComponentStateObserver * _obser)
			{
				auto it = find(m_Ovservers.begin(), m_Ovservers.end(), _obser);
				if (m_Ovservers.end() == it)
				{
					return;
				}
				m_Ovservers.erase(it);
			}

			//-----------------------------------------------------------
			// Notify
			//-----------------------------------------------------------
			void ComponentStateSubject::Notify()
			{
				Utility::Estd::for_each(
					m_Ovservers,
					[this](auto& _) {_->OnEvent(this); });
			}

		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------

