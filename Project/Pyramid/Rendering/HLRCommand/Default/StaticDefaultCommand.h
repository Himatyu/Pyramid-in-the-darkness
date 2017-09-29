/**
* @file		StaticDefaultCommand.h
* @brief	デフォルトのコマンドを所持
* @author	S.OIKAWA
* @date		2016.12.30
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"singleton.h"
#include"../HLRCPipelineStage.h"
#include<array>
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Utility
{
	class ICommand;
}

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
				/// デフォルトのコマンドを所持
				/// </summary>
				class StaticDefaultCommand:
					public Utility::Singleton<StaticDefaultCommand>
				{
					using DefaultCommandList = std::array<
						::Utility::ICommand*,
						Stage::HLRCPipelineStage::StageCount>;
				public:
#pragma region  defaults
					//-----------------------------------------------------------
					// defaults
					//-----------------------------------------------------------
					StaticDefaultCommand();
					~StaticDefaultCommand();

					StaticDefaultCommand(const StaticDefaultCommand&) = default;
					StaticDefaultCommand(StaticDefaultCommand&&) = default;

					StaticDefaultCommand& operator=(const StaticDefaultCommand&) = default;
					StaticDefaultCommand& operator=(StaticDefaultCommand&&) = default;
#pragma endregion

#pragma region function
					//-----------------------------------------------------------
					// function
					//-----------------------------------------------------------

#pragma endregion

#pragma region property
	//-----------------------------------------------------------
	// property
	//-----------------------------------------------------------
					PROPERTY_REF(m_DefaultCommands, DefaultCommands, DefaultCommandList);
#pragma endregion
				private:
#pragma region value
	//-----------------------------------------------------------
	// val
	//-----------------------------------------------------------
					
					DefaultCommandList	m_DefaultCommands;
#pragma endregion
				};
			}
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------