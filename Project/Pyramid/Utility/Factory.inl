/**
* @file		ClientFactory.inl
* @brief	テンプレート関数定義
* @author	S.OIKAWA
* @date		2016.05.25
*/
#pragma once

//-----------------------------------------------------------
// include 
//-----------------------------------------------------------
#include "Factory.h"
//-----------------------------------------------------------
// Create
//-----------------------------------------------------------
template <class Base>
template <class Child>
Child Factory<Base>::Create()
{
	auto it = m_CreatorMap.find(typeid(Child));
	if (it == m_CreatorMap.end())
	{
		___THROW_EXCEPTION_POINT(Utility::Exception,"登録されていない型のクリエイターに生成要求");
		return nullptr;
	}

	Creator<Base>* pCreator = (*it).second;
	return dynamic_cast<Child*>(pCreator->Create());
}

//-----------------------------------------------------------
// Create : typeindex
//-----------------------------------------------------------
template <class Base>
Base Factory<Base>::Create(std::type_index _type)
{
	auto it = m_CreatorMap.find(_type);
	if (it == m_CreatorMap.end())
	{
		___THROW_EXCEPTION_POINT(Utility::Exception, "登録されていない型のクリエイターに生成要求");
		return nullptr;
	}

	Creator<Base>* pCreator = (*it).second;
	return pCreator->Create();
}

//-----------------------------------------------------------
// HasType
//-----------------------------------------------------------
template<class Base>
inline bool Factory<Base>::HasType(std::type_index _type)
{
	return !(m_CreatorMap.find(_type) == m_CreatorMap.end());
}

//-----------------------------------------------------------
// IsEmpty
//-----------------------------------------------------------
template<class Base>
inline bool Factory<Base>::IsEmpty()
{
	m_CreatorMap.empty();
}

//-----------------------------------------------------------
// Register
//-----------------------------------------------------------
template<class Base>
template <class CreatorType>
bool Factory<Base>::Register
(
)
{
	auto it = m_CreatorMap.find(typeid(CreatorType::ValueType));
	if (it != m_CreatorMap.end())
	{
		return false;
	}
	m_CreatorMap[typeid(CreatorType::ValueType)] = new CreatorType;
	return true;
}

//-----------------------------------------------------------
// dtor 
//-----------------------------------------------------------
template<class Base>
Factory<Base>::~Factory()
{
	if (m_CreatorMap.empty())
	{
		return;
	}

	auto it = m_CreatorMap.begin();

	while (it != m_CreatorMap.end())
	{
		SAFE_DELETE((*it).second);
		it++;
	}

}

//-----------------------------------------------------------
// HasType
//-----------------------------------------------------------
template<class Base>
template <class Type>
bool Factory<Base>::HasType()
{
	return !(m_CreatorMap.find(typeid(Type)) == m_CreatorMap.end());
}

//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------