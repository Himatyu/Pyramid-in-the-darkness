/**
* @file		DrawIndexedPrimitive.h
* @brief	�C���f�b�N�X�t���̃����_�����O�R�}���h
* @author	S.OIKAWA
* @date		2016.11.8
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"HLRCommandBase.h"
#include<d3dx9.h>
#include<utility>
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------
class ::Utility::CommandExecutor;
#pragma endregion
namespace Pyramid
{
	namespace Rendering
	{
		namespace HLRCommand
		{
			using DrawIndexedParam =
				std::tuple<D3DPRIMITIVETYPE,INT, UINT, UINT,UINT,UINT>;
			/// <summary>
			/// �C���f�b�N�X�t���̃����_�����O�R�}���h
			/// </summary>
			class DrawIndexedPrimitive final :
				public HLRCommandBase<DrawIndexedParam>
			{
			public:
#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				DrawIndexedPrimitive(DrawIndexedParam, ::Utility::CommandExecutor*);
				~DrawIndexedPrimitive() = default;

				DrawIndexedPrimitive(const DrawIndexedPrimitive&) = default;
				DrawIndexedPrimitive(DrawIndexedPrimitive&&) = default;

				DrawIndexedPrimitive& operator=(const DrawIndexedPrimitive&) = default;
				DrawIndexedPrimitive& operator=(DrawIndexedPrimitive&&) = default;
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
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------