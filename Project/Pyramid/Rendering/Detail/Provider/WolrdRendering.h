/**
* @file		WolrdRendering.h
* @brief	ワールド空間のレンダリングを提供
* @author	S.OIKAWA
* @date		2017.05.26
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"../IRenderable.h"
#include"../RenderingContext.h"
#include"../LightingPublisher.h"
#include"../Optimize/CommandFinalizer.h"
#include"Interface.h"
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
			namespace Provider
			{
				/// <summary>
				/// ワールド空間のレンダリングを提供
				/// </summary>
				class WolrdRendering final :
					public Interface
				{
				public:
#pragma region  defaults
					//-----------------------------------------------------------
					// defaults
					//-----------------------------------------------------------
					WolrdRendering();
					~WolrdRendering() = default;

					WolrdRendering(const WolrdRendering&) = default;
					WolrdRendering(WolrdRendering&&) = default;

					WolrdRendering& operator=(const WolrdRendering&) = default;
					WolrdRendering& operator=(WolrdRendering&&) = default;
#pragma endregion

#pragma region function
					//-----------------------------------------------------------
					// function
					//-----------------------------------------------------------

					/// <summary>
					/// レンダリングを行う
					/// </summary>
					void Rendering() override;

					/// <summary>
					/// ライトをセットする
					/// </summary>
					void SetLights(Shaders::Shader *);

				private:
					void Draw(
						std::vector<Viewer*>& _views,
						Viewer*& _pCurrentViewer,
						Detail::Optimize::CommandFinalizer& _finalizer
					);
#pragma endregion
				public:
#pragma region property
					//-----------------------------------------------------------
					// property
					//-----------------------------------------------------------
					PROPERTY_REF(m_RenderingContext, Context, Detail::RenderingContext);
					PROPERTY_R_ONLY(m_CurrentViewer, pCurrentViewer, Viewer*);
					PROPERTY(m_IsFpsLimit, IsFpsLimit, bool);
#pragma endregion

				private:
#pragma region value
					//-----------------------------------------------------------
					// val
					//-----------------------------------------------------------
					Detail::RenderingContext 				m_RenderingContext;
					Detail::LightingPublisher				m_LightingPublisher;
					Detail::Optimize::CommandFinalizer		m_CommandFinalizer;

					Viewer*					 		m_CurrentViewer = nullptr;
					bool					 		m_IsFpsLimit = false; 
#pragma endregion
				};
			}
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------