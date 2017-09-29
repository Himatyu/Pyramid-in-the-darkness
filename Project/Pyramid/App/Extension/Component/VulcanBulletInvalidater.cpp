/**
* @file		VulcanBulletInvalidater.cpp
* @brief
* @author
* @date
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"VulcanBulletInvalidater.h"
#include"../App/Extension/Object/VulcanBullet.h"
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
				VulcanBulletInvalidater::VulcanBulletInvalidater():
					m_DisableTimer(1.5f,false,true)
				{
				}

				//-----------------------------------------------------------
				// Init
				//-----------------------------------------------------------
				void VulcanBulletInvalidater::Init()
				{
					m_DisableTimer.Reset();
					m_DisableTimer.IsActive = true;
					m_IsFire = true;
				}

				//-----------------------------------------------------------
				// Updata
				//-----------------------------------------------------------
				void VulcanBulletInvalidater::Updata()
				{
					if (m_DisableTimer.IsElapsed)
					{
						m_pOwner->CastTo<Object::VulcanBullet*>()->OnInvalidate();
					}
				}

				//-----------------------------------------------------------
				//  OnInvalidate
				//-----------------------------------------------------------
				void VulcanBulletInvalidater::OnInvalidate()
				{
					m_IsFire = false;
					m_DisableTimer.IsActive = false;
				}
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------