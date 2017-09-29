/**
* @file		ComponentsPossession.h
* @brief	コンポーネントを管理する.
* @author	S.OIKAWA
* @date		2016.09.26
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"../Components/Creators/ComponentCreator.h"
#include"../Components/Component.h"
#include"../Utility/Factory.h"
#include"SafetyIterate.h"
#include"Nullable.h"
#include<algorithm>
#include<memory>
#include<vector>
#include<list>
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------

namespace Pyramid
{
	namespace Components
	{
		class Component;
	}

	namespace GameObject
	{
		class Object;
		using spComponent = std::shared_ptr<Components::Component>;

		template<class Ty>
		using NullableSp = Utility::Nullable<std::shared_ptr<Ty>>;
	}
}
#pragma endregion

namespace Pyramid
{
	namespace GameObject
	{

		/// <summary>
		/// コンポーネントを管理する.
		/// </summary>
		class ComponentsPossession
		{
		public:
#pragma region  defaults
			//-----------------------------------------------------------
			// defaults
			//-----------------------------------------------------------
			ComponentsPossession() = delete;
			ComponentsPossession(Object*);
			virtual ~ComponentsPossession();

			ComponentsPossession(const ComponentsPossession&);
			ComponentsPossession(ComponentsPossession&&);

			ComponentsPossession& operator=(const ComponentsPossession&);
			ComponentsPossession& operator=(ComponentsPossession&&);
#pragma endregion

#pragma region function
			//-----------------------------------------------------------
			// function
			//-----------------------------------------------------------

			/// <summary>
			/// コンポーネントを追加.
			/// </summary>
			template <class Type, class ...Param>
			std::shared_ptr<Type> AddComponent(Param&&...);

			/// <summary>
			/// コンポーネントを削除.
			/// </summary>
			template <class Type>
			void RemoveComponent();

			/// <summary>
			/// コンポーネントの取得.
			/// </summary>
			template <class Type>
			Utility::Nullable<std::shared_ptr<Type>> GetComponent();

			/// <summary>
			/// コンポーネントの取得.
			/// </summary>
			template <class Type>
			Utility::Nullable<std::shared_ptr<Type>> GetComponentFromTag(std::string);

			/// <summary>
			/// コンポーネントの複数取得.
			/// </summary>
			template <class Type>
			Utility::Nullable<std::vector<std::shared_ptr<Type>>> GetComponents();

			/// <summary>
			/// コンポーネント所持確認.
			/// </summary>
			template <class Type>
			bool HasComponent();

#pragma endregion

#pragma region property
			//-----------------------------------------------------------
			// property
			//-----------------------------------------------------------
			
			PROPERTY_CR_R_ONLY(m_AllComponents, AllComponents, std::list<spComponent>);
			PROPERTY_REF(m_UpdatableComponents,
				UpdatableComponents, 
				Utility::SafetyIterate<Components::Component*>);
			PROPERTY_REF(m_DrawbleComponents,
				DrawbleComponents, 
				Utility::SafetyIterate<Components::Component*>);

#pragma endregion

		protected:
#pragma region value
			//-----------------------------------------------------------
			// val
			//-----------------------------------------------------------
			Object*									m_pOwner;
			std::list<spComponent>					m_AllComponents;			
			Utility::SafetyIterate<Components::Component*>		m_DrawbleComponents;
			Utility::SafetyIterate<Components::Component*>		m_UpdatableComponents;
#pragma endregion
		};
#include"ComponentsPossession.inl"
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------