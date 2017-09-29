/**
* @file		Object.h
* @brief	�K��I�u�W�F�N�g�N���X
* @author	S.OIKAWA
* @date		2016.02.19
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"Priority.hpp"
#include"ICastable.h"
#include"TypeComparable.h"
#include"TypeStringConvertible.h"
#include"Detail\StateQueryable.h"
#include"Detail\IEventHook.h"
#include"Observers/ObjectStateSubject.h"
#include"Detail\ComponentsPossession.h"
#include"ObjectManager.h"	//SubjectId

#include<string>
#include<vector>
#include<array>

#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define 
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Blueprint
	{
		class Level;
	}

	namespace Components
	{
		namespace Observers
		{
			class ComponentStateObserver;
			using ComponentObservers =
				std::array<ComponentStateObserver*,
				GameObject::Observers::SubjectMax>;
		}
	}

	namespace GameObject
	{
		namespace Observers
		{
			using ObjectSubjects =
				std::array<ObjectStateSubject,
				SubjectId::SubjectMax>;
		}
	}
}
#pragma endregion

namespace Pyramid
{
	namespace GameObject
	{
		/// <summary>
		/// Pyramid�ň����I�u�W�F�N�g.
		/// �R�s�[�͂��Ă�����������Ȃ̂ŗ��p�͔�����悤��.
		/// </summary>
		class Object :
			public Utility::TypeComparable,
			public Utility::ICastable,
			public StateQueryable,
			public IEventHook,
			public ComponentsPossession
		{
			friend class Blueprint::Level;
		public:

#pragma region  defaults
			//-----------------------------------------------------------
			// defaults
			//-----------------------------------------------------------
			Object() = delete;
			Object(Blueprint::Level*);
			virtual ~Object();

			Object(const Object&);
			Object(Object&&);

#pragma endregion

#pragma region  operator
			//-----------------------------------------------------------
			// operator
			//-----------------------------------------------------------
			Object& operator=(const Object&);
			Object& operator=(Object&&);

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
			virtual void Finit() override;

			/// <summary>
			/// �A�b�v�f�[�g�̑O�ɃR�[�������.
			/// </summary>
			virtual void FastUpdata() override;

			/// <summary>
			/// �X�V.
			/// </summary>
			virtual void Updata() override;

			/// <summary>
			/// �A�b�v�f�[�g�̌�ɃR�[�������.
			/// </summary>
			virtual void LateUpdata() override;

			/// <summary>
			/// �`��.
			/// </summary>
			virtual void PreDraw() override;

			___DEBUG_DEFINE
			(
				virtual void DebugUpdata();
			)
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

		private:
			/// <summary>
			/// �N���[��
			/// </summary>
			void Clone(const Object& _other);

			/// <summary>
			/// ���[�u
			/// </summary>
			void Move(Object& _other);

			/// <summary>
			/// �^�o�^
			/// </summary>
			template<class Ty>
			void TypeApply();
#pragma endregion

		public:
#pragma region property
			//-----------------------------------------------------------
			// property
			//-----------------------------------------------------------

			PROPERTY_REF_HOOKABLE(m_UpdataPriority, UpdataPriority, Utility::Priority<UINT>, ModifyPriority);
			PROPERTY(m_pOwner, pOwner, Blueprint::Level*);
			PROPERTY_REF(m_Tag, Tag, std::string);
			PROPERTY_REF_R_ONLY(m_StateSubjects, StateSubjects, Observers::ObjectSubjects);
			PROPERTY_REF_R_ONLY(m_ComponentStateObservers,
				ComponentStateObservers,
				Components::Observers::ComponentObservers);

#pragma endregion

		protected:
#pragma region value
			//-----------------------------------------------------------
			// val
			//-----------------------------------------------------------
			Utility::Priority<UINT>						m_UpdataPriority;
			Blueprint::Level*							m_pOwner;
			std::string									m_Tag;
			Observers::ObjectSubjects					m_StateSubjects;
			Components::Observers::ComponentObservers	m_ComponentStateObservers;
#pragma endregion

		};
#include"Object.inl"
	}
}

//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------

