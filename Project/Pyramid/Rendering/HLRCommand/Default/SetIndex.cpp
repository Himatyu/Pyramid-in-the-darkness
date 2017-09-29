/**
* @file		SetIndex.cpp
* @brief	�f�t�H���g�C���f�b�N�X�o�b�t�@��]������
* @author	S.OIKAWA
* @date		2016.11.8
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"SetIndex.h"
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
				void SetIndex::Execute()
				{
					auto pDevice = Graphics::Instantiate().Device;
					pDevice->SetIndices(nullptr);
				}
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------