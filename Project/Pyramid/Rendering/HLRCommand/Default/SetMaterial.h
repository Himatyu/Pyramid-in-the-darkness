/**
* @file		SetMaterial.h
* @brief	�f�t�H���g�}�e���A�����f�o�C�X�ɑ��M����
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
				/// �}�e���A�����f�o�C�X�ɑ��M����
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
					/// �f�o�C�X�ɑ��M����
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