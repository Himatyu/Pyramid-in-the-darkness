/**
* @file		PlayerTrackingCamara.h
* @brief	カメラの参照を持ちプレイヤーを追跡させる
* @author	S.OIKAWA
* @date		2017.02.15
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"../Includer.h"
#include"../Object/Actor.h"
#include"PlayerModule.h"
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
				/// カメラの参照を持ちプレイヤーを追跡させる
				/// </summary>
				class PlayerTrackingCamara : 
					public PlayerModule
				{
				public:
#pragma region  defaults
					//-----------------------------------------------------------
					// defaults
					//-----------------------------------------------------------
					PlayerTrackingCamara(Object::Actor*);
					PlayerTrackingCamara();
					~PlayerTrackingCamara() = default;

					PlayerTrackingCamara(const PlayerTrackingCamara&) = default;
					PlayerTrackingCamara(PlayerTrackingCamara&&) = default;

					PlayerTrackingCamara& operator=(const PlayerTrackingCamara&) = default;
					PlayerTrackingCamara& operator=(PlayerTrackingCamara&&) = default;
#pragma endregion

#pragma region function
					//-----------------------------------------------------------
					// function
					//-----------------------------------------------------------
					void Init(Object::Actor* _pCameraActor) ;
					void Updata() override;
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
					Object::Actor*	m_pCameraActor;
#pragma endregion
				};
			}
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------