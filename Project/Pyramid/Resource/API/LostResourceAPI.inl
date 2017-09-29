/**
* @file		LostResourceAPI.inl
* @brief	デバイスロスト時定義テンプレート実装
* @author	S.OIKAWA
* @date		2016.09.04
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"LostResourceAPI.h"
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------
template<class ResourceFile>
template<class Type>
inline bool LostResourceAPI<ResourceFile>::ResourceIsType()
{
	return (typeid(Type) == typeid(*m_spResourceFile));
}
#pragma endregion


//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------