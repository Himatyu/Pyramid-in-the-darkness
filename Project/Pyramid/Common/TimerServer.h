/**
* @file		TimerServer.h
* @brief	フレーム感覚と時間倍率を所持する
* @author	S.OIKAWA
* @date		2016.11.26
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include<chrono>
#include"../MT/Order/TaskOrder.h"
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------

#pragma endregion

namespace Pyramid
{
	namespace Common
	{
		/// <summary>
		/// フレーム感覚と時間倍率を所持する
		/// 単位はミリ秒
		/// </summary>
		class TimerServer final :
			private MT::Order::TaskOrder<TimerServer>
		{
		public:
#pragma region  defaults
			//-----------------------------------------------------------
			// defaults
			//-----------------------------------------------------------
			TimerServer();
			~TimerServer();

			TimerServer(const TimerServer&) = default;
			TimerServer(TimerServer&&) = default;

			TimerServer& operator=(const TimerServer&) = default;
			TimerServer& operator=(TimerServer&&) = default;
#pragma endregion

#pragma region function
			//-----------------------------------------------------------
			// function
			//-----------------------------------------------------------
		private:
			/// <summary>
			/// フレーム感覚と時間倍率を更新
			/// </summary>
			void Updata();
#pragma endregion

#pragma region property
	//-----------------------------------------------------------
	// property
	//-----------------------------------------------------------

#pragma endregion

#pragma region value
	//-----------------------------------------------------------
	// val
	//-----------------------------------------------------------
		public:
			static float DeltaTime;
			static float TimeScale;

		private:
			std::chrono::system_clock::time_point	m_Start, m_End;

#pragma endregion
		};
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------