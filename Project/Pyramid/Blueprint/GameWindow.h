/**
* @file		GameWindow.h
* @brief	�Q�[���E�B���h
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
		/// MCI�R�}���h���󂯎��Q�[���p�̃E�B���h.
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
				/// MCI�R�}���h���󂯎��v���[�W��.
				/// </summary>
			virtual LRESULT WndProc(UINT uMsg, WPARAM wParam, LPARAM lParam) override;

		};
	}
}

//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------