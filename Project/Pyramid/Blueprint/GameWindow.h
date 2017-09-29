/**
* @file		GameWindow.h
* @brief	ゲームウィンド
* @author	S.OIKAWA
* @date		2016.08.25
*/

#pragma once
//-----------------------------------------------------------
// include 
//-----------------------------------------------------------
#include "window.h"

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Blueprint
	{

		/// <summary>
		/// MCIコマンドを受け取るゲーム用のウィンド.
		/// </summary>
		class GameWindow final :
			public Window
		{
		public:
			//-----------------------------------------------------------
			// defaults 
			//-----------------------------------------------------------
			GameWindow() = default;
			virtual ~GameWindow() = default;

			GameWindow(const GameWindow&) = default;
			GameWindow(GameWindow&&) = default;

			GameWindow&operator=(const GameWindow&) = default;
			GameWindow&operator=(GameWindow&&) = default;

			//-----------------------------------------------------------
			// function 
			//-----------------------------------------------------------
				/// <summary>
				/// MCIコマンドも受け取るプロージャ.
				/// </summary>
			virtual LRESULT WndProc(UINT uMsg, WPARAM wParam, LPARAM lParam) override;

		};
	}
}

//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------