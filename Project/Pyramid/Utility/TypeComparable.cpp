/**
* @file		TypeComparable.cpp
* @brief	型比較を提供
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
	// == TypeComparable : 非コンスト関数の呼び出しのため非コンストオブジェクト
	//-----------------------------------------------------------
	bool TypeComparable::operator==(TypeComparable & _Type)
	{
		_ASSERT_EXPR(
			_Type.m_Types.size() == m_Types.size(), _T(L"配列長の異なる配列の比較"));

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
			_Type.m_Types.size() == m_Types.size(), _T(L"配列長が違う"));

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