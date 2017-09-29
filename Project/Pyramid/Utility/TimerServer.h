/**
* @file	TimerServer.h
* @brief  �^�C���T�[�o�[
* @author S.OIKAWA
* @date	2016/07/26
*/
#pragma once
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include<vector>
#include"singleton.h"
//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Utility
{
	/// <summary>
	/// �N���C�A���g�̑O����`.
	/// </summary>
	class TimerClient;

	/// <summary>
	/// �^�C�}�[�N���C�A���g���X�V����T�[�o.
	/// </summary>
	class TimerServer:
		public Singleton<TimerServer>
	{
		friend class TimerClient;
		//-----------------------------------------------------------
		// delaults
		//-----------------------------------------------------------
	public:
		TimerServer();
		~TimerServer() = default;

		TimerServer(const  TimerServer&) = default;
		TimerServer(TimerServer&&) = default;

		TimerServer& operator=(const TimerServer&) = default;
		TimerServer& operator=(TimerServer&&) = default;
		//-----------------------------------------------------------
		// function
		//-----------------------------------------------------------
#pragma region func

	public:
		/// <summary>
		/// �T�[�o�[�̍X�V.
		/// ���t���[���ĂԂ��Ƃ�DeltaTime�ƁA�^�C�}�[�N���C�A���g���X�V.
		/// </summary>
		void Updata();

	private:
		
		/// <summary>
		/// �^�C�}�[���X�V.
		/// </summary>
		void TimersUpdata();
#pragma endregion

		//-----------------------------------------------------------
		// Val
		//-----------------------------------------------------------
#pragma region val
	public:
		static double DeltaTime;			//!< �t���[���Ԏ���
		static double TimeScale;			//!< ���Ԕ{��

	private:
		LARGE_INTEGER mBegin, mEnd;			//!< �t���[���̊J�n�����ƏI������
		LARGE_INTEGER mFreq;				//!< �b�ԃN���b�N��
		LARGE_INTEGER mFreamDistance;		//!< �t���[���ԃN���b�N�J�E���g

		std::vector<TimerClient*> mClients;	//!< �^�C�}�[���X�g

#pragma endregion

	};
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------
