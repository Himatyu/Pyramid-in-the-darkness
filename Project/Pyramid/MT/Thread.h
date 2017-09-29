/**
* @file		Thread.h
* @brief	スレッドを所持するクラス
* @author	S.OIKAWA
* @date		2016.4.29
* @date		2016.05.26 デフォルトコピー・ムーブ追加\
*/
#pragma once

//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include<thread>
#include<mutex>
#include<condition_variable>
#include"Jobs/IThreadJob.h"

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace MT
	{
		//前方定義
		class ThreadSystem;

		/// <summary>
		/// スレッドを所持するクラス
		/// ジョブの破棄はしない
		/// </summary>
		class Thread final
		{
			//-----------------------------------------------------------
			// ctor.dtor
			//-----------------------------------------------------------
		public:
			/// <summary>
			/// コンストラクタ
			/// </summary>
			Thread();

			/// <summary>
			/// 共有スレッドコンストラクタ
			/// </summary>
			/// <param name=""></param>
			explicit Thread(ThreadSystem* _pthSys);

			/// <summary>
			/// デストラクタ
			/// </summary>
			~Thread();

			//-----------------------------------------------------------
			// default
			//-----------------------------------------------------------
			Thread(const Thread&) = default;
			Thread(Thread&&) = default;

			Thread& operator=(const Thread&) = default;
			Thread& operator=(Thread&&) = default;

			//-----------------------------------------------------------
			// function
			//-----------------------------------------------------------
				/// <summary>
				/// スレット起動,ジョブ待機状態に
				/// </summary>
			void Standby();

			/// <summary>
			/// スレット停止
			/// </summary>
			void Stop();

			/// <summary>
			/// ジョブ実行.
			/// ほとんど専有スレッド用
			/// </summary>
			/// <param name="pJob">実行するジョブポインタ</param>
			void Execute(Jobs::IThreadJob* _pJob);

			/// <summary>
			/// 終了待機
			/// </summary>
			void Join();

		private:
			/// <summary>
			/// 別スレッド起動で行う処理を呼び出す
			/// </summary>
			void Job();

		public:
			//-----------------------------------------------------------
			// Property
			//-----------------------------------------------------------
			THREAD_SAFE_PROPERTY(m_IsIdle, isIdle, bool, m_IsIdleMtx);
			THREAD_SAFE_PROPERTY(m_IsClose, isClose, bool, m_IsCloseMtx);
			THREAD_SAFE_PROPERTY(m_IsMonopolize, isMonopolize, bool, m_IsMonopolizeMtx);
			THREAD_SAFE_PROPERTY(m_IsReady, IsReady, bool, m_IsReadyMtx);
		private:
			//-----------------------------------------------------------
			// Val
			//-----------------------------------------------------------
			std::thread			m_Th;				//スレッド実体
			std::mutex			m_IsMonopolizeMtx;	//m_isMonopolize ミューテックス
			std::mutex			m_IsIdleMtx;		//m_isIdle ミューテックス
			std::mutex			m_IsCloseMtx;		//m_isClose ミューテックス
			std::mutex			m_IsReadyMtx;		//m_isClose ミューテックス
			Jobs::IThreadJob*	m_pJob;				//実行ジョブ
			ThreadSystem*		m_pSystem;			//システムポインタ
			volatile bool		m_IsIdle;
			volatile bool		m_IsClose;
			volatile bool		m_IsMonopolize;
			volatile bool		m_IsReady;		//spurious wakeup対策、Systemからのみ真がセットされジョブ実行後に偽をセットする
		};
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------