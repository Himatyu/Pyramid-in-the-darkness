/**
* @file		HLRCommandPipeline
* @brief	HLRCのステージとデフォルトコマンドを定義する
* @author	S.OIKAWA
* @date		2016.11.16
*/
#pragma once

//-----------------------------------------------------------
// include 
//-----------------------------------------------------------
#include"CommandListener.h"
#include"CommandExecutor.h"
#include"HLRCPipelineStage.h"
#include<vector>
#include<array>
//-----------------------------------------------------------
// define 
//-----------------------------------------------------------
class ::Utility::ICommand;

namespace Pyramid
{
	namespace Rendering
	{
		namespace HLRCommand
		{
			/// <summary>
			/// パイプライン構築に必要なコマンドを管理・実行する.
			/// 基本となるコマンドをStageingに入れておき
			/// 変更する際はCimmitedを操作する
			/// </summary>
			class HLRCommandPipeline :
				public ::Utility::CommandListener,
				private ::Utility::CommandExecutor
			{
			public:
				//-----------------------------------------------------------
				// defaluts
				//-----------------------------------------------------------
				HLRCommandPipeline();
				virtual ~HLRCommandPipeline();
				
				HLRCommandPipeline(const HLRCommandPipeline&) = default;
				HLRCommandPipeline(HLRCommandPipeline&&) = default;

				HLRCommandPipeline& operator=(const HLRCommandPipeline&);
				HLRCommandPipeline&operator=(HLRCommandPipeline&&) = default;

				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------

				/// <summary>
				/// コマンドを発行する
				/// </summary>
				template<class Command,class ...Args>
				void StageingCommand(Stage::HLRCPipelineStage _stage,Args&&... args);

				/// <summary>
				/// コマンドの取り消し
				/// </summary>
				void RemoveCommitedCommand(Stage::HLRCPipelineStage _stage, bool _IsRelease = false);

				/// <summary>
				/// 登録破棄
				/// </summary>
				void RemoveCommitedCommand(Utility::ICommand* _pCmd, bool _IsRelease = false);

				/// <summary>
				/// コマンドを入れ替える.
				/// </summary>
				void SwapCommitedCommand(
					Stage::HLRCPipelineStage,
					Utility::ICommand*, 
					bool _IsRelease = false);

				/// <summary>
				/// コマンド確定
				/// 不足分をデフォルトコマンドで補う
				/// リストを直に変更するためコマンドイテレーション中は使わないこと
				/// </summary>
				void CommitCommandImmediate();

				/// <summary>
				/// コマンドを実行する
				/// </summary>
				void Run();

				/// <summary>
				/// コマンドの抽出
				/// </summary>
				template<class Cmd>
				std::vector<Cmd*> SelectToCommitedCommand();

				/// <summary>
				/// StageingコマンドをCommitedにコピーする
				/// </summary>
				void Restore();
			
				/// <summary>
				/// コマンドをクリアする
				/// </summary>
				void ClearStageingCommand();

			private:
				std::vector<::Utility::ICommand*>::iterator FindInsertItForStageing(Stage::HLRCPipelineStage);
				std::vector<::Utility::ICommand**> FindCommitedCommandWithStage(Stage::HLRCPipelineStage);

				//-----------------------------------------------------------
				// val
				//-----------------------------------------------------------
			private:
				Stage::HLRCPipelineStage					m_Stage;
				std::vector<::Utility::ICommand*>	m_StageingCommand;

			};
#include"HLRCommandPipeline.inl"
		}
	}
}
//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------