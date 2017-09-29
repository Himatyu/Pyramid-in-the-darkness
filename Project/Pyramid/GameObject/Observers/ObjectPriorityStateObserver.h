/**
* @file		ObjectPriorityStateObserver.h
* @brief	�I�u�W�F�N�g�̃v���C�I���e�B�̕ύX���󂯎�胊�X�g���X�V����.
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
			/// �v���C�I���e�B�̕ύX���󂯎�胊�X�g���X�V����.
			/// </summary>
			class ObjectPriorityStateObserver final :
				public ObjectStateObserver
			{
			public:
#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				ObjectPriorityStateObserver(ObjectManager&);
				~ObjectPriorityStateObserver() = default;

				ObjectPriorityStateObserver(const ObjectPriorityStateObserver&) = default;
				ObjectPriorityStateObserver(ObjectPriorityStateObserver&&) = default;

				ObjectPriorityStateObserver& operator=(const ObjectPriorityStateObserver&) = default;
				ObjectPriorityStateObserver& operator=(ObjectPriorityStateObserver&&) = default;
#pragma endregion

#pragma region function
				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------
				/// <summary>
				/// Manager��Updata���X�g�������ɕ��ёւ���.
				/// </summary>
				void OnEvent(ObjectStateSubject* _ChangedSubject) override;

#pragma endregion

#pragma region property
				//-----------------------------------------------------------
				// property
				//-----------------------------------------------------------

#pragma endregion

#pragma region value
	//-----------------------------------------------------------
	// val
	//-----------------------------------------------------------

#pragma endregion
			};
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------