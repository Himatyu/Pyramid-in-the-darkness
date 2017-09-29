/**
* @file		Key.inl
* @brief	キーボードの入力を扱う
* @author	S.OIKAWA
* @date		2017.02.12
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"Key.h"
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------

#pragma endregion

//-----------------------------------------------------------
// IsKeyPushs
//-----------------------------------------------------------
inline bool Key::IsKeyPushs()
{
	return true;
}

template<class First, class ...Param>
inline bool Key::IsKeyPushs(First _first, Param  ... _rest)
{
	return (IsKeyPush(_first) && IsKeyPushs(_rest...));
}



//-----------------------------------------------------------
// IsKeyDowns
//-----------------------------------------------------------
inline bool Key::IsKeyDowns()
{
	return true;
}

template<class First, class ...Param>
inline bool Key::IsKeyDowns(First _first, Param  ... _rest)
{
	return IsKeyDown(_first) && IsKeyDowns(_rest...);
}

//-----------------------------------------------------------
// IsKeyUps
//-----------------------------------------------------------
inline bool Key::IsKeyUps()
{
	return true;
}

template<class First, class ...Param>
inline bool Key::IsKeyUps(First _first, Param  ... _rest)
{
	return IsKeyUp(_first) && IsKeyUps(_rest...);
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------