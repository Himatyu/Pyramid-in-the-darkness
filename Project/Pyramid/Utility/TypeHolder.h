/**
* @file		TypeHolder.h
* @brief	Œ^î•ñ‚ğ‚Â
* @author	S.OIKAWA
* @date		2017.06.04
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include<typeindex>
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------

#pragma endregion

namespace Utility
{
	/// <summary>
	/// Œ^î•ñ‚ğ‚Â
	/// </summary>
	template<class Ty>
	class TypeHolder
	{
	public:
		using Type = Ty;
#pragma region  defaults
		//-----------------------------------------------------------
		// defaults
		//-----------------------------------------------------------
		TypeHolder() = default;
		virtual ~TypeHolder() = default;

		TypeHolder(const TypeHolder&) = default;
		TypeHolder(TypeHolder&&) = default;

		TypeHolder& operator=(const TypeHolder&) = default;
		TypeHolder& operator=(TypeHolder&&) = default;
#pragma endregion

#pragma region function
		//-----------------------------------------------------------
		// function
		//-----------------------------------------------------------

#pragma endregion

#pragma region property
	//-----------------------------------------------------------
	// property
	//-----------------------------------------------------------
		PROPERTY_REF(m_Type, TypeIndex, ::std::type_index);
#pragma endregion

#pragma region value
	//-----------------------------------------------------------
	// val
	//-----------------------------------------------------------
	protected:
		::std::type_index	m_Type = typeid(Ty);
#pragma endregion
	};
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------