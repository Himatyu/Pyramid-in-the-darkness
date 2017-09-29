/**
* @file		TimerClient.h
* @brief		�^�C�}�[�N���C�A���g
* @author		S.OIKAWA
* @date		2016/07/26
*/
#pragma once

//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"Macro.h"
//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Utility
{
	/// <summary>
	/// ���Ԍo�߂��v������^�C�}�[.
	/// </summary>
	class TimerClient
	{
		//-----------------------------------------------------------
		// ctor.dtor
		//-----------------------------------------------------------
	public:
		TimerClient();
		~TimerClient();

		//-----------------------------------------------------------
		// defaults
		//-----------------------------------------------------------
		TimerClient(const TimerClient&) = default;
		TimerClient(TimerClient&&) = default;

		TimerClient& operator=(const TimerClient&) = default;
		TimerClient& operator=(TimerClient&&) = default;

		//-----------------------------------------------------------
		// function
		//-----------------------------------------------------------
#pragma region func

	public:

		/// <summary>
		/// �؂�ւ�.
		/// </summary>
		/// <param name="flag">�L��or����</param>
		void SetActive(const bool flag);

		/// <summary>
		/// ������.
		/// </summary>
		/// <param name="time">�v������</param>
		/// <param name="reset">���[�v���邩</param>
		void Init(const double time, const bool reset = false, bool active = false);

		/// <summary>
		/// �^�C�}�[�X�V.
		/// �T�[�o�[���炵���Ă΂�Ȃ�.
		/// </summary>
		void Updata();

#pragma endregion

	public:
		//-----------------------------------------------------------
		// property
		//-----------------------------------------------------------
		PROPERTY_CR_R_ONLY(mIsTimeUP, isTimeUP, bool);
		PROPERTY_REF(mIsReset, isReset, bool);

		//-----------------------------------------------------------
		// val
		//-----------------------------------------------------------
#pragma region val
	private:
		bool mIsTimeUP = false;		//!���Ԍo�߂�����
		bool mIsReset = false;		//!���[�v���邩
		bool mIsActive = false;		//!�L����
		double mTime, mNow;			//!�ݒ莞�ԂƎc�莞��
#pragma endregion

	};
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------