/**
* @file		Holder.h
* @brief	リスナーの登録と登録削除を行う
* @author	S.OIKAWA
* @date		2017.06.01
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"Manager.h"
#include"TypeList.h"
#include"IUnknown.h"
#include"Nullable.h"
#include"NullType.h"
#include"Estd.h"
#include<vector>
#include<array>
#include<typeindex>
#include<utility>
#include<type_traits>
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace UI
	{
		namespace Event
		{
			namespace Listener
			{
				template<class Interface>
				using Manager = 
					::Utility::Manager<::std::vector<Interface>>;
			}
		}
	}
}
#pragma endregion

namespace Pyramid
{
	namespace UI
	{
		namespace Event
		{
			namespace Listener
			{
				/// <summary>
				/// リスナーの登録と登録削除を行う
				/// </summary>
				template<class ...Interfaces>
				class Holder 
				{
				public:
					using InterfaceList =
						typename Utility::ConvertToTypeList<Interfaces...>::Result;

					using ArrayElement = ::std::pair<
						const::std::type_info*,::Utility::Unknown*>;

#pragma region  defaults
					//-----------------------------------------------------------
					// defaults
					//-----------------------------------------------------------
					Holder();
					virtual ~Holder();

					Holder(const Holder&) = default;
					Holder(Holder&&) = default;

					Holder& operator=(const Holder&) = default;
					Holder& operator=(Holder&&) = default;
#pragma endregion

#pragma region function
					//-----------------------------------------------------------
					// function
					//-----------------------------------------------------------

					/// <summary>
					/// リスナーの登録を行う
					/// </summary>
					template<class Interface>
					void AddListener(Interface*);
					
					/// <summary>
					/// リスナーの登録削除を行う
					/// </summary>
					template<class Interface>
					void RemoveListener(Interface*);

				protected:
					/// <summary>
					/// マネージャを検索する
					/// </summary>
					template<class Interface>
					::Utility::Nullable<Manager<Interface*>*>
						FindOfManager();

				private:
					template<class InterfaceTypeList>
					void ParseAndRegister();

#pragma endregion

#pragma region property
					//-----------------------------------------------------------
					// property
					//-----------------------------------------------------------

#pragma endregion

#pragma region value
				protected:
					//-----------------------------------------------------------
					// val
					//-----------------------------------------------------------
					::std::array<
						ArrayElement,
						sizeof...(Interfaces)
						>	m_Managers;
#pragma endregion
				};
#include"Holder.inl"
				
			}
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------