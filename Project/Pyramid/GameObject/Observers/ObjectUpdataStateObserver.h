/**
* @file		ObjectUpdataStateObserver.h
* @brief	オブジェクトアップデート状態の変更を受信する.
* @author	S.OIKAWA
* @date		2016.09.029
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
			/// オブジェクトアップデート状態の変更を受信して更新リストを更新する.
			/// </summary>
			class ObjectUpdataStateObserver final :
				public ObjectStateObserver
			{
			public:
#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				ObjectUpdataStateObserver(ObjectManager&);
				~ObjectUpdataStateObserver() = default;

				ObjectUpdataStateObserver(const ObjectUpdataStateObserver&) = default;
				ObjectUpdataStateObserver(ObjectUpdataStateObserver&&) = default;

				ObjectUpdataStateObserver& operator=(const ObjectUpdataStateObserver&) = default;
				ObjectUpdataStateObserver& operator=(ObjectUpdataStateObserver&&) = default;
#pragma endregion

#pragma region function
				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------
				/// <summary>
				/// Managerの更新リストを更新する（日本語おかしくないかｗ）
				/// </summary>
				void OnEvent(ObjectStateSubject* _pChangedSubject) override;

#pragma endregion

			};

		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------
