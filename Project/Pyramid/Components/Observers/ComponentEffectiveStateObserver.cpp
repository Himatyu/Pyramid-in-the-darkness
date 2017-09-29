/**
* @file		ComponentEffectiveStateObserver.cpp
* @brief	コンポーネントの有効無効の変更を受け取りリストの更新を行う
* @author	S.OIKAWA
* @date		2016.09.20
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"ComponentEffectiveStateObserver.h"
#include"ComponentStateSubject.h"
#include"../GameObject/Object.h"
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
			ComponentEffectiveStateObserver::
				ComponentEffectiveStateObserver(GameObject::Object & _obj) :
				ComponentStateObserver(_obj)
			{
			}

			//-----------------------------------------------------------
			// OnEvent
			//-----------------------------------------------------------
			void ComponentEffectiveStateObserver::
				OnEvent(ComponentStateSubject * _ChangedSubject)
			{
				//変更前の情報を保持するよりも、検索するよりも早いはず
				auto pCom = _ChangedSubject->pOwner;

				if ((pCom)->isActive)
				{
					m_pOwner->UpdatableComponents.AddRequest(pCom);
					m_pOwner->DrawbleComponents.AddRequest(pCom);
					return;
				}
				m_pOwner->UpdatableComponents.RemoveRequest(pCom);
				m_pOwner->DrawbleComponents.RemoveRequest(pCom);

			}
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------

