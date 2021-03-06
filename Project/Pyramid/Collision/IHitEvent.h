/**
* @file		IHitEvent.h
* @brief	衝突イベント
* @author	S.OIKAWA
* @date		2017.05.12
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"HitResult.h"

#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------

#pragma endregion

namespace Pyramid
{
	namespace Collision
	{
		/// <summary>
		/// 衝突イベント
		/// </summary>
		class IHitEvent
		{
		public:
#pragma region  defaults
			//-----------------------------------------------------------
			// defaults
			//-----------------------------------------------------------
			IHitEvent() = default;
			~IHitEvent() = default;

			IHitEvent(const IHitEvent&) = default;
			IHitEvent(IHitEvent&&) = default;

			IHitEvent& operator=(const IHitEvent&) = default;
			IHitEvent& operator=(IHitEvent&&) = default;
#pragma endregion

#pragma region function
			//-----------------------------------------------------------
			// function
			//-----------------------------------------------------------

			/// <summary>
			/// 衝突した瞬間にmap登録して発行
			/// </summary>
			virtual void OnCollisionEnter(HitResult) = 0 {};

			/// <summary>
			/// 登録された状態で衝突で発行
			/// </summary>
			virtual void OnCollisionStay(HitResult) = 0 {};

			/// <summary>
			/// 登録された状態で衝突がなければ発行
			/// </summary>
			virtual void OnCollisionExit(HitResult) = 0 {};
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

#pragma endregion
		};
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------