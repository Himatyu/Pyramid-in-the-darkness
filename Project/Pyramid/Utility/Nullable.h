/**
* @file		Nullable.h
* @brief	nullÇãñóeÅAî‰ärÇíÒãüÇ∑ÇÈ
* @author	S.OIKAWA
* @date		2016.09.12
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"NullType.h"
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Utility
{
	using null = nullptr_t;
}
#pragma endregion

namespace Utility
{
	/// <summary>
	/// nullî‰ärÇãñóeÇ∑ÇÈ
	/// </summary>
	template<class Type>
	class Nullable
	{
	public:
#pragma region  defaults
		//-----------------------------------------------------------
		// defaults
		//-----------------------------------------------------------
		Nullable() = default;
		Nullable(NullType);
		Nullable(const Type&);
		~Nullable() = default;

		Nullable(const Nullable&) = default;
		Nullable(Nullable&&) = default;

		Nullable& operator=(const Nullable&) = default;
		Nullable& operator=(Nullable&&) = default;

#pragma endregion

#pragma region  operator
		//-----------------------------------------------------------
		// operator
		//-----------------------------------------------------------
		Type& operator->();
		Type& operator*();
		Nullable& operator=(const nullptr_t&);
		bool operator==(const nullptr_t&);
		bool operator!=(const nullptr_t&);
		explicit operator bool();
#pragma endregion

#pragma region property
	//-----------------------------------------------------------
	// property
	//-----------------------------------------------------------
		PROPERTY_REF(m_Value, Value, Type);
		PROPERTY_R_ONLY(m_HasValue, IsHasValue, bool);
#pragma endregion
	private:
#pragma region value
		//-----------------------------------------------------------
		// val
		//-----------------------------------------------------------
		bool m_HasValue = false;
		Type m_Value;
#pragma endregion
	};
#include"Nullable.inl"
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------
