/**
* @file		LevelCreator.inl
* @brief	レベル生成関数を提供する
* @author	S.OIKAWA
* @date		2016.10.10
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"LevelCreator.h"

#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------

#pragma endregion

/// <summary>Childを生成しスマポParentで返す</summary>
///<returns>親又生成したコンポーネントのスマポ</returns>
template<class Child, class Parent>
inline Parent LevelCreator<Child, Parent>::Create()
{
	return new Child;
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------