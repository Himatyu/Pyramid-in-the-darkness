/**
* @file		BeginScene.cpp
* @brief	デフォルトBeginSceneを発行する
* @author	S.OIKAWA
* @date		2016.11.10
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"BeginScene.h"
#include"../../Graphics.h"
#include"CommandExecutor.h"
#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Rendering
	{
		namespace HLRCommand
		{
			namespace Default
			{
				//-----------------------------------------------------------
				// Execute
				//-----------------------------------------------------------
				void BeginScene::Execute()
				{
					auto pDevice = Graphics::Instantiate().Device;
					pDevice->BeginScene();

				}
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------
