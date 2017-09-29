/**
* @file		OBB.h
* @brief	�L�����E��
* @author	S.OIKAWA
* @date		2017.03.04
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"Vector3.h"
#include"Nullable.h"
#include"IDiagram.h"
#include<array>
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
			/// �L�����E��
			/// </summary>
			class OBB :
				public IDiagram
			{
				using AxisType = std::array<Utility::Vector3, 3>;
			public:
#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				OBB();
				~OBB() = default;

				OBB(const OBB&) = default;
				OBB(OBB&&) = default;

				OBB& operator=(const OBB&) = default;
				OBB& operator=(OBB&&) = default;
#pragma endregion

#pragma region function
				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------

				/// <summary>
				/// ���W��OBB���ɂ��邩���؂���
				/// null���A��Β��A����ȊO�͊O
				/// </summary>
				Utility::Nullable<float> IsInside(const Utility::Vector3&);

				/// <summary>
				/// ��������ɓ��e���ꂽ�ӂ̔����̒��������Z����
				/// </summary>
				float CalculateHalfProjectLengthOnSeparatAxis(const Utility::Vector3&);

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
				/// ��]���s��
				/// ������vector�̓f�O���[�ň���
				/// </summary>
				void RotateTo(const Utility::Vector3&)override;

				/// <summary>
				/// ������Ԃɖ߂�
				/// �e���͎����s�̒���1
				/// �̈�A���W��0
				/// </summary>
				void Initialize() override;
#pragma endregion

#pragma region property
	//-----------------------------------------------------------
	// property
	//-----------------------------------------------------------
				PROPERTY_REF(m_Half, Half, Utility::Vector3);
				PROPERTY_REF(m_Center, Center, Utility::Vector3);
				PROPERTY_REF(m_LocalAxis[0], LocalAxisX, Utility::Vector3);
				PROPERTY_REF(m_LocalAxis[1], LocalAxisY, Utility::Vector3);
				PROPERTY_REF(m_LocalAxis[2], LocalAxisZ, Utility::Vector3);
				PROPERTY_REF(m_LocalAxis, LocalAxis, AxisType);
#pragma endregion

#pragma region value
	//-----------------------------------------------------------
	// val
	//-----------------------------------------------------------
			private:
				Utility::Vector3		m_Half;
				Utility::Vector3		m_Center;
				std::array<Utility::Vector3, 3>	m_LocalAxis;
#pragma endregion
			};
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------