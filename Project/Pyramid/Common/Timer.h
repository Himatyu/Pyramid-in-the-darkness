/**
* @file		Timer.h
* @brief	�񓯊��ōX�V����^�C�}
* @author	S.OIKAWA
* @date		2016.11.26
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
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
		/// �񓯊��ōX�V����^�C�}
		/// �P�ʂ͕b
		/// �J��Ԃ��Ȃ��ꍇ�A�o�߂������ɐ^
		/// </summary>
		class Timer final :
			private MT::Order::TaskOrder<Timer>
			{
			public:
			#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				Timer(double _time, bool _isActive = false,bool isOnce = false);
				~Timer();

				Timer(const Timer&) = default;
				Timer(Timer&&) = default;

				Timer& operator=(const Timer&) = default;
				Timer& operator=(Timer&&) = default;
			#pragma endregion

			#pragma region function
				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------
				void Reset(double newTime = -1);

			private:
				void Updata();
				void SetTimeNotify();
			#pragma endregion

			#pragma region property
				//-----------------------------------------------------------
				// property
				//-----------------------------------------------------------
			public:
				PROPERTY_CR_R_ONLY(m_IsElapsed, IsElapsed,bool);
				PROPERTY_REF(m_IsOnce, IsOnce, bool);
				PROPERTY_REF(m_IsActive, IsActive, bool);
				PROPERTY_REF_HOOKABLE(m_SetTime, SetTime, double, SetTimeNotify);
			#pragma endregion

			#pragma region value
				//-----------------------------------------------------------
				// val
				//-----------------------------------------------------------
			private:
				bool m_IsElapsed;
				bool m_IsOnce;
				bool m_IsActive;

				double	m_SetTime, m_Rest;
			#pragma endregion
			};
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------