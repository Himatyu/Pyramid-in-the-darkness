/**
* @file		ComponentRenderStateObserver.h
* @brief	コンポーネントの描画状態の変更を受信し、リストを更新する.
* @author	S.OIKAWA
* @date		2016.09.20
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
			class ComponentStateSubject;

			/// <summary>
			/// コンポーネントの描画状態を監視.
			/// </summary>
			class ComponentRenderStateObserver final :
				public ComponentStateObserver
			{
			public:
#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				ComponentRenderStateObserver(GameObject::Object&);
				~ComponentRenderStateObserver() = default;

				ComponentRenderStateObserver(const ComponentRenderStateObserver&) = default;
				ComponentRenderStateObserver(ComponentRenderStateObserver&&) = default;

				ComponentRenderStateObserver& operator=(const ComponentRenderStateObserver&) = default;
				ComponentRenderStateObserver& operator=(ComponentRenderStateObserver&&) = default;
#pragma endregion

#pragma region function
				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------
				/// <summary>
				/// Drawableリスト更新.
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