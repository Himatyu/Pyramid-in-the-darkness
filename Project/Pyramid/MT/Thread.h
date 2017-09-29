/**
* @file		Thread.h
* @brief	�X���b�h����������N���X
* @author	S.OIKAWA
* @date		2016.4.29
* @date		2016.05.26 �f�t�H���g�R�s�[�E���[�u�ǉ�\
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
		//�O����`
		class ThreadSystem;

		/// <summary>
		/// �X���b�h����������N���X
		/// �W���u�̔j���͂��Ȃ�
		/// </summary>
		class Thread final
		{
			//-----------------------------------------------------------
			// ctor.dtor
			//-----------------------------------------------------------
		public:
			/// <summary>
			/// �R���X�g���N�^
			/// </summary>
			Thread();

			/// <summary>
			/// ���L�X���b�h�R���X�g���N�^
			/// </summary>
			/// <param name=""></param>
			explicit Thread(ThreadSystem* _pthSys);

			/// <summary>
			/// �f�X�g���N�^
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
				/// �X���b�g�N��,�W���u�ҋ@��Ԃ�
				/// </summary>
			void Standby();

			/// <summary>
			/// �X���b�g��~
			/// </summary>
			void Stop();

			/// <summary>
			/// �W���u���s.
			/// �قƂ�ǐ�L�X���b�h�p
			/// </summary>
			/// <param name="pJob">���s����W���u�|�C���^</param>
			void Execute(Jobs::IThreadJob* _pJob);

			/// <summary>
			/// �I���ҋ@
			/// </summary>
			void Join();

		private:
			/// <summary>
			/// �ʃX���b�h�N���ōs���������Ăяo��
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
			std::thread			m_Th;				//�X���b�h����
			std::mutex			m_IsMonopolizeMtx;	//m_isMonopolize �~���[�e�b�N�X
			std::mutex			m_IsIdleMtx;		//m_isIdle �~���[�e�b�N�X
			std::mutex			m_IsCloseMtx;		//m_isClose �~���[�e�b�N�X
			std::mutex			m_IsReadyMtx;		//m_isClose �~���[�e�b�N�X
			Jobs::IThreadJob*	m_pJob;				//���s�W���u
			ThreadSystem*		m_pSystem;			//�V�X�e���|�C���^
			volatile bool		m_IsIdle;
			volatile bool		m_IsClose;
			volatile bool		m_IsMonopolize;
			volatile bool		m_IsReady;		//spurious wakeup�΍�ASystem����̂ݐ^���Z�b�g����W���u���s��ɋU���Z�b�g����
		};
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------