/**
* @file	TimerServer.h
* @brief  タイムサーバー
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
	/// クライアントの前方定義.
	/// </summary>
	class TimerClient;

	/// <summary>
	/// タイマークライアントを更新するサーバ.
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
		/// サーバーの更新.
		/// 毎フレーム呼ぶことでDeltaTimeと、タイマークライアントを更新.
		/// </summary>
		void Updata();

	private:
		
		/// <summary>
		/// タイマーを更新.
		/// </summary>
		void TimersUpdata();
#pragma endregion

		//-----------------------------------------------------------
		// Val
		//-----------------------------------------------------------
#pragma region val
	public:
		static double DeltaTime;			//!< フレーム間時間
		static double TimeScale;			//!< 時間倍率

	private:
		LARGE_INTEGER mBegin, mEnd;			//!< フレームの開始時刻と終了時刻
		LARGE_INTEGER mFreq;				//!< 秒間クロック数
		LARGE_INTEGER mFreamDistance;		//!< フレーム間クロックカウント

		std::vector<TimerClient*> mClients;	//!< タイマーリスト

#pragma endregion

	};
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------
