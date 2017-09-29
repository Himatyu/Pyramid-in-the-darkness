/**
* @file		SetVertexDeclaration.cpp
* @brief	FVFをデバイスに送信する機能提供
* @author	S.OIKAWA
* @date		2016.11.8
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"SetVertexDeclaration.h"
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
				void SetVertexDeclaration::Execute()
				{
					auto pDevice = Graphics::Instantiate().Device;
					pDevice->SetFVF(DWORD{0});
					pDevice->SetVertexDeclaration(nullptr);
				}
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------