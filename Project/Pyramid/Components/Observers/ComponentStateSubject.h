/**
* @file		ComponentStateSubject.h
* @brief	コンポーネントの状態をオブジェクトに通知
* @author	S.OIKAWA
* @date		2016.09.20
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include<vector>
#include<memory>
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
};
#pragma endregion

namespace Pyramid
{
	namespace Components
	{
		namespace Observers
		{
			class ComponentStateObserver;

			/// <summary>
			/// コンポーネントの状態を通知.
			/// </summary>
			class ComponentStateSubject final
			{
			public:
#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				ComponentStateSubject() = default;
				virtual ~ComponentStateSubject() = default;

				ComponentStateSubject(const ComponentStateSubject&) = default;
				ComponentStateSubject(ComponentStateSubject&&) = default;

				ComponentStateSubject& operator=(const ComponentStateSubject&) = default;
				ComponentStateSubject& operator=(ComponentStateSubject&&) = default;
#pragma endregion

#pragma region function
				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------
				/// <summary>監視者登録</summary>	
				///<param name="_obser">登録監視者</param>
				void Attach(ComponentStateObserver* _obser);

				/// <summary>監視者削除</summary>
				///<param name="_obser">削除監視者</param>
				void Detach(ComponentStateObserver* _obser);

				/// <summary>通知</summary>
				void Notify();

#pragma endregion

#pragma region property
				//-----------------------------------------------------------
				// property
				//-----------------------------------------------------------
				PROPERTY(m_pOwner, pOwner, Component*);
				PROPERTY_REF(m_Ovservers, Ovservers, std::vector<ComponentStateObserver*>);
#pragma endregion

			protected:
#pragma region value
				//-----------------------------------------------------------
				// val
				//-----------------------------------------------------------
				std::vector<ComponentStateObserver*>	m_Ovservers;
				Component*								m_pOwner;			//spだと自己参照が起こる
#pragma endregion
			};
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------