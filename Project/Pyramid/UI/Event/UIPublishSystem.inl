/**
* @file		UIPublishSystem.inl
* @brief	UIのイベントリスナー/パブリッシャーを登録し、イベントの発行を行う
* @author	S.OIKAWA
* @date		2017.05.26
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include "UIPublishSystem.h"

#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------

#pragma endregion

/// <summary>
/// パブリッシャーへの登録
/// </summary>
template<class Publisher, class Ty>
inline void UIPublishSystem::AddListener(Ty* _pUI)
{	
	auto findResult = FindPublisher<Publisher>();
	
	if (!findResult)
	{
		___D_LOG("登録していないパブリッシャーにリスナーの登録要求");
		return;
	}

	(*findResult)->AddListener(
		_pUI,
		static_cast<typename Publisher::Type*>(_pUI));
}

/// <summary>
/// パブリッシャーへの登録解除
/// </summary>
template<class Publisher, class Ty>
inline void UIPublishSystem::RemoveListener(Ty* _pUI)
{
	auto findResult = FindPublisher<Publisher>();

	if (!findResult)
	{
		___D_LOG("登録していないパブリッシャーにリスナーの登録削除要求");
		return;
	}

	(*findResult)->RemoveListener(
		_pUI,
		static_cast<typename Publisher::Type*>(_pUI));
}

/// <summary>
/// パブリッシャーの登録
/// </summary>
template<class Publisher>
inline void UIPublishSystem::RegisterOfPublisher()
{
	if (m_Publishrs.find(typeid(Publisher)) != m_Publishrs.end())
	{
		return;
	}
	auto pPublisher = new Publisher;
	auto pCasted = static_cast<Publisher::Abstract*>(pPublisher);
	m_Publishrs[typeid(Publisher)] =  pCasted;
}

/// <summary>
/// パブリッシャーの登録解除
/// </summary>
template<class Publisher>
inline void UIPublishSystem::UnRegisterOfPublisher()
{
	auto findResult = FindPublisher<Publisher>();

	if (!findResult)
	{
		return;
	}
	SAFE_DELETE(*findResult);
	m_Publishrs.erase(typeid(Publisher));
}

//-----------------------------------------------------------
// FindPublisher
//-----------------------------------------------------------
template<class Ty>
inline 
::Utility::Nullable<Publisher::Abstract*>
UIPublishSystem::FindPublisher()
{
	auto findResult =
		::Utility::Estd::find_if(
			m_Publishrs,
			[&](::std::pair<::std::type_index, Publisher::Abstract*> _)
	{
		return  _.first == typeid(Ty);
	});

	if (m_Publishrs.end() == findResult)
	{
		return{};
	}

	return ::Utility::Nullable<Publisher::Abstract*>((*findResult).second);
}


//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------