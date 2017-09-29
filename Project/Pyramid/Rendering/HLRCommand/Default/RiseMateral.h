/**
* @file		RiseMateral.h
* @brief	�f�t�H���g�}�e���A���̏���
* @author	S.OIKAWA
* @date		2016.11.15
*/
#pragma once

//-----------------------------------------------------------
// include 
//-----------------------------------------------------------
#include"ICommand.h"

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
				/// �}�e���A���̍폜���f�o�C�X�ɒʒm����
				/// </summary>
				class RiseMateral final :
					public ::Utility::ICommand
				{
				public:
#pragma region  defaults
					//-----------------------------------------------------------
					// defaults
					//-----------------------------------------------------------
					RiseMateral() = default;
					~RiseMateral() = default;

					RiseMateral(const RiseMateral&) = default;
					RiseMateral(RiseMateral&&) = default;

					RiseMateral& operator=(const RiseMateral&) = default;
					RiseMateral& operator=(RiseMateral&&) = default;
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