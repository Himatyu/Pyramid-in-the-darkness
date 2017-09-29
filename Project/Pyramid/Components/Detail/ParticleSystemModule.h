/**
* @file		ParticleSystemModule.h
* @brief	パーティクルシステムを構成するモジュール
* @author	S.OIKAWA
* @date		2016.12.14
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"../Transform.h"
#include"../Common/TextureAnimUV.h"
#include"../Common/WorldVolume.h"
#include"../Common/Defines.h"
#include"../Rendering/Color.h"
#include"../Rendering/Materials/ParticleMaterial.h"
#include"../Rendering/Detail/Optimize/JudgmentSameSpaceOfFrustum.h"
#include"SafetyIterate.h"
#include"Vector3.h"
#include<functional>
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Rendering
	{
		namespace ComponentRender
		{
			class ParticleRender;
		}
	}
}
#pragma endregion

namespace Pyramid
{
	namespace Components
	{
		class ParticleSystem;
		namespace Detail
		{
			class Particle;
			class ParticleEmitter;
			class ParticleBlaster;
			/// <summary>
			/// パーティクルシステムを構成するモジュール
			/// </summary>
			class ParticleSystemModule :
				private Rendering::Detail::Optimize::JudgmentSameSpaceOfFrustum
			{
				friend class Particle;
				friend class ParticleEmitter;
				friend class ParticleBlaster;
				friend class Rendering::ComponentRender::ParticleRender;
			public:
#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				ParticleSystemModule(ParticleSystem*, UINT);
				virtual ~ParticleSystemModule();

				ParticleSystemModule(const ParticleSystemModule&) = default;
				ParticleSystemModule(ParticleSystemModule&&) = default;

				ParticleSystemModule& operator=(const ParticleSystemModule&) = default;
				ParticleSystemModule& operator=(ParticleSystemModule&&) = default;
#pragma endregion

#pragma region function
				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------
				/// <summary>
				/// モジュールのアクティベート
				/// </summary>
				virtual void Activate() ;

				/// <summary>
				/// モジュール更新
				/// </summary>
				virtual void Updata() ;

				/// <summary>
				/// パーティクルを放出する
				/// </summary>
				virtual void Emit() = 0;

				/// <summary>
				/// システムのトランスフォーム取得
				/// </summary>
				Common::NullableSp<Transform> SerchSystemTransfrom();

#pragma endregion

			public:
#pragma region property
				//-----------------------------------------------------------
				// property
				//-----------------------------------------------------------
				PROPERTY_REF(m_AdditionalInitialize,	AdditionalInitialize,	std::function<void(Detail::Particle&)>);
				PROPERTY_REF(m_AdditionalUpdata,		AdditionalUpdata,		std::function<void(Detail::Particle&)>);
				PROPERTY_REF(m_TextureUV, TextureUV, Common::TextureAnimUV);
				PROPERTY_REF(m_Material, Material, Rendering::Materials::ParticleMateral);
				PROPERTY_REF(m_StartColor, StartColor, Rendering::Color);
				PROPERTY_REF(m_StartPosition, StartPosition, Utility::Vector3);
				PROPERTY_REF(m_StartAccel, StartAccel, Utility::Vector3);
				PROPERTY_REF(m_Delay, Delay, float);
				PROPERTY_REF(m_StartSpeed, StartSpeed, float);
				PROPERTY_REF(m_StartSize, StartSize, float);
				PROPERTY_REF(m_StartRotation, StartRotation, float);
				PROPERTY_REF(m_Lifetime, Lifetime, float);
				PROPERTY_REF(m_InheritVelocit, InheritVelocit, float);
				PROPERTY_REF(m_GravityMultiplier, GravityMultiplier, float);
				PROPERTY_REF(m_Duration, Duration, float);
				PROPERTY_REF(m_IsLooping, IsLooping, bool);
				PROPERTY_REF(m_IsEmitt, IsEmitt, bool);

#pragma endregion

			private:
#pragma region value
				//-----------------------------------------------------------
				// val
				//-----------------------------------------------------------
				Rendering::Materials::ParticleMateral	m_Material;
				Utility::SafetyIterate<Particle*>		m_Pool;
				Common::TextureAnimUV					m_TextureUV;

				std::function<void(Detail::Particle&)>  m_AdditionalInitialize;
				std::function<void(Detail::Particle&)>  m_AdditionalUpdata;

				//パーティクルごとに持たせるのは無駄なので範囲として定義
				Common::WorldVolume						m_Volume;	

				Rendering::Color						m_StartColor;
				Utility::Vector3						m_StartPosition;
				Utility::Vector3						m_StartAccel;

				float									m_StartSpeed = 1;
				float									m_StartSize = 1;
				float									m_StartRotation = 0;
				float									m_Lifetime = 1;

				float									m_InheritVelocit = 1;
				float									m_GravityMultiplier = 0;

				float									m_Delay = 0;

				float									m_Duration = 0;
				bool									m_IsLooping = false;

				bool									m_IsEmitt = false;
				float									m_RestTimeNextEmmit = 0;
				float									m_RestDuration = 0;
				float									m_RestDelay = 0;

				ParticleSystem*							m_pOwner;
				Particle*								m_pMemHead;
#pragma endregion
			};
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------