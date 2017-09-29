/**
* @file		FbxRender.cpp
* @brief	Fbx‚ÌƒŒƒ“ƒ_ƒŠƒ“ƒO‚ð’è‹`
* @author	S.OIKAWA
* @date		2016.11.8
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"FbxRender.h"
#include"../Rendering/HLRCommand/HLRCommandPipeline.h"
#include"../Rendering/HLRCommand/Default/StaticDefaultCommand.h"
#include"../Rendering/Detail/StaticResource/Particle.h"
#include"../Materials/MeshMaterial.h"
#include"../Components/Transform.h"
#include"../Includer/RenderingIncluder.h"
#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------

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
			FbxRender::FbxRender(
				std::vector<Materials::MeshMaterial*>& _pMats) :
				m_pMaterials(_pMats),
				m_Pipeline(),
				OptimizationRender(m_Pipeline),
				Optimizer
				(
					{ m_Pipeline,m_RenderVolume },
					{ m_RenderVolume,this ,0 }
				)
			{
			}

			//-----------------------------------------------------------
			// dtor
			//-----------------------------------------------------------
			FbxRender::~FbxRender()
			{
				m_LowLevelPipeline.ClearStageingCommand();
			}


			//-----------------------------------------------------------
			// Init
			//-----------------------------------------------------------
			void FbxRender::Init(
				Common::Sp<Resources::Model::FbxFile>& _fbx,
				Common::Sp<Components::Transform>&		_spTrans,
				UINT _priority)
			{
				m_spFbxFile = _fbx;
				m_pMatrix = m_pRawMatrix = &_spTrans->MatWorld;

				WorldObjectRender::Init(_fbx->Volume, &_spTrans->Position);
				SetMLRC(_priority);

				PublishFbxCommand();
				PreparatLowLevel();

				CallInit();
			}

			//-----------------------------------------------------------
			// Update
			//-----------------------------------------------------------
			void FbxRender::OptimizerUpdate()
			{
				CallUpdate();
			}

			//-----------------------------------------------------------
			// PrepareToOptimize
			//-----------------------------------------------------------
			void FbxRender::PrepareToOptimize()
			{

			}

			//-----------------------------------------------------------
			// Optimize
			//-----------------------------------------------------------
			void FbxRender::Optimize(const Detail::Optimize::Context & _context)
			{
				CallOptimize(_context);
			}

			//-----------------------------------------------------------
			// PrepareToRendering
			//-----------------------------------------------------------
			void FbxRender::PrepareToRendering()
			{
				auto& setCmds =
					Optimizated.SelectToCommitedCommand<SetMaterial>();

				for (auto& _ : setCmds)
				{
					_->PushData->SetMatrix(*m_pMatrix);
				}
			}

			//-----------------------------------------------------------
			// Rendering
			//-----------------------------------------------------------
			void FbxRender::Rendering()
			{
				Optimizated.Run();
			}

			//-----------------------------------------------------------
			// PublishFbxCommand
			//-----------------------------------------------------------
			void FbxRender::PublishFbxCommand()
			{
				auto materialIt = m_pMaterials.begin();
				for (auto& _ : m_spFbxFile->Meshs)
				{
					m_Pipeline.StageingCommand<BeginScene>(Stage::BeginScene, &m_Pipeline);
					m_Pipeline.StageingCommand<SetDeclaration>(Stage::SetVertexDeclaration, _->Declaration, &m_Pipeline);
					m_Pipeline.StageingCommand<SetVertex>(Stage::SetVertex, &_->VertexBuffer, &m_Pipeline);
					m_Pipeline.StageingCommand<SetIndex>(Stage::SetIndex, &_->IndexBuffer, &m_Pipeline);
					m_Pipeline.StageingCommand<SetMaterial>(Stage::SetMaterial, *materialIt, &m_Pipeline);
					m_Pipeline.StageingCommand<DrawIndexedPrimitive>(Stage::Draw, std::make_tuple(
						D3DPT_TRIANGLELIST,
						0,
						0,
						_->IndexCount,
						0,
						_->PolygonCount), &m_Pipeline);
					m_Pipeline.StageingCommand<RiseMateral>(Stage::RiseMateral, *materialIt, &m_Pipeline);
					m_Pipeline.StageingCommand<EndScene>(Stage::EndScene, &m_Pipeline);
					materialIt++;
				}
				m_Pipeline.CommitCommandImmediate();
			}

			//-----------------------------------------------------------
			// PreparatLowLevel
			//-----------------------------------------------------------
			void FbxRender::PreparatLowLevel()
			{
				auto& particleResource =
					Detail::StaticResource::Particle::Instantiate();
				m_LowLevelPipeline =
					particleResource.SkeletonPipeline;
				auto& setMats =
					m_LowLevelPipeline
					.SelectToCommitedCommand<SetMaterial>();

				auto& risMats =
					m_LowLevelPipeline
					.SelectToCommitedCommand<RiseMateral>();

				for (auto& _ : setMats)
				{
					_->PushData = &m_LowLevelMaterial;
				}

				for (auto& _ : risMats)
				{
					_->PushData = &m_LowLevelMaterial;
				}

				m_LowLevelMaterial.SetMatrix(*m_pRawMatrix);
				m_LowLevelMaterial.ArrayUV = Common::DiagonalUV{ 0.0,0.0,1.0,1.0 };
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------