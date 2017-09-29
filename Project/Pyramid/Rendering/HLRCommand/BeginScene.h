/**
* @file		BeginScene.h
* @brief	BeginScene�𔭍s����
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
			/// BeginScene�𔭍s����
			/// </summary>
			class BeginScene final :
				public HLRCommandBase<::Utility::NullType>
			{
			public:
#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				BeginScene(::Utility::CommandExecutor*);
				~BeginScene() = default;

				BeginScene(const BeginScene&) = default;
				BeginScene(BeginScene&&) = default;

				BeginScene& operator=(const BeginScene&) = default;
				BeginScene& operator=(BeginScene&&) = default;
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