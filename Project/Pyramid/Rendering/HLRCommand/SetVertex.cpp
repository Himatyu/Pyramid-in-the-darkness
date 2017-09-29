/**
* @file		SetVertex.cpp
* @brief	頂点情報をデバイスに転送する
* @author	S.OIKAWA
* @date		2016.11.8
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"SetVertex.h"
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
			SetVertex::SetVertex(
				DirectXVertexBuffer* _pVertex,
				::Utility::CommandExecutor* _pExe):
				HLRCommandBase(_pVertex,_pExe)
			{
			}

			//-----------------------------------------------------------
			// Execute
			//-----------------------------------------------------------
			void SetVertex::Execute()
			{
				auto pDevice = Graphics::Instantiate().Device;
				pDevice->SetStreamSource(0, m_PushData->Data, 0, m_PushData->TypeSize);
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------