/**
* @file		EndScene.h
* @brief	EndScene�̃R�}���h��
* @author	S.OIKAWA
* @date		2016.11.10
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"HLRCommandBase.h"
#include"../Utility/NullType.h"
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
			/// EndScene�̃R�}���h��
			/// </summary>
			class EndScene final :
				public HLRCommandBase<::Utility::NullType>
			{
			public:
#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				EndScene(::Utility::CommandExecutor*);
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

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------