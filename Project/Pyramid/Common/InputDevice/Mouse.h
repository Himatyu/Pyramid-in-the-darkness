/**
* @file		Mouse.h
* @brief	�}�E�X
* @author	S.OIKAWA
* @date		2017.02.12
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"singleton.h"
#include"Device.h"
#include"Vector2.h"
#include<Windows.h>
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------

#pragma endregion
namespace Pyramid
{
	namespace Common
	{
		namespace InputDevice
		{
			/// <summary>
			/// �}�E�X�̓��͂�����
			/// </summary>
			class Mouse :
				public Utility::Singleton<Mouse>,
				public Device
			{
			public:
				enum Id : int
				{
					LButton = 0,
					RButon,
					MButton,
				};


#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				Mouse();
				~Mouse();

				Mouse(const Mouse&) = default;
				Mouse(Mouse&&) = default;

				Mouse& operator=(const Mouse&) = default;
				Mouse& operator=(Mouse&&) = default;
#pragma endregion

#pragma region function
				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------

				/// <summary>
				/// �}�E�X�̃{�^����������Ă���ΐ^��Ԃ�
				/// </summary>
				bool IsPushButton(Id);

				/// <summary>
				/// �}�E�X�̃{�^���������ꂽ�t���[���̂ݐ^��Ԃ�
				/// </summary>
				bool IsDownButton(Id);

				/// <summary>
				/// �}�E�X�̃{�^���������ꂽ�t���[���̂ݐ^��Ԃ�
				/// </summary>
				bool IsUpButton(Id);

			private:
				void SetUp() override;
				void Updata() override;

#pragma endregion

#pragma region property
			public:
				//-----------------------------------------------------------
				// property
				//-----------------------------------------------------------
				PROPERTY_CR_R_ONLY(m_MousePosition, Position, Utility::Vector2);
#pragma endregion
			private:
#pragma region value
				//-----------------------------------------------------------
				// val
				//-----------------------------------------------------------
				DIMOUSESTATE2		m_MouseState;
				DIMOUSESTATE2		m_MouseStatePrevFream;
				HWND				m_Hwnd;
				Utility::Vector2	m_MousePosition;
#pragma endregion
			};
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------