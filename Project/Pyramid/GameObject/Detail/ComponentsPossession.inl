/**
* @file		ComponentsPossession.inl
* @brief	コンポーネントを管理する.
* @author	S.OIKAWA
* @date		2016.09.26
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"ComponentsPossession.h"

#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------

#pragma endregion
//-----------------------------------------------------------
// AddComponent
//-----------------------------------------------------------
template<class Type, class ...Param>
inline std::shared_ptr<Type>
ComponentsPossession::AddComponent(Param && ..._param)
{
	auto spCom = std::make_shared<Type>(_param...);
	spCom->pOwner = m_pOwner;
	spCom->Components::Component::Init();
	spCom->TypeApply<Type>();

	m_AllComponents.push_back(spCom);

	if (spCom->UpdataQuery())
	{
		m_UpdatableComponents.AddRequest(spCom.get());
	}

	if (spCom->DrawQuery())
	{
		m_DrawbleComponents.AddRequest(spCom.get());
	}

	//コピーする必要があるのでクリエイターを登録する
	::Utility::Factory <spComponent>::Instantiate()
		.Register< Components::Creators::ComponentCreator<Type>>();

	return spCom;
}

//-----------------------------------------------------------
// RemoveComponent
//-----------------------------------------------------------
template<class Type>
inline void ComponentsPossession::RemoveComponent()
{
	if (!m_AllComponents.size())
	{
		return;
	}

	auto spCom = GetComponent<Type>().Value;
	m_AllComponents.remove(spCom);
	m_UpdatableComponents.RemoveRequest(spCom.get());
	m_DrawbleComponents.RemoveRequest(spCom.get());
}

//-----------------------------------------------------------
// GetComponent
//-----------------------------------------------------------
template<class Type>
inline ::Utility::Nullable<std::shared_ptr<Type>>
ComponentsPossession::GetComponent()
{
	if (!m_AllComponents.size())
	{
		return ::Utility::Nullable<std::shared_ptr<Type>>();
	}

	for (auto& _ : m_AllComponents)
	{
		if (_->IsSame(typeid(Type), 0))
		{
			return ::Utility::Nullable<std::shared_ptr<Type>>
				(std::dynamic_pointer_cast<Type>(_));
		}
	}
	return ::Utility::Nullable<std::shared_ptr<Type>>();
}


//-----------------------------------------------------------
// GetComponentFromTag
//-----------------------------------------------------------
template<class Type>
inline 
Utility::Nullable<std::shared_ptr<Type>> 
ComponentsPossession::GetComponentFromTag
(std::string _tag)
{
	auto searched = GetComponents<Type>();

	if (!searched)
	{
		return Utility::NullType();
	}

	auto finded = searched.Value;
	auto result =
		Utility::Estd::find_if(
		finded, 
		[_tag](Common::Sp<Type>& _spCom)
	{
		return _spCom->Tag == _tag;
	});

	if (std::end(finded) == result)
	{
		return Utility::NullType();
	}

	return *result;
}

//-----------------------------------------------------------
// GetComponents 
//-----------------------------------------------------------
template<class Type>
inline ::Utility::Nullable<std::vector<std::shared_ptr<Type>>>
ComponentsPossession::GetComponents()
{
	if (!m_AllComponents.size())
	{
		return ::Utility::Nullable<std::vector<std::shared_ptr<Type>>>();
	}

	std::vector<std::shared_ptr<Type>> result;
	for (auto& _ : m_AllComponents)
	{
		if (_->IsSame(typeid(Type),0))
		{
			result.push_back(std::dynamic_pointer_cast<Type>(_));
		}
	}
	return Utility::Nullable<std::vector<std::shared_ptr<Type>>>(result);
}

//-----------------------------------------------------------
// HasComponent 
//-----------------------------------------------------------
template<class Type>
inline bool ComponentsPossession::HasComponent()
{
	if (!m_AllComponents.size())
	{
		return false;
	}

	for (auto& _ : m_AllComponents)
	{
		if (_->IsSame(typeid(Type), 0))
		{
			return true;
		}
	}
	return false;
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------