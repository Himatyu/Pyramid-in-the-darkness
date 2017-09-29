/**
* @file		SetDeclaration.cpp
* @brief	���_�錾���f�o�C�X�ɑ��M����@�\��
* @author	S.OIKAWA
* @date		2016.11.8
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"SetDeclaration.h"
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
			SetDeclaration::SetDeclaration(
				LPDIRECT3DVERTEXDECLARATION9 _pDec,
				::Utility::CommandExecutor* _pExe):
				HLRCommandBase(_pDec,_pExe)
			{
			}

			//-----------------------------------------------------------
			// Execute
			//-----------------------------------------------------------
			void SetDeclaration::Execute()
			{
				auto pDevice = Graphics::Instantiate().Device;
				pDevice->SetVertexDeclaration(m_PushData);
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------