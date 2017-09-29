/**
* @file		UIRender.cpp
* @brief	UI‚ðƒŒƒ“ƒ_ƒŠƒ“ƒO‚·‚é
* @author	S.OIKAWA
* @date		2017.05.26
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"UIRender.h"
#include"../Detail/Provider/UIRendering.h"
#include"../RenderProvider.h"
#include"../Rendering/HLRCommand/HLRCommandPipeline.h"
#include"../Rendering/HLRCommand/Default/StaticDefaultCommand.h"
#include"../Includer/RenderingIncluder.h"
#include"../Detail/StaticResource/UI.h"
#include"../UI/UITransform.h"
#include"../Constant.h"
#include<d3dx9.h>
#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Rendering
	{
		using namespace HLRCommand;
		using namespace Detail::Provider;
		namespace ComponentRender
		{
			//-----------------------------------------------------------
			// ctor
			//-----------------------------------------------------------
			UIRender::UIRender(UI::UITransform& _trans):
				Detail::Render(m_Pipeline),
				m_UITransform(_trans),
				m_Material(Constant::UIShaderPath),
				m_Overlap(Color::White())
			{
				RegisterOfCommand();
				RegisterOfProvider();

				m_Material.SetMatrix(m_World);
				m_Material.pColor = &m_Overlap;
			}

			//-----------------------------------------------------------
			// dtor
			//-----------------------------------------------------------
			UIRender::~UIRender()
			{
				UnRegisterOfProvider();
			}

			//-----------------------------------------------------------
			// PrepareToRendering
			//-----------------------------------------------------------
			void UIRender::PrepareToRendering()
			{
				auto& trans = m_UITransform;
				m_World = trans.CalculatWorldMatrix();
				m_Depth = trans.Position.Z;
			}

			//-----------------------------------------------------------
			// RegisterOfCommand
			//-----------------------------------------------------------
			void UIRender::RegisterOfCommand()
			{
				auto& staticUI = Detail::StaticResource::UI::Instantiate();
				m_Pipeline.StageingCommand<BeginScene>(Stage::BeginScene, &m_Pipeline);
				m_Pipeline.StageingCommand<SetDeclaration>(
					Stage::SetVertexDeclaration, staticUI.Declaration, &m_Pipeline);
				m_Pipeline.StageingCommand<SetVertex>(Stage::SetVertex, &staticUI.VertexBuffer, &m_Pipeline);
				m_Pipeline.StageingCommand<SetMaterial>(Stage::SetMaterial, &m_Material, &m_Pipeline);
				m_Pipeline.StageingCommand<DrawPrimitive>(
					Stage::Draw,
					std::make_tuple(D3DPT_TRIANGLESTRIP, 0, staticUI.PolygenCount), &m_Pipeline);
				m_Pipeline.StageingCommand<RiseMateral>(Stage::RiseMateral, &m_Material, &m_Pipeline);
				m_Pipeline.StageingCommand<EndScene>(Stage::EndScene, &m_Pipeline);
				m_Pipeline.CommitCommandImmediate();
			}

			//-----------------------------------------------------------
			// RegisterOfProvider
			//-----------------------------------------------------------
			void UIRender::RegisterOfProvider()
			{
				auto& provider = RenderProvider::Instantiate().UI;
				provider.Add(this);
			}

			//-----------------------------------------------------------
			// RegisterOfProvider
			//-----------------------------------------------------------
			void UIRender::UnRegisterOfProvider()
			{
				auto& provider = RenderProvider::Instantiate().UI;
				provider.Remove(this);
			}

			//-----------------------------------------------------------
			// ChangeEventOfRenderState
			//-----------------------------------------------------------
			void UIRender::ChangeEventOfRenderState()
			{
				if (m_IsRenderring == m_CeshOfRenderState)
				{
					return;
				}

				if (m_IsRenderring)
				{
					RegisterOfProvider();
				}
				else
				{
					UnRegisterOfProvider();
				}

				m_CeshOfRenderState = m_IsRenderring;
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------