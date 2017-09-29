/**
* @file		Constant.h
* @brief	InputDeviceÇÃíËêîÇíËã`Ç∑ÇÈ
* @author	S.OIKAWA
* @date		2017.02.12
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include<windef.h>
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
			class Constant final
			{
			public:
#pragma region value
				//-----------------------------------------------------------
				// val
				//-----------------------------------------------------------
				static const UINT DeviceBufferSizeForKey;
				static const UINT DeviceBufferSizeForMouse;

#pragma endregion
			};
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------