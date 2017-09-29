/**
* @file		BackJetEffector.h
* @brief	後方ジェットのエフェクト制御
* @author	S.OIKAWA
* @date		2017.02.23
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"../Includer.h"
#include"../App/Extension/Component/PlayerModule.h"
#include"../App/Extension/Component/MovementControl.h"
#include<vector>
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
				/// 後方ジェットのエフェクト制御
				/// </summary>
				class BackJetEffector :
					public PlayerModule
				{
				public:
#pragma region  defaults
					//-----------------------------------------------------------
					// defaults
					//-----------------------------------------------------------
					BackJetEffector();
					BackJetEffector(Object::Actor*);
					~BackJetEffector() = default;

					BackJetEffector(const BackJetEffector&) = default;
					BackJetEffector(BackJetEffector&&) = default;

					BackJetEffector& operator=(const BackJetEffector&) = default;
					BackJetEffector& operator=(BackJetEffector&&) = default;
#pragma endregion

#pragma region function
					//-----------------------------------------------------------
					// function
					//-----------------------------------------------------------
					void Init() override;
					void Updata() override;

				private:
					void ConfigureParticleInitialize();
					void ConfigureParticleUpdata();
					void NotifyChangeJetLength();
					void SetTextureInEmitters();
#pragma endregion
				public:
#pragma region property
	//-----------------------------------------------------------
	// property
	//-----------------------------------------------------------
					PROPERTY_HOOKABLE(m_JetLength,
						JetLength,
						float, 
						NotifyChangeJetLength);
#pragma endregion
				private:
#pragma region value
					//-----------------------------------------------------------
					// val
					//-----------------------------------------------------------
					std::vector<Components::Detail::ParticleEmitter*> m_Emitters;
					Common::Sp<MovementControler> m_MovementControler;
					float m_JetLength;
#pragma endregion
				};
			}
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------