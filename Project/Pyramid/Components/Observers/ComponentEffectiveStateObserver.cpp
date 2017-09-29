/**
* @file		ComponentEffectiveStateObserver.cpp
* @brief	�R���|�[�l���g�̗L�������̕ύX���󂯎�胊�X�g�̍X�V���s��
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
				//�ύX�O�̏���ێ���������A����������������͂�
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

