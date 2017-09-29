/**
* @file		FbxRender.h
* @brief	Fbxのレンダリングを定義
* @author	S.OIKAWA
* @date		2016.11.8
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"../Rendering/HLRCommand/HLRCommandPipeline.h"
#include"../Rendering/Materials/MeshMaterial.h"
#include"../Rendering/Materials/ProgressiveMeshMaterial.h"
#include"../Detail/OptimizationRender.h"
#include"../Detail/Optimize/CommandOptimizer.h"
#include"../Detail/Optimize/ObjectOptimizer.h"
#include"../Detail/Optimize/Optimizer.h"
#include"../HLRCommand/HLRCommandPipeline.h"
#include"../Resource/Model/FbxFile.h"
#include"../Resource/ResourceType.h"
#include"../Common/Defines.h"

#include<memory>
#include<d3dx9.h>
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{	
	namespace Components
	{
		class Transform;
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
			/// Fbxのレンダリングを行う.
			/// </summary>
			class FbxRender final :
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
				FbxRender(
					std::vector<Materials::MeshMaterial*>&);
				~FbxRender();

				FbxRender(const FbxRender&) = default;
				FbxRender(FbxRender&&) = default;

				FbxRender& operator=(const FbxRender&) = default;
				FbxRender& operator=(FbxRender&&) = default;
#pragma endregion

#pragma region function
				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------

				/// <summary>
				/// コマンドを設定すると
				/// Optimizerの初期化
				/// </summary>
				void Init(
					Common::Sp<Resources::Model::FbxFile>&,
					Common::Sp<Components::Transform>&,
					UINT _priority);

				/// <summary>
				/// Optimizerの更新
				/// </summary>
				void OptimizerUpdate();

				/// <summary>
				/// 最適化準備
				/// </summary>
				void PrepareToOptimize()override;

				/// <summary>
				/// 最適化
				/// </summary>
				void Optimize(const Detail::Optimize::Context&)override;

				/// <summary>
				/// 描画準備
				/// </summary>
				void PrepareToRendering() override;

				/// <summary>
				/// 描画
				/// </summary>
				void Rendering() override;

			private:
				void PublishFbxCommand();
				void PreparatLowLevel();

#pragma endregion
			public:
				//-----------------------------------------------------------
				// property
				//-----------------------------------------------------------
				PROPERTY_REF(
					m_LowLevelMaterial, 
					LowLevelMaterial, 
					Rendering::Materials::ProgressiveMeshMaterial);

			private:
#pragma region value
				//-----------------------------------------------------------
				// val
				//-----------------------------------------------------------
				HLRCommand::HLRCommandPipeline					m_Pipeline;
				Common::Sp<Resources::Model::FbxFile>			m_spFbxFile;
				std::vector<Materials::MeshMaterial*>&			m_pMaterials;
				Rendering::Materials::ProgressiveMeshMaterial	m_LowLevelMaterial;
				HLRCommand::HLRCommandPipeline					m_LowLevelPipeline;
				D3DXMATRIX*										m_pRawMatrix;
				D3DXMATRIX*										m_pMatrix;
#pragma endregion
			};
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------