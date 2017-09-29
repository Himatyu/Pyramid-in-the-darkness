/**
* @file		SetMaterial.h
* @brief	�}�e���A�����f�o�C�X�ɑ��M����
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
			/// �}�e���A�����f�o�C�X�ɑ��M����
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
				/// �f�o�C�X�ɑ��M����
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