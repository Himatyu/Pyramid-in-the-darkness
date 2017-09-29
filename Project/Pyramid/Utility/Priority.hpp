/**
* @file			Priority.hpp
* @brief		�D��x���
* @author		S.OIKAWA
* @date			2016.04.27
*/
#pragma once
//-----------------------------------------------------------
// include 
//-----------------------------------------------------------
#include"Macro.h"

//-----------------------------------------------------------
// define 
//-----------------------------------------------------------

namespace Utility
{
	/// <summary>
	/// �D��x
	/// </summary>
	template<class Ty>
	class Priority
	{
	public:

		//-----------------------------------------------------------
		// ctor.dtor
		//-----------------------------------------------------------
		Priority() = default;
		Priority(Ty _pri) { m_priority = _pri; }	//�Öٌ^�ϊ��Ł�int������
		virtual ~Priority() = default;

		//-----------------------------------------------------------
		// default
		//-----------------------------------------------------------

		Priority(const Priority&) = default;
		Priority(Priority&&) = default;

		Priority& operator=(const Priority&) = default;
		Priority& operator=(Priority&&) = default;

		//-----------------------------------------------------------
		// operator
		//-----------------------------------------------------------
		bool operator<(const Priority& _src) const
		{
			return(m_priority < _src.priority);
		}
		bool operator>(const Priority& _src) const
		{
			return(m_priority > _src.priority);
		}
		bool operator==(const Priority& _src) const
		{
			return(m_priority == _src.m_priority);
		}

		operator Ty() const { return m_priority; }

		//-----------------------------------------------------------
		// property
		//-----------------------------------------------------------
		PROPERTY(m_priority, priority, Ty);

		//-----------------------------------------------------------
		// Val
		//-----------------------------------------------------------
	private:
		Ty m_priority = 0;
	};
}
//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------

