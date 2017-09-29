/**
* @file		Particle.h
* @brief	パーティクルに必要なリソース
* @author	S.OIKAWA
* @date		2016.12.1
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"singleton.h"
#include"Quad.h"
#include"../Rendering/HLRCommand/HLRCommandPipeline.h"
#include"../Rendering/HLRCommand/Default/SetMaterial.h"
#include"../Rendering/HLRCommand/Default/RiseMateral.h"
#include<d3d9.h>

#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------

#pragma endregion

namespace Pyramid
{
	namespace Rendering
	{
		namespace Detail
		{
			namespace StaticResource
			{
				/// <summary>
				/// パーティクルに必要なリソース
				/// </summary>
				class Particle :
					public Quad,
					public Utility::Singleton<Particle>
				{
				public:
#pragma region  defaults
					//-----------------------------------------------------------
					// defaults
					//-----------------------------------------------------------
					Particle();
					~Particle() = default;

					Particle(const Particle&) = default;
					Particle(Particle&&) = default;

					Particle& operator=(const Particle&) = default;
					Particle& operator=(Particle&&) = default;
#pragma endregion

					//-----------------------------------------------------------
					// function
					//-----------------------------------------------------------
				private:
					void CreatePipeline();
					void CreateBuffer();

				public:
#pragma region property
					//-----------------------------------------------------------
					// property
					//-----------------------------------------------------------
					PROPERTY_REF_R_ONLY(m_SkeletonPipeline, SkeletonPipeline, HLRCommand::HLRCommandPipeline);

#pragma endregion
				private:
#pragma region value
					//-----------------------------------------------------------
					// val
					//-----------------------------------------------------------
					HLRCommand::HLRCommandPipeline					m_SkeletonPipeline;

					HLRCommand::Default::SetMaterial				m_EmptySetCmd;
					HLRCommand::Default::RiseMateral				m_EmptyRiseCmd;
#pragma endregion
				};
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------