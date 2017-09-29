/**
* @file		ParticleSystem.cpp
* @brief		パーティクル実装
* @author		S.OIKAWA
* @date		2016.09.12
*/

//-----------------------------------------------------------
// include 
//-----------------------------------------------------------
#include "ParticleSystem.h"
#include"../Rendering/Detail/StaticResource/Particle.h"
#include"../Common/TimerServer.h"
#include"Detail/ParticleEmitter.h"
#include"Detail/ParticleBlaster.h"
#include"Estd.h"

//-----------------------------------------------------------
// define 
//-----------------------------------------------------------
namespace Pyramid
{
	using namespace Blueprint;
	using namespace Utility;
	using namespace Common;
	namespace Components
	{
		//-----------------------------------------------------------
		// dtor
		//-----------------------------------------------------------
		ParticleSystem::~ParticleSystem()
		{
			m_EmitterList.Apply();
			m_BlasterList.Apply();

			Utility::Estd::for_each(
				m_EmitterList.Vector,
				[](EmitterData& _) 
			{
				SAFE_DELETE(_.first);
				SAFE_DELETE(_.second);
			});

			Utility::Estd::for_each(
				m_BlasterList.Vector,
				[](BlasterData& _)
			{
				SAFE_DELETE(_.first);
				SAFE_DELETE(_.second);
			});
		}
		//-----------------------------------------------------------
		// init
		//-----------------------------------------------------------
		void ParticleSystem::Init()
		{
			//バッファの作成
			Rendering::Detail::StaticResource::Particle::Instantiate();

			m_spTransform = pOwner->GetComponent<Transform>();
		}
		//-----------------------------------------------------------
		// Updata 
		//-----------------------------------------------------------
		void ParticleSystem::Updata()
		{
			if (!m_IsEmitt)
			{
				return;
			}

			if (m_RestDelay >= 0)
			{
				m_RestDelay -= TimerServer::DeltaTime;

				for (auto& _ : m_EmitterList.Vector)
				{
					_.first->IsActive = true;
				}

				for (auto& _ : m_BlasterList.Vector)
				{
					_.first->IsActive = true;
				}
				return;
			}

			m_RestDuration -= TimerServer::DeltaTime;
			if (m_RestDuration < 0)
			{
				if (!m_IsLooping)
				{
					return;
				}
				Reactivate();
			}

			for (auto& _ : m_EmitterList.Vector)
			{
				if (!_.first->IsElapsed && !_.second->IsEmitt)
				{
					continue;
				}
				if (!_.second->IsEmitt)
				{
					_.second->Activate();
				}
				_.second->Updata();
			}

			for (auto& _ : m_BlasterList.Vector)
			{
				if (!_.first->IsElapsed && !_.second->IsEmitt)
				{
					continue;
				}
				if (!_.second->IsEmitt)
				{
					_.second->Activate();
				}
				_.second->Updata();
			}
		}

		//-----------------------------------------------------------
		// Emission
		//-----------------------------------------------------------
		void ParticleSystem::Emission()
		{
			m_IsEmitt = true;
			m_RestDelay = m_Delay;
			m_RestDuration = m_Duration;
			m_EmitterList.Apply();
			m_BlasterList.Apply();
		}

		//-----------------------------------------------------------
		// Stop
		//-----------------------------------------------------------		
		void ParticleSystem::Stop()
		{
			Utility::Estd::for_each(
				m_EmitterList.Vector,
				[](EmitterData& _)
			{
				SAFE_DELETE(_.first);
				SAFE_DELETE(_.second);
			});
		}

		//-----------------------------------------------------------
		// ReserveEmitter
		//-----------------------------------------------------------
		Detail::ParticleEmitter & ParticleSystem::ReserveEmitter(float _time,UINT _poolCpunt)
		{
			auto emitter = std::make_pair(
				new Common::Timer(_time, false, true),
				new Detail::ParticleEmitter(this, _poolCpunt));

			m_EmitterList.AddRequest(emitter);

			return *emitter.second;
		}

		//-----------------------------------------------------------
		// ReserveBlaster
		//-----------------------------------------------------------
		Detail::ParticleBlaster & ParticleSystem::ReserveBlaster(float _time, UINT _poolCount)
		{
			auto blaster = std::make_pair(
				new Common::Timer(_time, false, true),
				new Detail::ParticleBlaster(this, _poolCount));

			m_BlasterList.AddRequest(blaster);

			return *blaster.second;
		}

		//-----------------------------------------------------------
		// Activate
		//-----------------------------------------------------------
		void ParticleSystem::Reactivate()
		{
			m_RestDuration = m_Duration;
			m_RestDelay = m_Delay;
			m_EmitterList.Apply();
			for (auto& _ : m_EmitterList.Vector)
			{
				_.first->Reset();
			}
		}
	}
}

//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------


