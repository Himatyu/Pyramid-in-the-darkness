/**
* @file		HLRCommandPipeline
* @brief	HLRC�̃X�e�[�W�ƃf�t�H���g�R�}���h���`����
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
			/// �p�C�v���C���\�z�ɕK�v�ȃR�}���h���Ǘ��E���s����.
			/// ��{�ƂȂ�R�}���h��Stageing�ɓ���Ă���
			/// �ύX����ۂ�Cimmited�𑀍삷��
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
				/// �R�}���h�𔭍s����
				/// </summary>
				template<class Command,class ...Args>
				void StageingCommand(Stage::HLRCPipelineStage _stage,Args&&... args);

				/// <summary>
				/// �R�}���h�̎�����
				/// </summary>
				void RemoveCommitedCommand(Stage::HLRCPipelineStage _stage, bool _IsRelease = false);

				/// <summary>
				/// �o�^�j��
				/// </summary>
				void RemoveCommitedCommand(Utility::ICommand* _pCmd, bool _IsRelease = false);

				/// <summary>
				/// �R�}���h�����ւ���.
				/// </summary>
				void SwapCommitedCommand(
					Stage::HLRCPipelineStage,
					Utility::ICommand*, 
					bool _IsRelease = false);

				/// <summary>
				/// �R�}���h�m��
				/// �s�������f�t�H���g�R�}���h�ŕ₤
				/// ���X�g�𒼂ɕύX���邽�߃R�}���h�C�e���[�V�������͎g��Ȃ�����
				/// </summary>
				void CommitCommandImmediate();

				/// <summary>
				/// �R�}���h�����s����
				/// </summary>
				void Run();

				/// <summary>
				/// �R�}���h�̒��o
				/// </summary>
				template<class Cmd>
				std::vector<Cmd*> SelectToCommitedCommand();

				/// <summary>
				/// Stageing�R�}���h��Commited�ɃR�s�[����
				/// </summary>
				void Restore();
			
				/// <summary>
				/// �R�}���h���N���A����
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