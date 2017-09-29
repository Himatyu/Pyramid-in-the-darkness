/**
* @file		Noncopyable.h
* @brief	コピーを禁止する
* @author	S.OIKAWA
* @date		2016.05.25
*/
#pragma once

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Utility
{
	/// <summary>
	///private継承でコピーを禁止する
	/// <summary>
	class Noncopyable
	{
	protected:
		//-----------------------------------------------------------
		// default 
		//-----------------------------------------------------------
		Noncopyable() = default;
		~Noncopyable() = default;

		void operator =(const Noncopyable& src) = delete;
		Noncopyable(const Noncopyable& src) = delete;
	};
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------