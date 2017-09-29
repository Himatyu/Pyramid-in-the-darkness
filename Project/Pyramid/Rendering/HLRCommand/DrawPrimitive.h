/**
* @file		DrawPrimitive.h
* @brief	レンダリングコマンド
* @author	S.OIKAWA
* @date		2016.11.8
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"HLRCommandBase.h"
#include<d3dx9.h>
#include<utility>
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------
class ::Utility::CommandExecutor;
#pragma endregion

namespace Pyramid
{
	namespace Rendering
	{
		namespace HLRCommand
		{
			using DrawParam = std::tuple<D3DPRIMITIVETYPE, UINT, UINT>;
			/// <summary>
			/// レンダリングコマンド
			/// </summary>
			class DrawPrimitive final :
				public HLRCommandBase<DrawParam>
			{
			public:
#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				DrawPrimitive(DrawParam, ::Utility::CommandExecutor*);
				~DrawPrimitive() = default;

				DrawPrimitive(const DrawPrimitive&) = default;
				DrawPrimitive(DrawPrimitive&&) = default;

				DrawPrimitive& operator=(const DrawPrimitive&) = default;
				DrawPrimitive& operator=(DrawPrimitive&&) = default;
#pragma endregion

#pragma region function
				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------

				/// <summary>
				/// デバイスに送信する.
				/// </summary>
				void Execute() override;
#pragma endregion
			};
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------