/**
* @file		TypeComparable.cpp
* @brief	�^��r���
* @author	S.OIKAWA
* @date		2016.09.19
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"TypeComparable.h"
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Utility
{
#pragma endregion
	//-----------------------------------------------------------
	// == type_index
	//-----------------------------------------------------------
	bool TypeComparable::IsSame(
			const std::type_index & _Type, unsigned _index)
	{
		return (*AccessOfIndex(_index).Value == _Type);
	}

	//-----------------------------------------------------------
	// == TypeComparable : ��R���X�g�֐��̌Ăяo���̂��ߔ�R���X�g�I�u�W�F�N�g
	//-----------------------------------------------------------
	bool TypeComparable::operator==(TypeComparable & _Type)
	{
		_ASSERT_EXPR(
			_Type.m_Types.size() == m_Types.size(), _T(L"�z�񒷂̈قȂ�z��̔�r"));

		for (int i = 0; i < m_Types.size(); i++)
		{
			if (_Type.m_Types[i] != m_Types[i])
			{
				return false;
			}
		}
		return true;
	}

	//-----------------------------------------------------------
	// != TypeComparable 
	//-----------------------------------------------------------
	bool TypeComparable::operator!=(TypeComparable & _Type)
	{
		_ASSERT_EXPR(
			_Type.m_Types.size() == m_Types.size(), _T(L"�z�񒷂��Ⴄ"));

		for (int i = 0; i < m_Types.size(); i++)
		{
			if (_Type.m_Types[i] != m_Types[i])
			{
				return true;
			}
		}
		return false;
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------