/**
* @file		HLRCommandPipeline.inl
* @brief	HLRC�̃X�e�[�W�ƃf�t�H���g�R�}���h���`����
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
/// �R�}���h�ǉ�
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
		auto pCasted = dynamic_cast<Cmd*>(_);	//HACK ���ꂵ���v�����Ȃ�����

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