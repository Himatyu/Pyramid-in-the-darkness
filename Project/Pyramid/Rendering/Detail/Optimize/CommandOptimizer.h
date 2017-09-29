/**
* @file		CommandOptimizer.h
* @brief	レンダリングコマンドを最適化する
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
				/// レンダリングコマンドを最適化する
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
					/// 視錐台再登録
					/// </summary>
					void Update() override {};

					/// <summary>
					/// 最適化を行う
					/// </summary>
					void RunOptimize(const Context&) override ;

				public:
					/// <summary>
					/// LODの切り替えイベントを追加する
					/// </summary>
					void AddLODSwitchEvent(SwitchEvent&);

					/// <summary>
					/// LODの切り替えイベントを削除する
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