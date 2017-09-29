/**
* @file		BackJetEffector.cpp
* @brief	後方ジェットのエフェクト制御
* @author	S.OIKAWA
* @date		2017.02.23
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"BackJetEffector.h"
#include"../App/Constant.h"
#include"Mathf.h"
#include<math.h>
#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
using namespace Pyramid::Resources;
using namespace Pyramid::Rendering;
using namespace Pyramid::Common;
using namespace Pyramid::Components;
using namespace Pyramid::Components::Detail;
using namespace Pyramid::App::Extension::Object;
using namespace Pyramid::App::Extension::Component;

void SetTextureInMaterial(
	ParticleEmitter* _pEmmit,
	Sp<Texture::DirectXTextureFile>& _refSpTexture)
{
	_pEmmit->
		Material.
		Texture.
		spResourceFile = _refSpTexture;
}

/// <summary>
/// 増えるかも
/// </summary>
enum JetEffect : int
{
	Right = 0,
	Left,
	RightBlur,
	LeftBlur,
	Count
};

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
				BackJetEffector::BackJetEffector():
					PlayerModule(nullptr)
				{
				}

				//-----------------------------------------------------------
				// ctor
				//-----------------------------------------------------------
				BackJetEffector::BackJetEffector(Object::Actor * _pPlayer):
					PlayerModule(_pPlayer),
					m_JetLength(0.5f)
				{
					NotifyChangeJetLength();
				}

				//-----------------------------------------------------------
				// Init
				//-----------------------------------------------------------
				void BackJetEffector::Init()
				{									
					//HACK これも許せん
					for (auto i = 0; i < RightBlur; i++)
					{						
						auto& system = 
							m_pOwner->AddComponent<Components::ParticleSystem>();
						system->Init();
						auto pEmmit = &system->ReserveEmitter(3.0f, 35);
						pEmmit->Duration = 1.0f;
						pEmmit->IsLooping = true;
						pEmmit->Rate = 30;
						pEmmit->StartSpeed = 1.0f;
						pEmmit->Activate();						
							
						m_Emitters.push_back(pEmmit);
						system->Duration = 1.0f;
						system->IsLooping = true;
						system->Emission();
					}

					for (int i = RightBlur; i < Count; i++)
					{
						auto& system =
							m_pOwner->AddComponent<Components::ParticleSystem>();
						system->Init();
						auto pEmmit = &system->ReserveEmitter(3.0f, 20);
						pEmmit->Duration = 1.0f;
						pEmmit->IsLooping = true;
						pEmmit->Rate = 15;
						pEmmit->StartSpeed = 1.0f;
						pEmmit->Activate();

						m_Emitters.push_back(pEmmit);
						system->Duration = 1.0f;
						system->IsLooping = true;
						system->Emission();
					}

					SetTextureInEmitters();
					ConfigureParticleInitialize();
					ConfigureParticleUpdata();

					m_MovementControler = 
						pPlayer->GetComponent<MovementControler>().Value;

				}

				//-----------------------------------------------------------
				// Updata
				//-----------------------------------------------------------
				void BackJetEffector::Updata()
				{
					//TODO 定数化
					JetLength =
						sin(
							(m_MovementControler->Speed/
								(Constant::PlayerSpeedMax*0.5f))*
							Utility::Mathf::PI*0.25f
							)*1.0f;
					
					JetLength -= Common::TimerServer::DeltaTime*0.5f;

					JetLength =
						Utility::Mathf::Clamp(
						JetLength,
						0.25f,
						1.f
					);

				}

				//-----------------------------------------------------------
				// ConfigureParticleInitialize
				//-----------------------------------------------------------
				void BackJetEffector::ConfigureParticleInitialize()
				{
					auto& CulcInitPos =
						[](Actor* _pPlayer,bool _IsRight)
						-> Utility::Vector3
					{
						auto spTrans = _pPlayer->spTransform;

						return
							spTrans->Position +
							-spTrans->Forward +
							(_IsRight ?
								Utility::Vector3::rigth :
								-Utility::Vector3::rigth)
							*0.25f;
					};

					auto& InitColorAndSize = [&]
					(Components::Detail::Particle& _particle,
						Rendering::Color& _color)
					{
						_particle.Color = _color;
						_particle.Size = 0.0f;
					};

					auto& addInitL = [&]
					(Components::Detail::Particle& _particle)->void
					{
						_particle.Position = CulcInitPos(pPlayer,false);
						InitColorAndSize(_particle, Rendering::Color::White());
					};

					auto& addInitR = [&]
					(Components::Detail::Particle& _particle)->void
					{
						_particle.Position = CulcInitPos(pPlayer,true);
						InitColorAndSize(_particle, Rendering::Color::White());
					};
					m_Emitters[JetEffect::Right]->AdditionalInitialize = addInitR;
					m_Emitters[JetEffect::Left]->AdditionalInitialize = addInitL;

					m_Emitters[JetEffect::RightBlur]->AdditionalInitialize = addInitR;
					m_Emitters[JetEffect::LeftBlur]->AdditionalInitialize = addInitL;
				}

				//-----------------------------------------------------------
				// ConfigureParticleUpdata
				//-----------------------------------------------------------
				void BackJetEffector::ConfigureParticleUpdata()
				{
					auto& UpdataColorAndSize = [&]
					(Components::Detail::Particle& _particle,
						BackJetEffector* effector)
					{
						_particle.Size =
							Utility::Mathf::Clamp(
								sin(Utility::Mathf::PI*_particle.TimeProgress),
								0.0, 0.1)*
							effector->JetLength;

						_particle.Color = 
							Rendering::Color::Lerp(
								Rendering::Color::White(),
								Rendering::Color::White(),
								_particle.TimeProgress);

						_particle.Color.A =
							sin(Utility::Mathf::PI*_particle.TimeProgress);
					};
										
					auto& UpdataParticlePosition = [&]
					(Components::Detail::Particle& _particle,
						bool _isRight,
						BackJetEffector* effector)
					{
						auto spTrans = effector->pPlayer->spTransform;

						_particle.Position =
							spTrans->Position +
							-spTrans->Forward *0.8f +
							(_isRight ?
								spTrans->Right :
								-spTrans->Right)*
							0.25f +
							(-spTrans->Forward*
								effector->JetLength*
								_particle.TimeProgress);
					};

					auto& addUpdateL = [&]
					(Components::Detail::Particle& _particle)->void
					{						
						UpdataColorAndSize(_particle, this);
						UpdataParticlePosition(_particle, false,this);
					};

					auto& addUpdateR = [&]
					(Components::Detail::Particle& _particle)->void
					{
						UpdataColorAndSize(_particle, this);
						UpdataParticlePosition(_particle, true, this);
					};

					m_Emitters[JetEffect::Right]->AdditionalUpdata = addUpdateR;
					m_Emitters[JetEffect::Left]->AdditionalUpdata = addUpdateL;

					auto& UpdataBlurColorAndSize = [&]
					(Components::Detail::Particle& _particle)
					{
						_particle.Color.A =
							Utility::Mathf::Lerp(
								0.3,
								0.0,
								_particle.TimeProgress);

						_particle.Size = (1-_particle.TimeProgress)*0.4f;
					};

					auto& addBlurUpdataL = [&]
					(Components::Detail::Particle& _particle)
					{
						UpdataBlurColorAndSize(_particle);
						UpdataParticlePosition(_particle, false, this);
					};

					auto& addBlurUpdataR = [&]
					(Components::Detail::Particle& _particle)
					{
						UpdataBlurColorAndSize(_particle);
						UpdataParticlePosition(_particle, true, this);
					};

					m_Emitters[JetEffect::RightBlur]->AdditionalUpdata = addBlurUpdataR;
					m_Emitters[JetEffect::LeftBlur]->AdditionalUpdata = addBlurUpdataL;
				}

				//-----------------------------------------------------------
				// NotifyChangeJetLength
				//-----------------------------------------------------------
				void BackJetEffector::NotifyChangeJetLength()
				{
					for (auto& _ : m_Emitters)
					{
						_->Duration = m_JetLength;
					}
				}
				
				//-----------------------------------------------------------
				// SetTextureWithMaterial
				//-----------------------------------------------------------
				void BackJetEffector::SetTextureInEmitters()
				{
					auto& mgr = ResourceManager::Instantiate();
					auto jetTexture =
						mgr.OnLoad<Texture::DirectXTextureFile>(Constant::PathOfJetTexture);

					for (auto& _ : m_Emitters)
					{
						SetTextureInMaterial(_, jetTexture);
					}
				}
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------