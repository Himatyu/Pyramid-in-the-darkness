/**
* @file		MLRC.cpp
* @brief	中間レンダリングコマンド
* @author	S.OIKAWA
* @date		2016.12.30
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"MLRC.h"
#include"../OptimizationRender.h"

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
			namespace Optimize
			{
				//-----------------------------------------------------------
				// ctor
				//-----------------------------------------------------------
				MLRC::MLRC(
					Utility::Priority<UINT> _priority,
					OptimizationRender * _pTarget,
					Utility::Vector3* _pPositions) :
					m_RenderingPriority(_priority),
					m_RenderingTarget(_pTarget),
					m_pWorldPosition(_pPositions)
				{
				}

				//-----------------------------------------------------------
				// ctor
				//-----------------------------------------------------------
				MLRC::MLRC(const MLRC& _mlrc):
					m_RenderingPriority(_mlrc.m_RenderingPriority),
					m_RenderingTarget(_mlrc.m_RenderingTarget),
					m_pWorldPosition(_mlrc.m_pWorldPosition)
				{
				}
				

				//-----------------------------------------------------------
				// operator<
				//-----------------------------------------------------------
				bool MLRC::operator<(const MLRC & _src) const
				{
					return(m_RenderingPriority < _src.ConstPriority);
				}

				//-----------------------------------------------------------
				// operator>
				//-----------------------------------------------------------
				bool MLRC::operator>(const MLRC & _src) const
				{
					return(m_RenderingPriority > _src.ConstPriority);
				}
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------


