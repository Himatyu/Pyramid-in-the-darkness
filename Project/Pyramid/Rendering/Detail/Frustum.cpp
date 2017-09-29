/**
* @file		Frustum.cpp
* @brief	視錐体
* @author	S.OIKAWA
* @date		2016.12.30
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"Frustum.h"
#include"../Viewer.h"
#include"../Common/WorldSpaceDivider.h"
#include"Vector3.h"
#include<cmath>
#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
using namespace Utility;
using namespace Pyramid;
namespace 
{

}


namespace Pyramid
{
	namespace Rendering
	{
		namespace Detail
		{			
			//-----------------------------------------------------------
			// ctor
			//-----------------------------------------------------------
			Frustum::Frustum(Viewer& _viewer):
				m_Viewer(_viewer),
				JudgmentSameSpaceOfFrustum(m_WorldVolume)
			{
				m_WorldVolume.pPosition = &m_Center;
				Common::WorldSpaceDivider::Instantiate().Register(*this);
			}

			//-----------------------------------------------------------
			// ctor
			//-----------------------------------------------------------
			Frustum::~Frustum()
			{
				Common::WorldSpaceDivider::Instantiate().UnRegister(*this);

			}

			//-----------------------------------------------------------
			// =
			//-----------------------------------------------------------
			Frustum & Frustum::operator=(const Frustum & _other)
			{
				m_Viewer = _other.m_Viewer;
				m_Planes = _other.m_Planes;
				return *this;
			}

			//-----------------------------------------------------------
			// CheckOutSide
			//-----------------------------------------------------------
			bool Frustum::CheckOutSide(const Utility::Vector3& _position)
			{
				for (auto& _ : m_Planes)
				{
					auto result = 
						(_.DecisionPositionRelationship(_position));
					if(Common::Diagram::ResultRelationship::back == result)
					{ 
						return true;
					}
				}
				return false;
			}

			//-----------------------------------------------------------
			// PlanesUpdate
			//-----------------------------------------------------------
			void Frustum::PlanesUpdate()
			{
				//TODO リファクタ　関数長い
				Vector3 nearCenter,farCenter,
					look,up(m_Viewer.m_UpVec),right;

				look = m_Viewer.m_LookatPt - m_Viewer.m_EyePt;
				look.Normalize();
				up.Normalize();
				right = Vector3::Cross( up,look);
				right.Normalize();

				nearCenter = m_Viewer.m_EyePt + look * m_Viewer.m_Near;
				farCenter = m_Viewer.m_EyePt + look * m_Viewer.m_Far;


				float nearHeightHarf, nearWidthHarf,
					farHeightHarf, farWidthHarf;

				float temp = 2 * tan(m_Viewer.m_Fov*0.5f);

				nearHeightHarf = temp * m_Viewer.m_Near * 1.0f;
				nearWidthHarf = nearHeightHarf * m_Viewer.m_Aspect;

				farHeightHarf = temp * m_Viewer.m_Far * 1.0f;
				farWidthHarf  = farHeightHarf * m_Viewer.m_Aspect;


				auto offUp = up * nearHeightHarf;
				auto offRight = right * nearWidthHarf;

				m_Vertex[NearTopLeft]		= nearCenter + offUp - offRight;
				m_Vertex[NearTopRight]		= nearCenter + offUp + offRight;
				m_Vertex[NearBottomLeft]	= nearCenter - offUp - offRight;
				m_Vertex[NearBottomRight]	= nearCenter - offUp + offRight;

				offUp = up * farHeightHarf;
				offRight = right * farWidthHarf;

				m_Vertex[FarTopLeft]		= farCenter + offUp - offRight;
				m_Vertex[FarTopRight]		= farCenter + offUp + offRight;
				m_Vertex[FarBottomLeft]		= farCenter - offUp - offRight;
				m_Vertex[FarBottomRight]	= farCenter - offUp + offRight;

				m_Planes[Near].Set(		m_Vertex[NearTopLeft],		m_Vertex[NearTopRight],		m_Vertex[NearBottomLeft]);
				m_Planes[Far].Set(		m_Vertex[FarTopRight],		m_Vertex[FarTopLeft],		m_Vertex[FarBottomLeft]);
				m_Planes[Top].Set(		m_Vertex[NearTopLeft],		m_Vertex[FarTopLeft],		m_Vertex[FarTopRight]);
				m_Planes[Bottom].Set(	m_Vertex[FarBottomRight],	m_Vertex[FarBottomLeft],	m_Vertex[NearBottomLeft]);
				m_Planes[Right].Set(	m_Vertex[NearTopRight],		m_Vertex[FarTopRight],		m_Vertex[FarBottomRight]);
				m_Planes[Left].Set(		m_Vertex[FarTopLeft],		m_Vertex[NearTopLeft],		m_Vertex[NearBottomLeft]);
				
			}

			//-----------------------------------------------------------
			// CompositionPointUpdate
			//-----------------------------------------------------------
			void Frustum::CompositionPointUpdate()
			{
				auto look = m_Viewer.m_LookatPt - m_Viewer.m_EyePt;
				look.Normalize();

				m_Center =
					m_Viewer.m_EyePt + look * ((m_Viewer.m_Far - m_Viewer.m_Near)*0.5f);

				auto length = look.GetLengthSquared();
				auto dotVec =
					Vector3::Dot(look, m_Vertex[NearTopRight] - m_Vertex[FarTopRight]) /
					(length*length) * look;
				m_WorldVolume.Volume.Max =
					Vector3(
						(m_Vertex[FarTopLeft] - m_Vertex[FarTopRight]).GetLength()*0.5f,
						(m_Vertex[FarTopLeft] - m_Vertex[FarBottomLeft]).GetLength()*0.5f,
						(dotVec).GetLength()*0.5f
						);
				m_WorldVolume.Volume.Min = -m_WorldVolume.Volume.Max;

				auto& ins = Common::WorldSpaceDivider::Instantiate();
				ins.ReRegister(*this);
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------