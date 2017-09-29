#include "Optimizer.h"
/**
* @file		Optimizer.inl
* @brief	�œK�����s��
* @author	S.OIKAWA
* @date		2017.03.31
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

//-----------------------------------------------------------
// CallInit :�p�C�v���C�����R�s�[����̂ŃR�}���h���s��ɍs��
//-----------------------------------------------------------
template<class ...Args>
inline 
void Optimizer<Args...>::CallInit()
{
	for (auto& _ : m_InterfaceList)
	{
		_->Init();
	}
}

//-----------------------------------------------------------
// CallUpdate
//-----------------------------------------------------------
template<class ...Args>
inline void Optimizer<Args...>::CallUpdate()
{
	for (auto& _ : m_InterfaceList)
	{
		_->Update();
	}
}

//-----------------------------------------------------------
// CallOptimize
//-----------------------------------------------------------
template<class ...Args>
inline
void
Optimizer<Args...>::CallOptimize(const Context & _context)
{
	for (auto& _ : m_InterfaceList)
	{
		_->RunOptimize(_context);
	}
}


//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------