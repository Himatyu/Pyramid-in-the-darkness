/**
* @file		IOptimize.h
* @brief	最適化インターフェース
* @author	S.OIKAWA
* @date		2017.03.28
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------

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
				class Context;
			}
		}
	}
}
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
				/// 最適化インターフェース
				/// </summary>
				class IOptimize
				{
				public:
#pragma region  defaults
					//-----------------------------------------------------------
					// defaults
					//-----------------------------------------------------------
					IOptimize() = default;
					virtual ~IOptimize() = default;

					IOptimize(const IOptimize&) = default;
					IOptimize(IOptimize&&) = default;

					IOptimize& operator=(const IOptimize&) = default;
					IOptimize& operator=(IOptimize&&) = default;
#pragma endregion

#pragma region function
					//-----------------------------------------------------------
					// function
					//-----------------------------------------------------------
					virtual void PrepareToOptimize() = 0 {};			//フレームごとの呼び出し前提
					virtual void Optimize(const Context&) = 0 {};
#pragma endregion

#pragma region property
					//-----------------------------------------------------------
					// property
					//-----------------------------------------------------------
					PROPERTY(m_RenderID, RenderID,unsigned);
#pragma endregion
				protected:
#pragma region value
					//-----------------------------------------------------------
					// val
					//-----------------------------------------------------------
					unsigned	m_RenderID;
#pragma endregion
				};
			}
		}
	}
}


//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------