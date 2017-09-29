/**
* @file		UIRender.h
* @brief	UI�������_�����O����
* @author	S.OIKAWA
* @date		2017.05.26
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"../Detail/Render.h"
#include"../HLRCommand/HLRCommandPipeline.h"
#include"../Materials/UIMaterial.h"
#include"../Shaders/UIShader.h"
#include"../Rendering/Color.h"
#include"../Resource/ResourceType.h"

#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace UI
	{
		class UITransform;
	}
}
#pragma endregion

namespace Pyramid
{
	namespace Rendering
	{
		namespace ComponentRender
		{
			/// <summary>
			/// UI�������_�����O����
			/// Depth���傫���قǉ��Ƀ����_�����O����(0-1)
			/// </summary>
			class UIRender final : 
				public Detail::Render
			{
			public:
#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				UIRender(UI::UITransform&);
				~UIRender();

				UIRender(const UIRender&) = default;
				UIRender(UIRender&&) = default;

				UIRender& operator=(const UIRender&) = default;
				UIRender& operator=(UIRender&&) = default;
#pragma endregion

#pragma region function
				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------

				/// <summary>
				/// Rendering�̒��O�ɌĂ΂��
				/// </summary>
				void PrepareToRendering() override ;

			private:
				void RegisterOfCommand();
				void RegisterOfProvider();
				void UnRegisterOfProvider();
				void ChangeEventOfRenderState();
#pragma endregion

#pragma region property
	//-----------------------------------------------------------
	// property
	//-----------------------------------------------------------
			public:
				PROPERTY_HOOKABLE(m_IsRenderring,
					IsRenderring,bool, ChangeEventOfRenderState);
				PROPERTY_REF(m_Overlap, Overlap, Rendering::Color);
				PROPERTY_REF(m_Material.Texture, Texture, Resources::TextureDx);
				PROPERTY(m_Depth, Depth, float);

#pragma endregion
			private:
#pragma region value
	//-----------------------------------------------------------
	// val
	//-----------------------------------------------------------
				bool								m_IsRenderring = true;
				bool								m_CeshOfRenderState = true;
				float								m_Depth;
				Rendering::Color					m_Overlap;
				UI::UITransform&					m_UITransform;
				D3DXMATRIX							m_World;
				HLRCommand::HLRCommandPipeline		m_Pipeline;
				Materials::UIMaterial				m_Material;
#pragma endregion
			};
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------