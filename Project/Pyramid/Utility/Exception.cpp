/**
* @file	Exception.cpp
* @brief	例外クラス実装部
* @author	S.OIKAWA
* @date	2016/4/22
*/

//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"Exception.h"

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Utility
{

	//-----------------------------------------------------------
	// ctor
	//-----------------------------------------------------------
	Exception::Exception(const std::string& _msg)
		:m_Msg(_msg),
		m_ExceptionDetailBuffer("Err : " + _msg)
	{}


	//-----------------------------------------------------------
	// ctor
	//-----------------------------------------------------------
	Exception::Exception
		(
			const char* _file,
			const char* _func,
			const int _line,
			const std::string& _msg
			)
		:m_Msg(_msg),
		m_Filename(_file),
		m_FunctionName(_func),
		m_Line(_line),
		m_ExceptionDetailBuffer
		("Err : " + _msg + " function : " + _func + " line : " + std::to_string(_line) + +" file : " + _file)
	{
	}
}
//-----------------------------------------------------------
//　EOF
//-----------------------------------------------------------

