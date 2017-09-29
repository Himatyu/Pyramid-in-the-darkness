/**
* @file		Device.h
* @brief	入力デバイスの機能を定義
* @author	S.OIKAWA
* @date		2017.02.12
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include<dinput.h>
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
			/// 入力デバイスの機能を定義
			/// </summary>
			class Device
			{
			public:
#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				Device() = default;
				~Device() = default;

				Device(const Device&) = default;
				Device(Device&&) = default;

				Device& operator=(const Device&) = default;
				Device& operator=(Device&&) = default;
#pragma endregion

#pragma region function
				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------
				virtual void SetUp() = 0;
				virtual void Updata() = 0;
#pragma endregion

#pragma region property
				//-----------------------------------------------------------
				// property
				//-----------------------------------------------------------

#pragma endregion
			protected:
#pragma region value
				//-----------------------------------------------------------
				// val
				//-----------------------------------------------------------
				LPDIRECTINPUTDEVICE8 m_pDevice;

#pragma endregion
			};
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------