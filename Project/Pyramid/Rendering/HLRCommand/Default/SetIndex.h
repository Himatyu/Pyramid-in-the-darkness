/**
* @file		SetIndex.h
* @brief	デフォルトインデックスバッファを転送する
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
				/// 空のインデックスバッファを転送する
				/// </summary>
				class SetIndex final :
					public ::Utility::ICommand
				{
				public:
#pragma region  defaults
					//-----------------------------------------------------------
					// defaults
					//-----------------------------------------------------------
					SetIndex() = default;;
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
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------