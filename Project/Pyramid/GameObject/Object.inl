#include "Object.h"
/**
* @file		Object.inl
* @brief
* @author
* @date
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

//-----------------------------------------------------------
// TypeApply
//-----------------------------------------------------------
template<class Ty>
inline void Object::TypeApply()
{
	TypePossession::TypeApply<Ty>();
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------