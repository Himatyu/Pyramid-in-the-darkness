/**
* @file		StaticValue.inl
* @brief	静的変数で開放順序を指定したいオブジェクに使用する
* @author	S.OIKAWA
* @date		2016.11.14
*/
#pragma once

//-----------------------------------------------------------
// include 
//-----------------------------------------------------------
#include"StaticValue.h"

//-----------------------------------------------------------
// define 
//-----------------------------------------------------------

template <class Type>
Type* StaticValue<Type>::m_pInstance = nullptr;

/// <summary>
/// ctor
/// </summary>
template<class Ty>
inline StaticValue<Ty>::StaticValue()
{
	m_pInstance = new Ty;
	StaticValueFinalizer::AddFinalizer(&Destroy);
}

/// <summary>
/// 変換オペレータ
/// </summary>
template<class Ty>
inline StaticValue<Ty>::operator Ty()
{
	return *m_pInstance;
}

template<class Ty>
inline Ty & StaticValue<Ty>::operator = (Ty _other)
{
	*m_pInstance = _other;
}

template<class Ty>
inline Ty & StaticValue<Ty>::operator->()
{
	return *m_pInstance;
}

/// <summary>
/// 破棄処理
/// </summary>
template<class Ty>
inline void StaticValue<Ty>::Destroy()
{
	SAFE_DELETE(m_pInstance);
}

//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------