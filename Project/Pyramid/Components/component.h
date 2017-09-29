/**
* @file		Component.h
* @brief	コンポーネントのベース.
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
		/// コンポーネントのベース.
		/// 親ポインタからコピー生成される可能性があるので
		/// 引数なしのctorを用意すること
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
			/// 初期化.
			/// </summary>
			virtual void Init() override;

			/// <summary>
			/// 終了処理.
			/// </summary>
			virtual void Finit() override {};

			/// <summary>
			/// アップデートの前にコールされる.
			/// </summary>
			virtual void FastUpdata() override {};

			/// <summary>
			/// 更新.
			/// </summary>
			virtual void Updata() override {};

			/// <summary>
			/// アップデートの後にコールされる.
			/// </summary>
			virtual void LateUpdata() override {};

			/// <summary>
			/// 描画前処理.
			/// </summary>
			virtual void PreDraw() override {};


			/// <summary>
			/// デバック機能
			/// </summary>
			___DEBUG_DEFINE(virtual void AdditionalUpdataOfDebug() {});

		protected:
			/// <summary>
			/// isActive変更時のフック.
			/// </summary>
			virtual void ModifyisActive() override;

			/// <summary>
			/// isDestory変更時のフック.
			/// </summary>
			virtual void ModifyisDestory() override;

			/// <summary>
			/// isUpdata変更時のフック.
			/// </summary>
			virtual void ModifyisUpdata() override;

			/// <summary>
			/// isDraw変更時のフック.
			/// </summary>
			virtual void ModifyisDraw() override;

			/// <summary>
			/// プライオリティ変更時のフック
			/// </summary>
			virtual void ModifyPriority();

		protected:
			template<class Ty>
			void TypeApply(); //上書する

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