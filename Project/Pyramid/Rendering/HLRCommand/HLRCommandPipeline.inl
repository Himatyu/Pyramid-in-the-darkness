/**
* @file		HLRCommandPipeline.inl
* @brief	HLRCのステージとデフォルトコマンドを定義する
* @author	S.OIKAWA
* @date		2016.11.16
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"HLRCommandPipeline.h"
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------

#pragma endregion

/// <summary>
/// コマンド追加
/// </summary>
template<class Command, class ...Args>
inline 
void HLRCommandPipeline::
StageingCommand(
	Stage::HLRCPipelineStage _stage, 
	Args && ...args)
{
	auto insertIt = FindInsertItForStageing(_stage);
	*insertIt = 
		static_cast<::Utility::ICommand*>(new Command(args...));
}

//-----------------------------------------------------------
// Select
//-----------------------------------------------------------
template<class Cmd>
inline 
std::vector<Cmd*> 
HLRCommandPipeline::SelectToCommitedCommand()
{
	std::vector<Cmd*> result;	

	for (auto& _ : m_CommandList.Vector)
	{
		auto pCasted = dynamic_cast<Cmd*>(_);	//HACK これしか思いつかなかった

		if (!pCasted)
		{
			continue;
		}
		result.push_back(pCasted);
	}
		
	return std::move(result);
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------