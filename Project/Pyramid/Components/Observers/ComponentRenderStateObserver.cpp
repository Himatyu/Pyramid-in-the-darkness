/**
* @file		ComponentRenderStateObserver.cpp
* @brief	コンポーネントの描画状態を監視実装
* @author	S.OIKAWA
* @date		2016.09.20
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"ComponentRenderStateObserver.h"
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
			ComponentRenderStateObserver::
				ComponentRenderStateObserver(GameObject::Object & _obj) :
				ComponentStateObserver(_obj)
			{
			}

			//-----------------------------------------------------------
			// OnEvent
			//-----------------------------------------------------------
			void ComponentRenderStateObserver::
				OnEvent(ComponentStateSubject * _ChangedSubject)
			{
				auto pCom = _ChangedSubject->pOwner;

				if ((pCom)->DrawQuery())
				{
					m_pOwner->DrawbleComponents.AddRequest(pCom);
					return;
				}
				m_pOwner->DrawbleComponents.RemoveRequest(pCom);
			}
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------

