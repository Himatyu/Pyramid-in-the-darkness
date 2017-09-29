/**
* @file		Render.h
* @brief	レンダリングを行う
* @author	S.OIKAWA
* @date		2017.03.23
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"IRenderable.h"
#include"../HLRCommand/HLRCommandPipeline.h"
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------

#pragma endregion

namespace Pyramid
{
	namespace Rendering
	{
		namespace Detail
		{
			/// <summary>
			/// レンダリングを行う
			/// </summary>
			class Render : 
				public IRenderable
			{
			public:
#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				Render(HLRCommand::HLRCommandPipeline&);
				~Render() = default;

				Render(const Render&) = default;
				Render(Render&&) = default;

				Render& operator=(const Render&) = default;
				Render& operator=(Render&&) = default;
#pragma endregion

#pragma region function
				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------

				/// <summary>
				/// Renderingの直前に呼ばれる
				/// リソースが一つで部分的な変更を行うなどを想定
				/// </summary>
				virtual void PrepareToRendering() override {};

				/// <summary>
				/// Preparationの直後に呼ばれレンダリングを行う
				/// </summary>
				virtual void Rendering()override;

#pragma endregion

#pragma region property
	//-----------------------------------------------------------
	// property
	//-----------------------------------------------------------

#pragma endregion
			protected:
#pragma region value
	//-----------------------------------------------------------
	// val
	//-----------------------------------------------------------
				HLRCommand::HLRCommandPipeline&		m_Pipeline;
#pragma endregion
			};
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------