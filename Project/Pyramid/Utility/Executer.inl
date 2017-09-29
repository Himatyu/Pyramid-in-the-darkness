/**
* @file		Executer.h
* @brief	実行するジョブを保持して、実行機能を提供
* @author	S.OIKAWA
* @date		2016.09.21
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include "Executer.h"
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------

#pragma endregion

//-----------------------------------------------------------
// dtor 
//-----------------------------------------------------------
template<class Type>
inline Executer<Type>::~Executer()
{
	SAFE_DELETE(m_pFuncObj);
}

//-----------------------------------------------------------
// Register 
//-----------------------------------------------------------
template<class Type>
template<class Func>
inline void Executer<Type>::Register(Func && _func, Type* _this)
{
	SAFE_DELETE(m_pFuncObj);
	m_pFuncObj = new FuncObject(std::move(_func), std::move(_this));
}

//-----------------------------------------------------------
// Run 
//-----------------------------------------------------------
template<class Type>
inline void Executer<Type>::Execution()
{
	(*m_pFuncObj)();
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------