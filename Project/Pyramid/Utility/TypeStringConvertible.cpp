/**
* @file		TypeStringConvertible.cpp
* @brief	型情報のstring化機能提供
* @author	S.OIKAWA
* @date		2016.09.28
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"TypeStringConvertible.h"
#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Utility
{
	//-----------------------------------------------------------
	// OnApply
	//-----------------------------------------------------------
	void TypeStringConvertible::OnApply()
	{
		m_TypeName = *AccessOfIndex(0)->name();
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------

