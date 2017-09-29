/**
* @file		ParticleBlaster.h
* @brief	�p�[�e�B�N������Ăɕ��o����
* @author	S.OIKAWA
* @date		2016.12.14
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"../Detail/ParticleSystemModule.h"
#include"../Common/Timer.h"
#include<list>
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Rendering
	{
		namespace Detail
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
			/// <summary>
			/// �p�[�e�B�N���̕���
			/// </summary>
			class ParticleBlaster :
				public ParticleSystemModule
			{
			public:
#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				ParticleBlaster(ParticleSystem*, UINT _poolCount);
				~ParticleBlaster();

				ParticleBlaster(const ParticleBlaster&) = default;
				ParticleBlaster(ParticleBlaster&&) = default;

				ParticleBlaster& operator=(const ParticleBlaster&) = default;
				ParticleBlaster& operator=(ParticleBlaster&&) = default;
#pragma endregion

#pragma region function
				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------

				/// <summary>
				/// ���W���[���̃A�N�e�B�x�[�g
				/// </summary>
				virtual void Activate()override;

				/// <summary>
				/// �p�[�e�B�N������o����
				/// </summary>
				virtual void Emit() override;

				/// <summary>
				/// ���o�\����s��
				/// </summary>
				void Reserve(float,unsigned int);

#pragma endregion
			
			private:
				using BlastRecord = 
					std::list<std::tuple<Common::Timer*, unsigned int,bool> >;
				BlastRecord m_Reserve;

			};
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------