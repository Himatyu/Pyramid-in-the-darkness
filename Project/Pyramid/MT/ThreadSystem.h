/**
* @file		ThreadSystem.h
* @brief	�X���b�h�V�X�e��
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
			//�O����`
			class ThreadJobBase;
		}
	}
}

namespace Pyramid
{
	namespace MT
	{

		/// <summary>
		/// �X���b�h�Ǘ�
		/// �X���b�h���������ă^�X�N�����s
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
			/// �o�^�X���b�h�̏I���ҋ@
			/// ��L�X���b�h�͏���
			/// </summary>
			void Join();

			/// <summary>
			/// �Ǘ��X���b�h��
			/// </summary>
			/// <returns>�Ǘ��X���b�h��</returns>
			size_t TheradCount();

			/// <summary>
			/// ���L�X���b�h��
			/// </summary>
			/// <returns>���L�X���b�h��</returns>
			size_t CommonThreadCount();

			/// <summary>
			/// �X���b�h���g���邩�ǂ���
			/// </summary>
			/// <returns></returns>
			bool isUseMultiThread();

			/// <summary>
			/// �X���b�h�̐�L
			/// </summary>
			/// <returns>��L�X���b�h�̃|�C���^</returns>
			Thread* MonopolizeLockThread();

			/// <summary>
			/// �X���b�h�̐�L�̉���
			/// </summary>
			/// <param name=""></param>
			void MonopolizeReleaseThread(Thread*);

			/// <summary>
			/// �W���u���s
			/// </summary>
			/// <param name="pJob">���s����W���u�|�C���^</param>
			void JobExecute(Jobs::IThreadJob* _pJob);

			/// <summary>
			/// �W���u���s
			/// </summary>
			/// <param name="pJob">���s����W���u�|�C���^</param>
			template<class ChildTaskList>
			void JobExecute(ChildTaskList& _pJobs);

			/// <summary>
			/// �ꎞ�I�ɋ��L�X���b�h��S�J������
			/// </summary>
			void SystemDown();

			/// <summary>
			/// �m�ۂ�����
			/// </summary>
			void SystemStandUp();

		private:
			/// <summary>
			/// �S�X���b�h��ҋ@��Ԃ�
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
			/// �X���b�h���X�g
			/// </summary>
			::std::vector<Thread*> m_Threads;

			/// <summary>
			/// �n�[�h�E�F�A�ɂ��X���b�g���
			/// </summary>
			const int m_ThreadMax;

			/// <summary>
			/// �g�p�\�ȃX���b�h���
			/// </summary>
			int m_UsebleThreadMax;

			/// <summary>
			/// �X���b�h���g�p���邩
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

