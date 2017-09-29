/**
* @file		RiseMateral.h
* @brief	�}�e���A���̏���
* @author	S.OIKAWA
* @date		2016.11.15
*/
#pragma once

//-----------------------------------------------------------
// include 
//-----------------------------------------------------------
#include"HLRCommandBase.h"

//-----------------------------------------------------------
// define 
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Rendering
	{
		namespace Materials
		{
			class Material;
		}
	}
}
class ::Utility::CommandExecutor;
#pragma endregion

namespace Pyramid
{
	namespace Rendering
	{
		namespace HLRCommand
		{
			/// <summary>
			/// �}�e���A���̍폜���f�o�C�X�ɒʒm����
			/// </summary>
			class RiseMateral final :
				public HLRCommandBase<Materials::Material*>
			{
			public:
#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				RiseMateral(Materials::Material*, ::Utility::CommandExecutor*);
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

//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------