/**
* @file		Noncopyable.h
* @brief	�R�s�[���֎~����
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
	///private�p���ŃR�s�[���֎~����
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