/**
* @file		ObjectRenderStateObserver.cpp
* @brief	オブジェクトの描画状態を受信する
* @author	S.OIKAWA
* @date		2016.10.05
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"ObjectRenderStateObserver.h"
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
			ObjectRenderStateObserver::
				ObjectRenderStateObserver(ObjectManager & _mgr) :
				ObjectStateObserver(_mgr)
			{
			}

			//-----------------------------------------------------------
			// OnEvent
			//-----------------------------------------------------------
			void ObjectRenderStateObserver::
				OnEvent(ObjectStateSubject * _ChangedSubject)
			{
				auto pObj = _ChangedSubject->pOwner;

				if (pObj->DrawQuery())
				{
					m_ObjectManager.DrawbleObjects.AddRequest(pObj);
					return;
				}
				m_ObjectManager.DrawbleObjects.RemoveRequest(pObj);
			}

		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------
