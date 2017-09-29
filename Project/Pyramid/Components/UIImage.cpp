/**
* @file		UIImage.cpp
* @brief	UIÉCÉÅÅ[ÉW
* @author	S.OIKAWA
* @date		2017.05.26
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"UIImage.h"
#include"../UI/Event/UIPublishSystem.h"
#include"../UI/Event/Publisher/UIChangeState.h"
#pragma endregion

//-----------------------------------------------------------
// define
//-----------------------------------------------------------
namespace Pyramid
{
	namespace Components
	{
		//-----------------------------------------------------------
		// ctor
		//-----------------------------------------------------------
		UIImage::UIImage()
		{
			auto& ins = UI::Event::UIPublishSystem::Instantiate();
			ins.AddListener<UI::Event::Publisher::UIChangeState>(this);
		}

		//-----------------------------------------------------------
		// OnActivate
		//-----------------------------------------------------------
		void UIImage::OnActivate()
		{
			RelayEvent(&UI::Event::Listener::IUIChangeState::OnActivate);
			m_Render.IsRenderring = true;
		}

		//-----------------------------------------------------------
		// OnDeactivate
		//-----------------------------------------------------------
		void UIImage::OnDeactivate()
		{
			RelayEvent(&UI::Event::Listener::IUIChangeState::OnDeactivate);
			m_Render.IsRenderring = false;
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------