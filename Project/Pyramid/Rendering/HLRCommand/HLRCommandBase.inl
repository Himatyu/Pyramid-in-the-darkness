/**
* @file		HLRCommandBase.inl
* @brief	HLRコマンドの基本機能を提供
* @author	S.OIKAWA
* @date		2016.11.8
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"HLRCommandBase.h"
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------

#pragma endregion

/// <summary>
/// ctor
/// </summary>
template<class PushDataType>
inline 
HLRCommandBase<PushDataType>::HLRCommandBase(
	PushDataType _data, 
	::Utility::CommandExecutor* _pExecuter):
	m_PushData(_data),
	m_pOwner(_pExecuter)
{
}


//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------