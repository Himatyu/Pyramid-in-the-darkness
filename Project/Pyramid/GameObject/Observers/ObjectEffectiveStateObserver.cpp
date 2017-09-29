/**
* @file		ObjectEffectiveStateObserver.cpp
* @brief	オブジェクトの有効・無効のイベント通知を行う.
* @author	S.OIKAWA
* @date		2016.09.19
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"ObjectEffectiveStateObserver.h"
#include"ObjectStateSubject.h"
#include"../ObjectManager.h"
#include"../Object.h"
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
			//-----------------------------------------------------------
			// ctor
			//-----------------------------------------------------------
			ObjectEffectiveStateObserver::
				ObjectEffectiveStateObserver(ObjectManager & _mgr) :
				ObjectStateObserver(_mgr)
			{
			}

			//-----------------------------------------------------------
			// OnEvent 
			//-----------------------------------------------------------
			void ObjectEffectiveStateObserver::
				OnEvent(ObjectStateSubject * _ChangedSubject)
			{
				auto pObj = _ChangedSubject->pOwner;

				if (pObj->isActive)
				{
					m_ObjectManager.DrawbleObjects.AddRequest(pObj);
					m_ObjectManager.UpdatableObjects.AddRequest(pObj);
					return;
				}
				
				m_ObjectManager.DrawbleObjects.RemoveRequest(pObj);
				m_ObjectManager.UpdatableObjects.RemoveRequest(pObj);


			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------

