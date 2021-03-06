/**
* @file		Constant.h
* @brief	Resourcesの定数を定義する
* @author	S.OIKAWA
* @date		2016.11.28
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include<string>
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------

#pragma endregion

namespace Pyramid
{
	namespace Resources
	{
		class Constant final
		{
		public:
#pragma region value
		
		//-----------------------------------------------------------
		// Audio
		//-----------------------------------------------------------
			static const std::string ExtensionMP3;
			static const std::string ExtensionWAV;
			static const std::string OpenParamsDeviceTypeMPEG;
#pragma endregion
		};
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------