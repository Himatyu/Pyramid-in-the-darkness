/**
* @file		PlayerTrackingCamara.cpp
* @brief	�J�����̎Q�Ƃ������v���C���[��ǐՂ�����
* @author	S.OIKAWA
* @date		2017.02.15
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"PlayerTrackingCamara.h"
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
				PlayerTrackingCamara::PlayerTrackingCamara(Object::Actor * _pPlayer):
					PlayerModule(_pPlayer)
				{
				}

				//-----------------------------------------------------------
				// ctor
				//-----------------------------------------------------------
				PlayerTrackingCamara::PlayerTrackingCamara():
					PlayerModule(nullptr)
				{
				}

				//-----------------------------------------------------------
				// Init
				//-----------------------------------------------------------
				void PlayerTrackingCamara::Init(Object::Actor * _pCameraActor)
				{
					PlayerModule::Init();
					m_pCameraActor = _pCameraActor;

					_pCameraActor->GetComponent<Components::Camera>()
						->LockAt = m_pPlayer->spTransform;
				}

				//-----------------------------------------------------------
				// Updata
				//-----------------------------------------------------------
				void PlayerTrackingCamara::Updata()
				{
					m_pCameraActor
						->spTransform
						->Position = m_pPlayer
									->spTransform
									->Position + Utility::Vector3(0, 1, -3);
				}
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------