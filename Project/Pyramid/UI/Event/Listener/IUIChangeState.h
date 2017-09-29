/**
* @file		IUIChangeState.h
* @brief	有効無効を切り替えた際のイベントを受け取る
* @author	S.OIKAWA
* @date		2017.05.26
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"IUnknown.h"
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------

#pragma endregion

namespace Pyramid
{
	namespace UI
	{
		namespace Event
		{
			namespace Listener
			{
				/// <summary>
				/// 有効無効を切り替えた際のイベントを受け取る
				/// </summary>
				__interface IUIChangeState : 
					public ::Utility::IUnknown
				{
					void OnActivate();
					void OnDeactivate();
				};
			}
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------