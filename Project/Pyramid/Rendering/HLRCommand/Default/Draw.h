/**
* @file		PreDraw.h
* @brief	デフォルトレンダリングコマンド
* @author	S.OIKAWA
* @date		2016.11.8
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"ICommand.h"
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------
#pragma endregion

namespace Pyramid
{
	namespace Rendering
	{
		namespace HLRCommand
		{
			namespace Default
			{
				/// <summary>
				/// デフォルトレンダリングコマンド
				/// </summary>
				class Draw final :
					public ::Utility::ICommand
				{
				public:
#pragma region  defaults
					//-----------------------------------------------------------
					// defaults
					//-----------------------------------------------------------
					Draw() = default;
					~Draw() = default;

					Draw(const Draw&) = default;
					Draw(Draw&&) = default;

					Draw& operator=(const Draw&) = default;
					Draw& operator=(Draw&&) = default;
#pragma endregion

#pragma region function
					//-----------------------------------------------------------
					// function
					//-----------------------------------------------------------

					/// <summary>
					/// 何もレンダリングしない.
					/// </summary>
					void Execute() override;
#pragma endregion
				};
			}
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------