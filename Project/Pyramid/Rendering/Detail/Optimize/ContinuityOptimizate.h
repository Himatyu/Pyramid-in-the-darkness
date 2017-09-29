/**
* @file		ContinuityOptimizate.h
* @brief	RenderId�̘A�����ɂɊ�Â��œK�����s��
* @author	S.OIKAWA
* @date		2017.01.27
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"Range.h"
#include"Continuity.h"
#include"../../HLRCommand/HLRCPipelineStage.h"
#include"../../HLRCommand/HLRCommandPipeline.h"
#include<list>
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
				/// RenderId�̘A�����ɂɊ�Â��œK�����s��
				/// </summary>
				class ContinuityOptimizate
				{
				public:
					
#pragma region  defaults
					//-----------------------------------------------------------
					// defaults
					//-----------------------------------------------------------
					ContinuityOptimizate(HLRCommand::HLRCommandPipeline&);
					virtual ~ContinuityOptimizate();

					ContinuityOptimizate(const ContinuityOptimizate&);
					ContinuityOptimizate(ContinuityOptimizate&&) = default;

					ContinuityOptimizate& operator=(const ContinuityOptimizate&) = default;
					ContinuityOptimizate& operator=(ContinuityOptimizate&&) = default;
#pragma endregion

#pragma region function
					//-----------------------------------------------------------
					// function
					//-----------------------------------------------------------

					/// <summary>
					/// �p�C�v���C��������������
					/// </summary>
					void Init();

					/// <summary>
					/// �œK�����s��
					/// </summary>
					void Execut(Continuity _param);
#pragma endregion

#pragma region property
					//-----------------------------------------------------------
					// property
					//-----------------------------------------------------------
					PROPERTY_REF(
						m_IgnoreRangeHead,
						IgnoreRangeHead,
						Utility::Range<HLRCommand::Stage::HLRCPipelineStage>);

					PROPERTY_REF(
						m_IgnoreRangeMiddle,
						IgnoreRangeMiddleRangeList,
						std::list<Utility::Range<HLRCommand::Stage::HLRCPipelineStage>>);

					PROPERTY_REF(
						m_IgnoreRangeTail,
						IgnoreRangeTail,
						Utility::Range<HLRCommand::Stage::HLRCPipelineStage>);

					PROPERTY_REF_R_ONLY(
						m_Optimizated,
						Optimizated,
						HLRCommand::HLRCommandPipeline);
#pragma endregion
				private:
#pragma region value
					//-----------------------------------------------------------
					// val
					//-----------------------------------------------------------
					HLRCommand::HLRCommandPipeline&										m_RefPipeline;
					HLRCommand::HLRCommandPipeline										m_Optimizated;
					Utility::Range<HLRCommand::Stage::HLRCPipelineStage>				m_IgnoreRangeHead;
					std::list<Utility::Range<HLRCommand::Stage::HLRCPipelineStage>>		m_IgnoreRangeMiddle;
					Utility::Range<HLRCommand::Stage::HLRCPipelineStage>				m_IgnoreRangeTail;
					Continuity															m_Cache;

#pragma endregion
				};
			}
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------