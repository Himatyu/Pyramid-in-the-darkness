/**
* @file		StaticValue.cpp
* @brief	�ÓI�ϐ��ŊJ���������w�肵�����I�u�W�F�N�Ɏg�p����
* @author	S.OIKAWA
* @date		2016.11.14
*/

//-----------------------------------------------------------
// include 
//-----------------------------------------------------------
#include"StaticValue.h"

//-----------------------------------------------------------
// define 
//-----------------------------------------------------------

namespace Utility
{
	std::vector<StaticValueFinalizer::FinalizerFunc>
		StaticValueFinalizer::m_Finalizers = {};

	//-----------------------------------------------------------
	// AddFinalizer
	//-----------------------------------------------------------
	void StaticValueFinalizer::AddFinalizer(FinalizerFunc _func)
	{
		m_Finalizers.push_back(_func);
	}


	//-----------------------------------------------------------
	// Finalize
	//-----------------------------------------------------------
	void StaticValueFinalizer::Finalize()
	{
		for (auto& _ : m_Finalizers)
		{
			_();
		}
	}
}
//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------
