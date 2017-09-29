/**
* @file		BeginScene.cpp
* @brief	BeginScene‚ð”­s‚·‚é
* @author	S.OIKAWA
* @date		2016.11.10
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"BeginScene.h"
#include"../Graphics.h"
#include"CommandExecutor.h"
#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
using namespace Utility;
namespace Pyramid
{
	namespace Rendering
	{
		namespace HLRCommand
		{
			//-----------------------------------------------------------
			// ctor
			//-----------------------------------------------------------
			BeginScene::BeginScene(::Utility::CommandExecutor* _pExe) :
				HLRCommandBase(::Utility::NullType(),_pExe)
			{
			}

			//-----------------------------------------------------------
			// Execute
			//-----------------------------------------------------------
			void BeginScene::Execute()
			{
				auto pDevice = Graphics::Instantiate().Device;
				if (FAILED(pDevice->BeginScene()))
				{
					m_pOwner->Interruption();
				}
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------
