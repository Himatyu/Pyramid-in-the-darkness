#include "ColliderManager.h"
/**
* @file		ColliderManager.inl
* @brief	Collider‚Ì“o˜^Aíœ‚ğs‚¤
* @author	S.OIKAWA
* @date		2017.03.04
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

/// <summary>
/// Collider’Ç‰Á
/// </summary>
template<class AddCollider>
inline void ColliderManager::Add()
{
	std::type_index type = typeid(AddCollider);
	auto isRegisted =
		Utility::Estd::any_of(
			m_ColliderList,
			[&](RegisterInfo* _pInfo)
	{
		return (_pInfo->second == type);
	});

	if (isRegisted)
	{
		___D_LOG("“¯Œ^‚ÌCollider“o˜^");
		return;
	}

	m_ColliderList.push_back(
		new RegisterInfo(
			static_cast<ICollider*>(new AddCollider),
			type
			));
}

/// <summary>
/// Collideríœ
/// </summary>
template<class RemoveCollider>
inline void ColliderManager::Remove()
{
	auto type = typeid(RemoveCollider);

	auto result = Utility::Estd::find_if(
		m_ColliderList, 
		[&](RegisterInfo* _pInfo)
	{
		return (type == _pInfo->second);
	});
	if (result == m_ColliderList.end())
	{
		return;
	}
	m_ColliderList.remove(result);
	SAFE_DELETE(result->first);
	SAFE_DELETE(result);
}

/// <summary>
/// ColliderŒŸõ
/// </summary>
template<class FindCollider>
inline Utility::Nullable<Collider::ICollider*> 
ColliderManager::Find()
{
	auto result = Utility::Estd::find_if(
		m_ColliderList,
		[&](RegisterInfo* _) {return _->second == typeid(FindCollider); });
	if (result == m_ColliderList.end())
	{
		return{};
	}
	return Utility::Nullable<Collider::ICollider*>((*result)->first);
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------