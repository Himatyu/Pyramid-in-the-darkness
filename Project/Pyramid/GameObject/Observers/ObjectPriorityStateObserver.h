/**
* @file		ObjectPriorityStateObserver.h
* @brief	オブジェクトのプライオリティの変更を受け取りリストを更新する.
* @author	S.OIKAWA
* @date		2016.09.30
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"ObjectStateObserver.h"

#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------
#pragma endregion
namespace Pyramid
{
	namespace GameObject
	{
		namespace Observers
		{
			/// <summary>
			/// プライオリティの変更を受け取りリストを更新する.
			/// </summary>
			class ObjectPriorityStateObserver final :
				public ObjectStateObserver
			{
			public:
#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				ObjectPriorityStateObserver(ObjectManager&);
				~ObjectPriorityStateObserver() = default;

				ObjectPriorityStateObserver(const ObjectPriorityStateObserver&) = default;
				ObjectPriorityStateObserver(ObjectPriorityStateObserver&&) = default;

				ObjectPriorityStateObserver& operator=(const ObjectPriorityStateObserver&) = default;
				ObjectPriorityStateObserver& operator=(ObjectPriorityStateObserver&&) = default;
#pragma endregion

#pragma region function
				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------
				/// <summary>
				/// ManagerのUpdataリストを昇順に並び替える.
				/// </summary>
				void OnEvent(ObjectStateSubject* _ChangedSubject) override;

#pragma endregion

#pragma region property
				//-----------------------------------------------------------
				// property
				//-----------------------------------------------------------

#pragma endregion

#pragma region value
	//-----------------------------------------------------------
	// val
	//-----------------------------------------------------------

#pragma endregion
			};
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------