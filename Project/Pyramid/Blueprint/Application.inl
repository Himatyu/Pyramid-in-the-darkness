/**
* @file		Application.inl
* @brief	アプリケーションのテンプレート実装
* @author	S.OIKAWA
* @date		2016.08.20
*/
#pragma once

//-----------------------------------------------------------
// include 
//-----------------------------------------------------------
#include"Application.h"

/// <summary>
/// レベル読み込み.
/// 次フレーム頭にLoad.
/// </summary>
template<class LevelType>
void Application::LoadLevel(bool isCurrent)
{
	m_spLevelStream->RequestLoad<LevelType>(isCurrent);
}

/// <summary>
/// レベル読み込み.
/// LoadはされずにLoadLevel時に
/// 読み込み完了していれば即時に読み込まれる.
/// </summary>
template<class LevelType>
inline void Application::AsyncLoadLevel()
{
	m_spLevelStream->RequestAsyncLoad<LevelType>();
}

/// <summary>
/// レベル読み込みが終わっているか確認する.
/// </summary>
template<class LevelType>
inline bool Application::IsLoadedAsyncLevel()
{
	return m_spLevelStream->IsLoadedAsyncLevel<LevelType>();
}

//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------