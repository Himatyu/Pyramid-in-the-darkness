/**
* @file		ParticleSystem.h
* @brief	パーティクルシステムの定義
* @author	S.OIKAWA
* @date		2016.09.12
*/
#pragma once

//-----------------------------------------------------------
// include 
//-----------------------------------------------------------
#include "../Components/Component.h"
#include"../Common/Timer.h"
#include"../Common/Defines.h"
#include"SafetyIterate.h"
#include"Transform.h"
#include<utility>
//-----------------------------------------------------------
// define 
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Components
	{
		namespace Detail
		{
			class ParticleSystemModule;
			class ParticleEmitter;
			class ParticleBlaster;
			class Particle;
		}
	}

	namespace Rendering
	{
		namespace Detail
		{
			class ParticleRender;
		}
	}
}
namespace Pyramid
{
	namespace Components
	{
		/// <summary>
		/// パーティクルシステム.
		/// Hackあとでタスク切る
		/// </summary>
		class ParticleSystem :
			public Component
		{
			friend class Detail::ParticleSystemModule;
			friend class Rendering::Detail::ParticleRender;
		public:
			//-----------------------------------------------------------
			// default
			//-----------------------------------------------------------
			ParticleSystem() = default;
			~ParticleSystem();

			ParticleSystem(const ParticleSystem&) = default;
			ParticleSystem(ParticleSystem&&) = default;

			ParticleSystem&operator=(const ParticleSystem&) = default;
			ParticleSystem&operator=(ParticleSystem&&) = default;

			//-----------------------------------------------------------
			// function
			//-----------------------------------------------------------
			void Init() override;
			void Updata()override;
			void Emission();
			void Stop();

			Detail::ParticleEmitter&	ReserveEmitter(float _time, UINT _poolCount);
			Detail::ParticleBlaster&	ReserveBlaster(float _time, UINT _poolCount);
		private:
			void Reactivate();

			//-----------------------------------------------------------
			// PROPERTY
			//-----------------------------------------------------------
		public:
			PROPERTY_REF(m_Duration, Duration, float);
			PROPERTY_REF(m_Delay, Delay, float);
			PROPERTY_REF(m_IsLooping, IsLooping, bool);
			PROPERTY_REF(m_IsEmitt, IsEmitt, bool);

			//-----------------------------------------------------------
			// val
			//-----------------------------------------------------------
		private:
			using EmitterData = std::pair<Common::Timer*,Detail::ParticleEmitter*>;
			Utility::SafetyIterate<EmitterData>				m_EmitterList;
			using BlasterData = std::pair<Common::Timer*, Detail::ParticleBlaster*>;
			Utility::SafetyIterate<BlasterData>				m_BlasterList;

			Common::NullableSp<Transform>			m_spTransform;
			
			float									m_RestDuration = 0;
			float									m_RestDelay = 0;
			float									m_Duration = 0;
			float									m_Delay = 0;

			bool									m_IsLooping = false;
			bool									m_IsEmitt = false;
		};
	}
}

//-----------------------------------------------------------
// EOF 
//-----------------------------------------------------------