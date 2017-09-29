/**
* @file		ObjectRenderStateObserver.h
* @brief	�I�u�W�F�N�g�̕`���ԕύX�ʒm���󂯎��`�惊�X�g���X�V����.
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
			/// �����_�����O��Ԃ��Ď�����.
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
				/// Manager�̕`�惊�X�g���X�V����.
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