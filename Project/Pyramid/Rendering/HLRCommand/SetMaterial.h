/**
* @file		SetMaterial.h
* @brief	マテリアルをデバイスに送信する
* @author	S.OIKAWA
* @date		2016.11.8
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"HLRCommandBase.h"
#include"../Rendering/Materials/Material.h"
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
			/// マテリアルをデバイスに送信する
			/// </summary>
			class SetMaterial final :
				public HLRCommandBase<Materials::Material*>
			{
			public:
#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				SetMaterial(Materials::Material*, ::Utility::CommandExecutor*);
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

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------