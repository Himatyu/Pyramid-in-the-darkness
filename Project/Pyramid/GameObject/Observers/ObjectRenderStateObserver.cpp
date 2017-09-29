/**
* @file		ObjectRenderStateObserver.cpp
* @brief	�I�u�W�F�N�g�̕`���Ԃ���M����
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
