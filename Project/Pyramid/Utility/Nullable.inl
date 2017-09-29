#include "Nullable.h"
/**
* @file		Nullable.inl
* @brief	Nullableのテンプレート実装
* @author	S.OIKAWA
* @date		2016.09.07
*/
#pragma once


//-----------------------------------------------------------
// ctor
//-----------------------------------------------------------
template<class Type>
inline Utility::Nullable<Type>::Nullable(NullType _null)
	:m_Value{},
	m_HasValue(false)
{
}

//-----------------------------------------------------------
// ctor
//-----------------------------------------------------------
template<class Type>
inline Nullable<Type>::Nullable(const Type & _Value)
	:m_Value(_Value),
	m_HasValue(true)
{
}

//-----------------------------------------------------------
// = null
//-----------------------------------------------------------
template<class Type>
inline Nullable<Type> & Nullable<Type>::
operator=(const nullptr_t& _null)
{
	m_HasValue = false;
	return *this;
}

//-----------------------------------------------------------
// == null
//-----------------------------------------------------------
template<class Type>
inline bool Nullable<Type>::operator==(const nullptr_t& _null)
{
	return !m_HasValue;
}

//-----------------------------------------------------------
// != null
//-----------------------------------------------------------
template<class Type>
inline bool Utility::Nullable<Type>::operator!=(const nullptr_t &_null)
{
	return m_HasValue;
}

//-----------------------------------------------------------
// operator bool
//-----------------------------------------------------------
template<class Type>
inline Utility::Nullable<Type>::operator bool()
{
	return m_HasValue;
}

//-----------------------------------------------------------
// ->
//-----------------------------------------------------------
template<class Type>
inline Type & Nullable<Type>::operator->()
{
	_ASSERT_EXPR(m_HasValue, _T(L"Nullアクセス"));
	return m_Value;
}

//-----------------------------------------------------------
// *
//-----------------------------------------------------------
template<class Type>
inline Type & Utility::Nullable<Type>::operator*()
{
	_ASSERT_EXPR(m_HasValue, _T(L"Nullアクセス"));
	return m_Value;
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------

