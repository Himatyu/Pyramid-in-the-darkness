/**
* @file		OrderedJobExcuter.inl
* @brief	�^�X�N�����s����W���u������
* @author	S.OIKAWA
* @date		2016.11.25
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"OrderedJobExcuter.h"
#include<utility>
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------

#pragma endregion

/// <summary>
/// �R���e�i�ƃW���u���^�O�t���œo�^����
/// </summary>
template<class ExecuterType, class ...Args>
inline 
void 
OrderedJobExcuter::Register(
	std::string _key,
	Args && ...args)
{
	auto pExe = new ExecuterType(args...);
	m_Executers[_key] =
		std::make_pair(
			static_cast<Worker::IOrderedJobExecutable*>(pExe),true);
}

/// <summary>
/// �����ς݂̃W���u���^�O�t���œo�^����
/// </summary>
template<class Ty>
inline void 
OrderedJobExcuter::Register(Ty* _pExe,std::string _Key)
{
	m_Executers[_Key] =
		std::make_pair(
			static_cast<Worker::IOrderedJobExecutable*>(_pExe), false);
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------