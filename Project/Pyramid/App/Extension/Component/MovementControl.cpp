/**
* @file		MovementControler.cpp
* @brief	プレイヤーの移動管制を行う
* @author	S.OIKAWA
* @date		2017.02.13
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"MovementControl.h"
#include"Mathf.h"
#include"../App/Constant.h"
#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
using namespace Pyramid::Common;
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
				MovementControler::MovementControler(Object::Actor * _pPlayer):
					PlayerModule(_pPlayer)
				{
				}

				//-----------------------------------------------------------
				// ctor
				//-----------------------------------------------------------
				MovementControler::MovementControler():
					PlayerModule(nullptr)
				{
				}

				//-----------------------------------------------------------
				// Init
				//-----------------------------------------------------------
				void MovementControler::Init()
				{
				}

				//-----------------------------------------------------------
				// Updata
				//-----------------------------------------------------------
				void MovementControler::Updata()
				{
					auto& key = Common::InputDevice::Key::Instantiate();
					SpeedControl(key);
					MoveControl(key);
					ReflectionLook();

					m_pPlayer->spTransform->Position +=
						m_Movement * m_Speed * Common::TimerServer::DeltaTime;
					m_pPlayer->spTransform->Rotation =	m_Rotate;

				}

				//-----------------------------------------------------------
				// SpeedControl
				//-----------------------------------------------------------
				void MovementControler::SpeedControl(Common::InputDevice::Key& _key)
				{
					auto input = _key.IsKeyPush(DIK_LSHIFT);
					m_Speed += 
						(input) ?
						TimerServer::DeltaTime : -TimerServer::DeltaTime;

					m_Speed = 
						Utility::Mathf::Clamp(
							m_Speed,
							Constant::PlayerSpeedMin,
							Constant::PlayerSpeedMax);
				}

				//-----------------------------------------------------------
				// MoveControl
				//-----------------------------------------------------------
				void MovementControler::MoveControl(Common::InputDevice::Key & _key)
				{
					m_Movement = Utility::Vector3::forward;
					if (_key.IsKeyPush(DIK_D))
					{
						m_Movement += Utility::Vector3::rigth;
					}

					if (_key.IsKeyPush(DIK_A))
					{
						m_Movement += Utility::Vector3::left;
					}

					if (_key.IsKeyPush(DIK_W))
					{
						m_Movement += Utility::Vector3::up;
					}

					if (_key.IsKeyPush(DIK_S))
					{
						m_Movement += Utility::Vector3::down;
					}
				}

				//-----------------------------------------------------------
				// ReflectionLook
				//-----------------------------------------------------------
				void MovementControler::ReflectionLook()
				{
					auto Rotate = Common::TimerServer::DeltaTime * 20;
					m_Rotate.Z -= m_Movement.X*Rotate;
					m_Rotate.X -= m_Movement.Y*Rotate;

					auto BackRotate = Rotate*0.5f;//感覚値

					if (!m_Movement.X)
					{
						m_Rotate.Z += (m_Rotate.Z < 0) ? BackRotate : -BackRotate;
					}

					if (!m_Movement.Y)
					{		
						m_Rotate.X += (m_Rotate.X < 0) ? BackRotate : -BackRotate;
					}

					m_Rotate.Z = 
						Utility::Mathf::Clamp(
							m_Rotate.Z,
							-Constant::PlayerRotateLimmit, 
							Constant::PlayerRotateLimmit);

					m_Rotate.X =
						Utility::Mathf::Clamp(
							m_Rotate.X,
							-Constant::PlayerRotateLimmit,
							Constant::PlayerRotateLimmit);

				}
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------