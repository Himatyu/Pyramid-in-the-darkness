/**
* @file		Unknown.h
* @brief	void*として振る舞うオブジェクトを明示的に示す
* @author	S.OIKAWA
* @date		2017.06.02
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
	/// void*として振る舞うオブジェクトを明示的に示す
	/// </summary>
	__interface IUnknown
	{

	};

	/// <summary>
	/// void*として振る舞うオブジェクトを明示的に示す
	/// デストラクタを持つ
	/// </summary>
	class Unknown
	{
	public:
#pragma region  defaults
		//-----------------------------------------------------------
		// defaults
		//-----------------------------------------------------------
		Unknown() = default;
		virtual ~Unknown() = default;

		Unknown(const Unknown&) = default;
		Unknown(Unknown&&) = default;

		Unknown& operator=(const Unknown&) = default;
		Unknown& operator=(Unknown&&) = default;
#pragma endregion
	};
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------