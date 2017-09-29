/**
* @file		TimerClient.h
* @brief		タイマークライアント
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
	/// 時間経過を計測するタイマー.
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
		/// 切り替え.
		/// </summary>
		/// <param name="flag">有効or無効</param>
		void SetActive(const bool flag);

		/// <summary>
		/// 初期化.
		/// </summary>
		/// <param name="time">計測時間</param>
		/// <param name="reset">ループするか</param>
		void Init(const double time, const bool reset = false, bool active = false);

		/// <summary>
		/// タイマー更新.
		/// サーバーからしか呼ばれない.
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
		bool mIsTimeUP = false;		//!時間経過したか
		bool mIsReset = false;		//!ループするか
		bool mIsActive = false;		//!有効か
		double mTime, mNow;			//!設定時間と残り時間
#pragma endregion

	};
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------