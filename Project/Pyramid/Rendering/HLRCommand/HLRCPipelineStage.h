/**
* @file		HLRCPipelineStage.h
* @brief
* @author
* @date
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------

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
			namespace Stage
			{
				/// <summary>
				/// 最低限必要なコマンドリスト
				/// </summary>
				enum HLRCPipelineStage : int
				{
					BeginScene,
					SetVertexDeclaration,
					SetVertex,
					SetIndex,
					SetMaterial,
					Draw,
					RiseMateral,
					EndScene,
					StageCount,
				};
			}
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------