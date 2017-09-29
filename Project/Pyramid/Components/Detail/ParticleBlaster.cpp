/**
* @file		ParticleBlaster.cpp
* @brief	パーティクルを一斉に放出する
* @author	S.OIKAWA
* @date		2016.12.14
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"ParticleBlaster.h"
#include"Particle.h"
#include"SafetyIterate.h"
#include"../Common/TimerServer.h"
#include"../Common/Timer.h"
#include"../Constant.h"
#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Components
	{
		namespace Detail
		{
			//-----------------------------------------------------------
			// ctor
			//-----------------------------------------------------------
			ParticleBlaster::ParticleBlaster(
				ParticleSystem * _pSystem,
				UINT _poolCount):
				ParticleSystemModule(_pSystem,_poolCount)
			{
			}

			//-----------------------------------------------------------
			// dtor
			//-----------------------------------------------------------
			ParticleBlaster::~ParticleBlaster()
			{
				for (auto& _ : m_Reserve)
				{
					SAFE_DELETE(std::get<0>(_));
				}
			}

			//-----------------------------------------------------------
			// Activate
			//-----------------------------------------------------------
			void ParticleBlaster::Activate()
			{
				ParticleSystemModule::Activate();
				for (auto& _ : m_Reserve)
				{
					std::get<0>(_)->Reset();
					std::get<2>(_) = false;
				}
			}

			//-----------------------------------------------------------
			// Emit
			//-----------------------------------------------------------
			void ParticleBlaster::Emit()
			{
				for (auto& _ : m_Reserve)
				{
					auto timer = std::get<0>(_);
					timer->IsActive = true;

					if (timer->IsElapsed && !std::get<2>(_))
					{
						std::get<2>(_) = true;

						for (unsigned i = 0; i < std::get<1>(_); i++)
						{
							for (auto& par : m_Pool.Vector)
							{
								if (par->IsEmmit)
								{
									continue;
								}

								par->Init();
								par->IsEmmit = true;
								break;
							}
						}
					}
				}
			}

			//-----------------------------------------------------------
			// ReserveEmitter
			//-----------------------------------------------------------
			void ParticleBlaster::Reserve(float _time, unsigned int _count)
			{
				m_Reserve.push_back(
					std::make_tuple(
						new Common::Timer(_time,false,true), _count,false));
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------