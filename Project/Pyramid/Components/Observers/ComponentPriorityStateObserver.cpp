/**
* @file		ComponentPriorityStateObserver.cpp
* @brief	�R���|�[�l���g�̗D��x�̕ύX����M���ă��X�g���\�[�g����.
* @author	S.OIKAWA
* @date		2016.09.30
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"ComponentPriorityStateObserver.h"
#include"Estd.h"
#include"../GameObject/Object.h"
#include<algorithm>

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
			ComponentPriorityStateObserver::
				ComponentPriorityStateObserver(GameObject::Object & _obj) :
				ComponentStateObserver(_obj)
			{
			}

			//-----------------------------------------------------------
			// OnEvent
			//-----------------------------------------------------------
			void ComponentPriorityStateObserver::
				OnEvent(ComponentStateSubject * _ChangedSubject)
			{
				Utility::Estd::sort(m_pOwner->UpdatableComponents.Vector);
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------

