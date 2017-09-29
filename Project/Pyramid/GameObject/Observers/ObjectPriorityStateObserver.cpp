/**
* @file		ObjectPriorityStateObserver.cpp
* @brief	�I�u�W�F�N�g�̃v���C�I���e�B�̕ύX���󂯎�胊�X�g���X�V����.
* @author	S.OIKAWA
* @date		2016.09.30
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"ObjectPriorityStateObserver.h"
#include"Estd.h"
#include"../ObjectManager.h"
#include<algorithm>
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
			//-----------------------------------------------------------
			// ObjectPriorityStateObserver
			//-----------------------------------------------------------
			ObjectPriorityStateObserver::
				ObjectPriorityStateObserver(ObjectManager & _mgr) :
				ObjectStateObserver(_mgr)
			{
			}

			//-----------------------------------------------------------
			// OnEvent
			//-----------------------------------------------------------
			void ObjectPriorityStateObserver::
				OnEvent(ObjectStateSubject * _ChangedSubject)
			{
				Utility::Estd::sort(m_ObjectManager.UpdatableObjects.Vector);
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------

