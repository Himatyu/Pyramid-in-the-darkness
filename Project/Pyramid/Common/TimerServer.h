/**
* @file		TimerServer.h
* @brief	�t���[�����o�Ǝ��Ԕ{������������
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
		/// �t���[�����o�Ǝ��Ԕ{������������
		/// �P�ʂ̓~���b
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
			/// �t���[�����o�Ǝ��Ԕ{�����X�V
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