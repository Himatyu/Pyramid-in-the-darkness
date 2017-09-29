/**
* @file		CommandListener.cpp
* @brief	�R�}���h�o�^�A�폜����
* @author	S.OIKAWA
* @date		2016.11.8
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"CommandListener.h"
#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------

namespace Utility
{
	//-----------------------------------------------------------
	// StageingCommand
	//-----------------------------------------------------------
	void CommandListener::AddCommand(ICommand* _pCmd)
	{
		m_CommandList.AddRequest(_pCmd);
	}

	//-----------------------------------------------------------
	// RemoveCommitedCommand
	//-----------------------------------------------------------
	void CommandListener::RemoveCommand(ICommand* _pCmd)
	{
		m_CommandList.RemoveRequest(_pCmd);
	}

	//-----------------------------------------------------------
	// CommandApply
	//-----------------------------------------------------------
	void CommandListener::CommandApply()
	{
		m_CommandList.Apply();
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------