/**
	  * @file	singleton.inl
	  * @brief	シングルトンテンプレート実装
	  * @author	S.OIKAWA
	  * @date	2016.09.09
	  */
#pragma once

//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"singleton.h"

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
template <class Type> std::once_flag Singleton<Type>::m_InitFlag;
template <class Type> Type* Singleton<Type>::m_pInstance = nullptr;

//-----------------------------------------------------------
// Create
//-----------------------------------------------------------
template<class Type>
inline void Singleton<Type>::Create()
{
	m_pInstance = new Type;
	SingletonFinalizer::AddFinalizer(&Singleton<Type>::Destroy);
}

//-----------------------------------------------------------
// Destroy
//-----------------------------------------------------------
template<class Type>
inline void Singleton<Type>::Destroy()
{
	delete m_pInstance;
	m_pInstance = nullptr;
}

//-----------------------------------------------------------
// Instantiate
//-----------------------------------------------------------
template<class Type>
inline Type & Singleton<Type>::Instantiate()
{
	std::call_once(m_InitFlag, Create);
	return *m_pInstance;
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------