/**
* @file		ComponentCreator.inl
* @brief	コンポーネントの生成関数を提供
* @author	S.OIKAWA
* @date		2016.10.3
*/

#pragma once

//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"ComponentCreator.h"

//-----------------------------------------------------------
// define 
//-----------------------------------------------------------

/// <summary>
/// Childを生成しスマポParentで返す
/// </summary>
template<class Child, class Parent>
inline Parent ComponentCreator<Child, Parent>::Create()
{
	return std::make_shared<Child>();
}

//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------