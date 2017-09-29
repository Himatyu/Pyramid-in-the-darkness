/**
* @file		ComponentPriorityStateObserver.h
* @brief	�R���|�[�l���g�̗D��x�̕ύX����M���ă��X�g���\�[�g����.
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
			/// �R���|�[�l���g�̗D��x�̕ύX����M���ă��X�g���\�[�g����.
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
				/// Updateble���X�g�\�[�g.
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