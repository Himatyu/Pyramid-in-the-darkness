/**
* @file		HLRCommandPipeline.cpp
* @brief	HLRCのステージとデフォルトコマンドを定義する
* @author	S.OIKAWA
* @date		2016.11.16
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"HLRCommandPipeline.h"
#include"../Utility/ICommand.h"
#include"Estd.h"
#include"Default/StaticDefaultCommand.h"
#include<array>
#include<algorithm>
#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------

namespace Pyramid
{
	namespace Rendering
	{
		namespace HLRCommand
		{
			//-----------------------------------------------------------
			// ctor
			//-----------------------------------------------------------
			HLRCommandPipeline::HLRCommandPipeline() :
				CommandListener(),
				CommandExecutor(this),
				m_StageingCommand{ Stage::StageCount,nullptr }
			{				
			}
			//-----------------------------------------------------------
			// dtor
			//-----------------------------------------------------------
			HLRCommandPipeline::~HLRCommandPipeline()
			{
				CommandApply();
				auto& staticCommand =
					Default::StaticDefaultCommand::Instantiate();
				// HACK もっとスマートにできそう
				for (auto& _ : m_StageingCommand)
				{
					if (Utility::Estd::any_of(
						staticCommand.DefaultCommands,
						[_](auto it) {return _ == it; }))
					{
						continue;
					}
					SAFE_DELETE(_);
				}
			}

			//-----------------------------------------------------------
			// RemoveCommitedCommand
			//-----------------------------------------------------------
			void HLRCommandPipeline::RemoveCommitedCommand(Utility::ICommand * _pCmd, bool _IsRelease)
			{
				for (auto& _ : m_CommandList.Vector)
				{
					if (_ == _pCmd)
					{
						m_CommandList.RemoveRequest(_pCmd);
					}
				}
				if (_IsRelease)
				{
					SAFE_DELETE(_pCmd);
				}

			}

			//-----------------------------------------------------------
			// RemoveCommitedCommand
			//-----------------------------------------------------------
			void HLRCommandPipeline::RemoveCommitedCommand(
				Stage::HLRCPipelineStage _stage,
				bool _IsRelease)
			{
				auto removeList = FindCommitedCommandWithStage(_stage);
				for (auto& _ : removeList)
				{
					CommandListener::RemoveCommand(*_);
				}

				if (!_IsRelease)
				{
					return;
				}
				Utility::Estd::for_each(removeList, [&](auto _) {SAFE_DELETE(_); });

			}

			//-----------------------------------------------------------
			// SwapCommitedCommand
			//-----------------------------------------------------------
			void HLRCommandPipeline::SwapCommitedCommand(
				Stage::HLRCPipelineStage _stage,
				Utility::ICommand * _pCmd,
				bool _isRelease)
			{
				auto list = FindCommitedCommandWithStage(_stage);
				
				if (_isRelease)
				{
					Utility::Estd::for_each(list, [&](auto _) {SAFE_DELETE(_); });
				}

				for (auto& _ : list)
				{
					*_ = _pCmd;
				}
	
			}

			//-----------------------------------------------------------
			// CommandApplay
			//-----------------------------------------------------------
			void HLRCommandPipeline::CommitCommandImmediate()
			{
				auto listSize = m_StageingCommand.size();
				auto& staticCommand = Default::StaticDefaultCommand::Instantiate();
				for (unsigned i = 0; i < listSize; i++)
				{
					if (nullptr != m_StageingCommand[i])
					{
						continue;
					}
					auto CommandIndex =
						static_cast<Stage::HLRCPipelineStage>(i % Stage::StageCount);
					m_StageingCommand[i] = staticCommand.DefaultCommands[CommandIndex];
				}

				m_CommandList.Vector = m_StageingCommand;
			}

			//-----------------------------------------------------------
			// Run
			//-----------------------------------------------------------
			void HLRCommandPipeline::Run()
			{
				CommandExecutor::Run();
			}


			//-----------------------------------------------------------
			// Restore
			//-----------------------------------------------------------
			void HLRCommandPipeline::Restore()
			{
				m_CommandList.Vector = m_StageingCommand;
			}

			//-----------------------------------------------------------
			// ClearStageingCommand
			//-----------------------------------------------------------
			void HLRCommandPipeline::ClearStageingCommand()
			{
				m_StageingCommand.clear();
			}

			//-----------------------------------------------------------
			// FindInsertIt
			//-----------------------------------------------------------
			std::vector<::Utility::ICommand*>::iterator 
				HLRCommandPipeline::FindInsertItForStageing(Stage::HLRCPipelineStage _stage)
			{
				int backOffset = (Stage::StageCount - _stage);
				auto insertIt =
					m_StageingCommand.begin() + m_StageingCommand.size() - backOffset;
				while (*insertIt != nullptr)
				{
					auto newSize =
						m_StageingCommand.size() + Stage::StageCount;
					m_StageingCommand.resize(newSize, nullptr);

					auto offset = newSize - backOffset;
					insertIt = m_StageingCommand.begin() + offset;
				}
				return insertIt;
			}

			//-----------------------------------------------------------
			// FindCommandWithStage
			//-----------------------------------------------------------
			std::vector<::Utility::ICommand**> 
				HLRCommandPipeline::FindCommitedCommandWithStage(Stage::HLRCPipelineStage _stage)
			{
				unsigned offset = _stage;
				std::vector<Utility::ICommand**> resultList;
				while (offset < m_CommandList.Vector.size())
				{
					auto it = m_CommandList.Vector.begin() + offset;
					resultList.push_back(&*it);
					offset += Stage::StageCount;
				}
				return resultList;
			}

			//-----------------------------------------------------------
			// operator=(HLRCommandPipeline&)
			//-----------------------------------------------------------
			HLRCommandPipeline& 
				HLRCommandPipeline::operator=(const HLRCommandPipeline& _other)
			{
				m_StageingCommand = _other.m_StageingCommand;
				m_CommandList = _other.m_CommandList;
				return *this;
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------