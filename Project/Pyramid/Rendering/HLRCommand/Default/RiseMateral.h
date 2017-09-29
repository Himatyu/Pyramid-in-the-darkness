/**
* @file		RiseMateral.h
* @brief	デフォルトマテリアルの除去
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
				/// マテリアルの削除をデバイスに通知する
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