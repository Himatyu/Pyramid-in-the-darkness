/**
* @file		MovementControler.h
* @brief	プレイヤーの移動管制を行う
* @author	S.OIKAWA
* @date		2017.02.13
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"../Includer.h"
#include"../App/Player.h"
#include"../App/Extension/Component/PlayerModule.h"
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
				/// プレイヤーの移動管制を行う
				/// </summary>
				class MovementControler :
					public PlayerModule
				{
				public:
#pragma region  defaults
					//-----------------------------------------------------------
					// defaults
					//-----------------------------------------------------------
					MovementControler(Object::Actor*);
					MovementControler();
					~MovementControler() = default;

					MovementControler(const MovementControler&) = default;
					MovementControler(MovementControler&&) = default;

					MovementControler& operator=(const MovementControler&) = default;
					MovementControler& operator=(MovementControler&&) = default;
#pragma endregion

#pragma region function
					//-----------------------------------------------------------
					// function
					//-----------------------------------------------------------
					void Init()			override;
					void Updata()		override;


				private:
					void SpeedControl(Common::InputDevice::Key&);
					void MoveControl(Common::InputDevice::Key&);
					void ReflectionLook();
#pragma endregion
				public:
#pragma region property
	//-----------------------------------------------------------
	// property
	//-----------------------------------------------------------
					PROPERTY(m_Speed, Speed,float);
#pragma endregion
				private:
#pragma region value
	//-----------------------------------------------------------
	// val
	//-----------------------------------------------------------
					float					m_Speed = 0;
					Utility::Vector3		m_Movement;
					Utility::Vector3		m_Rotate;
#pragma endregion
				};
			}
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------