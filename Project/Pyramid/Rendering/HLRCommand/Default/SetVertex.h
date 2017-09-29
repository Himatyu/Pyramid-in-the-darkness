/**
* @file		SetVertex.h
* @brief	�f�t�H���g���_�����f�o�C�X�ɓ]������
* @author	S.OIKAWA
* @date		2016.11.8
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"ICommand.h"
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
				/// ��̒��_�����f�o�C�X�ɓ]������
				/// </summary>
				class SetVertex final :
					public ::Utility::ICommand
				{
				public:
#pragma region  defaults
					//-----------------------------------------------------------
					// defaults
					//-----------------------------------------------------------
					SetVertex() = default;
					~SetVertex() = default;

					SetVertex(const SetVertex&) = default;
					SetVertex(SetVertex&&) = default;

					SetVertex& operator=(const SetVertex&) = default;
					SetVertex& operator=(SetVertex&&) = default;
#pragma endregion

#pragma region function
					//-----------------------------------------------------------
					// function
					//-----------------------------------------------------------

					/// <summary>
					/// �f�o�C�X�ɑ��M����
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