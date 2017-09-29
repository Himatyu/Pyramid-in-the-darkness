/**
* @file		ParticleRender.h
* @brief	�p�[�e�B�N���������_�����O����
* @author	S.OIKAWA
* @date		2016.11.30
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"../Detail/OptimizationRender.h"
#include"../Detail/Optimize/CommandOptimizer.h"
#include"../Detail/Optimize/Optimizer.h"
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------

namespace Pyramid
{
	namespace Components
	{
		class ParticleSystem;
		namespace Detail
		{
			class ParticleSystemModule;
			class Particle;
		}
	}

	namespace Rendering
	{
		namespace HLRCommand
		{
			class HLRCommandPipeline;
		}
		namespace Materials
		{
			class ParticleMateral;
		}
	}
}
#pragma endregion
namespace Pyramid
{
	namespace Rendering
	{
		namespace ComponentRender
		{
			/// <summary>
			/// �p�[�e�B�N���̃����_�����O���s��
			/// </summary>
			class ParticleRender final :
				public Detail::OptimizationRender,
				public Detail::Optimize::Optimizer
				<
				Detail::Optimize::CommandOptimizer
				>
			{
			public:
#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				ParticleRender(
					Components::ParticleSystem*,
					Components::Detail::ParticleSystemModule*,
					Components::Detail::Particle*);
				~ParticleRender() = default;

				ParticleRender(const ParticleRender&) = default;
				ParticleRender(ParticleRender&&) = default;

				ParticleRender& operator=(const ParticleRender&) = default;
				ParticleRender& operator=(ParticleRender&&) = default;
#pragma endregion

#pragma region function
				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------

				/// <summary>
				/// �œK������
				/// </summary>
				void PrepareToOptimize()override;

				/// <summary>
				/// �œK��
				/// </summary>
				void Optimize(const Detail::Optimize::Context&)override;

				/// <summary>
				/// �`�揀��
				/// </summary>
				void PrepareToRendering() override;

				/// <summary>
				/// �`��
				/// </summary>
				void Rendering() override;
#pragma endregion

#pragma region property
				//-----------------------------------------------------------
				// property
				//-----------------------------------------------------------

#pragma endregion
			private:
#pragma region value
				Materials::ParticleMateral*					m_pMaterial;

				Components::Detail::Particle*				m_pParticle;
				Components::Detail::ParticleSystemModule*	m_pModule;
#pragma endregion
			};
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------