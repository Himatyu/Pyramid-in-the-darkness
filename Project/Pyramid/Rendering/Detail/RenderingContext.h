/**
* @file		RenderingContext.h
* @brief	レンダリングに必要な情報を集約する
* @author	S.OIKAWA
* @date		201611.12
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"SafetyIterate.h"
#include"CameraLayer.h"
#include"../Components/Detail/ILight.h"
#include<utility>
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
		namespace Detail
		{
			__interface ILight;
		}
	}
	namespace Rendering
	{
		class Viewer;
	}
}
#pragma endregion

namespace Pyramid
{
	namespace Rendering
	{
		namespace Detail
		{
			/// <summary>
			/// レンダリングに必要な情報を集約する
			/// </summary>
			class RenderingContext final
			{
			public:
#pragma region  defaults
				//-----------------------------------------------------------
				// defaults
				//-----------------------------------------------------------
				RenderingContext() = default;
				~RenderingContext() = default;

				RenderingContext(const RenderingContext&) = default;
				RenderingContext(RenderingContext&&) = default;

				RenderingContext& operator=(const RenderingContext&) = default;
				RenderingContext& operator=(RenderingContext&&) = default;
#pragma endregion

#pragma region function
				//-----------------------------------------------------------
				// function
				//-----------------------------------------------------------
				
#pragma endregion

#pragma region property
	//-----------------------------------------------------------
	// property
	//-----------------------------------------------------------
				PROPERTY_REF(m_CameraList, CameraList, Utility::SafetyIterate<Viewer*>);
				PROPERTY_REF(m_LightList, LightList, Utility::SafetyIterate<Components::Detail::ILight*>);
#pragma endregion
			private:
#pragma region value
	//-----------------------------------------------------------
	// val
	//-----------------------------------------------------------
				Utility::SafetyIterate<Viewer*>							m_CameraList;
				Utility::SafetyIterate<Components::Detail::ILight*>		m_LightList;
#pragma endregion
			};
		}
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------