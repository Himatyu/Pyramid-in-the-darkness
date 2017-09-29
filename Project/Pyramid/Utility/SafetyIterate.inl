/**
* @file		SafetyIterate.inl
* @brief	�x�N�^�[�̒ǉ��폜��x�����čs��
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
/// �o�^���N�G�X�g�𓊂���
/// Apply���Ȃ�����͍s���Ȃ��̂Œ���
/// </summary>
template<class Type>
inline void SafetyIterate<Type>::AddRequest(Type _value)
{
	m_AddRequestList.push_back(_value);
}

/// <summary>
/// �j�����N�G�X�g�𓊂���
/// Apply���Ȃ�����͍s���Ȃ��̂Œ���
/// </summary>
template<class Type>
inline void SafetyIterate<Type>::RemoveRequest(Type _value)
{
	m_RemoveRequestList.push_back(_value);
}

/// <summary>
/// �v�f���܂܂�Ă��邩�m�F����
/// ���N�G�X�g�̒��͌��Ȃ��̂�Applay���Ă�������
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
/// �j���A�o�^�v�����󗝂��X�V����
/// </summary>
template<class Type>
inline void SafetyIterate<Type>::Apply()
{
	if ((!m_RemoveRequestList.size() && !m_AddRequestList.size()))
	{
		return;
	}

	//HACK ���ɕ��@���肻��
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
/// �Q�Ƃ�Ԃ��I�y���[�^
/// </summary>
template<class Type>
inline SafetyIterate<Type>::operator std::vector<Type>&()
{
	return m_Vector;
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------