/**
* @file		SetDeclaration.h
* @brief	頂点宣言をデバイスに送信する機能提供
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
			/// 頂点宣言をデバイスに送信する機能提供
			/// </summary>
			class SetDeclaration final :
				public HLRCommandBase<LPDIRECT3DVERTEXDECLARATION9>
			{
			public:
#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				SetDeclaration(LPDIRECT3DVERTEXDECLARATION9,
					::Utility::CommandExecutor*);
				~SetDeclaration() = default;

				SetDeclaration(const SetDeclaration&) = default;
				SetDeclaration(SetDeclaration&&) = default;

				SetDeclaration& operator=(const SetDeclaration&) = default;
				SetDeclaration& operator=(SetDeclaration&&) = default;
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