/**
* @file		SetFVF.cpp
* @brief	FVFをデバイスに送信する機能提供
* @author	S.OIKAWA
* @date		2016.11.8
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"SetFVF.h"
#include"../Graphics.h"
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
			SetFVF::SetFVF(DWORD _fvf,
				::Utility::CommandExecutor* _pExe):
				HLRCommandBase(_fvf,_pExe)
			{
			}

			//-----------------------------------------------------------
			// Execute
			//-----------------------------------------------------------
			void SetFVF::Execute()
			{
				auto pDevice = Graphics::Instantiate().Device;
				pDevice->SetFVF(m_PushData);
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------