/**
* @file		ComponentCreator.inl
* @brief	�R���|�[�l���g�̐����֐����
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
/// Child�𐶐����X�}�|Parent�ŕԂ�
/// </summary>
template<class Child, class Parent>
inline Parent ComponentCreator<Child, Parent>::Create()
{
	return std::make_shared<Child>();
}

//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------