/**
* @file		ICommand.h
* @brief	コマンドパターンのベース
* @author	S.OIKAWA
* @date		2016.11.8
*/
#pragma once

//-----------------------------------------------------------
// define
//-----------------------------------------------------------

namespace Utility
{
	/// <summary>
	/// コマンドパターンのベース
	/// </summary>
	class ICommand
	{
	public:
#pragma region function
		//-----------------------------------------------------------
		// dtor
		//-----------------------------------------------------------
		virtual ~ICommand() = default;

		//-----------------------------------------------------------
		// function
		//-----------------------------------------------------------
		/// <summary>
		/// コマンド実行
		/// </summary>
		virtual void Execute() = 0;
#pragma endregion
	};
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------