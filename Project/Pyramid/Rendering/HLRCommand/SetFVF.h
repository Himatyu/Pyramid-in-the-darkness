/**
* @file		SetFVF.h
* @brief	FVFをデバイスに送信する機能提供
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
			/// FVFをデバイスに送信する機能提供
			/// </summary>
			class SetFVF final :
				public HLRCommandBase<DWORD>
			{
			public:
#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				SetFVF(DWORD, ::Utility::CommandExecutor*);
				~SetFVF() = default;

				SetFVF(const SetFVF&) = default;
				SetFVF(SetFVF&&) = default;

				SetFVF& operator=(const SetFVF&) = default;
				SetFVF& operator=(SetFVF&&) = default;
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