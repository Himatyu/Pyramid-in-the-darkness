/**
* @file		ObjectStateSubject.cpp
* @brief	オブジェクトの状態（有効・描画）を通知
* @author	S.OIKAWA
* @date		2016.09.19
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"ObjectStateSubject.h"
#include"ObjectStateObserver.h"
#include"Estd.h"
#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace GameObject
	{
		namespace Observers
		{
			using namespace std;
			using namespace Utility::Estd;
			//-----------------------------------------------------------
			// Attach
			//-----------------------------------------------------------
			void ObjectStateSubject::Attach(ObjectStateObserver * _obser)
			{
				if (!_obser)
				{
					return;
				}
				m_Observers.push_back(_obser);
			}

			//-----------------------------------------------------------
			// Detach
			//-----------------------------------------------------------
			void ObjectStateSubject::Detach(ObjectStateObserver * _obser)
			{
				auto it = find(m_Observers, _obser);
				if (m_Observers.end() == it)
				{
					return;
				}
				m_Observers.erase(it);
			}

			//-----------------------------------------------------------
			// Notify
			//-----------------------------------------------------------
			void ObjectStateSubject::Notify()
			{
				for_each(m_Observers,
					[this](ObjectStateObserver * _) {_->OnEvent(this); });
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------
