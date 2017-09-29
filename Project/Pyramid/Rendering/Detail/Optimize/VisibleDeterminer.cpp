/**
* @file		VisibleDeterminer.cpp
* @brief	オブジェクト単位の可視決定を行う
* @author	S.OIKAWA
* @date		2016.12.30
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"VisibleDeterminer.h"
#include"../Frustum.h"
#include"../../Constant.h"
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
				VisibleDeterminer::VisibleDeterminer(Common::WorldVolume& _vol)
					:m_RenderVolume(_vol)
				{
				}

				//-----------------------------------------------------------
				// ctor
				//-----------------------------------------------------------
				VisibleDeterminer::
					VisibleDeterminer(const VisibleDeterminer& _other)
					:m_RenderVolume(_other.m_RenderVolume)
				{
				}				

				//-----------------------------------------------------------
				// IsInSideFrustum
				//-----------------------------------------------------------
				bool VisibleDeterminer::IsInSideFrustum(Frustum & _frustum)
				{
					for (auto& plane : _frustum.Planes)
					{
						auto& normal = plane.Normal;
						auto& nPos = m_RenderVolume.Volume.GetNearByNormal(normal);
						auto& fPos = m_RenderVolume.Volume.GetFarByNormal(normal);

						auto nResult = _frustum.CheckOutSide(*m_RenderVolume.pPosition + nPos);
						auto fResult = _frustum.CheckOutSide(*m_RenderVolume.pPosition + fPos);
						if (nResult&&fResult)
						{
							return false;
						}
					}
					return true;
				}
			}
		}
	}
}


//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------