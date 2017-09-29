/**
* @file		ParticleSystemModule.h
* @brief	パーティクルシステムを構成するモジュール
* @author	S.OIKAWA
* @date		2016.12.14
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"ParticleSystemModule.h"
#include"Particle.h"
#include"../ParticleSystem.h"
#include"../Common/TimerServer.h"
#include"../Common/WorldSpaceDivider.h"
#include"../Constant.h"
#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
using namespace Pyramid::Common::SpaceDivide;
namespace Pyramid
{
	namespace Components
	{
		namespace Detail
		{
			//-----------------------------------------------------------
			// ctor
			//-----------------------------------------------------------
			ParticleSystemModule::ParticleSystemModule(
				ParticleSystem * _pOwner,
				UINT _poolCount):
				m_pOwner(_pOwner),
				m_StartColor(Rendering::Color::Transparent()),
				m_AdditionalInitialize(Constant::DefaultAdditionalInitialize),
				m_AdditionalUpdata(Constant::DefaultAdditionalUpdata),
				JudgmentSameSpaceOfFrustum(m_Volume)
			{
				auto pIt = m_pMemHead =
					static_cast<Particle*>(malloc(sizeof(Particle)*_poolCount));
				m_Pool.Vector.resize(_poolCount);
				for (auto& _ : m_Pool.Vector)
				{
					_ = new (pIt++) Particle(this);
					MLRCPublisherList.push_back(_);
				}

				m_Volume.pPosition = &_pOwner->m_spTransform->Position;
				Common::WorldSpaceDivider::Instantiate().Register(*this);
			}

			//-----------------------------------------------------------
			// dtor
			//-----------------------------------------------------------
			ParticleSystemModule::~ParticleSystemModule()
			{
				Common::WorldSpaceDivider::Instantiate().UnRegister(*this);
				for (auto& _ : m_Pool.Vector)
				{
					_->~Particle();
				}
				free(m_pMemHead);

			}

			//-----------------------------------------------------------
			// Activate
			//-----------------------------------------------------------
			void ParticleSystemModule::Activate()
			{
				m_IsEmitt = true;
				m_RestDuration = m_Duration;
				m_RestDelay = m_Delay;
			}

			//-----------------------------------------------------------
			// Updata
			//-----------------------------------------------------------
			void ParticleSystemModule::Updata()
			{
				if (!m_IsEmitt)
				{
					return;
				}

				if (m_RestDelay > 0)
				{
					m_RestDelay -= Common::TimerServer::DeltaTime;
					return;
				}

				m_RestDuration -= Common::TimerServer::DeltaTime;
				if (m_RestDuration < 0)
				{
					if (!m_IsLooping)
					{
						return;
					}
					Activate();
				}
				Emit();
			}

			//-----------------------------------------------------------
			// SerchSystemTransfrom
			//-----------------------------------------------------------
			Common::NullableSp<Transform> ParticleSystemModule::SerchSystemTransfrom()
			{
				return m_pOwner->m_spTransform;
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------