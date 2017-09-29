/**
* @file		Defines.h
* @brief	Rendering‚Ì’è‹`
* @author	S.OIKAWA
* @date		2017.03.31
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"InterfaceCoordinator.h"
#include"Detail/Optimize/ObjectOptimizer.h"
#include"Detail/Optimize/CommandOptimizer.h"
#include"Detail/Optimize/IOptimizer.h"
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Rendering
	{
		namespace Detail
		{
			namespace Optimize
			{
				using OptimizeCommandOnly = 
					Utility::InterfaceCoordinator<
					IOptimizer,
					CommandOptimizer>;

				using OptimizeObjectOnly =
					Utility::InterfaceCoordinator<
					IOptimizer,
					ObjectOptimizer>;

				using OptimizeCommandAndObject =
					Utility::InterfaceCoordinator<
					IOptimizer,
					ObjectOptimizer,
					CommandOptimizer>;
			}
		}
	}
}
#pragma endregion

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------