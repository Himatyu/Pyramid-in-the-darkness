/**
* @file		EndScene.cpp
* @brief	EndScene‚ÌƒRƒ}ƒ“ƒh‰»
* @author	S.OIKAWA
* @date		2016.11.10
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"EndScene.h"
#include"../Graphics.h"
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
			//-----------------------------------------------------------
			// ctor
			//-----------------------------------------------------------
			EndScene::EndScene(::Utility::CommandExecutor* _pExe):
				HLRCommandBase(::Utility::NullType(),_pExe)
			{
			}

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

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------