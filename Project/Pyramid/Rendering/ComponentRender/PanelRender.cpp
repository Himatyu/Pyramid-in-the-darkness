/**
* @file		PanelRender.cpp
* @brief
* @author
* @date
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"PanelRender.h"
#include"../Detail/StaticResource/Panel.h"
#include"../Materials/PanelMaterial.h"
#include"../Includer/RenderingIncluder.h"
#include"../Components/Transform.h"
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
			PanelRender::PanelRender():
				OptimizationRender(m_Pipeline),
				Optimizer
				(
					{ m_Pipeline,m_RenderVolume },
					{ m_RenderVolume,this ,0 }
				)
			{
				//m_RenderId = 2;
				auto& staticQuad = Detail::StaticResource::Panel::Instantiate();

				m_Pipeline.StageingCommand<BeginScene>(Stage::BeginScene, &m_Pipeline);
				m_Pipeline.StageingCommand<SetDeclaration>(
					Stage::SetVertexDeclaration, staticQuad.Declaration, &m_Pipeline);
				m_Pipeline.StageingCommand<SetVertex>(Stage::SetVertex, &staticQuad.VertexBuffer, &m_Pipeline);
				m_Pipeline.StageingCommand<SetMaterial>(Stage::SetMaterial, m_pMaterial, &m_Pipeline);
				m_Pipeline.StageingCommand<DrawPrimitive>(
					Stage::Draw,
					std::make_tuple(D3DPT_TRIANGLEFAN, 0, staticQuad.PolygenCount), &m_Pipeline);
				m_Pipeline.StageingCommand<RiseMateral>(Stage::RiseMateral, m_pMaterial, &m_Pipeline);
				m_Pipeline.StageingCommand<EndScene>(Stage::EndScene, &m_Pipeline);
				m_Pipeline.CommitCommandImmediate();
			}


			//-----------------------------------------------------------
			// Init
			//-----------------------------------------------------------
			void PanelRender::Init(
				Common::WorldVolume & _vol,
				Common::Sp<Components::Transform> _spTrans,
				UINT _priorty, 
				Materials::PanelMaterial* _pMat)
			{
				m_pMaterial = _pMat;
				WorldObjectRender::Init(_vol.Volume, &_spTrans->Position);
				SetMLRC(_priorty);
				CallInit();
			}


			//-----------------------------------------------------------
			// OptimizerUpdate
			//-----------------------------------------------------------
			void PanelRender::OptimizerUpdate()
			{
				CallUpdate();
			}

			//-----------------------------------------------------------
			// PrepareToOptimize
			//-----------------------------------------------------------
			void PanelRender::PrepareToOptimize()
			{
			}

			//-----------------------------------------------------------
			// Optimize
			//-----------------------------------------------------------
			void PanelRender::Optimize(const Detail::Optimize::Context & _context)
			{
				CallOptimize(_context);
			}

			//-----------------------------------------------------------
			// PrepareToRendering
			//-----------------------------------------------------------
			void PanelRender::PrepareToRendering()
			{
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------