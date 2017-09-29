/**
* @file		Plane.cpp
* @brief	•½–Ê
* @author	S.OIKAWA
* @date		2016.12.31
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"Plane.h"
#include"../Common/Diagram/Constant.h"
#include"../Components/Transform.h"

#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Common
	{
		namespace Diagram
		{

			//-----------------------------------------------------------
			// ctor
			//-----------------------------------------------------------
			Plane::Plane()
			{
				m_A = 0;
				m_B = 0;
				m_C = 0;
				m_D = 0;
				m_Normal = ::Utility::Vector3::up;
			}

			//-----------------------------------------------------------
			// ctor
			//-----------------------------------------------------------
			Plane::Plane(
				const Utility::Vector3 & _position,
				const Utility::Vector3 _normal)
			{
				Set(_position, _normal);
			}

			//-----------------------------------------------------------
			// ctor
			//-----------------------------------------------------------
			Plane::Plane(
				const Utility::Vector3 & _positionA,
				const Utility::Vector3 & _positionB,
				const Utility::Vector3 & _positionC)
			{
				Set(_positionA, _positionB, _positionC);
			}

			//-----------------------------------------------------------
			// DecisionPositionRelationship
			//-----------------------------------------------------------
			ResultRelationship
				Plane::DecisionPositionRelationship(const Utility::Vector3& _position)
			{
				auto result =
					Utility::Vector3::Dot(_position, m_Normal) + m_D;

				if (abs(result) < Constant::SpsilonInUsePlane)
				{
					return ResultRelationship::on;
				}

				if (result < 0)
				{
					return ResultRelationship::back;
				}

				return ResultRelationship::on;
			}

			//-----------------------------------------------------------
			// Set
			//-----------------------------------------------------------
			void Plane::Set(
				const Utility::Vector3 & _position,
				const Utility::Vector3& _normal)
			{
				m_A = _position.X*_normal.X;
				m_B = _position.Y*_normal.Y;
				m_C = _position.Z*_normal.Z;
				m_D = -Utility::Vector3::Dot(_position, _normal);
				m_Normal = _normal;
			}

			//-----------------------------------------------------------
			// Set
			//-----------------------------------------------------------
			void Plane::Set(
				const Utility::Vector3 & _positionA,
				const Utility::Vector3 & _positionB,
				const Utility::Vector3 & _positionC)
			{
				auto ba = _positionA - _positionB;
				auto bc = _positionC - _positionB;

				auto normal = Utility::Vector3::Cross(ba, bc);
				normal.Normalize();

				//”CˆÓ‚Ì“_‚È‚ñ‚ÅA‚Å
				Set(_positionA, normal);
			}

			//-----------------------------------------------------------
			// UpdatePosition
			//-----------------------------------------------------------
			void Plane::ReflectionOfTransfrom(Common::Sp<Components::Transform>& _spTrans)
			{
				Set(_spTrans->Position, m_Normal);
			}

			//-----------------------------------------------------------
			// MoveTo
			//-----------------------------------------------------------
			void Plane::MoveTo(const Utility::Vector3 & _moved)
			{
				Set(_moved, m_Normal);
			}

			//-----------------------------------------------------------
			// Initialize
			//-----------------------------------------------------------
			void Plane::Initialize()
			{
				Plane();
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------