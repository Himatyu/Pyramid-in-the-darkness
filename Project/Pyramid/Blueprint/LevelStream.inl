/**
* @file		LevelStream.inl
* @brief	レベルストリームのテンプレート実装
* @author	S.OIKAWA
* @date		2016.09.04
*/
#pragma once
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"LevelStream.h"

/// <summary>
/// レベル読み込み.
/// 次フレーム頭にLoad.
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
/// レベル読み込み.
/// リクエストのあった全てのレベルが
/// 読み込まれないとアクセスできない.
/// </summary>
template<class LevelType>
inline void LevelStream::RequestAsyncLoad()
{
	auto& mtSystem = MT::ThreadSystem::Instantiate();
	if (!mtSystem.isActive || !mtSystem.isUseMultiThread())
	{
		___D_LOG("非同期ロードの失敗、ThreadSystemの使用不可");
		return;
	}

	//追加読み込み
	if (m_pLoadThread)
	{
		m_AsyncLoadLevel.LoadRequest<LevelType>();
		return;
	}

	m_pLoadThread = mtSystem.MonopolizeLockThread();
	if (!m_pLoadThread)
	{
		___D_LOG("非同期ロードの失敗、専有スレッドの取得失敗");
		return;
	}

	//新規読み込み
	m_AsyncLoadLevel.LoadRequest<LevelType>();
	m_pLoadThread->Execute(&m_AsyncLoadLevel);
}

/// <summary>
/// レベル読み込みが終わっているか確認する.
/// </summary>
template<class LevelType>
inline bool LevelStream::IsLoadedAsyncLevel()
{
	//参照にするとロック時間がエラく長くなるのでコピー
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