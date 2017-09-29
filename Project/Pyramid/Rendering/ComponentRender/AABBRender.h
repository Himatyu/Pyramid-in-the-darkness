/**
* @file		AABBRender.h
* @brief	�f�o�b�N�p��AABB�������_�����O����
* @author	S.OIKAWA
* @date		2017.02.06
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"../Detail/OptimizationRender.h"
#include"../Detail/Optimize/CommandOptimizer.h"
#include"../Detail/Optimize/ObjectOptimizer.h"
#include"../Detail/Optimize/Optimizer.h"
#include"../HLRCommand/HLRCommandPipeline.h"
#include"../Buffer.h"
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
			/// AABB�������_�����O����
			/// </summary>
			class AABBRender : 
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
				AABBRender();
				~AABBRender() = default;

				AABBRender(const AABBRender&) = default;
				AABBRender(AABBRender&&) = default;

				AABBRender& operator=(const AABBRender&) = default;
				AABBRender& operator=(AABBRender&&) = default;
#pragma endregion

#pragma region function
				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------
				
				/// <summary>
				/// ������
				/// </summary>
				void Init(
					Common::WorldVolume&, 
					Common::Sp<Components::Transform>,
					UINT );

				/// <summary>
				/// Optimizer�̍X�V
				/// </summary>
				void OptimizerUpdate();

				/// <summary>
				/// �œK������
				/// </summary>
				void PrepareToOptimize()override ;

				/// <summary>
				/// �œK��
				/// </summary>
				void Optimize(const Detail::Optimize::Context&)override ;

				/// <summary>
				/// �`�揀��
				/// </summary>
				void PrepareToRendering() override ;

				/// <summary>
				/// �`��
				/// </summary>
				void Rendering() override;

			private:
				void UpdataBuffer();
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
				HLRCommand::HLRCommandPipeline			m_Pipeline;
				DirectXVertexBuffer						m_VertexBuffer;
				LPDIRECT3DVERTEXDECLARATION9			m_Declaration = nullptr;
#pragma endregion
			};
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------