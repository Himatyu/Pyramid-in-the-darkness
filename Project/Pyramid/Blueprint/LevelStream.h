/**
* @file		LevelStream.h
* @brief	レベル管理クラス
* @author	S.OIKAWA
* @date		2016/07/26
*/
#pragma once

//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include<list>
#include<vector>
#include<functional>
#include<typeindex>
#include"../MT/Jobs/AsyncLoadLevel.h"
#include"../MT/Thread.h"
#include"../MT/ThreadSystem.h"
//-----------------------------------------------------------
// define
//-----------------------------------------------------------

namespace Pyramid
{
	namespace Blueprint
	{
		class Level;
		using LevelProc = void(Level& _lv);
		#define ProcType [](Level& _lv)

		/// <summary>
		/// レベル管理クラス.
		/// 確保開放は更新中に行いたくないのでフレームの頭で行う.
		/// </summary>
		class LevelStream final
		{
		public:
			//-----------------------------------------------------------
			// defaults
			//-----------------------------------------------------------
			LevelStream() = default;
			~LevelStream();

			LevelStream(const LevelStream&) = default;
			LevelStream(LevelStream&&) = default;

			LevelStream& operator=(const LevelStream&) = default;
			LevelStream &operator=(LevelStream&&) = default;

			//-----------------------------------------------------------
			// function
			//-----------------------------------------------------------
				/// <summary>
				/// レベル読み込み.
				/// 次フレーム頭にLoad.
				/// </summary>
			template<class LevelType>
			void RequestLoad(bool _isCurrent);

			/// <summary>
			/// レベル読み込み.
			/// リクエストのあった全てのレベルが
			/// 読み込まれないとアクセスできない.
			/// </summary>
			template<class LevelType>
			void RequestAsyncLoad();

			/// <summary>
			/// レベル読み込みが終わっているか確認する.
			/// </summary>
			template<class LevelType>
			bool IsLoadedAsyncLevel();

			/// <summary>
			/// 非同期読み込みを中止する
			/// </summary>
			void InterruptionAsyncLoad();

			/// <summary>
			/// 破棄リストに追加.
			/// 次フレーム頭にUnLoad
			/// </summary>
			/// <param name="_lv">破棄レベルポインタ</param>
			void RequestUnLoad(Level* _lv);

			/// <summary>
			/// レベル更新.
			/// FreamProcsの登録数のみ更新.
			/// 例えばFreamProcs[0~1]ならLevels[0~1]しか更新しない.
			/// </summary>
			void UpdataStream();

		private:
			/// <summary>
			/// レベルの確保、登録
			/// </summary>
			void Load();

			/// <summary>
			/// レベルの開放、登録破棄.
			/// </summary>
			void UnLoad();

		public:
			//-----------------------------------------------------------
			// val
			//-----------------------------------------------------------
				/// <summary>
				/// 登録レベルの更新方法.
				/// [0]がプレイヤーのいるレベルで[1]や[2]は近くのレベル.
				/// ↑みたいな感じで処理分ける.
				/// inout激しかったら見直す.
				/// </summary>
			static std::vector<std::function<LevelProc>>		FreamProcs;

		private:
			std::list<Level*>									m_Levels;
			std::vector<std::pair<Level*, bool>>				m_requestLoadLevel;
			std::vector<Level*>									m_requestUnloadLevel;
			std::list<std::pair<Level*, std::type_index>>		m_AsyncLoadedLecelList;

			MT::Thread*											m_pLoadThread;
			MT::Jobs::AsyncLoadLevel							m_AsyncLoadLevel;

		};
#include"LevelStream.inl"
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------

