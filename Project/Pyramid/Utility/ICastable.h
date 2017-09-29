/**
* @file		ICastable.h
* @brief	ダイナミックキャストを提供
* @author	S.OIKAWA
* @date		2017.03.03
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------

#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------

#pragma endregion

namespace Utility
{
	/// <summary>
	/// ダイナミックキャストを提供
	/// </summary>
	class ICastable
	{
	public:
#pragma region  defaults
		//-----------------------------------------------------------
		// defaults
		//-----------------------------------------------------------
		ICastable() = default;
		virtual ~ICastable() = default;

		ICastable(const ICastable&) = default;
		ICastable(ICastable&&) = default;

		ICastable& operator=(const ICastable&) = default;
		ICastable& operator=(ICastable&&) = default;
#pragma endregion

#pragma region function
		//-----------------------------------------------------------
		// function
		//-----------------------------------------------------------
		template<class Casted>
		Casted CastTo();
#pragma endregion

	};
#include"ICastable.inl"

}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------