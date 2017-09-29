/**
* @file		CommandListener.h
* @brief	コマンドの登録、削除を提供する
* @author	S.OIKAWA
* @date		2016.11.8
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include<vector>
#include"SafetyIterate.h"
#pragma endregion

#pragma region define
	//-----------------------------------------------------------
	// define
	//-----------------------------------------------------------
#pragma endregion

namespace Utility
{
	class ICommand;
	/// <summary>
	/// コマンドを登録する
	/// </summary>
	class CommandListener
	{
	public:
#pragma region  defaults
		//-----------------------------------------------------------
		// defaults
		//-----------------------------------------------------------
		CommandListener() = default;
		virtual ~CommandListener() = default;

		CommandListener(const CommandListener&) = default;
		CommandListener(CommandListener&&) = default;

		CommandListener& operator=(const CommandListener&) = default;
		CommandListener& operator=(CommandListener&&) = default;
#pragma endregion

#pragma region function
		//-----------------------------------------------------------
		// function
		//-----------------------------------------------------------

		/// <summary>
		/// コマンド追加.
		/// </summary>
		void AddCommand(ICommand*);

		/// <summary>
		/// コマンド削除.
		/// </summary>
		void RemoveCommand(ICommand*);

		/// <summary>
		/// コマンドを確定する
		/// 空いたコマンドがある場合インデックスがずれるので注意
		/// </summary>
		void CommandApply();
#pragma endregion

#pragma region property
		//-----------------------------------------------------------
		// property
		//-----------------------------------------------------------
		PROPERTY_REF(m_CommandList.Vector, CommandList, std::vector<ICommand*>);
#pragma endregion

	protected:
#pragma region value
		//-----------------------------------------------------------
		// val
		//-----------------------------------------------------------
		SafetyIterate<ICommand*>		m_CommandList;
#pragma endregion
	};

}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------