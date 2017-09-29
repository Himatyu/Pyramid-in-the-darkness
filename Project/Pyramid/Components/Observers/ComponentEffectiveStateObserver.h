/**
* @file		ComponentEffectiveStateObserver.h
* @brief	�R���|�[�l���g�̗L�������̕ύX���󂯎�胊�X�g�̍X�V���s��
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

			class ComponentEffectiveStateObserver final :
				public ComponentStateObserver
			{
			public:
#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				ComponentEffectiveStateObserver(GameObject::Object&);
				~ComponentEffectiveStateObserver() = default;

				ComponentEffectiveStateObserver(const ComponentEffectiveStateObserver&) = default;
				ComponentEffectiveStateObserver(ComponentEffectiveStateObserver&&) = default;

				ComponentEffectiveStateObserver& operator=(const ComponentEffectiveStateObserver&) = default;
				ComponentEffectiveStateObserver& operator=(ComponentEffectiveStateObserver&&) = default;
#pragma endregion

#pragma region function
				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------

				/// <summary>
				/// PlanesUpdate,Draw���X�g�X�V.
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