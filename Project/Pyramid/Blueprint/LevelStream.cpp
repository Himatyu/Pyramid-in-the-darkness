/**
* @file		LevelStream.cpp
* @brief	レベルストリーム実装
* @author	S.OIKAWA
* @date		2016/07/28
*/

//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include "LevelStream.h"
#include "Level.h"
#include"Estd.h"
//-----------------------------------------------------------
// define
//-----------------------------------------------------------
using namespace std;
namespace Pyramid
{
	namespace Blueprint
	{

		std::vector<function<LevelProc>> LevelStream::FreamProcs;

		//-----------------------------------------------------------
		// dtor
		//-----------------------------------------------------------
		LevelStream::~LevelStream()
		{
			Utility::Estd::for_each(m_Levels, [](auto& _) {SAFE_DELETE(_); });
			Utility::Estd::for_each(m_requestLoadLevel, [](auto& _) {SAFE_DELETE(_.first); });
			Utility::Estd::for_each(m_AsyncLoadedLecelList, [](auto& _) {SAFE_DELETE(_.first); });
		}

		//-----------------------------------------------------------
		// InterruptionAsyncLoad
		//-----------------------------------------------------------
		void LevelStream::InterruptionAsyncLoad()
		{
			m_AsyncLoadLevel.Interruption();
		}

		//-----------------------------------------------------------
		// UnLoad
		//-----------------------------------------------------------
		void LevelStream::RequestUnLoad(Level* _lv)
		{
			if (!_lv)
			{
				___D_LOG("ヌルポのアンロードリクエスト");
				return;
			}
			m_requestUnloadLevel.push_back(_lv);
		}

		//-----------------------------------------------------------
		// UpdataStream
		//-----------------------------------------------------------
		void LevelStream::UpdataStream()
		{
			if (m_pLoadThread && m_pLoadThread->isIdle)
			{
				auto& asyncLoadLevel = m_AsyncLoadLevel.LoadedLevelList;
				m_AsyncLoadedLecelList.merge(asyncLoadLevel);
				asyncLoadLevel.clear();
				MT::ThreadSystem::Instantiate().MonopolizeReleaseThread(m_pLoadThread);
				m_pLoadThread = nullptr;
			}

			UnLoad();
			Load();

			if (m_Levels.empty())
			{
				return;
			}

			auto level_it = m_Levels.begin();
			for (auto& it : FreamProcs)
			{
				if (level_it == m_Levels.end())
				{
					break;
				}

				it(**level_it);
				level_it++;
			}
		}

		//-----------------------------------------------------------
		// Load
		//-----------------------------------------------------------
		void LevelStream::Load()
		{
			if (m_requestLoadLevel.empty())
			{
				return;
			}

			for (auto& it : m_requestLoadLevel)
			{
				if (it.second)
				{
					m_Levels.push_front(it.first);
					continue;
				}

				m_Levels.push_back(it.first);
			}
			m_requestLoadLevel.clear();
		}

		//-----------------------------------------------------------
		// UnLoad
		//-----------------------------------------------------------
		void LevelStream::UnLoad()
		{
			if (m_requestUnloadLevel.empty())
			{
				return;
			}

			for (auto& it : m_requestUnloadLevel)
			{
				m_Levels.remove(it);
				m_AsyncLoadedLecelList.remove_if([it](auto& _) {return _.first == it; });
				SAFE_DELETE(it);
			}

			m_requestUnloadLevel.clear();
		}

	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------
