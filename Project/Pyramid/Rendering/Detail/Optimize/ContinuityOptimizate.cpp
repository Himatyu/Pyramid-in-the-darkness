/**
* @file		ContinuityOptimizate.cpp
* @brief	RenderIdÇÃòAë±ê´Ç…Ç…äÓÇ√Ç≠ç≈ìKâªÇçsÇ§
* @author	S.OIKAWA
* @date		2017.01.27
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"ContinuityOptimizate.h"
#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
using namespace Pyramid::Rendering::HLRCommand::Stage;

std::list<HLRCPipelineStage>
ConvertRangeToList(Utility::Range<HLRCPipelineStage>& _range)
{
	std::list<HLRCPipelineStage> result;

	auto it = _range.Min;
	while (it <= _range.Max)
	{
		result.push_back(it);
		it = static_cast<HLRCPipelineStage>(static_cast<int>(it) + 1);
	}
	return result;
}

namespace Pyramid
{
	namespace Rendering
	{
		namespace Detail
		{
			namespace Optimize
			{
				//-----------------------------------------------------------
				// ctor
				//-----------------------------------------------------------
				ContinuityOptimizate::ContinuityOptimizate(
					HLRCommand::HLRCommandPipeline & _refLine) :
					m_RefPipeline(_refLine),
					m_Optimizated(),
					m_IgnoreRangeHead(StageCount, StageCount),
					m_IgnoreRangeTail(StageCount, StageCount)
				{
				}


				//-----------------------------------------------------------
				// ctor
				//-----------------------------------------------------------
				ContinuityOptimizate::ContinuityOptimizate(
					const ContinuityOptimizate& _other) :
					m_RefPipeline(_other.m_RefPipeline),
					m_Optimizated(),
					m_IgnoreRangeHead(StageCount, StageCount),
					m_IgnoreRangeTail(StageCount, StageCount)
				{
				}


				//-----------------------------------------------------------
				// dtor
				//-----------------------------------------------------------
				ContinuityOptimizate::~ContinuityOptimizate()
				{
					m_Optimizated.ClearStageingCommand();
				}


				//-----------------------------------------------------------
				// Init
				//-----------------------------------------------------------
				void ContinuityOptimizate::Init()
				{
					m_Optimizated = m_RefPipeline;
				}

				//-----------------------------------------------------------
				// Execut
				//-----------------------------------------------------------
				void ContinuityOptimizate::Execut(Continuity _param)
				{
					if (m_Cache == _param)
					{
						return;
					}
					m_Cache = _param;

					m_Optimizated = m_RefPipeline;
					std::list<HLRCPipelineStage> ignoreList;

					switch (_param)
					{
					case Continuity::None:
						return;

					case Continuity::Tail:
						ignoreList = ConvertRangeToList(m_IgnoreRangeTail);
						break;

					case Continuity::Head:
						ignoreList = ConvertRangeToList(m_IgnoreRangeHead);
						break;

					case Continuity::Middle:

						for (auto& _ : m_IgnoreRangeMiddle)
						{
							Utility::Estd::combineList(ignoreList, ConvertRangeToList(_));
						}
						break;

					default:
						break;
					}

					for (auto& _ : ignoreList)
					{
						m_Optimizated.RemoveCommitedCommand(_);
					}
				}
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------