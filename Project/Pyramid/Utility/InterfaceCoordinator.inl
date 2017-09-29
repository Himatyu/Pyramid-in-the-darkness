/**
* @file		InterfaceCoordinator.inl
* @brief	インターフェースをまとめる
* @author	S.OIKAWA
* @date		2017.03.30
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
template<class Interface, class ...TyList>
InterfaceCoordinator<Interface, TyList...>::
InterfaceCoordinator(TyList ...args) :
	TyList(args)...
{
	Parse(0, args...);
};

template<class Interface, class ...TyList>
template<class Ty>
void 
InterfaceCoordinator<Interface, TyList...>::
Parse(int _index, Ty _ty)
{
	m_InterfaceList[_index++] = static_cast<Ty*>(this);
}

template<class Interface, class ...TyList>
template<class Ty, class ...Tail>
void 
InterfaceCoordinator<Interface, TyList...>::
Parse(int _index, Ty _ty, Tail... tail)
{
	m_InterfaceList[_index++] = static_cast<Ty*>(this);
	Parse(_index, tail...);
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------