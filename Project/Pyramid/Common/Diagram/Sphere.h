/**
* @file		Sphere.h
* @brief	�Փ˔��苅
* @author	S.OIKAWA
* @date		2017.03.04
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
			/// <summary>
			/// �Փ˔��苅
			/// </summary>
			class Sphere :
				public IDiagram
			{
			public:
#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				Sphere();
				~Sphere() = default;

				Sphere(const Sphere&) = default;
				Sphere(Sphere&&) = default;

				Sphere& operator=(const Sphere&) = default;
				Sphere& operator=(Sphere&&) = default;
#pragma endregion

#pragma region function
				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------

				/// <summary>
				/// �X�V
				/// </summary>
				void ReflectionOfTransfrom(Common::Sp<Components::Transform>&) override;

				/// <summary>
				/// �g�k
				/// </summary>
				void ScaleTo(const Utility::Vector3&) override;

				/// <summary>
				/// �ړ�
				/// </summary>
				void MoveTo(const Utility::Vector3&) override;

				/// <summary>
				/// ������Ԃɖ߂�
				/// �̈�(0,0,0,~0)
				/// </summary>
				void Initialize() override ;
#pragma endregion

#pragma region property
	//-----------------------------------------------------------
	// property
	//-----------------------------------------------------------
				PROPERTY(m_R, R, float);
				PROPERTY_REF(m_Center, Center, Utility::Vector3);
#pragma endregion

#pragma region value
	//-----------------------------------------------------------
	// val
	//-----------------------------------------------------------
			private:
				float				m_R;
				Utility::Vector3	m_Center;
#pragma endregion

			};
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------