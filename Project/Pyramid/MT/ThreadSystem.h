/**
* @file		ThreadSystem.h
* @brief	スレッドシステム
* @author	S.OIKAWA
* @date		2016.4.29
*/
#pragma once
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include<vector>
#include<thread>
#include <algorithm>
#include <queue>
#include"Thread.h"
#include"../Utility/VectorExtension.hpp"
#include"singleton.h"
//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace MT
	{
		namespace Jobs
		{
			//前方定義
			class ThreadJobBase;
		}
	}
}

namespace Pyramid
{
	namespace MT
	{

		/// <summary>
		/// スレッド管理
		/// スレッドを所持してタスクを実行
		/// </summary>
		class ThreadSystem final :
			public ::Utility::Singleton<ThreadSystem>
		{
			//-----------------------------------------------------------
			// ctor.dtor
			//-----------------------------------------------------------
		public:
			ThreadSystem();
			~ThreadSystem();

			//-----------------------------------------------------------
			// default
			//-----------------------------------------------------------
			ThreadSystem(const ThreadSystem&) = default;
			ThreadSystem(ThreadSystem&&) = default;

			ThreadSystem& operator=(const ThreadSystem&) = default;
			ThreadSystem& operator=(ThreadSystem&&) = default;

			//-----------------------------------------------------------
			// function
			//-----------------------------------------------------------
		public:

			/// <summary>
			/// 登録スレッドの終了待機
			/// 専有スレッドは除く
			/// </summary>
			void Join();

			/// <summary>
			/// 管理スレッド数
			/// </summary>
			/// <returns>管理スレッド数</returns>
			size_t TheradCount();

			/// <summary>
			/// 共有スレッド数
			/// </summary>
			/// <returns>共有スレッド数</returns>
			size_t CommonThreadCount();

			/// <summary>
			/// スレッドを使えるかどうか
			/// </summary>
			/// <returns></returns>
			bool isUseMultiThread();

			/// <summary>
			/// スレッドの専有
			/// </summary>
			/// <returns>専有スレッドのポインタ</returns>
			Thread* MonopolizeLockThread();

			/// <summary>
			/// スレッドの専有の解除
			/// </summary>
			/// <param name=""></param>
			void MonopolizeReleaseThread(Thread*);

			/// <summary>
			/// ジョブ実行
			/// </summary>
			/// <param name="pJob">実行するジョブポインタ</param>
			void JobExecute(Jobs::IThreadJob* _pJob);

			/// <summary>
			/// ジョブ実行
			/// </summary>
			/// <param name="pJob">実行するジョブポインタ</param>
			template<class ChildTaskList>
			void JobExecute(ChildTaskList& _pJobs);

			/// <summary>
			/// 一時的に共有スレッドを全開放する
			/// </summary>
			void SystemDown();

			/// <summary>
			/// 確保し直す
			/// </summary>
			void SystemStandUp();

		private:
			/// <summary>
			/// 全スレッドを待機状態に
			/// </summary>
			void Ready();


			//-----------------------------------------------------------
			// property
			//-----------------------------------------------------------
		public:
			THREAD_SAFE_PROPERTY(m_isActive, isActive, bool, m_IsActive);
			PROPERTY_REF_R_ONLY(m_QueueMutex, QueueMutex, ::std::mutex);
			PROPERTY_REF_R_ONLY(m_QueueCondition, QueueCondition, ::std::condition_variable);
			PROPERTY_REF(m_Tasks, Tasks, ::std::queue< Pyramid::MT::Jobs::IThreadJob* >);

			//-----------------------------------------------------------
			// Val
			//-----------------------------------------------------------
		private:
			/// <summary>
			/// スレッドリスト
			/// </summary>
			::std::vector<Thread*> m_Threads;

			/// <summary>
			/// ハードウェアによるスレット上限
			/// </summary>
			const int m_ThreadMax;

			/// <summary>
			/// 使用可能なスレッド上限
			/// </summary>
			int m_UsebleThreadMax;

			/// <summary>
			/// スレッドを使用するか
			/// </summary>
			bool m_isActive;

			::std::queue< Jobs::IThreadJob* > m_Tasks;

			::std::mutex				m_QueueMutex;
			::std::mutex				m_IsActive;
			::std::condition_variable m_QueueCondition;
		};
#include"ThreadSystem.inl"
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------

