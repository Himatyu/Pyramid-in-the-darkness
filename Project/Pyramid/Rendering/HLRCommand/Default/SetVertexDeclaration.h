/**
* @file		SetVertexDeclaration.h
* @brief	�f�t�H���g�̒��_���𑗐M����
* @author	S.OIKAWA
* @date		2016.11.8
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"ICommand.h"
#include<d3dx9.h>
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------

#pragma endregion

namespace Pyramid
{
	namespace Rendering
	{
		namespace HLRCommand
		{
			namespace Default
			{
				/// <summary>
				/// ��̒��_�����f�o�C�X�ɑ��M����@�\��
				/// </summary>
				class SetVertexDeclaration final :
					public ::Utility::ICommand
				{
				public:
#pragma region  defaults
					//-----------------------------------------------------------
					// defaults
					//-----------------------------------------------------------
					SetVertexDeclaration() = default;
					~SetVertexDeclaration() = default;

					SetVertexDeclaration(const SetVertexDeclaration&) = default;
					SetVertexDeclaration(SetVertexDeclaration&&) = default;

					SetVertexDeclaration& operator=(const SetVertexDeclaration&) = default;
					SetVertexDeclaration& operator=(SetVertexDeclaration&&) = default;
#pragma endregion

#pragma region function
					//-----------------------------------------------------------
					// function
					//-----------------------------------------------------------

					/// <summary>
					/// �f�o�C�X�ɑ��M����.
					/// </summary>
					void Execute() override;
#pragma endregion
				};
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------