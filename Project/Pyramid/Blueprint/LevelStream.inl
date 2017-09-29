/**
* @file		LevelStream.inl
* @brief	���x���X�g���[���̃e���v���[�g����
* @author	S.OIKAWA
* @date		2016.09.04
*/
#pragma once
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"LevelStream.h"

/// <summary>
/// ���x���ǂݍ���.
/// ���t���[������Load.
/// </summary>
template<class LevelType>
void LevelStream::RequestLoad(bool _isCurrent)
{
	for (auto& _ : m_AsyncLoadedLecelList)
	{
		if (_.second == typeid(LevelType))
		{
			m_requestLoadLevel.emplace_back(std::make_pair(_.first, _isCurrent));
			m_AsyncLoadedLecelList.remove(_);
			return;
		}
	}

	m_requestLoadLevel.emplace_back(std::make_pair(new LevelType, _isCurrent));
	return;
}

/// <summary>
/// ���x���ǂݍ���.
/// ���N�G�X�g�̂������S�Ẵ��x����
/// �ǂݍ��܂�Ȃ��ƃA�N�Z�X�ł��Ȃ�.
/// </summary>
template<class LevelType>
inline void LevelStream::RequestAsyncLoad()
{
	auto& mtSystem = MT::ThreadSystem::Instantiate();
	if (!mtSystem.isActive || !mtSystem.isUseMultiThread())
	{
		___D_LOG("�񓯊����[�h�̎��s�AThreadSystem�̎g�p�s��");
		return;
	}

	//�ǉ��ǂݍ���
	if (m_pLoadThread)
	{
		m_AsyncLoadLevel.LoadRequest<LevelType>();
		return;
	}

	m_pLoadThread = mtSystem.MonopolizeLockThread();
	if (!m_pLoadThread)
	{
		___D_LOG("�񓯊����[�h�̎��s�A��L�X���b�h�̎擾���s");
		return;
	}

	//�V�K�ǂݍ���
	m_AsyncLoadLevel.LoadRequest<LevelType>();
	m_pLoadThread->Execute(&m_AsyncLoadLevel);
}

/// <summary>
/// ���x���ǂݍ��݂��I����Ă��邩�m�F����.
/// </summary>
template<class LevelType>
inline bool LevelStream::IsLoadedAsyncLevel()
{
	//�Q�Ƃɂ���ƃ��b�N���Ԃ��G���������Ȃ�̂ŃR�s�[
	auto nowLoadedLevels = m_AsyncLoadLevel.LoadedLevelList;
	for (auto& _ : nowLoadedLevels)
	{
		if (_.second == typeid(LevelType))
		{
			return true;
		}
	}
	return false;
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------