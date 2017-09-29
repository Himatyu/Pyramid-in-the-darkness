/**
* @file		Creator.h
* @brief	あらゆる型の生成関数を提供
* @author	S.OIKAWA
* @date		2016.02.19
*/
#pragma once

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Utility
{
	/// <summary>
	///クリエイターベース
	/// </summary>
	template<class Type>
	class Creator
	{
	public:
		//-----------------------------------------------------------
		// ctor.dtor
		//-----------------------------------------------------------
		Creator() = default;
		virtual ~Creator() = default;

		//-----------------------------------------------------------
		// default 
		//-----------------------------------------------------------
		Creator(const Creator&) = default;
		Creator(Creator&&) = default;

		Creator&operator=(const Creator&) = default;
		Creator&operator=(Creator&&) = default;

		//-----------------------------------------------------------
		// function
		//-----------------------------------------------------------
		/// <summary>
		/// クリエイト関数
		/// </summary>
		/// <returns>生成型</returns>
		virtual Type Create() = 0;
	};
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------
