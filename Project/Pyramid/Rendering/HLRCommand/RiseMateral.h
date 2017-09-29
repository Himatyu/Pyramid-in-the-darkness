/**
* @file		RiseMateral.h
* @brief	マテリアルの除去
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
			/// マテリアルの削除をデバイスに通知する
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
				/// デバイスに送信する
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