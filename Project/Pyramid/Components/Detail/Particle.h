/**
* @file		Particle.h
* @brief	最小パーティクルを定義
* @author	S.OIKAWA
* @date		2016.11.30
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"../MT/Order/TaskOrder.h"
#include"../Rendering/Color.h"
#include"../Rendering/ComponentRender/ParticleRender.h"
#include"../../Common/TextureAnimFream.h"
#include"../Rendering/Detail/Optimize/MLRC.h"
#include"../Rendering/Detail/Optimize/MLRCPublisher.h"
#include"Vector3.h"
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------

#pragma endregion
namespace Pyramid
{
	namespace Components
	{
		namespace Detail
		{
			class ParticleSystemModule;
			/// <summary>
			/// 最小パーティクル
			/// </summary>
			class Particle :
				public MT::Order::TaskOrder<Particle>,
				public Rendering::Detail::Optimize::MLRCPublisher
			{
				friend class Rendering::ComponentRender::ParticleRender;
			public:
#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				Particle(ParticleSystemModule*);
				~Particle();

				Particle(const Particle&) = default;
				Particle(Particle&&) = default;

				Particle& operator=(const Particle&) = default;
				Particle& operator=(Particle&&) = default;
#pragma endregion

#pragma region function
				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------

				/// <summary>
				/// 初期化.
				/// Emitterからの呼び出しを想定
				/// </summary>
				void Init();

			private:
				void Updata();
				void TimeUpdata();
				void PositionUpdata();
				void CommitMatrix();

				void IsEmittNotify();
#pragma endregion
			public:
#pragma region property
				//-----------------------------------------------------------
				// property
				//-----------------------------------------------------------
				PROPERTY_REF(m_Color,				Color,				Rendering::Color);
				PROPERTY_REF(m_Position,			Position,			Utility::Vector3);
				PROPERTY_REF(m_Accel,				Accel,				Utility::Vector3);
				PROPERTY_REF(m_Speed,				Speed,				float);
				PROPERTY_REF(m_Size,				Size,				float);
				PROPERTY_REF(m_Rotation,			Rotation,			float);
				PROPERTY_REF(m_Lifetime,			Lifetime,			float);
				PROPERTY_REF(m_IsBillboard,			IsBillboard,		bool);
				PROPERTY_REF_R_ONLY(m_TimeProgress,	TimeProgress,		float);
				PROPERTY_REF(m_IsEmmit, IsEmmit, bool);
				
#pragma endregion
			private:
#pragma region value
				//-----------------------------------------------------------
				// val
				//-----------------------------------------------------------
				Rendering::ComponentRender::ParticleRender		m_Render;
				Common::TextureAnimFream				m_Fream;
				D3DXMATRIX								m_World;

				Rendering::Color						m_Color;
				Utility::Vector3						m_Position;
				Utility::Vector3						m_Accel;
				float									m_Lifetime;
				float									m_Speed;
				float									m_Size;
				float									m_Rotation;

				float									m_RotateZ;
				float									m_TimeProgress;
				ParticleSystemModule*					m_pModule;
				bool									m_IsEmmit;
				bool									m_IsBillboard;

#pragma endregion
			};
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------