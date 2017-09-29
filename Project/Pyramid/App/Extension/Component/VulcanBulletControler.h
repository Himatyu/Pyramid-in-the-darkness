/**
* @file		VulcanBulletControler.h
* @brief	バルカンバレットをコントロールする
* @author	S.OIKAWA
* @date		2017.02.15
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"../Includer.h"
#include"../App/Extension/Object/VulcanBullet.h"
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------

#pragma endregion

namespace Pyramid
{
	namespace App
	{
		namespace Extension
		{
			namespace Component
			{
				/// <summary>
				/// バルカンバレットをコントロールする
				/// </summary>
				class VulcanBulletControler :
					public Components::Component
				{
				public:
#pragma region  defaults
					//-----------------------------------------------------------
					// defaults
					//-----------------------------------------------------------
					VulcanBulletControler();
					~VulcanBulletControler() = default;

					VulcanBulletControler(const VulcanBulletControler&) = default;
					VulcanBulletControler(VulcanBulletControler&&) = default;

					VulcanBulletControler& operator=(const VulcanBulletControler&) = default;
					VulcanBulletControler& operator=(VulcanBulletControler&&) = default;
#pragma endregion

#pragma region function
					//-----------------------------------------------------------
					// function
					//-----------------------------------------------------------
					void Init(
						Utility::Vector3& _StartPos,
						Utility::Vector3& _Forward);

					void Updata() override;
					void OnInvalidate();
#pragma endregion

#pragma region property
					//-----------------------------------------------------------
					// property
					//-----------------------------------------------------------

#pragma endregion
				private:
#pragma region value
					//-----------------------------------------------------------
					// val
					//-----------------------------------------------------------
					Object::VulcanBullet*					m_pBullet;
					std::shared_ptr<Components::Transform>	m_spTransform;
					Utility::Vector3						m_Forward;
					float									m_Speed ;
#pragma endregion
				};
			}
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------