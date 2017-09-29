/**
* @file		SetMaterial.cpp
* @brief	マテリアルをデバイスに送信する
* @author	S.OIKAWA
* @date		2016.11.8
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include "..\HLRCommand\SetMaterial.h"
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
			SetMaterial::SetMaterial(Materials::Material* _pMat, 
				::Utility::CommandExecutor* _pExe):
				HLRCommandBase(_pMat,_pExe)
			{
			}

			//-----------------------------------------------------------
			// Execute
			//-----------------------------------------------------------
			void SetMaterial::Execute()
			{
				m_PushData->SetMateral();
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------
