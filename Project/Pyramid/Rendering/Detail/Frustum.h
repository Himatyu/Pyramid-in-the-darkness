/**
* @file		Frustum.h
* @brief	������
* @author	S.OIKAWA
* @date		2016.12.30
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include<d3dx9.h>
#include"Vector3.h"
#include"../Common/Diagram/Plane.h"
#include"../Rendering/Detail/Optimize/JudgmentSameSpaceOfFrustum.h"
#include"../Common/WorldVolume.h"
#include<array>
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Rendering
	{
		class Viewer;
	}
}
#pragma endregion

namespace Pyramid
{
	namespace Rendering
	{
		namespace Detail
		{
			/// <summary>
			/// ������
			/// ���[���h��Ԃɑ���
			/// </summary>
			class Frustum final :
				public Optimize::JudgmentSameSpaceOfFrustum
			{
			public:
				enum Plane : unsigned
				{
					Near,
					Far,
					Top,
					Bottom,
					Right,
					Left
				};

				enum Vertex : unsigned
				{
					NearTopLeft,
					NearTopRight,
					NearBottomLeft,
					NearBottomRight,
					FarTopLeft,
					FarTopRight,
					FarBottomLeft,
					FarBottomRight
				};

				using FrustumPlanes = std::array<Common::Diagram::Plane, 6>;

#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				Frustum(Viewer&);
				~Frustum();

				Frustum(const Frustum&) = default;
				Frustum(Frustum&&) = default;

				Frustum& operator=(const Frustum&);
				Frustum& operator=(Frustum&&) = default;
#pragma endregion

#pragma region function
				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------

				/// <summary>
				/// ���W���r���[�{�����[���Ɋ܂܂�Ă��邩���ׂ�
				/// �Ԃ��l�̓r�b�g�R�[�h�ŕԋp�����
				/// </summary>
				bool CheckOutSide(const Utility::Vector3& _position);

				/// <summary>
				/// �����̂��\�����镽�ʂ̍X�V
				/// </summary>
				void PlanesUpdate();

				/// <summary>
				/// ���ʂ̒��_�ƒ��S�_���X�V
				/// </summary>
				void CompositionPointUpdate();

#pragma endregion

#pragma region property
				//-----------------------------------------------------------
				// property
				//-----------------------------------------------------------
				PROPERTY_REF(m_Planes, Planes, FrustumPlanes);
#pragma endregion
			private:
#pragma region value
				//-----------------------------------------------------------
				// val
				//-----------------------------------------------------------
				FrustumPlanes					m_Planes;
				Common::WorldVolume				m_WorldVolume;
				Viewer&							m_Viewer;
				Utility::Vector3				m_Center;
				std::array<Utility::Vector3,8>	m_Vertex;
#pragma endregion
			};
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------