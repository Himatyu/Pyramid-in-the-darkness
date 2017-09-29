/**
* @file		TypeComparable.h
* @brief	Œ^”äŠr‚ð’ñ‹Ÿ
* @author	S.OIKAWA
* @date		2016.09.19
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"TypePossession.h"
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------

#pragma endregion

namespace Utility
{
	/// <summary>
	/// Œ^”äŠr.
	/// </summary>
	class TypeComparable :
		public TypePossession
	{
	public:
#pragma region  defaults
		//-----------------------------------------------------------
		// defaults
		//-----------------------------------------------------------
		TypeComparable() = default;
		virtual ~TypeComparable() = default;

		TypeComparable(const TypeComparable&) = default;
		TypeComparable(TypeComparable&&) = default;

		TypeComparable& operator=(const TypeComparable&) = default;
		TypeComparable& operator=(TypeComparable&&) = default;
#pragma endregion

#pragma region operator
		//-----------------------------------------------------------
		// operator==
		//-----------------------------------------------------------	
		bool IsSame(const std::type_index& _Type,unsigned _index);
		virtual bool operator==(TypeComparable& _Type);
		virtual bool operator!=(TypeComparable& _Type);
#pragma endregion

#pragma region property
		//-----------------------------------------------------------
		// property
		//-----------------------------------------------------------

#pragma endregion

#pragma region function
	//-----------------------------------------------------------
	// function
	//-----------------------------------------------------------

#pragma endregion

#pragma region value
	//-----------------------------------------------------------
	// val
	//-----------------------------------------------------------

#pragma endregion
	};
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------


