/**
* @file		ComponentUpdataStateObserver.cpp
* @brief	コンポーネントのアップデート状態を監視する.
* @author	S.OIKAWA
* @date		2016.09.29
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"ComponentUpdataStateObserver.h"
#include"../Component.h"
#include"../GameObject/Object.h"
#include<memory>

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
			// ctor
			//-----------------------------------------------------------
			ComponentUpdataStateObserver::
				ComponentUpdataStateObserver(GameObject::Object & _obj) :
				ComponentStateObserver(_obj)
			{
			}

			//-----------------------------------------------------------
			// OnEvent
			//-----------------------------------------------------------
			void ComponentUpdataStateObserver::
				OnEvent(ComponentStateSubject * _ChangedSubject)
			{
				auto pCom = _ChangedSubject->pOwner;
				if ((pCom)->UpdataQuery())
				{
					m_pOwner->UpdatableComponents.AddRequest(pCom);
					return;
				}
				m_pOwner->UpdatableComponents.RemoveRequest(pCom);
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------
