/**
* @file		SetMaterial.h
* @brief	デフォルトマテリアルをデバイスに送信する
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
				/// マテリアルをデバイスに送信する
				/// </summary>
				class SetMaterial final :
					public ::Utility::ICommand
				{
				public:
#pragma region  defaults
					//-----------------------------------------------------------
					// defaults
					//-----------------------------------------------------------
					SetMaterial() = default;
					~SetMaterial() = default;

					SetMaterial(const SetMaterial&) = default;
					SetMaterial(SetMaterial&&) = default;

					SetMaterial& operator=(const SetMaterial&) = default;
					SetMaterial& operator=(SetMaterial&&) = default;
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