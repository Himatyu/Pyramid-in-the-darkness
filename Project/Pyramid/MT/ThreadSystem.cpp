/**
* @file			ThreadSystem.cpp
* @brief		スレッドシステム実装
* @author		S.OIKAWA
* @date			2016.04.29
*/

//-----------------------------------------------------------
// include 
//-----------------------------------------------------------
#include "ThreadSystem.h"
#include"Thread.h"
#include"Jobs/IThreadJob.h"
#include"../Utility/VectorExtension.hpp"

//-----------------------------------------------------------
// define 
//-----------------------------------------------------------
namespace Pyramid
{
	namespace MT
	{

		//-----------------------------------------------------------
		// ctor
		//-----------------------------------------------------------
		ThreadSystem::ThreadSystem() :
			m_ThreadMax(std::thread::hardware_concurrency()),
			m_UsebleThreadMax(int(m_ThreadMax *0.5f)),			//テスト値
			m_isActive(true)
		{
			Ready();
		}

		//-----------------------------------------------------------
		// dtor
		//-----------------------------------------------------------
		ThreadSystem::~ThreadSystem()
		{
			m_isActive = false;
			m_QueueCondition.notify_all();
			for (auto it : m_Threads)
			{
				SAFE_DELETE(it);
			}
		}

		//-----------------------------------------------------------
		// すべてのスレッドを実行待機させる
		//-----------------------------------------------------------
		void ThreadSystem::Ready()
		{
			m_Threads.reserve(m_UsebleThreadMax);
			for (int i = 0; i < m_UsebleThreadMax; i++)
			{
				auto pTh = new Thread(this);
				pTh->Standby();
				m_Threads.emplace_back(pTh);
			}
		}

		//-----------------------------------------------------------
		// すべてのスレッドを待機する
		//-----------------------------------------------------------
		void ThreadSystem::Join()
		{
			while (!Tasks.empty())
			{
				for (auto& it : m_Threads)
				{
					if (!it->isMonopolize)
					{
						it->Join();
					}
				}
			}
		}

		//-----------------------------------------------------------
		// TheradCount
		//-----------------------------------------------------------
		size_t ThreadSystem::TheradCount()
		{
			return m_Threads.size();
		}

		//-----------------------------------------------------------
		// CommonThreadCount 
		//-----------------------------------------------------------
		size_t ThreadSystem::CommonThreadCount()
		{
			return ::Utility::VectorCount_if(
				m_Threads,
				[](Thread* _th)->bool
			{
				return !_th->isMonopolize;
			});
		}

		//-----------------------------------------------------------
		// isUseMultiThread
		//-----------------------------------------------------------
		bool ThreadSystem::isUseMultiThread()
		{
			return m_UsebleThreadMax&&m_isActive;
		}

		//-----------------------------------------------------------
		// MonopolizeLockThread
		//-----------------------------------------------------------
		Thread* ThreadSystem::MonopolizeLockThread()
		{
			for (auto& it : m_Threads)
			{
				if (!it->isMonopolize || it->isIdle)
				{
					it->isMonopolize = true;
					m_QueueCondition.notify_one();
					return it;
				}
			}

			___D_LOG("Not Monopolity Thread");
			return nullptr;
		}

		//-----------------------------------------------------------
		// MonopolizeReleaseThread 
		//-----------------------------------------------------------
		void ThreadSystem::MonopolizeReleaseThread(Thread* _pJob)
		{
			_pJob->isMonopolize = false;
		}

		//-----------------------------------------------------------
		// JobExecute
		//-----------------------------------------------------------
		void ThreadSystem::JobExecute(Jobs::IThreadJob* _pJob)
		{
			{
				std::unique_lock<std::mutex> lock(m_QueueMutex);

				if (!m_isActive)
				{//無効ならメインスレッドで実行
					_pJob->Job();
					return;
				}
				m_Tasks.emplace(_pJob);
			}
			//1つの待機状態解除
			m_QueueCondition.notify_one();
		}

		//-----------------------------------------------------------
		// SystemDown 
		//-----------------------------------------------------------
		void ThreadSystem::SystemDown()
		{
			m_isActive = false;
			m_QueueCondition.notify_all();
			Utility::VectorClean<Thread*>
				(m_Threads,
					[](Thread* _pThr)->bool 
			{
				return !_pThr->isMonopolize; 
			}, true);
		}

		//-----------------------------------------------------------
		//  SystemStandUp
		//-----------------------------------------------------------
		void ThreadSystem::SystemStandUp()
		{
			m_isActive = true;
			int threadCount = m_UsebleThreadMax - m_Threads.size();
			for (int i = 0; i < threadCount; i++)
			{
				auto pThr = new Thread(this);
				pThr->Standby();
				m_Threads.emplace_back(pThr);
			}

		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------

