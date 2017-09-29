/**
* @file		VulcanBullet.h
* @brief	�o���b�g�I�u�W�F�N�g
* @author	S.OIKAWA
* @date		2017.02.15
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"Actor.h"
#include"../App/Extension/Component/VulcanBulletInvalidater.h"
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace App
	{
		namespace Extension
		{
			namespace Component
			{
				class VulcanBulletControler;
			}
		}
	}
}
#pragma endregion

namespace Pyramid
{
	namespace App
	{
		namespace Extension
		{
			namespace Object
			{
				/// <summary>
				/// �o���b�g�I�u�W�F�N�g
				/// </summary>
				class VulcanBullet :
					public Actor
				{
				public:
#pragma region  defaults
					//-----------------------------------------------------------
					// defaults
					//-----------------------------------------------------------
					VulcanBullet(Blueprint::Level*);
					~VulcanBullet() = default;

					VulcanBullet(const VulcanBullet&) = default;
					VulcanBullet(VulcanBullet&&) = default;

					VulcanBullet& operator=(const VulcanBullet&) = default;
					VulcanBullet& operator=(VulcanBullet&&) = default;
#pragma endregion

#pragma region function
					//-----------------------------------------------------------
					// function
					//-----------------------------------------------------------
					void Init() override;

					void Updata() override;
					
					/// <summary>
					/// ���˃C�x���g
					/// </summary>
					void OnFire(
						Utility::Vector3& _PopPos,
						std::shared_ptr<Components::Transform> _Player);

					/// <summary>
					/// �������C�x���g
					/// ���Ԃ��o���A�Փ˂����ۂɔ��s
					/// </summary>
					void OnInvalidate();
#pragma endregion

#pragma region property
					//-----------------------------------------------------------
					// property
					//-----------------------------------------------------------
					PROPERTY_R_ONLY(m_pInvalidater->IsFire, IsFire, bool);
#pragma endregion
				private:
#pragma region value
					//-----------------------------------------------------------
					// val
					//-----------------------------------------------------------

					std::shared_ptr<Component::VulcanBulletControler>		m_pControler;
					std::shared_ptr<Component::VulcanBulletInvalidater>		m_pInvalidater;
					std::shared_ptr<Components::Mesh>						m_pMesh;

#pragma endregion
				};
			}
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------