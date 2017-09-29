/**
* @file		BeginScene.h
* @brief	デフォルトBeginSceneを発行する
* @author	S.OIKAWA
* @date		2016.11.10
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"../HLRCommandBase.h"
#include"../Utility/NullType.h"
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Utility
{
	class	CommandExecutor;
}
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
				/// BeginSceneを発行する
				/// </summary>
				class BeginScene final :
					public ::Utility::ICommand
				{
				public:
#pragma region  defaults
					//-----------------------------------------------------------
					// defaults
					//-----------------------------------------------------------
					BeginScene() = default;
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
					/// デバイスに送信する
					/// </summary>
					void Execute() override;
#pragma endregion
				
#pragma region val

#pragma endregion
				};
			}
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------