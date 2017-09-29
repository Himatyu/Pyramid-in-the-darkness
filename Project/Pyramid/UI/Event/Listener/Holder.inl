/**
* @file		Holder.inl
* @brief	ƒŠƒXƒi[‚Ì“o˜^‚Æ“o˜^íœ‚ğs‚¤
* @author	S.OIKAWA
* @date		2017.06.01
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include "Holder.h"

#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace
{
	using ArrayElement = ::std::pair<
		const ::std::type_info*, ::Utility::Unknown*>;

	template<unsigned ArrayLength>
	using RegisterArray 
		= ::std::array<ArrayElement, ArrayLength>;

//-----------------------------------------------------------
// ListRegister
//-----------------------------------------------------------
	template<class TyList,
		unsigned ArrayLength = ::Utility::Length<TyList>::Result>
	struct ListRegister
	{
		static_assert(
			std::is_pointer<typename TyList::Head>::value == false, "use pointer !! in UI::Event::Listener::Holder");

		static void Register(RegisterArray<ArrayLength>& _array,unsigned _index = 0)
		{
			auto pManager = 
				new	Pyramid::UI::Event::Listener::Manager<
				::std::add_pointer<typename TyList::Head>::type>;

			_array[_index] =
				::std::make_pair(&typeid(TyList::Head),
								static_cast<::Utility::Unknown*>(pManager));

			ListRegister<TyList::Tail, ArrayLength>::Register(_array,++_index);
		}
	};

	template<unsigned ArrayLength>
	struct ListRegister<::Utility::NullType, ArrayLength>
	{
		static void Register(RegisterArray<ArrayLength>& , unsigned)
		{
			return;
		}
	};
}

#pragma endregion


/// <summary>
/// ctor
/// </summary>
template<class ...Interfaces>
inline Holder<Interfaces...>::Holder()
{
	ParseAndRegister<Holder<Interfaces...>::InterfaceList>();
}


/// <summary>
/// ctor
/// </summary>
template<class ...Interfaces>
inline Holder<Interfaces...>::~Holder()
{
	for (auto& _ : m_Managers)
	{
		SAFE_DELETE(_.second);
	}
}


//-----------------------------------------------------------
// ParseAndRegister
//-----------------------------------------------------------
template<class ...Interfaces>
template<class InterfaceTypeList>
inline void Holder<Interfaces...>::ParseAndRegister()
{
	ListRegister<InterfaceTypeList>::Register(m_Managers);
}

/// <summary>
/// ƒ}ƒl[ƒWƒƒ‚ğŒŸõ‚·‚é
/// </summary>
template<class ...Interfaces>
template<class Interface>
inline 
::Utility::Nullable<Manager<Interface*>*>
Holder<Interfaces...>::FindOfManager()
{
	auto findResult = ::Utility::Estd::find_if(
		m_Managers,
		[&](ArrayElement& _)
	{
		return typeid(Interface) == *(_.first);
	});

	if (m_Managers.end() == findResult)
	{
		return {};
	}

	auto pManager =
		static_cast<Manager<Interface*>*>((*findResult).second);

	return ::Utility::Nullable<Manager<Interface*>*>(pManager);
}

/// <summary>
/// ƒŠƒXƒi[‚Ì“o˜^‚ğs‚¤
/// </summary>
template<class ...Interfaces>
template<class Interface>
inline void Holder<Interfaces...>::AddListener(Interface*  _pIf)
{
	auto findResult = FindOfManager<Interface>();
	if (!findResult)
	{
		return;
	}
	(*findResult)->Add(_pIf);
}

/// <summary>
/// ƒŠƒXƒi[‚Ì“o˜^íœ‚ğs‚¤
/// </summary>
template<class ...Interfaces>
template<class Interface>
inline 
void 
Holder<Interfaces...>::RemoveListener(Interface*  _pIf)
{
	auto findResult = FindOfManager<Interface>();
	if (!findResult)
	{
		return;
	}
	(*findResult)->Remove(_pIf);
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------