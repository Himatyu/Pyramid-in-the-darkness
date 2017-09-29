/**
* @file		ComponentStateObserver.h
* @brief	コンポーネントの状態を監視する
* @author	S.OIKAWA
* @date		2016.09.20
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------

#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Object
	{
		class Object;
	}
}

#pragma endregion

namespace Pyramid
{
	namespace Components
	{
		namespace Observers
		{
			class ComponentStateSubject;

			/// <summary>
			/// コンポーネントの状態を監視する
			/// </summary>
			class ComponentStateObserver
			{
			public:
#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				ComponentStateObserver(GameObject::Object&);
				virtual ~ComponentStateObserver() = default;

				ComponentStateObserver(const ComponentStateObserver&) = default;
				ComponentStateObserver(ComponentStateObserver&&) = default;

				ComponentStateObserver& operator=(const ComponentStateObserver&) = default;
				ComponentStateObserver& operator=(ComponentStateObserver&&) = default;
#pragma endregion

#pragma region function
				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------
				virtual void OnEvent(ComponentStateSubject* _ChangedSubject) = 0;
#pragma endregion

#pragma region property
				//-----------------------------------------------------------
				// property
				//-----------------------------------------------------------
				PROPERTY(m_pOwner, pOwner, GameObject::Object*);
#pragma endregion
			protected:
#pragma region value
				//-----------------------------------------------------------
				// val
				//-----------------------------------------------------------
				GameObject::Object*		m_pOwner;
#pragma endregion
			};
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------