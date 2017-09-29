/**
* @file		NullType.h
* @brief	終端や空を意味する
* @author	S.OIKAWA
* @date		2016.11.10
*/
#pragma once
namespace Utility
{
	/// <summary>
	/// 終端や空を意味する
	/// </summary>
	class NullType
	{
	public:
#pragma region  defaults
		//-----------------------------------------------------------
		// defaults
		//-----------------------------------------------------------
		NullType() = default;
		~NullType() = default;

		NullType(const NullType&) = default;
		NullType(NullType&&) = default;

		NullType& operator=(const NullType&) = default;
		NullType& operator=(NullType&&) = default;
#pragma endregion
	};
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------