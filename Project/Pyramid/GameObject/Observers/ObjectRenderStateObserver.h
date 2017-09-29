/**
* @file		ObjectRenderStateObserver.h
* @brief	オブジェクトの描画状態変更通知を受け取り描画リストを更新する.
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
			/// レンダリング状態を監視する.
			/// </summary>
			class ObjectRenderStateObserver final :
				public ObjectStateObserver
			{
			public:
#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				ObjectRenderStateObserver(ObjectManager& _mgr);
				~ObjectRenderStateObserver() = default;

				ObjectRenderStateObserver(const ObjectRenderStateObserver&) = default;
				ObjectRenderStateObserver(ObjectRenderStateObserver&&) = default;

				ObjectRenderStateObserver& operator=(const ObjectRenderStateObserver&) = default;
				ObjectRenderStateObserver& operator=(ObjectRenderStateObserver&&) = default;
#pragma endregion

#pragma region function
				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------
				/// <summary>
				/// Managerの描画リストを更新する.
				/// </summary>
				void OnEvent(ObjectStateSubject* _ChangedSubject) override;

#pragma endregion

			};
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------