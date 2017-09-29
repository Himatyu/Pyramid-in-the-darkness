/**
* @file		Particle.cpp
* @brief	最小パーティクルを定義
* @author	S.OIKAWA
* @date		2016.11.30
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"Particle.h"
#include"../Constant.h"
#include"../Common/Constant.h"
#include"../Common/TimerServer.h"
#include"../Rendering/ComponentRender/ParticleRender.h"
#include"../Rendering/RendringPriority.h"
#include"../MT/Worker/MLRCPublisher.h"
#include"../Rendering/RenderProvider.h"
#include"../Rendering/Viewer.h"
#include"../ParticleSystem.h"
#include"ParticleSystemModule.h"
#include"Mathf.h"
#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
using namespace Pyramid::Rendering::HLRCommand::Stage;
using CmdStage = HLRCPipelineStage;
namespace Pyramid
{
	namespace Components
	{
		namespace Detail
		{
			//-----------------------------------------------------------
			// ctor
			//-----------------------------------------------------------
			Particle::Particle(ParticleSystemModule* _pModule):
				m_pModule(_pModule),
				m_Render(_pModule->m_pOwner, _pModule, this),
				MLRCPublisher(_pModule->m_Volume, &m_Render),
				m_IsBillboard(true)
			{
				Init();

				Order(
					&Particle::Updata,
					Common::Constant::MTUpdataGrupName,
					Constant::ParticleMTUpdataLineID);
			
				SetMLRCommand(Rendering::RendringPriority::Transparent);

				auto ignoreHead = 
					Utility::Range<CmdStage>(CmdStage::EndScene, CmdStage::EndScene);
				auto ignoreTail = 
					Utility::Range<CmdStage>(CmdStage::BeginScene, CmdStage::SetIndex);
				m_Render.IgnoreRangeHead = ignoreHead;
				m_Render.IgnoreRangeTail = ignoreTail;

				auto& ignoreList = m_Render.IgnoreRangeMiddleRangeList;
				ignoreList.push_back(ignoreHead);
				ignoreList.push_back(ignoreTail);
			}
			
			//-----------------------------------------------------------
			// dtor
			//-----------------------------------------------------------
			Particle::~Particle()
			{
				OrderCancel(OrderList[0]);
			}
			
			//-----------------------------------------------------------
			// Init
			//-----------------------------------------------------------
			void Particle::Init()
			{
				m_Color		= m_pModule->m_StartColor;
				m_Lifetime	= m_pModule->m_Lifetime;
				m_Speed		= m_pModule->m_StartSpeed;
				m_Rotation	= m_pModule->m_StartRotation;
				m_Size		= m_pModule->m_StartSize;
				m_Position	= m_pModule->m_StartPosition;
				m_Accel		= m_pModule->m_StartAccel;

				m_pModule->m_TextureUV.AttachFream(m_Fream);
				m_RotateZ = 0;
				m_TimeProgress = 0;
				
				auto trans = m_pModule->SerchSystemTransfrom();
				if (trans)
				{
					m_Position += trans.Value->Position;
				}
				m_pModule->AdditionalInitialize(*this);

				IsCommandPublish = false;
				IsEmmit = false;

			}

			//-----------------------------------------------------------
			// Updata
			//-----------------------------------------------------------
			void Particle::Updata()
			{
				if (!m_IsEmmit )
				{
					return;
				}

				IsCommandPublish = true;	//実行順の関係でここで設定

				TimeUpdata();
				PositionUpdata();
				m_Fream.Updata();
				m_pModule->AdditionalUpdata(*this);

				CommitMatrix();
			}

			//-----------------------------------------------------------
			// TimeUpdata
			//-----------------------------------------------------------
			void Particle::TimeUpdata()
			{
				auto deltaTime = Common::TimerServer::DeltaTime;
				m_Lifetime -= deltaTime;

				if (m_Lifetime <= 0)
				{
					IsEmmit = false;
					m_TimeProgress = 1;
					return;
				}
				m_TimeProgress = 1.0f-(m_Lifetime / m_pModule->m_Lifetime);

			}

			//-----------------------------------------------------------
			// PositionUpdata
			//-----------------------------------------------------------
			void Particle::PositionUpdata()
			{
				auto delta =
					Constant::ParticleGravity * m_pModule->m_GravityMultiplier;
				delta += m_Accel;
				m_Position += delta * Common::TimerServer::DeltaTime *m_Speed;
				m_RotateZ += m_Rotation* Common::TimerServer::DeltaTime;

				if (m_pModule->m_InheritVelocit)
				{
					auto trans = m_pModule->SerchSystemTransfrom();
					if (trans)
					{
						m_Position += 
							trans.Value->Velocity * 
							m_pModule->m_InheritVelocit*
							Common::TimerServer::DeltaTime;
					}
				}

			}

			//-----------------------------------------------------------
			// CommitMatrix
			//-----------------------------------------------------------
			void Particle::CommitMatrix()
			{
				D3DXMATRIX		scale, rot, trans;
				D3DXMatrixIdentity(&scale);
				D3DXMatrixIdentity(&rot);
				D3DXMatrixIdentity(&trans);

				D3DXMatrixScaling(&scale, m_Size, m_Size, 1);
				D3DXMatrixRotationZ(&rot, m_RotateZ);
				D3DXMatrixTranslation(&trans, m_Position.X, m_Position.Y, m_Position.Z);

				if (m_IsBillboard)
				{
					auto pView =
						Rendering::RenderProvider::Instantiate().Wolrd.pCurrentViewer;

					D3DXMATRIX Inv = pView->View;
					D3DXMatrixInverse(&Inv, NULL, &Inv);
					Inv._41 = 0.0f;
					Inv._42 = 0.0f;
					Inv._43 = 0.0f;
					rot *= Inv;
				}

				m_World = scale * rot * trans;
			}

			//-----------------------------------------------------------
			// IsEmittNotify
			//-----------------------------------------------------------
			void Particle::IsEmittNotify()
			{
				IsCommandPublish = m_IsEmmit;
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------