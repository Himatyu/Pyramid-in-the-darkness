/**
* @file		Application.inl
* @brief	�A�v���P�[�V�����̃e���v���[�g����
* @author	S.OIKAWA
* @date		2016.08.20
*/
#pragma once

//-----------------------------------------------------------
// include 
//-----------------------------------------------------------
#include"Application.h"

/// <summary>
/// ���x���ǂݍ���.
/// ���t���[������Load.
/// </summary>
template<class LevelType>
void Application::LoadLevel(bool isCurrent)
{
	m_spLevelStream->RequestLoad<LevelType>(isCurrent);
}

/// <summary>
/// ���x���ǂݍ���.
/// Load�͂��ꂸ��LoadLevel����
/// �ǂݍ��݊������Ă���Α����ɓǂݍ��܂��.
/// </summary>
template<class LevelType>
inline void Application::AsyncLoadLevel()
{
	m_spLevelStream->RequestAsyncLoad<LevelType>();
}

/// <summary>
/// ���x���ǂݍ��݂��I����Ă��邩�m�F����.
/// </summary>
template<class LevelType>
inline bool Application::IsLoadedAsyncLevel()
{
	return m_spLevelStream->IsLoadedAsyncLevel<LevelType>();
}

//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------