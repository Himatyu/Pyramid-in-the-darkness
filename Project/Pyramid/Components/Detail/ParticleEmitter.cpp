/**
* @file		ParticleEmitter.h
* @brief	�p�[�e�B�N���̕��o���`����
* @author	S.OIKAWA
* @date		2016.12.14
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"ParticleEmitter.h"
#include"Particle.h"
#include"../ParticleSystem.h"
#include"../Common/TimerServer.h"
#include"../Constant.h"
#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Components
	{
		namespace Detail
		{
			//-----------------------------------------------------------
			// ctor
			//-----------------------------------------------------------
			ParticleEmitter::ParticleEmitter(
				ParticleSystem* _pOwner, 
				UINT _poolCount) :
				ParticleSystemModule(_pOwner, _poolCount)
			{
			}

			//-----------------------------------------------------------
			// dtor
			//-----------------------------------------------------------
			ParticleEmitter::~ParticleEmitter()
			{
			}

			//-----------------------------------------------------------
			// Emmit
			//-----------------------------------------------------------
			void ParticleEmitter::Emit()
			{
				
				if (m_RestTimeNextEmmit > 0)
				{
					m_RestTimeNextEmmit -= Common::TimerServer::DeltaTime;
					return;
				}

				if (!m_Rate)
				{
					m_RestTimeNextEmmit = 0;
				}
				else
				{
					m_RestTimeNextEmmit = 1.0f / m_Rate; //Rate�ύX�����\�����l���E�E�E����K�v���邩�H
				}

				for (auto& _ : m_Pool.Vector)
				{
					if (_->IsEmmit)
					{
						continue;
					}

					_->Init();
					_->IsEmmit = true;
					break;
				}
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------