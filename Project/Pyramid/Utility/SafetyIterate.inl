/**
* @file		SafetyIterate.inl
* @brief	ベクターの追加削除を遅延して行う
* @author	S.OIKAWA
* @date		2016.09.25
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"SafetyIterate.h"
#include <algorithm>
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------

#pragma endregion



//-----------------------------------------------------------
// ctor
//-----------------------------------------------------------
template<class Type>
inline 
Utility::SafetyIterate<Type>::SafetyIterate(const SafetyIterate & _rhv)
{
	m_AddRequestList		= _rhv.m_AddRequestList;
	m_RemoveRequestList		= _rhv.m_RemoveRequestList;
	m_Vector				= _rhv.m_Vector;
}

//-----------------------------------------------------------
// move
//-----------------------------------------------------------
template<class Type>
inline SafetyIterate<Type>::SafetyIterate(SafetyIterate && _rhv)
{
	m_AddRequestList	= std::move(_rhv.m_AddRequestList);
	m_RemoveRequestList = std::move(_rhv.m_RemoveRequestList);
	m_Vector			= std::move(_rhv.m_Vector);
}

//-----------------------------------------------------------
// move operator
//-----------------------------------------------------------
template<class Type>
inline SafetyIterate<Type> & SafetyIterate<Type>::operator=(SafetyIterate && _rhv)
{
	m_AddRequestList = std::move(_rhv.m_AddRequestList);
	m_RemoveRequestList = std::move(_rhv.m_RemoveRequestList);
	m_Vector = std::move(_rhv.m_Vector);
	return *this;
}

/// <summary>
/// 登録リクエストを投げる
/// Applyしない限りは行われないので注意
/// </summary>
template<class Type>
inline void SafetyIterate<Type>::AddRequest(Type _value)
{
	m_AddRequestList.push_back(_value);
}

/// <summary>
/// 破棄リクエストを投げる
/// Applyしない限りは行われないので注意
/// </summary>
template<class Type>
inline void SafetyIterate<Type>::RemoveRequest(Type _value)
{
	m_RemoveRequestList.push_back(_value);
}

/// <summary>
/// 要素が含まれているか確認する
/// リクエストの中は見ないのでApplayしておくこと
/// </summary>
template<class Type>
inline bool SafetyIterate<Type>::IsContains(Type _value)
{
	auto it = std::find(___RANGE_BASED(m_Vector),_value);
	if (m_Vector.end() == it)
	{
		return false;
	}
	return true;
}

/// <summary>
/// 破棄、登録要求を受理し更新する
/// </summary>
template<class Type>
inline void SafetyIterate<Type>::Apply()
{
	if ((!m_RemoveRequestList.size() && !m_AddRequestList.size()))
	{
		return;
	}

	//HACK 他に方法ありそう
	std::list<Type> removeList;
	auto& addEnd = m_AddRequestList.end();

	for (auto& _ : m_RemoveRequestList)
	{
		auto result = Utility::Estd::find(m_AddRequestList, _);
		if (addEnd == result)
		{
			continue;
		}
		removeList.push_back(_);
	}

	for (auto _ : removeList)
	{
		m_RemoveRequestList.remove(_);
		m_AddRequestList.remove(_);
	}

	auto end = m_Vector.end();
	for (auto& _ : m_RemoveRequestList)
	{
		auto result = Utility::Estd::find(m_Vector, _);
		if (end == result)
		{
			continue;
		}
		m_Vector.erase(result);
		end = m_Vector.end();
	}
	m_RemoveRequestList.clear();

	for (auto& _ : m_AddRequestList)
	{
		m_Vector.push_back(_);
	}
	
	m_AddRequestList.clear();
}

/// <summary>
/// 参照を返すオペレータ
/// </summary>
template<class Type>
inline SafetyIterate<Type>::operator std::vector<Type>&()
{
	return m_Vector;
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------