/**
* @file		SetIndex.h
* @brief	�f�t�H���g�C���f�b�N�X�o�b�t�@��]������
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
				/// ��̃C���f�b�N�X�o�b�t�@��]������
				/// </summary>
				class SetIndex final :
					public ::Utility::ICommand
				{
				public:
#pragma region  defaults
					//-----------------------------------------------------------
					// defaults
					//-----------------------------------------------------------
					SetIndex() = default;;
					~SetIndex() = default;

					SetIndex(const SetIndex&) = default;
					SetIndex(SetIndex&&) = default;

					SetIndex& operator=(const SetIndex&) = default;
					SetIndex& operator=(SetIndex&&) = default;
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