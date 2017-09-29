/**
* @file		ComponentUpdataStateObserver.h
* @brief	�R���|�[�l���g�̃A�b�v�f�[�g��Ԃ̕ύX����M���A���X�g���X�V����.
* @author	S.OIKAWA
* @date		2016.09.29
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
namespace Pyramid
{
	namespace GameObject
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

			/// <summary>
			/// �R���|�[�l���g�̃A�b�v�f�[�g��Ԃ��Ď�����.
			/// </summary>
			class ComponentUpdataStateObserver final :
				public ComponentStateObserver
			{
			public:
#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				ComponentUpdataStateObserver(GameObject::Object&);
				~ComponentUpdataStateObserver() = default;

				ComponentUpdataStateObserver(const ComponentUpdataStateObserver&) = default;
				ComponentUpdataStateObserver(ComponentUpdataStateObserver&&) = default;

				ComponentUpdataStateObserver& operator=(const ComponentUpdataStateObserver&) = default;
				ComponentUpdataStateObserver& operator=(ComponentUpdataStateObserver&&) = default;
#pragma endregion

#pragma region function
				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------
				/// <summary>
				/// Updata���X�g�̍X�V.
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