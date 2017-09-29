/**
* @file		EndScene.cpp
* @brief	デフォルトEndSceneのコマンド化
* @author	S.OIKAWA
* @date		2016.11.10
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"EndScene.h"
#include"../../Graphics.h"
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
				void EndScene::Execute()
				{
					auto pDevice = Graphics::Instantiate().Device;
					pDevice->EndScene();
				}
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------