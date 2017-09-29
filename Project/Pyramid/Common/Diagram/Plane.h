
/**
* @file		Plane.h
* @brief	平面
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
			/// 平面
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
				/// ある一点と面との関係を算出する
				/// </summary>
				ResultRelationship
					DecisionPositionRelationship(const Utility::Vector3& _position);

				/// <summary>
				/// セット
				/// </summary>
				void Set(
					const Utility::Vector3& _position,
					const Utility::Vector3& _normal);
				
				/// <summary>
				/// セット
				/// </summary>
				void Set(
					const Utility::Vector3& _positionA,
					const Utility::Vector3& _positionB,
					const Utility::Vector3& _positionC);

				/// <summary>
				/// 更新
				/// </summary>
				void ReflectionOfTransfrom(Common::Sp<Components::Transform>&) override;

				/// <summary>
				/// 移動
				/// </summary>
				void MoveTo(const Utility::Vector3&) override;

				/// <summary>
				/// 初期状態に戻す
				/// 0,0,0を通り0,1,0を向く平面
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