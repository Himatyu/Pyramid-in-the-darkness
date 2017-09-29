/**
* @file		Panel.cpp
* @brief
* @author
* @date
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"Panel.h"
#include"../Rendering/RendringPriority.h"
#include"../Common/WorldSpaceDivider.h"
#include"../Components/Transform.h"
#include"../GameObject/Object.h"
#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
using namespace Pyramid::Common::SpaceDivide;

namespace Pyramid
{
	namespace Components
	{
		//-----------------------------------------------------------
		// ctor
		//-----------------------------------------------------------
		Panel::Panel()
		{

		}

		//-----------------------------------------------------------
		// Init
		//-----------------------------------------------------------
		void Panel::Init()
		{
			auto& trans = pOwner->GetComponent<Transform>();

			m_Render.Init(
				m_Volume,
				trans.Value,
				Rendering::RendringPriority::Geometry,
				&m_Material);

			m_Material.SetMatrix(trans->MatWorld);
			m_Volume.pPosition = &trans->Position;
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------