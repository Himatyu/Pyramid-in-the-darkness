/**
* @file		IHitEvent.h
* @brief	è’ìÀÉCÉxÉìÉg
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
		/// è’ìÀÉCÉxÉìÉg
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
			/// è’ìÀÇµÇΩèuä‘Ç…mapìoò^ÇµÇƒî≠çs
			/// </summary>
			virtual void OnCollisionEnter(HitResult) = 0 {};

			/// <summary>
			/// ìoò^Ç≥ÇÍÇΩèÛë‘Ç≈è’ìÀÇ≈î≠çs
			/// </summary>
			virtual void OnCollisionStay(HitResult) = 0 {};

			/// <summary>
			/// ìoò^Ç≥ÇÍÇΩèÛë‘Ç≈è’ìÀÇ™Ç»ÇØÇÍÇŒî≠çs
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