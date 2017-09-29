/**
* @file		CommandExecutor.h
* @brief	�R�}���h�����s����
* @author	S.OIKAWA
* @date		2016.11.10
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------

#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------

#pragma endregion

namespace Utility
{
	class CommandListener;
	/// <summary>
	/// �R�}���h�����s����
	/// </summary>
	class CommandExecutor
	{
	public:
#pragma region  defaults
		//-----------------------------------------------------------
		// defaults
		//-----------------------------------------------------------
		CommandExecutor(CommandListener*);
		~CommandExecutor() = default;

		CommandExecutor(const CommandExecutor&) = default;
		CommandExecutor(CommandExecutor&&) = default;

		CommandExecutor& operator=(const CommandExecutor&) = default;
		CommandExecutor& operator=(CommandExecutor&&) = default;
#pragma endregion

#pragma region function
		//-----------------------------------------------------------
		// function
		//-----------------------------------------------------------

		/// <summary>
		/// ���s����
		/// </summary>
		void Run();

		/// <summary>
		/// ���s�𒆎~����
		/// </summary>
		void Interruption();
#pragma endregion

	private:
#pragma region value
		//-----------------------------------------------------------
		// val
		//-----------------------------------------------------------
		CommandListener*	m_pListener;
		bool				m_IsInterrupt;
#pragma endregion
	};
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------