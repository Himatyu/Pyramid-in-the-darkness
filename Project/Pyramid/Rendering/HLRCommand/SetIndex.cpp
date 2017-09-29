/**
* @file		SetIndex.cpp
* @brief	�C���f�b�N�X�o�b�t�@��]������
* @author	S.OIKAWA
* @date		2016.11.8
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"SetIndex.h"
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
			SetIndex::SetIndex(DirectXIndexBuffer* _pIndex,
				::Utility::CommandExecutor* _pExe):
				HLRCommandBase(_pIndex,_pExe)
			{
			}

			//-----------------------------------------------------------
			// Execute
			//-----------------------------------------------------------
			void SetIndex::Execute()
			{
				auto pDevice = Graphics::Instantiate().Device;
				pDevice->SetIndices(m_PushData->Data);
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------