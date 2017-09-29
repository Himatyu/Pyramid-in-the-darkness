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
#include"../../Graphics.h"
#include<d3dx9.h>
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
				void SetVertex::Execute()
				{
					auto pDevice = Graphics::Instantiate().Device;
					D3DCAPS9 caps;
					pDevice->GetDeviceCaps(&caps);
					
					for (unsigned i = 0; i < caps.MaxStreams; i++)
					{
						pDevice->SetStreamSource(0, nullptr, 0, 0);
					}
				}
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------