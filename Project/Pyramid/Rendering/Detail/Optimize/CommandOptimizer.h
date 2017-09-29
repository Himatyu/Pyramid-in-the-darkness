/**
* @file		CommandOptimizer.h
* @brief	�����_�����O�R�}���h���œK������
* @author	S.OIKAWA
* @date		2017.03.24
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"ContinuityOptimizate.h"
#include"LODSwitcher.h"
#include"IOptimizer.h"
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
		namespace Detail
		{
			namespace Optimize
			{
				/// <summary>
				/// �����_�����O�R�}���h���œK������
				/// </summary>
				class CommandOptimizer :
					public IOptimizer
				{
				public:
#pragma region  defaults
					//-----------------------------------------------------------
					// defaults
					//-----------------------------------------------------------
					CommandOptimizer(HLRCommand::HLRCommandPipeline&, Common::WorldVolume&);
					virtual ~CommandOptimizer() = default;

					CommandOptimizer(const CommandOptimizer&);
					CommandOptimizer(CommandOptimizer&&) = default;

					CommandOptimizer& operator=(const CommandOptimizer&) = default;
					CommandOptimizer& operator=(CommandOptimizer&&) = default;
#pragma endregion

#pragma region function
					//-----------------------------------------------------------
					// function
					//-----------------------------------------------------------		
				protected:

					/// <summary>
					/// 
					/// </summary>
					void Init() override ;

					/// <summary>
					/// ������ēo�^
					/// </summary>
					void Update() override {};

					/// <summary>
					/// �œK�����s��
					/// </summary>
					void RunOptimize(const Context&) override ;

				public:
					/// <summary>
					/// LOD�̐؂�ւ��C�x���g��ǉ�����
					/// </summary>
					void AddLODSwitchEvent(SwitchEvent&);

					/// <summary>
					/// LOD�̐؂�ւ��C�x���g���폜����
					/// </summary>
					void RemoveLODSwitchEvent(SwitchEvent&);

#pragma endregion

#pragma region property
				//-----------------------------------------------------------
				// property
				//-----------------------------------------------------------
					PROPERTY_R_ONLY(m_Switcher.DistanceToCamera, DistanceToCamera,float);

					PROPERTY_REF(
						m_Optimizate.IgnoreRangeHead,
						IgnoreRangeHead,
						Utility::Range<HLRCommand::Stage::HLRCPipelineStage>);

					PROPERTY_REF(
						m_Optimizate.IgnoreRangeMiddleRangeList,
						IgnoreRangeMiddleRangeList,
						std::list<Utility::Range<HLRCommand::Stage::HLRCPipelineStage>>);

					PROPERTY_REF(
						m_Optimizate.IgnoreRangeTail,
						IgnoreRangeTail,
						Utility::Range<HLRCommand::Stage::HLRCPipelineStage>);


					PROPERTY_REF_R_ONLY(
						m_Optimizate.Optimizated,
						Optimizated,
						HLRCommand::HLRCommandPipeline);

#pragma endregion
				private:
#pragma region value
				//-----------------------------------------------------------
				// val
				//-----------------------------------------------------------
					LODSwitcher					m_Switcher;
					ContinuityOptimizate		m_Optimizate;

#pragma endregion
				};
			}
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------