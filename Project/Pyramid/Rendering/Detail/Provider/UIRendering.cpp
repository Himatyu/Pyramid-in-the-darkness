/**
* @file		UIRendering.cpp
* @brief	UI‚ÌƒŒƒ“ƒ_ƒŠƒ“ƒO
* @author	S.OIKAWA
* @date		2017.05.26
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"UIRendering.h"
#include"../../ComponentRender/UIRender.h"
#include"../../Graphics.h"
#include"Estd.h"
#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Rendering
	{
		namespace Detail
		{
			namespace Provider
			{
				//-----------------------------------------------------------
				// ctor
				//-----------------------------------------------------------
				UIRendering::UIRendering()
				{
					auto& graphics = Graphics::Instantiate();
					
					m_Projection = 
					{ 
						2.0f / graphics.Width, 0.0f, 0.0f, 0.0f,
						0.0f, -2.0f / graphics.Height, 0.0f, 0.0f,
						0.0f, 0.0f, 1.0f, 0.0f,
						-1.0f, 1.0f, 0.0f, 1.0f
					 };
				}

				//-----------------------------------------------------------
				// Rendering
				//-----------------------------------------------------------
				void UIRendering::Rendering()
				{
					m_Container.sort(
					[](const ComponentRender::UIRender* _lhv, 
						const ComponentRender::UIRender* _rhv) 
					{
						return _lhv->Depth > _rhv->Depth; 
					});

					for (auto& _ : m_Container)
					{
						_->PrepareToRendering();
						_->Rendering();
					}
				}
			}
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------