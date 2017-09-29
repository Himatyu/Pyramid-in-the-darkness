/**
* @file		IRenderable.h
* @brief	レンダリング可能なインターフェース提供
* @author	S.OIKAWA
* @date		2016.11.4
*/
#pragma once

namespace Pyramid
{
	namespace Rendering
	{
		namespace Detail
		{
			/// <summary>
			/// レンダリング可能にするインターフェース
			/// </summary>
			__interface IRenderable
			{
				void PrepareToRendering();
				void Rendering();
			};
		}
	}
}
//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------