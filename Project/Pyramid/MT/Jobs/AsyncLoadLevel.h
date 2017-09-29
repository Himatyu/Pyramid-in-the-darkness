/**
* @file		AsyncLoadLevel.h
* @brief	非同期のレベル読み込みを提供
* @author	S.OIKAWA
* @date		2016.10.08
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"IThreadJob.h"
#include"../Blueprint/Creators/LevelCreator.h"
#include<mutex>
#include<list>
#include<utility>
#include<typeindex>
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Blueprint
	{
		class Level;
	}
}

namespace Pyramid
{
	namespace MT
	{
		namespace Jobs
		{
			using LevelData = std::pair<Blueprint::Level*, std::type_index>;
			using RequestDate =
				std::pair<
				::Utility::Creator<Blueprint::Level*>*,
				std::type_index>;
#pragma endregion

			/// <summary>
			/// 非同期のレベル読み込み.
			/// </summary>
			class AsyncLoadLevel  final :
				public IThreadJob
			{
			public:
#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				AsyncLoadLevel() = default;
				~AsyncLoadLevel();

				AsyncLoadLevel(const AsyncLoadLevel&) = default;
				AsyncLoadLevel(AsyncLoadLevel&&) = default;

				AsyncLoadLevel& operator=(const AsyncLoadLevel&) = default;
				AsyncLoadLevel& operator=(AsyncLoadLevel&&) = default;
#pragma endregion

#pragma region function
				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------

				/// <summary>
				/// 登録したレベルを読み込む.
				/// リストが無くなるまでロードし続ける.
				/// </summary>
				virtual void Job();

				/// <summary>
				/// 読み込むのを中断する.
				/// 現在の読み込みは完了させてから終了する.
				/// リクエストリストは初期化される.
				/// </summary>
				void Interruption();

				/// <summary>
				/// ロードリクエストを送る.
				/// 中断状態の場合解除する.
				/// </summary>
				template<class Lv>
				void LoadRequest();

#pragma endregion

#pragma region property
				//-----------------------------------------------------------
				// property
				//-----------------------------------------------------------
				//外でクリアさせるのでconstはつけない,スレッドをまたぐのでコピー
				THREAD_SAFE_PROPERTY_R_ONLY(
					m_LoadedLevelList,
					LoadedLevelList,
					std::list<LevelData>,
					m_LoadedLevelListMutex
				);

#pragma endregion

			private:
#pragma region value
				//-----------------------------------------------------------
				// val
				//-----------------------------------------------------------
				std::list <RequestDate>				m_LevelLoadRequestList;
				std::mutex							m_LevelLoadRequestListMutex;

				bool								m_IsInterruption;
				std::mutex							m_IsInterruptionMutex;

				std::mutex							m_LoadedLevelListMutex;
				std::list<LevelData>				m_LoadedLevelList;
#pragma endregion
			};
#include"AsyncLoadLevel.inl"
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------

