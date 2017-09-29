/**
* @file		DrawIndexedPrimitive.h
* @brief	インデックス付きのレンダリングコマンド
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
			using DrawIndexedParam =
				std::tuple<D3DPRIMITIVETYPE,INT, UINT, UINT,UINT,UINT>;
			/// <summary>
			/// インデックス付きのレンダリングコマンド
			/// </summary>
			class DrawIndexedPrimitive final :
				public HLRCommandBase<DrawIndexedParam>
			{
			public:
#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				DrawIndexedPrimitive(DrawIndexedParam, ::Utility::CommandExecutor*);
				~DrawIndexedPrimitive() = default;

				DrawIndexedPrimitive(const DrawIndexedPrimitive&) = default;
				DrawIndexedPrimitive(DrawIndexedPrimitive&&) = default;

				DrawIndexedPrimitive& operator=(const DrawIndexedPrimitive&) = default;
				DrawIndexedPrimitive& operator=(DrawIndexedPrimitive&&) = default;
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