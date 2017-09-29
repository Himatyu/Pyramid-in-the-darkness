/**
* @file		Manager.inl
* @brief	コンテナで管理するベース
* @author	S.OIKAWA
* @date		2017.03.07
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include "Manager.h"

#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------

#pragma endregion

/// <summary>
/// 追加
/// </summary>
template< class Container>
inline
void
Manager<Container>::Add(typename Container::value_type _val)
{
	m_Container.push_back(_val);
}

/// <summary>
/// 削除
/// 開放は行わない
/// </summary>
template<class Container>
inline
void
Manager<Container>::Remove(typename Container::value_type _val)
{
	if (m_Container.empty())
	{
		return;
	}

	auto it = std::begin(m_Container);
	auto end = std::end(m_Container);

	while (it != end)
	{
		if (*it == _val)
		{
			it = m_Container.erase(it);
			end = std::end(m_Container);
			continue;
		}
		it++;
	}
}

/// <summary>
/// 射影
/// </summary>
template<class Container>
inline 
Nullable<std::list<typename Container::value_type>>
Utility::Manager<Container>::
Select(std::function<bool(typename Container::value_type)>& _pred)
{
	auto& finded = Estd::find_all(m_Container, _pred);

	if (m_Container.empty() || finded.empty())
	{
		return Nullable<std::list<typename Container::value_type>>();
	}

	std::list<typename Container::value_type> result;
	for (auto& _ : finded)
	{
		result.push_back(_);
	}
		
	return { result };
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------