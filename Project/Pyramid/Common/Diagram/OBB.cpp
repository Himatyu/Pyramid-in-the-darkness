/**
* @file		OBB.cpp
* @brief	有効境界箱
* @author	S.OIKAWA
* @date		2017.03.04
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"OBB.h"
#include"../Components/Transform.h"
#include<math.h>
#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
using namespace Pyramid::Components;
using namespace Utility;

namespace Pyramid
{
	namespace Common
	{
		namespace Diagram
		{


			//-----------------------------------------------------------
			// ctor
			//-----------------------------------------------------------
			OBB::OBB() :
				m_LocalAxis()
			{
				m_LocalAxis[0] = { 1, 0, 0 };
				m_LocalAxis[1] = { 0, 1, 0 };
				m_LocalAxis[2] = { 0, 0, 1 };
			}

			//-----------------------------------------------------------
			// IsInside
			//-----------------------------------------------------------
			Utility::Nullable<float> OBB::IsInside(const Utility::Vector3 & _p)
			{
				Utility::Vector3 outer;

				for (int i = 0; i < 3; i++)
				{
					auto half = m_Half.AccessByIndex(i);
					_ASSERT_EXPR(half >= 0, _T(L"OBB点内外判定にて幅又は高さ又は奥行きが無い"));

					auto scaleHalf =
						Utility::Vector3::Dot(_p - m_Center, m_LocalAxis[i]) / half;

					scaleHalf = std::abs(scaleHalf);
					if (scaleHalf <= 1)
					{
						continue;
					}

					outer += (1 - scaleHalf) * half * m_LocalAxis[i];
				}

				if (Utility::Vector3::zero == outer)
				{
					return Utility::Nullable<float>();
				}

				return Utility::Nullable<float>(outer.GetLength());
			}

			//-----------------------------------------------------------
			// CalculateHalfProjectLengthOnSeparatAxis
			//-----------------------------------------------------------
			float OBB::CalculateHalfProjectLengthOnSeparatAxis(
				const Utility::Vector3 & _separatAxis)
			{
				auto& calcLenByAxis =
					[&](
						const Utility::Vector3& _axis,
						int _index)
				{
					return
						std::abs(
							Utility::Vector3::Dot(
								_separatAxis,
								m_LocalAxis[_index] *
								m_Half.AccessByIndex(_index)
							)
						);
				};

				return
					Utility::Vector3
					(
						calcLenByAxis(_separatAxis, 0),
						calcLenByAxis(_separatAxis, 1),
						calcLenByAxis(_separatAxis, 2)
					)
					.GetLength();
			}

			//-----------------------------------------------------------
			// ReflectionOfTransfrom
			//-----------------------------------------------------------
			void OBB::ReflectionOfTransfrom(Common::Sp<Transform>& _spTrans)
			{
				m_Center = _spTrans->Position;
				m_LocalAxis[0] = Vector3::Rotate(m_LocalAxis[0], _spTrans->MatRotate);
				m_LocalAxis[1] = Vector3::Rotate(m_LocalAxis[1], _spTrans->MatRotate);
				m_LocalAxis[2] = Vector3::Rotate(m_LocalAxis[2], _spTrans->MatRotate);
			}

			//-----------------------------------------------------------
			// ScaleTo
			//-----------------------------------------------------------
			void OBB::ScaleTo(const Utility::Vector3 & _scale)
			{
				if (_scale == Utility::Vector3::once)
				{
					return;
				}
				m_Half.X *= _scale.X;
				m_Half.Y *= _scale.Y;
				m_Half.Z *= _scale.Z;
			}

			//-----------------------------------------------------------
			// MoveTo
			//-----------------------------------------------------------
			void OBB::MoveTo(const Utility::Vector3 & _moved)
			{
				m_Center = _moved;
			}

			//-----------------------------------------------------------
			// Rotation
			//-----------------------------------------------------------
			void OBB::RotateTo(const Utility::Vector3& _rotate)
			{
				if (_rotate == Utility::Vector3::zero)
				{
					return;
				}
				D3DXMATRIX rot;
				D3DXMatrixRotationYawPitchRoll(&rot,
					D3DXToRadian(_rotate.Y),
					D3DXToRadian(_rotate.X),
					D3DXToRadian(_rotate.Z));
				m_LocalAxis[0] = Vector3::Rotate(m_LocalAxis[0], rot);
				m_LocalAxis[1] = Vector3::Rotate(m_LocalAxis[1], rot);
				m_LocalAxis[2] = Vector3::Rotate(m_LocalAxis[2], rot);
			}

			//-----------------------------------------------------------
			// Initialize
			//-----------------------------------------------------------
			void OBB::Initialize()
			{
				m_Half = m_Center = { 0,0,0 };
				m_LocalAxis[0] = { 1, 0, 0 };
				m_LocalAxis[1] = { 0, 1, 0 };
				m_LocalAxis[2] = { 0, 0, 1 };
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------