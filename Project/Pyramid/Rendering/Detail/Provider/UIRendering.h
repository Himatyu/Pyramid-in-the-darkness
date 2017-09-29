/**
* @file		UIRendering.h
* @brief	UIのレンダリング
* @author	S.OIKAWA
* @date		2017.05.26
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"Interface.h"
#include"Manager.h"
#include<list>
#include<d3dx9.h>
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Rendering
	{
		namespace ComponentRender
		{
			class UIRender;
		}
	}
}
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
				///UIのレンダリング
				/// </summary>
				class UIRendering final : 
					public Interface,
					public ::Utility::Manager<
						::std::list<ComponentRender::UIRender*>>
				{
				public:
#pragma region  defaults
					//-----------------------------------------------------------
					// defaults
					//-----------------------------------------------------------
					UIRendering();
					~UIRendering() = default;

					UIRendering(const UIRendering&) = default;
					UIRendering(UIRendering&&) = default;

					UIRendering& operator=(const UIRendering&) = default;
					UIRendering& operator=(UIRendering&&) = default;
#pragma endregion

#pragma region function
					//-----------------------------------------------------------
					// function
					//-----------------------------------------------------------

					/// <summary>
					/// 描画
					/// </summary>
					void Rendering() override;
#pragma endregion

#pragma region property
	//-----------------------------------------------------------
	// property
	//-----------------------------------------------------------
					PROPERTY_REF_R_ONLY(m_Projection, Projection, D3DXMATRIX);
#pragma endregion

#pragma region value
	//-----------------------------------------------------------
	// val
	//-----------------------------------------------------------
				private:
					D3DXMATRIX	m_Projection;
#pragma endregion
				};
			}
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------