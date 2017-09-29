/**
* @file		Abstract.inl
* @brief	�C�x���g�������[����
* @author	S.OIKAWA
* @date		2017.06.02
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include "Abstract.h"

#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------

#pragma endregion

/// <summary>
/// �C�x���g�������[����
/// </summary>
template<class ...Interfaces>
template<class Ty>
inline void 
Abstract<Interfaces...>::RelayEvent(InterfaceOfNonArgs<Ty> _pFunc)
{
	auto findResult = FindOfManager<Ty>();

	if (!findResult)
	{
		return;
	}
	auto& container = (*findResult)->Value;
	for (auto& _ : container)
	{
		(_->*_pFunc)();
	}
}

/// <summary>
/// �C�x���g�������[����
/// �C�ӂ̈������󂯎��InterfaceType���`���ă����[
///<sample>
/// template<class Ty>
/// using InterfaceOfOneInt = void (Ty::*)(int);
///
/// ___interface Foo{void foo(int);}
///
/// RelayEvent<Foo, InterfaceOfOneInt>(&Foo::foo,0);
///</sample>
/// </summary>
template<class ...Interfaces>
template<class Ty, template<class> class InterfaceType, class ...Args>
inline void 
Abstract<Interfaces...>::RelayEvent(
	typename InterfaceType<Ty> _func,
	Args ...args)
{
	auto findResult = FindOfManager<Ty>();

	if (!findResult)
	{
		return;
	}
	auto& container = (*findResult)->Value;
	for (auto& _ : container)
	{
		(_->*_pFunc)(args...);
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------