/**
* @file		Constant.h
* @brief	MTÇÃíËêîÇíËã`Ç∑ÇÈ
* @author	S.OIKAWA
* @date		2016.11.28
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
	namespace MT
	{
		class Constant final
		{
		public:
#pragma region value
		//-----------------------------------------------------------
		// val
		//-----------------------------------------------------------
			static const UINT JobLineDefaultReserveInContainer;
			static const UINT JobListDefaultReserveInLine;

#pragma endregion
		};
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------