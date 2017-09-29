/**
* @file		Subject.cpp
* @brief	SubjectŽÀ‘•
* @author	S.OIKAWA
* @date		2016.04.27 DoxyGen
*/

//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"Subject.h"
#include"Observer.h"
#include"VectorExtension.hpp"

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Utility
{
	//-----------------------------------------------------------
	// Attach
	//-----------------------------------------------------------
	void Subject::Attach(Observer* _obser)
	{
		m_Ovservers.emplace_back(_obser);
	}

	//-----------------------------------------------------------
	// Detach
	//-----------------------------------------------------------
	void Subject::Detach(Observer* _obser)
	{
		//Hack
		auto it = std::begin(m_Ovservers);
		for (; it != std::end(m_Ovservers); ++it)
		{
			if (_obser == *it)
			{
				m_Ovservers.erase(it);
				return;
			}
		}
	}
	//-----------------------------------------------------------
	// Notify
	//-----------------------------------------------------------
	void Subject::Notify()
	{
		for (auto& it : m_Ovservers)
		{
			it->OnEvent(this);
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------