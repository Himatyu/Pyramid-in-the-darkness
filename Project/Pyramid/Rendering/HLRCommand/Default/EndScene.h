/**
* @file		EndScene.h
* @brief	�f�t�H���gEndScene�̃R�}���h��
* @author	S.OIKAWA
* @date		2016.11.10
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
				/// EndScene�̃R�}���h��
				/// </summary>
				class EndScene final :
					public ::Utility::ICommand
				{
				public:
#pragma region  defaults
					//-----------------------------------------------------------
					// defaults
					//-----------------------------------------------------------
					EndScene() = default;
					~EndScene() = default;

					EndScene(const EndScene&) = default;
					EndScene(EndScene&&) = default;

					EndScene& operator=(const EndScene&) = default;
					EndScene& operator=(EndScene&&) = default;
#pragma endregion

#pragma region function
					//-----------------------------------------------------------
					// function
					//-----------------------------------------------------------

					/// <summary>
					/// �f�o�C�X�ɑ��M����
					/// </summary>
					void Execute() override;
				};
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------