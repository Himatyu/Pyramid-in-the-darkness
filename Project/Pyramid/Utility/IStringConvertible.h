/**
* @file		IStringConvertible.h
* @brief	型をstringにするインターフェースを提供.
* @author	S.OIKAWA
* @date		2016.09.19
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include<string>
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------

#pragma endregion
namespace Utility
{
	/// <summary>
	/// 型をstringにするインターフェース.
	/// </summary>
	template<class Type>
	class IStringConvertible
	{
	public:
#pragma region function
		//-----------------------------------------------------------
		// function
		//-----------------------------------------------------------
		std::string ToString();
#pragma endregion

	};
#include"IStringConvertible.inl"
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------
