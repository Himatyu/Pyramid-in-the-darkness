/**
* @file		PanelRender.h
* @brief	�p�l���������_�����O����
* @author	S.OIKAWA
* @date		2016.12.26
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"../Detail/OptimizationRender.h"
#include"../Rendering/HLRCommand/HLRCommandPipeline.h"
#include"../Detail/Optimize/CommandOptimizer.h"
#include"../Detail/Optimize/ObjectOptimizer.h"
#include"../Detail/Optimize/Optimizer.h"
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Rendering
	{
		namespace Materials
		{
			class PanelMaterial;
		}
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
			/// �p�l���������_�����O����
			/// </summary>
			class PanelRender final :
				public Detail::OptimizationRender,
				public Detail::Optimize::Optimizer
				<
				Detail::Optimize::CommandOptimizer,
				Detail::Optimize::ObjectOptimizer
				>
			{
			public:
#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				PanelRender();
				~PanelRender() = default;

				PanelRender(const PanelRender&) = default;
				PanelRender(PanelRender&&) = default;

				PanelRender& operator=(const PanelRender&) = default;
				PanelRender& operator=(PanelRender&&) = default;
#pragma endregion

#pragma region function
				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------

				void Init(
					Common::WorldVolume&,
					Common::Sp<Components::Transform>,
					UINT,
					Materials::PanelMaterial*);
				
				/// <summary>
				/// Optimizer�̍X�V
				/// </summary>
				void OptimizerUpdate();

				/// <summary>
				/// �œK������
				/// </summary>
				void PrepareToOptimize()override;

				/// <summary>
				/// �œK��
				/// </summary>
				void Optimize(const Detail::Optimize::Context&)override;

				/// <summary>
				/// �`�揀��
				/// </summary>
				void PrepareToRendering() override;

				
#pragma endregion

#pragma region property
				//-----------------------------------------------------------
				// property
				//-----------------------------------------------------------

#pragma endregion
			private:
#pragma region value
				//-----------------------------------------------------------
				// val
				//-----------------------------------------------------------
				HLRCommand::HLRCommandPipeline		m_Pipeline;
				Materials::PanelMaterial*			m_pMaterial = nullptr;
#pragma endregion
			};
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------