/**
* @file		UIButton.h
* @brief	�{�^��UI
* @author	S.OIKAWA
* @date		2017.05.26
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"../UI/IUI.h"
#include"../UI/Event/Listener/Abstract.h"
#include"../UI/Event/Listener/IUIChangeState.h"
#include"../UI/Event/Listener/IUICursor.h"
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------

#pragma endregion

namespace Pyramid
{
	namespace Components
	{
		/// <summary>
		///�{�^��UI
		/// </summary>
		class UIButton final :
			public UI::IUI,
			public UI::Event::Listener::Abstract
				<UI::Event::Listener::IUIChangeState,
				UI::Event::Listener::IUICursor>
		{
		public:
#pragma region  defaults
			//-----------------------------------------------------------
			// defaults
			//-----------------------------------------------------------
			UIButton();
			virtual ~UIButton() = default;

			UIButton(const UIButton&) = default;
			UIButton(UIButton&&) = default;

			UIButton& operator=(const UIButton&) = default;
			UIButton& operator=(UIButton&&) = default;
#pragma endregion

#pragma region function
			//-----------------------------------------------------------
			// function
			//-----------------------------------------------------------

			/// <summary>
			/// �L�����C�x���g
			/// �����_�����O��L���ɂ���
			/// </summary>
			virtual void OnActivate() override;

			/// <summary>
			/// �������C�x���g
			/// �����_�����O�𖳌�������
			/// </summary>
			virtual void OnDeactivate() override;

			virtual void OnCursorEnter()override;
			virtual void OnCursorExit()override;
			virtual void OnCursorClick()override;
			
#pragma endregion

#pragma region property
	//-----------------------------------------------------------
	// property
	//-----------------------------------------------------------

#pragma endregion

#pragma region value
	//-----------------------------------------------------------
	// val
	//-----------------------------------------------------------

#pragma endregion
		};
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------