/**
* @file		CommandExecutor.cpp
* @brief
* @author
* @date
*/

//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include "CommandExecutor.h"
#include"CommandListener.h"
#include"ICommand.h"
//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Utility
{
	//-----------------------------------------------------------
	// ctor
	//-----------------------------------------------------------
	CommandExecutor::CommandExecutor(CommandListener* _Listener) :
		m_pListener(_Listener),
		m_IsInterrupt(false)
	{
	}

	//-----------------------------------------------------------
	// Run
	//-----------------------------------------------------------
	void CommandExecutor::Run()
	{
		m_pListener->CommandApply();
		for (auto& _ : m_pListener->CommandList)
		{
			if (m_IsInterrupt)
			{
				break;
			}
			_->Execute();
		}
		m_IsInterrupt = false;
	}

	//-----------------------------------------------------------
	// Interruption
	//-----------------------------------------------------------
	void CommandExecutor::Interruption()
	{
		m_IsInterrupt = true;
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------