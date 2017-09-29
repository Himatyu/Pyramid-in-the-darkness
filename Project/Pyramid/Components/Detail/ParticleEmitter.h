/**
* @file		ParticleEmitter.h
* @brief	パーティクルの放出を定義する
* @author	S.OIKAWA
* @date		2016.12.14
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"ParticleSystemModule.h"
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
		class ParticleSystem;
		namespace Detail
		{
			/// <summary>
			/// パーティクルの放射
			/// </summary>
			class ParticleEmitter :
				public ParticleSystemModule
			{
			public:
#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				ParticleEmitter(ParticleSystem*,UINT);
				~ParticleEmitter();

				ParticleEmitter(const ParticleEmitter&) = default;
				ParticleEmitter(ParticleEmitter&&) = default;

				ParticleEmitter& operator=(const ParticleEmitter&) = default;
				ParticleEmitter& operator=(ParticleEmitter&&) = default;
#pragma endregion

#pragma region function
				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------

				/// <summary>
				/// パーティクルを放出する
				/// </summary>
				virtual void Emit() override;

				//-----------------------------------------------------------
				// property
				//-----------------------------------------------------------
				PROPERTY_REF(m_Rate, Rate, float);

				//-----------------------------------------------------------
				// val
				//-----------------------------------------------------------
				float									m_Rate = 1;


#pragma endregion
			};
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------