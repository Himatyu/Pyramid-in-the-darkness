/**
* @file		SetVertex.h
* @brief	���_�����f�o�C�X�ɓ]������
* @author	S.OIKAWA
* @date		2016.11.8
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"HLRCommandBase.h"
#include"../Buffer.h"
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
			/// <summary>
			/// ���_�����f�o�C�X�ɓ]������
			/// </summary>
			class SetVertex final :
				public HLRCommandBase<DirectXVertexBuffer*>
			{
			public:
#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				SetVertex(DirectXVertexBuffer*, ::Utility::CommandExecutor*);
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

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------