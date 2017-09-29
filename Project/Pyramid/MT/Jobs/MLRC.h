/**
* @file		MLRC.h
* @brief	中間描画コマンド
* @author	S.OIKAWA
* @date		2016.11.23
*/
#pragma once

//-----------------------------------------------------------
//  include
//-----------------------------------------------------------
#include"Priority.hpp"
#include"../Rendering/Detail/IRenderable.h"
//-----------------------------------------------------------
// define
//-----------------------------------------------------------

namespace Planet9
{
	namespace Rendering
	{
		namespace Detail
		{
			__interface IRenderable;
		}
	}
}

namespace Planet9
{
	namespace Rendering
	{
		namespace MLRCommand
		{
			/// <summary>
			/// 中間描画コマンド
			/// </summary>
			class MLRC
			{
			public:
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				MLRC() = default;
				~MLRC() = default;

				MLRC(const MLRC&) = default;
				MLRC(MLRC&&) = default;

				MLRC& operator=(const MLRC&) = default;
				MLRC& operator=(MLRC&&) = default;

				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------
				PROPERTY_REF(m_RenderingPriority, Priority, Utility::Priority);

			private:
				Utility::Priority		m_RenderingPriority;
				Detail::IRenderable*	m_RenderTarget;
			};
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------