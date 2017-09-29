/**
* @file		ObjectUpdataStateObserver.h
* @brief	�I�u�W�F�N�g�A�b�v�f�[�g��Ԃ̕ύX����M����.
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
			/// �I�u�W�F�N�g�A�b�v�f�[�g��Ԃ̕ύX����M���čX�V���X�g���X�V����.
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
				/// Manager�̍X�V���X�g���X�V����i���{�ꂨ�������Ȃ������j
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
