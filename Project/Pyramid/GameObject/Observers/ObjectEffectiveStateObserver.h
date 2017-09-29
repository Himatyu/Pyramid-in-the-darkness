/**
* @file		ObjectEffectiveStateObserver.h
* @brief	�I�u�W�F�N�g�̗L���E�����̃C�x���g�ʒm���󂯎��Ώۃ��X�g���X�V����.
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
			/// �I�u�W�F�N�g�̗L���E�����̃C�x���g�ʒm���󂯎��Ώۃ��X�g���X�V����.
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
				/// Manager�̍X�V�E�`�惊�X�g���X�V����.
				/// </summary>
				void OnEvent(ObjectStateSubject* _ChangedSubject) override;

			#pragma endregion

			};
}}}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------