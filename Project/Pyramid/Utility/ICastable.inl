/**
* @file		ICastable.inl
* @brief	�_�C�i�~�b�N�L���X�g���
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
/// �_�C�i�~�b�N�L���X�g���s��
/// </summary>
template<class Casted>
inline Casted ICastable::CastTo()
{
	return dynamic_cast<Casted>(this);
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------