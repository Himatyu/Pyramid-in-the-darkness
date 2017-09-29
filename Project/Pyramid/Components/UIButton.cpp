/**
* @file		UIButton.cpp
* @brief	ƒ{ƒ^ƒ“UI
* @author	S.OIKAWA
* @date		2017.05.26
*/

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"UIButton.h"
#include"../UI/Event/UIPublishSystem.h"
#include"../UI/Event/Publisher/UIChangeState.h"
#include"../UI/Event/Publisher/UICursor.h"
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
		UIButton::UIButton()
		{
			auto& ins = UI::Event::UIPublishSystem::Instantiate();
			ins.AddListener<UI::Event::Publisher::UIChangeState>(this);
			ins.AddListener<UI::Event::Publisher::UICursor>(this);
		}

		//-----------------------------------------------------------
		// OnActivate
		//-----------------------------------------------------------
		void UIButton::OnActivate()
		{
			RelayEvent(&UI::Event::Listener::IUIChangeState::OnActivate);
			m_Render.IsRenderring = true;
			auto& ins = UI::Event::UIPublishSystem::Instantiate();
			ins.AddListener<UI::Event::Publisher::UICursor>(this);
		}

		//-----------------------------------------------------------
		// OnDeactivate
		//-----------------------------------------------------------
		void UIButton::OnDeactivate()
		{
			RelayEvent(&UI::Event::Listener::IUIChangeState::OnDeactivate);
			m_Render.IsRenderring = false;
			auto& ins = UI::Event::UIPublishSystem::Instantiate();
			ins.RemoveListener<UI::Event::Publisher::UICursor>(this);
		}

		//-----------------------------------------------------------
		// OnCursorEnter
		//-----------------------------------------------------------
		void UIButton::OnCursorEnter()
		{
			RelayEvent(&UI::Event::Listener::IUICursor::OnCursorEnter);
		}

		//-----------------------------------------------------------
		// OnCursorExit
		//-----------------------------------------------------------
		void UIButton::OnCursorExit()
		{
			RelayEvent(&UI::Event::Listener::IUICursor::OnCursorExit);
		}

		//-----------------------------------------------------------
		// OnCursorClick
		//-----------------------------------------------------------
		void UIButton::OnCursorClick()
		{
			RelayEvent(&UI::Event::Listener::IUICursor::OnCursorClick);
		}
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------