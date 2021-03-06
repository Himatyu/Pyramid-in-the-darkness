/**
* @file		Constant.cpp
* @brief	Blueprintの定数を定義する
* @author	S.OIKAWA
* @date		2016.11.28
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"Constant.h"
#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Blueprint
	{
		const TCHAR Constant::ClassName[] = _T("Pyramid");
		const TCHAR Constant::ClientProc[] = _T("childProc");

		const unsigned Constant::DivideSpaceLevel = 7;
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------