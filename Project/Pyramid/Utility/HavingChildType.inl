/**
* @file		HavingChildType.inl
* @brief	HavingChildType�̃e���v���[�g����
* @author	S.OIKAWA
* @date		2016.09.07
*/
#pragma once

//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"HavingChildType.h"

//-----------------------------------------------------------
// HasType
//-----------------------------------------------------------
template<class Type>
inline bool HavingChildType::HasType()
{
	return m_ChildType == typeid(Type);
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------

