/**
* @file		OptimizationRender.h
* @brief	最適化後にレンダリングを行う
* @author	S.OIKAWA
* @date		2017.01.27
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"WorldObjectRender.h"
#include"Optimize/IOptimize.h"
#include"Optimize/Context.h"
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Rendering
	{
		class RenderProvider;
	}
}
#pragma endregion

namespace Pyramid
{
	namespace Rendering
	{
		namespace Detail
		{
			/// <summary>
			/// 最適化後にレンダリングを行う
			/// </summary>
			class OptimizationRender :
				public WorldObjectRender,
				public Optimize::IOptimize
			{
				friend class CommandFinalizer;
				friend class RenderProvider;
			public:
#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				OptimizationRender(HLRCommand::HLRCommandPipeline&);
				~OptimizationRender();

				OptimizationRender(const OptimizationRender&) = default;
				OptimizationRender(OptimizationRender&&) = default;

				OptimizationRender& operator=(const OptimizationRender&) = default;
				OptimizationRender& operator=(OptimizationRender&&) = default;
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

#pragma endregion
#pragma region value
				//-----------------------------------------------------------
				// val
				//-----------------------------------------------------------

#pragma endregion
			};
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------