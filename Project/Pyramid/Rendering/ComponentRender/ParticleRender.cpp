/**
* @file		ParticleRender.cpp
* @brief	パーティクルをレンダリングする
* @author	S.OIKAWA
* @date		2016.11.30
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"ParticleRender.h"
#include"../Rendering/HLRCommand/HLRCommandPipeline.h"

#include"../Components/ParticleSystem.h"
#include"../Components/Detail/ParticleEmitter.h"
#include"../Components/Detail/Particle.h"
#include"../Rendering/Materials/ParticleMaterial.h"
#include"../Rendering/Detail/StaticResource/Particle.h"
#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
using namespace Pyramid::Components::Detail;

namespace Pyramid
{
	namespace Rendering
	{
		using namespace HLRCommand;
		namespace ComponentRender
		{
			//-----------------------------------------------------------
			// ctor
			//-----------------------------------------------------------
			ParticleRender::ParticleRender(
				Components::ParticleSystem* _pSystem,
				Components::Detail::ParticleSystemModule* _pModule,
				Components::Detail::Particle* _pParticle):
				m_pParticle(_pParticle),
				m_pModule(_pModule),
				m_pMaterial(&_pModule->m_Material),
				OptimizationRender(
					Detail::StaticResource::Particle::Instantiate().SkeletonPipeline),
				Optimizer
				(
					{ m_Pipeline,m_RenderVolume }
				)
			{
				RenderID = 3;
				m_RenderVolume.pPosition = &_pParticle->Position;

			}			

			//-----------------------------------------------------------
			// PrepareToOptimize
			//-----------------------------------------------------------
			void ParticleRender::PrepareToOptimize()
			{
			}

			//-----------------------------------------------------------
			// Optimize
			//-----------------------------------------------------------
			void ParticleRender::Optimize(
				const Detail::Optimize::Context & _context)
			{
				CallOptimize(_context);
			}

			//-----------------------------------------------------------
			// PrepareToRendering
			//-----------------------------------------------------------
			void ParticleRender::PrepareToRendering()
			{
				//1particle:1materialは無駄なのでEmitterのマテリアルの値を変えてレンダリング
				m_pMaterial->SetMatrix(m_pParticle->m_World);
				m_pMaterial->pArrayUV =
					std::move(m_pModule->m_TextureUV.getUV(m_pParticle->m_Fream));
				m_pMaterial->pColor = &m_pParticle->Color;

				auto& list =
					Optimizated.SelectToCommitedCommand<HLRCommand::SetMaterial>();
				auto& list2 =
					Optimizated.SelectToCommitedCommand<HLRCommand::RiseMateral>();

				for (auto& _ : list)
				{
					_->PushData = &m_pModule->Material;
				}
				for (auto& _ : list2)
				{
					_->PushData = &m_pModule->Material;
				}
			}

			//-----------------------------------------------------------
			// Rendering
			//-----------------------------------------------------------
			void ParticleRender::Rendering()
			{
				Optimizated.Run();
			}

		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------


