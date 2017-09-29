
/**
* @file		Plane.h
* @brief	����
* @author	S.OIKAWA
* @date		2016.12.31
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"Vector3.h"
#include"IDiagram.h"
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Components
	{
		class Transform;
	}
}
#pragma endregion

namespace Pyramid
{
	namespace Common
	{
		namespace Diagram
		{
			enum ResultRelationship : int
			{
				back = 0,
				front,
				on,
			};

			/// <summary>
			/// ����
			/// </summary>
			class Plane :
				public IDiagram
			{
			public:
#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				Plane();
				Plane(const Utility::Vector3& _position, const Utility::Vector3 _normal);
				Plane(const Utility::Vector3& _positionA,
					const Utility::Vector3& _positionB, 
					const Utility::Vector3& _positionC);
				~Plane() = default;

				Plane(const Plane&) = default;
				Plane(Plane&&) = default;

				Plane& operator=(const Plane&) = default;
				Plane& operator=(Plane&&) = default;
#pragma endregion

#pragma region function
				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------

				/// <summary>
				/// �����_�ƖʂƂ̊֌W���Z�o����
				/// </summary>
				ResultRelationship
					DecisionPositionRelationship(const Utility::Vector3& _position);

				/// <summary>
				/// �Z�b�g
				/// </summary>
				void Set(
					const Utility::Vector3& _position,
					const Utility::Vector3& _normal);
				
				/// <summary>
				/// �Z�b�g
				/// </summary>
				void Set(
					const Utility::Vector3& _positionA,
					const Utility::Vector3& _positionB,
					const Utility::Vector3& _positionC);

				/// <summary>
				/// �X�V
				/// </summary>
				void ReflectionOfTransfrom(Common::Sp<Components::Transform>&) override;

				/// <summary>
				/// �ړ�
				/// </summary>
				void MoveTo(const Utility::Vector3&) override;

				/// <summary>
				/// ������Ԃɖ߂�
				/// 0,0,0��ʂ�0,1,0����������
				/// </summary>
				void Initialize() override ;
#pragma endregion

#pragma region property
				//-----------------------------------------------------------
				// property
				//-----------------------------------------------------------
				PROPERTY(m_A, A, float);
				PROPERTY(m_B, B, float);
				PROPERTY(m_C, C, float);
				PROPERTY(m_D, D, float);
				PROPERTY_CR_R_ONLY(m_Normal, Normal, Utility::Vector3);
#pragma endregion
			private:
#pragma region value
				//-----------------------------------------------------------
				// val
				//-----------------------------------------------------------
				float m_A;
				float m_B;
				float m_C;
				float m_D;

				Utility::Vector3 m_Normal;
#pragma endregion
			};
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------