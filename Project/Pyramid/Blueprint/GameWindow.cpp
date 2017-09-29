/**
* @file		GameWindow.cpp
* @brief	ゲーム用のウィンド実装
* @author	S.OIKAWA
* @date		2016.09.04
*/

//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include "GameWindow.h"
#include"../Resource/Audio/MCIMessageDispatcher.h"

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
using namespace Pyramid::Resources;
namespace Pyramid
{
	namespace Blueprint
	{

		//-----------------------------------------------------------
		// WndProc
		//-----------------------------------------------------------
		LRESULT GameWindow::WndProc(UINT uMsg, WPARAM wParam, LPARAM lParam)
		{
			switch (uMsg)
			{
			case WM_CREATE:
				return OnCreate((LPCREATESTRUCT)lParam);

			case WM_DROPFILES:
				OnDropFiles((HDROP)wParam);
				return 0;

			case WM_CLOSE:
			case WM_DESTROY:
				OnDestroy();
				break;
			case MM_MCINOTIFY:
				Audio::MCIMessageDispatcher::Instantiate()
					.DispatchMessageA(wParam, lParam);
				break;

			default:
				break;
			}
			return DefWindowProc(uMsg, wParam, lParam);
		}

	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------