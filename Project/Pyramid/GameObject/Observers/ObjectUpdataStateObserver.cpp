/**
* @file		ObjectUpdataStateObserver.cpp
* @brief	�I�u�W�F�N�g�A�b�v�f�[�g��Ԃ��Ď�����.
* @author	S.OIKAWA
* @date		2016.09.029
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"ObjectUpdataStateObserver.h"
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
			ObjectUpdataStateObserver::
				ObjectUpdataStateObserver(ObjectManager & _mgr) :
				ObjectStateObserver(_mgr)
			{
			}

			//-----------------------------------------------------------
			// OnEvent
			//-----------------------------------------------------------
			void ObjectUpdataStateObserver::
				OnEvent(ObjectStateSubject * _pChangedSubject)
			{
				auto pObj = _pChangedSubject->pOwner;

				if (pObj->UpdataQuery())
				{
					m_ObjectManager.UpdatableObjects.AddRequest(pObj);
					return;
				}
				m_ObjectManager.UpdatableObjects.RemoveRequest(pObj);

			}

		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------

