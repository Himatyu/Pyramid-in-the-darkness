/**
* @file		ObjectEffectiveStateObserver.h
* @brief	オブジェクトの有効・無効のイベント通知を受け取り対象リストを更新する.
* @author	S.OIKAWA
* @date		2016.09.19
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
namespace Pyramid
{
	namespace GameObject
	{
		namespace Observers
		{
			class ObjectStateSubject;
		}
	}
}
#pragma endregion

namespace Pyramid
{
	namespace GameObject
	{
		namespace Observers
		{

			/// <summary>
			/// オブジェクトの有効・無効のイベント通知を受け取り対象リストを更新する.
			/// </summary>
			class ObjectEffectiveStateObserver final :
				public ObjectStateObserver
			{
			public:
			#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				ObjectEffectiveStateObserver(ObjectManager& _mgr);
				~ObjectEffectiveStateObserver() = default;

				ObjectEffectiveStateObserver(const ObjectEffectiveStateObserver&) = default;
				ObjectEffectiveStateObserver(ObjectEffectiveStateObserver&&) = default;

				ObjectEffectiveStateObserver& operator=(const ObjectEffectiveStateObserver&) = default;
				ObjectEffectiveStateObserver& operator=(ObjectEffectiveStateObserver&&) = default;
			#pragma endregion

			#pragma region function
				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------
				/// <summary>
				/// Managerの更新・描画リストを更新する.
				/// </summary>
				void OnEvent(ObjectStateSubject* _ChangedSubject) override;

			#pragma endregion

			};
}}}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------