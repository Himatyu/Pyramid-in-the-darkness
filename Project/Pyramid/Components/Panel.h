/**
* @file		Panel.h
* @brief	パネル
* @author	S.OIKAWA
* @date		2017.01.12
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"../Components/Component.h"
#include"../MT/Order/TaskOrder.h"
#include"../MT/Worker/MLRCPublisher.h"
#include"../Rendering/Detail/Optimize/MLRC.h"
#include"../Rendering/ComponentRender/PanelRender.h"
#include"../Rendering/Materials/PanelMaterial.h"
#include"../Rendering/Detail/Optimize/MLRCPublisher.h"
#include"../Common/WorldVolume.h"
#include"../Rendering/Detail/Optimize/JudgmentSameSpaceOfFrustum.h"
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
		/// <summary>
		/// パネル
		/// </summary>
		class Panel : 
			public Component,
			private MT::Order::TaskOrder<Panel>
		{
		public:
#pragma region  defaults
			//-----------------------------------------------------------
			// defaults
			//-----------------------------------------------------------
			Panel();
			~Panel() = default;

			Panel(const Panel&) = default;
			Panel(Panel&&) = default;

			Panel& operator=(const Panel&) = default;
			Panel& operator=(Panel&&) = default;
#pragma endregion

#pragma region function
			//-----------------------------------------------------------
			// function
			//-----------------------------------------------------------
			
			/// <summary>
			/// 初期化
			/// </summary>
			void Init() override;
#pragma endregion

#pragma region property
	//-----------------------------------------------------------
	// property
	//-----------------------------------------------------------
			PROPERTY_REF(m_Material, panelMaterial, Rendering::Materials::PanelMaterial);
#pragma endregion
		private:
#pragma region value
	//-----------------------------------------------------------
	// val
	//-----------------------------------------------------------
			Rendering::Materials::PanelMaterial				m_Material;
			Rendering::ComponentRender::PanelRender			m_Render;
			Common::WorldVolume								m_Volume;
#pragma endregion
		};
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------