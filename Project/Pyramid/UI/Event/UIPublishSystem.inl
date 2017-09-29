/**
* @file		UIPublishSystem.inl
* @brief	UI�̃C�x���g���X�i�[/�p�u���b�V���[��o�^���A�C�x���g�̔��s���s��
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
/// �p�u���b�V���[�ւ̓o�^
/// </summary>
template<class Publisher, class Ty>
inline void UIPublishSystem::AddListener(Ty* _pUI)
{	
	auto findResult = FindPublisher<Publisher>();
	
	if (!findResult)
	{
		___D_LOG("�o�^���Ă��Ȃ��p�u���b�V���[�Ƀ��X�i�[�̓o�^�v��");
		return;
	}

	(*findResult)->AddListener(
		_pUI,
		static_cast<typename Publisher::Type*>(_pUI));
}

/// <summary>
/// �p�u���b�V���[�ւ̓o�^����
/// </summary>
template<class Publisher, class Ty>
inline void UIPublishSystem::RemoveListener(Ty* _pUI)
{
	auto findResult = FindPublisher<Publisher>();

	if (!findResult)
	{
		___D_LOG("�o�^���Ă��Ȃ��p�u���b�V���[�Ƀ��X�i�[�̓o�^�폜�v��");
		return;
	}

	(*findResult)->RemoveListener(
		_pUI,
		static_cast<typename Publisher::Type*>(_pUI));
}

/// <summary>
/// �p�u���b�V���[�̓o�^
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
/// �p�u���b�V���[�̓o�^����
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