/**
* @file		EndScene.h
* @brief	EndSceneのコマンド化
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
			/// EndSceneのコマンド化
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
				/// デバイスに送信する
				/// </summary>
				void Execute() override;
			};
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------