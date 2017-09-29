/**
* @file		Component.cpp
* @brief	�R���|�[�l���g�̃x�[�X.
* @author	S.OIKAWA
* @date		2016.09.26
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"Component.h"
#include<memory>
#include"Estd.h"
#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Components
	{
		using namespace GameObject;

		//-----------------------------------------------------------
		// ctor
		//-----------------------------------------------------------
		Component::Component()
		{
		}

		//-----------------------------------------------------------
		// Init 
		//-----------------------------------------------------------
		void Component::Init()
		{
			//Component�R���X�g���N�^����shardPtr�̎擾���o���Ȃ����炱���ł��
			auto spCom = shared_from_this();
			Utility::Estd::for_each(
				m_StateSubjects, 
				[&](auto& _) {_.pOwner = spCom.get(); });
			auto& subjects = m_StateSubjects;
			auto& ovservers = m_pOwner->ComponentStateObservers;	//ComponentsPossession��pOwner�Z�b�g
			for (int i = 0; i < GameObject::Observers::SubjectMax; i++)
			{
				subjects[i].Attach(ovservers[i]);
			}
		}
		//-----------------------------------------------------------
		// ModifyisActive
		//-----------------------------------------------------------
		void Component::ModifyisActive()
		{
			m_StateSubjects[GameObject::Observers::EffectiveState].Notify();
		}

		//-----------------------------------------------------------
		// ModifyisDestory
		//-----------------------------------------------------------
		void Component::ModifyisDestory()
		{
			m_StateSubjects[GameObject::Observers::EffectiveState].Notify();
		}

		//-----------------------------------------------------------
		// ModifyisUpdata
		//-----------------------------------------------------------
		void Component::ModifyisUpdata()
		{
			m_StateSubjects[GameObject::Observers::UpdataState].Notify();
		}

		//-----------------------------------------------------------
		// ModifyisDraw
		//-----------------------------------------------------------
		void Component::ModifyisDraw()
		{
			m_StateSubjects[GameObject::Observers::DrawState].Notify();
		}

		//-----------------------------------------------------------
		// ModifyPriority
		//-----------------------------------------------------------
		void Component::ModifyPriority()
		{
			m_StateSubjects[GameObject::Observers::PriorityState].Notify();
		}

	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------
