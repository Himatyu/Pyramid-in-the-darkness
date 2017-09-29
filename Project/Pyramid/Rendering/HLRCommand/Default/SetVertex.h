/**
* @file		SetVertex.h
* @brief	デフォルト頂点情報をデバイスに転送する
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
				/// 空の頂点情報をデバイスに転送する
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
					/// デバイスに送信する
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