/**
* @file		DelayEvent.h
* @brief	遅延衝突イベント
* @author	S.OIKAWA
* @date		2017.05.10
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"../HitResult.h"
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Collision
	{
		namespace Detail
		{
			class ICollidee;

			/// <summary>
			/// 遅延衝突イベントタイプ
			/// </summary>
			enum DelayEventType : int
			{
				Enter = 0,
				Stay = 1,
				Exit = 2
			};
		}
	}
}
#pragma endregion

namespace Pyramid
{
	namespace Collision
	{
		namespace Detail
		{
			/// <summary>
			/// 遅延衝突イベント
			/// </summary>
			class DelayEvent
			{
			public:
#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				DelayEvent(ICollidee*, HitResult&, DelayEventType);
				DelayEvent() = default;
				~DelayEvent() = default;

				DelayEvent(const DelayEvent&) = default;
				DelayEvent(DelayEvent&&) = default;

				DelayEvent& operator=(const DelayEvent&) = default;
				DelayEvent& operator=(DelayEvent&&) = default;
#pragma endregion

#pragma region function
				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------

				/// <summary>
				/// イベントを呼び出す
				/// </summary>
				void CallEvent();
#pragma endregion

#pragma region property
	//-----------------------------------------------------------
	// property
	//-----------------------------------------------------------

#pragma endregion
			private:
#pragma region value
	//-----------------------------------------------------------
	// val
	//-----------------------------------------------------------
				ICollidee*		m_pReceive;
				HitResult		m_Param;
				DelayEventType	m_EventType;
#pragma endregion
			};
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------