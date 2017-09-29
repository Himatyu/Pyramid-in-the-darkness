/**
* @file		ComponentPriorityStateObserver.h
* @brief	コンポーネントの優先度の変更を受信してリストをソートする.
* @author	S.OIKAWA
* @date		2016.09.30
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"ComponentStateObserver.h"
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------
#pragma endregion

namespace Pyramid
{
	namespace Components
	{
		namespace Observers
		{

			/// <summary>
			/// コンポーネントの優先度の変更を受信してリストをソートする.
			/// </summary>
			class ComponentPriorityStateObserver final :
				public ComponentStateObserver
			{
			public:
#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				ComponentPriorityStateObserver(GameObject::Object&);
				~ComponentPriorityStateObserver() = default;

				ComponentPriorityStateObserver(const ComponentPriorityStateObserver&) = default;
				ComponentPriorityStateObserver(ComponentPriorityStateObserver&&) = default;

				ComponentPriorityStateObserver& operator=(const ComponentPriorityStateObserver&) = default;
				ComponentPriorityStateObserver& operator=(ComponentPriorityStateObserver&&) = default;
#pragma endregion

#pragma region function
				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------
				/// <summary>
				/// Updatebleリストソート.
				/// </summary>
				void OnEvent(ComponentStateSubject* _ChangedSubject) override;

#pragma endregion

			};
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------