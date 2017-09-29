/**
* @file		SetIndex.h
* @brief	インデックスバッファを転送する
* @author	S.OIKAWA
* @date		2016.11.8
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"HLRCommandBase.h"
#include"../Buffer.h"
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
			/// <summary>
			/// インデックスバッファを転送する
			/// </summary>
			class SetIndex final :
				public HLRCommandBase<DirectXIndexBuffer*>
			{
			public:
#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				SetIndex(DirectXIndexBuffer*,
					::Utility::CommandExecutor*);
				~SetIndex() = default;

				SetIndex(const SetIndex&) = default;
				SetIndex(SetIndex&&) = default;

				SetIndex& operator=(const SetIndex&) = default;
				SetIndex& operator=(SetIndex&&) = default;
#pragma endregion

#pragma region function
				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------

				/// <summary>
				/// デバイスに送信する
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