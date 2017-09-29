/**
* @file		AABB.cpp
* @brief	AABB
* @author	S.OIKAWA
* @date		2016.12.30
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"AABB.h"
#include"../Components/Transform.h"
#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
using namespace Pyramid::Components;

namespace Pyramid
{
	namespace Common
	{
		namespace Diagram
		{
			//-----------------------------------------------------------
			// ctor
			//-----------------------------------------------------------
			AABB::AABB():
				m_Min(-1,-1,-1),
				m_Max(1,1,1)
			{
			}

			//-----------------------------------------------------------
			// ctor
			//-----------------------------------------------------------
			AABB::AABB(const Utility::Vector3 & _Min, const Utility::Vector3 & _Max) :
				m_Max(_Max),
				m_Min(_Min)
			{
			}

			//-----------------------------------------------------------
			// GetNearByNormal
			//-----------------------------------------------------------
			Utility::Vector3
				AABB::GetNearByNormal(const Utility::Vector3& _normal)
			{
				return Utility::Vector3
					(
						_normal.X < 0 ? m_Min.X : m_Max.X,
						_normal.Y < 0 ? m_Min.Y : m_Max.Y,
						_normal.Z < 0 ? m_Min.Z : m_Max.Z
						);
			}

			//-----------------------------------------------------------
			// GetFarByNormal
			//-----------------------------------------------------------
			Utility::Vector3
				AABB::GetFarByNormal(const Utility::Vector3& _normal)
			{
				return Utility::Vector3
					(
						_normal.X < 0 ? m_Max.X : m_Min.X,
						_normal.Y < 0 ? m_Max.Y : m_Min.Y,
						_normal.Z < 0 ? m_Max.Z : m_Min.Z
						);
			}

			//-----------------------------------------------------------
			// ReflectionOfTransfrom
			//-----------------------------------------------------------
			void AABB::ReflectionOfTransfrom(Common::Sp<Transform>& _spTrans)
			{
				auto center = Utility::Vector3::CenterOf(m_Min, m_Max);
				m_Min = _spTrans->Position + (m_Min - center);
				m_Max = _spTrans->Position + (m_Max - center);
			}

			//-----------------------------------------------------------
			// ScaleTo
			//-----------------------------------------------------------
			void AABB::ScaleTo(const Utility::Vector3 & _scale)
			{
				auto center = Utility::Vector3::CenterOf(m_Min, m_Max);
				auto centerToMax = m_Max - center;
				centerToMax.X *= _scale.X;
				centerToMax.Y *= _scale.Y;
				centerToMax.Z *= _scale.Z;
				m_Min = center - centerToMax;
				m_Max = center + centerToMax;
			}

			//-----------------------------------------------------------
			// MoveTo
			//-----------------------------------------------------------
			void AABB::MoveTo(const Utility::Vector3 & _moved)
			{
				auto center = Utility::Vector3::CenterOf(m_Min, m_Max);
				m_Min = m_Min - center + _moved;
				m_Max = m_Max - center + _moved;
			}

			//-----------------------------------------------------------
			// IsInside
			//-----------------------------------------------------------
			Utility::Nullable<float> 
				AABB::IsInside(const Utility::Vector3 & _dist)
			{
				float len = 0;

				for (int i = 0; i < 3; i++)
				{
					auto distVal = _dist.AccessByIndex(i);
					auto mintVal = m_Min.AccessByIndex(i);
					auto maxtVal = m_Max.AccessByIndex(i);

					if (distVal < mintVal)
					{
						auto x = distVal - mintVal;
						len += x*x;
					}

					if (distVal > maxtVal)
					{
						auto x = distVal - maxtVal;
						len += x*x;
					}

				}

				if (!len)
				{
					return Utility::Nullable<float>();
				}

				return Utility::Nullable<float>(len);
			}
			
			//-----------------------------------------------------------
			// CalculateOfCenter
			//-----------------------------------------------------------
			Utility::Vector3 AABB::CalculateOfCenter()
			{
				auto minTomax = m_Max - m_Min;
				auto center = m_Min + minTomax*0.5f;
				return center;
			}

			//-----------------------------------------------------------
			// Initialize
			//-----------------------------------------------------------
			void AABB::Initialize()
			{
				m_Min = { -1, -1, -1 };
				m_Max = { 1, 1, 1 };
			}

			//-----------------------------------------------------------
			// operator +
			//-----------------------------------------------------------
			AABB AABB::operator+(const Utility::Vector3 & _pos) const
			{
				return AABB(m_Min + _pos, m_Max + _pos);
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------