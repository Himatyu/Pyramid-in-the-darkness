/**
* @file			Thread.cpp
* @brief		TheradAPI
* @author		S.OIKAWA
* @date			2016.04.29
*/

//-----------------------------------------------------------
// include 
//-----------------------------------------------------------
#include"Thread.h"
#include"ThreadSystem.h"
#include <condition_variable>
#include<iostream>

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
		Thread::Thread() :
			m_IsClose(false),
			m_IsIdle(true),
			m_IsMonopolize(false),
			m_pJob(nullptr),
			m_pSystem(nullptr)
		{
		}

		//-----------------------------------------------------------
		// ctor : ThreadSystem
		//-----------------------------------------------------------
		Thread::Thread(ThreadSystem * _pThSys) :
			m_IsClose(false),
			m_IsIdle(true),
			m_IsMonopolize(false),
			m_pJob(nullptr),
			m_pSystem(_pThSys),
			m_IsReady(false)
		{
		}

		//-----------------------------------------------------------
		// dtor
		//-----------------------------------------------------------
		Thread::~Thread()
		{
			Stop();
			m_Th.join();
		}

		//-----------------------------------------------------------
		// �X���b�h�N���A�W���u����
		//-----------------------------------------------------------
		void Thread::Standby()
		{
			m_Th = std::thread(&Thread::Job, this);
			isClose = false;
			isIdle = true;
		}

		//-----------------------------------------------------------
		// �X���b�h��~
		//-----------------------------------------------------------
		void Thread::Stop()
		{
			isClose = true;
			if (!isMonopolize)
			{
				m_pSystem->QueueCondition.notify_one();
				return;
			}
			m_Th.join();
		}

		//-----------------------------------------------------------
		// �W���u
		//-----------------------------------------------------------
		void Thread::Job()
		{
			while (true)
			{
				if (!isMonopolize)
				{
					//��̃X���b�h���f�[�^���󂯎��܂Ő�L����
					std::unique_lock<std::mutex> lock(m_pSystem->QueueMutex);
					isIdle = true;
					
					//�����ҋ@
					m_pSystem->QueueCondition
						.wait(lock,
						[&] {
						return !m_pSystem->isActive ||
							!m_pSystem->Tasks.empty() ||
							IsReady || isMonopolize; });

					if (isMonopolize)
					{
						continue;
					}					
					if (!m_pSystem->isActive || m_pSystem->Tasks.empty() || isClose)
					{
						return;
					}

					isIdle = false;
					m_pJob = std::move(m_pSystem->Tasks.front());
					m_pSystem->Tasks.pop();
					m_pJob->Job();
					m_pJob = nullptr;
					IsReady = false;
				}
				else
				{
					if (isClose)
					{
						return;
					}
					if (m_pJob)
					{
						isIdle = false;
						m_pJob->Job();
						m_pJob = nullptr;
						isIdle = true;
						IsReady = false;
					}
				}
			}
		}

		//-----------------------------------------------------------
		// �ҋ@
		//-----------------------------------------------------------
		void Thread::Join()
		{			
			while (IsReady)
			{
			}
		}

		//-----------------------------------------------------------
		// �W���u���s
		//-----------------------------------------------------------
		void Thread::Execute(Jobs::IThreadJob* _pJob)
		{
			//�W���C�����邱�Ƃ�pJob��ی삷��
			Join();

			m_pJob = _pJob;
			m_IsIdle = false;
		}

	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------