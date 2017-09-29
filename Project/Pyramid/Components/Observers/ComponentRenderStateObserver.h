/**
* @file		ComponentRenderStateObserver.h
* @brief	�R���|�[�l���g�̕`���Ԃ̕ύX����M���A���X�g���X�V����.
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
			/// �R���|�[�l���g�̕`���Ԃ��Ď�.
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
				/// Drawable���X�g�X�V.
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