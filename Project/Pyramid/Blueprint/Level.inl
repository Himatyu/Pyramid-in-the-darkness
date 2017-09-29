/**
* @file		Level.inl
* @brief	インライン実装
* @author	S.OIKAWA
* @date		2016/07/31
*/
#pragma once
//-----------------------------------------------------------
// include 
//-----------------------------------------------------------
#include"Level.h"

//-----------------------------------------------------------
// define 
//-----------------------------------------------------------

/// <summary>
/// オブジェクト実体化.
/// </summary>
template <class Type, class... Param>
Type& Level::Instantiate(Param&&... param)
{
	auto pObj = new Type(param...);
	m_ObjectManager.Register(pObj, true);

	pObj->TypeApply<Type>();
	auto& subjects = pObj->StateSubjects;
	auto& ovservers = m_ObjectManager.ObjectStateObservers;
	for (int i = 0; i < GameObject::Observers::SubjectMax; i++)
	{
		subjects[i].Attach(ovservers[i]);
	}
	pObj->pOwner = this;

	return *pObj;
}

/// <summary>
/// 型件検索を行う
/// </summary>
template<class Ty>
inline 
Utility::Nullable<GameObject::Object*> 
Pyramid::Blueprint::Level::FindWithType()
{
	if (!m_ObjectManager.AllObjects.size())
	{
		return Utility::Nullable<GameObject::Object*>();
	}

	auto& objs = m_ObjectManager.AllObjects;
	for (auto& _ : objs)
	{
		if (*_ == typeid(ty))
		{
			return Utility::Nullable<GameObject::Object*>(_);
		}
	}

	return Utility::Nullable<GameObject::Object*>();
}

/// <summary>
/// 型検索を行う
/// </summary>
template<class Ty>
inline 
Utility::Nullable<std::vector<GameObject::Object*>> 
Pyramid::Blueprint::Level::FindObjectsWithType()
{
	if (!m_ObjectManager.AllObjects.size())
	{
		return Utility::Nullable<std::vector<GameObject::Object*>>();
	}

	::Utility::Nullable<std::vector<std::shared_ptr<Ty>>> result;
	auto& objs = m_ObjectManager.AllObjects;
	for (auto& _ : objs)
	{
		if (*_ == typeid(Ty))
		{
			result.Value.push_back(std::dynamic_pointer_cast<Ty>(_));
		}
	}

	return result;
}


//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------