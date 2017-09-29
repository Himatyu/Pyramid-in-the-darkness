/**
* @file		LevelCreator.inl
* @brief	���x�������֐���񋟂���
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

/// <summary>Child�𐶐����X�}�|Parent�ŕԂ�</summary>
///<returns>�e�����������R���|�[�l���g�̃X�}�|</returns>
template<class Child, class Parent>
inline Parent LevelCreator<Child, Parent>::Create()
{
	return new Child;
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------