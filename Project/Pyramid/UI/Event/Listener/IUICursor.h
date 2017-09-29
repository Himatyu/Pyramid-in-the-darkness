/**
* @file		IUICursor.h
* @brief	�J�[�\���̏�Ԃɂ��C�x���g���󂯎��
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
				/// �J�[�\���̏�Ԃɂ��C�x���g���󂯎��
				/// </summary>
				__interface IUICursor :
					public ::Utility::IUnknown
				{
					void OnCursorEnter();
					void OnCursorExit();
					void OnCursorClick();
				}; 
			}
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------