/**
	  * @file	SingleTypeMap.inl
	  * @brief	SingleTypeMapのテンプレート実装
	  * @author	S.OIKAWA
	  * @date	2016.09.07
	  */
#pragma once
//-----------------------------------------------------------
// include
//-----------------------------------------------------------

//-----------------------------------------------------------
// ctor
//-----------------------------------------------------------
template<class Type>
inline SingleTypeMap<Type>::SingleTypeMap()
	:HavingChildType(typeid(Type))
{
}

//-----------------------------------------------------------
// dtor
//-----------------------------------------------------------
template<class Type>
inline SingleTypeMap<Type>::~SingleTypeMap()
{
	m_Map.clear();
}

//-----------------------------------------------------------
// Add
//-----------------------------------------------------------
template<class Type>
inline void SingleTypeMap<Type>::Add(std::string _key, Type _value)
{
	m_Map[_key] = _value;
}

//-----------------------------------------------------------
// Remove
//-----------------------------------------------------------
template<class Type>
inline void SingleTypeMap<Type>::Remove(std::string _key)
{
	m_Map.erase(_key);
}

//-----------------------------------------------------------
// Find
//-----------------------------------------------------------
template<class Type>
inline Nullable<Type> SingleTypeMap<Type>::Find(std::string _key)
{
	auto result = m_Map.find(_key);
	if (m_Map.end() == result)
	{
		return Nullable<Type>();
	}

	return Nullable<Type>(result->second);
}
//-----------------------------------------------------------
// EOF	
//-----------------------------------------------------------