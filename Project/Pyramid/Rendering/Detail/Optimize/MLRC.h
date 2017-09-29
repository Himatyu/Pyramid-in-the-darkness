/**
* @file		MLRC.h
* @brief	中間レンダリングコマンド
* @author	S.OIKAWA
* @date		2016.12.30
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"Priority.hpp"

#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Utility
{
	class Vector3;
}
namespace Pyramid
{
	namespace Rendering
	{
		namespace Detail
		{
			class OptimizationRender;
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
				/// 中間レンダリングコマンド
				/// </summary>
				class MLRC
				{
				public:
#pragma region  defaults
					//-----------------------------------------------------------
					// defaults
					//-----------------------------------------------------------
					MLRC() = default;
					MLRC(
						::Utility::Priority<UINT>,
						Detail::OptimizationRender*,
						::Utility::Vector3*);
					virtual ~MLRC() = default;

					MLRC(const MLRC&);
					MLRC(MLRC&&) = default;

					MLRC& operator=(const MLRC&) = default;
					MLRC& operator=(MLRC&&) = default;
#pragma endregion

#pragma region function
					//-----------------------------------------------------------
					// function
					//-----------------------------------------------------------
					bool operator<(const MLRC& _src) const;
					bool operator>(const MLRC& _src) const;

#pragma endregion

#pragma region property
					//-----------------------------------------------------------
					// property
					//-----------------------------------------------------------
					PROPERTY_REF(m_RenderingPriority, Priority, Utility::Priority<UINT>);
					PROPERTY_CR_R_ONLY(m_RenderingPriority, ConstPriority, Utility::Priority<UINT>);
					PROPERTY(m_RenderingTarget, pTarget, Detail::OptimizationRender*);
					PROPERTY(m_pWorldPosition, pWorldPosition, Utility::Vector3*);
					PROPERTY(m_Depth, Depth, float);

#pragma endregion
				private:
#pragma region value
					//-----------------------------------------------------------
					// val
					//-----------------------------------------------------------
					Utility::Priority<UINT>			m_RenderingPriority = 0;
					Detail::OptimizationRender*		m_RenderingTarget = nullptr;
					Utility::Vector3*				m_pWorldPosition = nullptr;//アクセス頻度を考えてポインタ
					float							m_Depth;
#pragma endregion
				};
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------