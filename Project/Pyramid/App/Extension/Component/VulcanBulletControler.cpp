/**
* @file		VulcanBulletControler.cpp
* @brief
* @author
* @date
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"VulcanBulletControler.h"
#pragma endregion

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
				//-----------------------------------------------------------
				// ctor
				//-----------------------------------------------------------
				VulcanBulletControler::VulcanBulletControler():
					m_Speed(250)
				{
				}

				//-----------------------------------------------------------
				// Init
				//-----------------------------------------------------------
				void VulcanBulletControler::Init(
					Utility::Vector3& _StartPos,
					Utility::Vector3& _Forward)
				{
					m_pBullet = m_pOwner->CastTo<Object::VulcanBullet*>();
					m_pBullet->spTransform->Position = _StartPos;
					m_Forward = _Forward;
				}

				//-----------------------------------------------------------
				// Updata
				//-----------------------------------------------------------
				void VulcanBulletControler::Updata()
				{
					m_pBullet->spTransform->Position += 
						m_Forward*m_Speed * Common::TimerServer::DeltaTime;
				}

				//-----------------------------------------------------------
				// OnInvalidate
				//-----------------------------------------------------------
				void VulcanBulletControler::OnInvalidate()
				{
					m_isActive = false;
				}
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------