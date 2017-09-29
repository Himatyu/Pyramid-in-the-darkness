/**
* @file		Component.h
* @brief	�R���|�[�l���g�̃x�[�X.
* @author	S.OIKAWA
* @date		2016.09.26
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"Priority.hpp"
#include"TypeComparable.h"
#include"TypeStringConvertible.h"
#include"../GameObject/Detail/StateQueryable.h"
#include"../GameObject/Detail/IEventHook.h"
#include"Observers/ComponentStateSubject.h"
#include"../GameObject/ObjectManager.h" //SubjectId
#include"Defines.h"
#include<array>
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------

namespace Pyramid
{
	namespace GameObject
	{
		class Object;
		class ComponentsPossession;
	}
}

namespace Pyramid
{
	namespace Components
	{		
		using ComponentSubjects =
			std::array<Observers::ComponentStateSubject,
			GameObject::Observers::SubjectId::SubjectMax>;
#pragma endregion

		/// <summary>
		/// �R���|�[�l���g�̃x�[�X.
		/// �e�|�C���^����R�s�[���������\��������̂�
		/// �����Ȃ���ctor��p�ӂ��邱��
		/// </summary>
		class Component :
			public Utility::TypeComparable,
			public GameObject::StateQueryable,
			public GameObject::IEventHook,
			public std::enable_shared_from_this<Component>
		{
			friend class GameObject::ComponentsPossession;
		public:
#pragma region  defaults
			//-----------------------------------------------------------
			// defaults
			//-----------------------------------------------------------
			Component();
			virtual ~Component() = default;

			Component(const Component&) = default;
			Component(Component&&) = default;

			Component& operator=(const Component&) = default;
			Component& operator=(Component&&) = default;
#pragma endregion

#pragma region function
			//-----------------------------------------------------------
			// function
			//-----------------------------------------------------------

			/// <summary>
			/// ������.
			/// </summary>
			virtual void Init() override;

			/// <summary>
			/// �I������.
			/// </summary>
			virtual void Finit() override {};

			/// <summary>
			/// �A�b�v�f�[�g�̑O�ɃR�[�������.
			/// </summary>
			virtual void FastUpdata() override {};

			/// <summary>
			/// �X�V.
			/// </summary>
			virtual void Updata() override {};

			/// <summary>
			/// �A�b�v�f�[�g�̌�ɃR�[�������.
			/// </summary>
			virtual void LateUpdata() override {};

			/// <summary>
			/// �`��O����.
			/// </summary>
			virtual void PreDraw() override {};


			/// <summary>
			/// �f�o�b�N�@�\
			/// </summary>
			___DEBUG_DEFINE(virtual void AdditionalUpdataOfDebug() {});

		protected:
			/// <summary>
			/// isActive�ύX���̃t�b�N.
			/// </summary>
			virtual void ModifyisActive() override;

			/// <summary>
			/// isDestory�ύX���̃t�b�N.
			/// </summary>
			virtual void ModifyisDestory() override;

			/// <summary>
			/// isUpdata�ύX���̃t�b�N.
			/// </summary>
			virtual void ModifyisUpdata() override;

			/// <summary>
			/// isDraw�ύX���̃t�b�N.
			/// </summary>
			virtual void ModifyisDraw() override;

			/// <summary>
			/// �v���C�I���e�B�ύX���̃t�b�N
			/// </summary>
			virtual void ModifyPriority();

		protected:
			template<class Ty>
			void TypeApply(); //�㏑����

#pragma endregion

		public:
#pragma region property
			//-----------------------------------------------------------
			// property
			//-----------------------------------------------------------
			PROPERTY(m_pOwner, pOwner, GameObject::Object*);
			PROPERTY_REF(m_Tag, Tag, std::string);
			PROPERTY_REF_HOOKABLE(m_UpdataPriority, UpdataPriority, Utility::Priority<UINT>, ModifyPriority);
			PROPERTY_REF_R_ONLY(m_StateSubjects, StateSubjects, ComponentSubjects);
#pragma endregion

		protected:
#pragma region value
			//-----------------------------------------------------------
			// val
			//-----------------------------------------------------------
			GameObject::Object*			m_pOwner;
			std::string					m_Tag;
			Utility::Priority<UINT>		m_UpdataPriority;
			ComponentSubjects			m_StateSubjects;

#pragma endregion
		};
#include"Component.inl"

}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------