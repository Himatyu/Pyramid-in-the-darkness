/**
* @file		MultiTypeMap.inl
* @brief	MultiTypeMapのテンプレート実装
* @author	S.OIKAWA
* @date		2016.09.08
*/
#pragma once

//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"MultiTypeMap.h"

//-----------------------------------------------------------
// define
//-----------------------------------------------------------

//-----------------------------------------------------------
// findHasTypeArray
//-----------------------------------------------------------
template<class Type>
inline SingleTypeMap<Type>* findHasType(
	std::vector<HavingChildType*>& _Maps)
{
	auto it = 
		std::find_if
		(
			_Maps.begin(),
			_Maps.end(), 
			[](HavingChildType* _) {return _->HasType<Type>(); }
		);
	if (_Maps.end() == it)
	{
		return nullptr;
	}

	return dynamic_cast<SingleTypeMap<Type>*>(*it);
}

//-----------------------------------------------------------
// Add
//-----------------------------------------------------------
template<class Type>
inline void MultiTypeMap::Add(std::string _key, Type  _value)
{
	auto pResult = findHasType<Type>(m_Maps);
	if (nullptr == pResult)
	{
		RegisterUseType<TypeList1<Type>>();
		findHasType<Type>(m_Maps)->Add(_key, _value);
		return;
	}
	pResult->Add(_key,_value);
}

//-----------------------------------------------------------
// Remove
//-----------------------------------------------------------
template<class Type>
inline void MultiTypeMap::Remove(std::string _key)
{
	auto pResult = findHasType<Type>(m_Maps);
	if (nullptr == pResult)
	{
		___D_LOG("無効な型のRemove " + _key);
		return;
	}
	pResult->Remove(_key);
}

//-----------------------------------------------------------
// Find
//-----------------------------------------------------------
template<class Type>
inline Nullable<Type> MultiTypeMap::Find(std::string _key)
{
	auto pResult = findHasType<Type>(m_Maps);
	if (nullptr == pResult)
	{
		return Nullable<Type>();
	}
	return pResult->Find(_key);
}

//-----------------------------------------------------------
// RegisterUseType
//-----------------------------------------------------------
template<>
inline void MultiTypeMap::RegisterUseType<NullType>()
{
	return;
}

template<class Type>
inline void MultiTypeMap::RegisterUseType()
{
	if (!findHasType<Type::Head>(m_Maps))
	{
		m_Maps.push_back(
			static_cast<HavingChildType*>(
				new SingleTypeMap<Type::Head>));
	}
	RegisterUseType<Type::Tail>();
}

//-----------------------------------------------------------
// UnRegisterUseType
//-----------------------------------------------------------
template<>
inline void MultiTypeMap::UnRegisterUseType<NullType>()
{
	return;
}

template<class Type>
inline void MultiTypeMap::UnRegisterUseType()
{
	auto pResult = findHasType<Type::Head>(m_Maps);
	if (pResult)
	{
		m_Maps.erase(std::find(m_Maps.begin(), m_Maps.end(), pResult));
		SAFE_DELETE(pResult);
	}
	UnRegisterUseType<Type::Tail>();
}

//-----------------------------------------------------------
// GetSingleTypeMap
//-----------------------------------------------------------
template<class Type>
inline SingleTypeMap<Type>& MultiTypeMap::GetSingleTypeMap()
{
#if _DEBUG
	if (!findHasType<Type>(m_Maps))
	{
		___THROW_EXCEPTION_POINT(Exception,"所持していないMapの取得要求");
	}
#endif
	return *findHasType<Type>(m_Maps);
}

//-----------------------------------------------------------
// HasType
//-----------------------------------------------------------
template<class Type>
inline bool MultiTypeMap::HasType()
{
	return (
		m_Maps.end() !=
		std::find_if
		(
			m_Maps.begin(),
			m_Maps.end(),
			[](HavingChildType* _)
				{
					return _->HasType<Type>();
				}
		));
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------