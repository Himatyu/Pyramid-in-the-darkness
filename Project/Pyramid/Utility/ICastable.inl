/**
* @file		ICastable.inl
* @brief	ダイナミックキャストを提供
* @author	S.OIKAWA
* @date		2017.03.03
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------

#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------

#pragma endregion

/// <summary>
/// ダイナミックキャストを行う
/// </summary>
template<class Casted>
inline Casted ICastable::CastTo()
{
	return dynamic_cast<Casted>(this);
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------