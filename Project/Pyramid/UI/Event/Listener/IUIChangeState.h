/**
* @file		IUIChangeState.h
* @brief	�L��������؂�ւ����ۂ̃C�x���g���󂯎��
* @author	S.OIKAWA
* @date		2017.05.26
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"IUnknown.h"
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------

#pragma endregion

namespace Pyramid
{
	namespace UI
	{
		namespace Event
		{
			namespace Listener
			{
				/// <summary>
				/// �L��������؂�ւ����ۂ̃C�x���g���󂯎��
				/// </summary>
				__interface IUIChangeState : 
					public ::Utility::IUnknown
				{
					void OnActivate();
					void OnDeactivate();
				};
			}
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------