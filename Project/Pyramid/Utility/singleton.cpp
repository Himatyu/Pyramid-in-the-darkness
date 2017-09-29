/**
* @file		singleton.cpp
* @brief	singletonのテンプレート実装
* @author	S.OIKAWA
* @date		2015.05.30
*/

//-----------------------------------------------------------
// include 
//-----------------------------------------------------------
#include "singleton.h"
#include"Estd.h"
//-----------------------------------------------------------
// define 
//-----------------------------------------------------------
namespace Utility
{
	std::vector<SingletonFinalizer::
		FinalizerFunc>SingletonFinalizer::m_Finalizers = {};
	//-----------------------------------------------------------
	//  AddFinalizer
	//-----------------------------------------------------------
	void SingletonFinalizer::AddFinalizer(FinalizerFunc _func)
	{
		m_Finalizers.push_back(_func);
	}

	//-----------------------------------------------------------
	// Finalize
	//-----------------------------------------------------------
	void SingletonFinalizer::Finalize()
	{
		Estd::reverse(m_Finalizers);
		for (auto& it : m_Finalizers)
		{
			it();
		}
	}
}
//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------