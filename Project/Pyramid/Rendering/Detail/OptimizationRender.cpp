/**
* @file		OptimizationRender.cpp
* @brief	LODの切り替えと連続性からなる最適化を行う
* @author	S.OIKAWA
* @date		2017.01.27
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"OptimizationRender.h"

#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Rendering
	{
		namespace Detail
		{
			//-----------------------------------------------------------
			// ctor
			//-----------------------------------------------------------
			OptimizationRender::OptimizationRender(
				HLRCommand::HLRCommandPipeline& _line):
				WorldObjectRender(_line)
			{
			}

			//-----------------------------------------------------------
			// dtor
			//-----------------------------------------------------------
			OptimizationRender::~OptimizationRender()
			{
			}

		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------