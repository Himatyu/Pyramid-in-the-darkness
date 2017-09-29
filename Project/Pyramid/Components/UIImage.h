/**
* @file		UIImage.h
* @brief	UI�C���[�W
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
		///UI�C���[�W
		/// </summary>
		class UIImage : 
			public UI::IUI,
			public UI::Event::Listener::Abstract
				<UI::Event::Listener::IUIChangeState>
		{
		public:
#pragma region  defaults
			//-----------------------------------------------------------
			// defaults
			//-----------------------------------------------------------
			UIImage();
			virtual ~UIImage() = default;

			UIImage(const UIImage&) = default;
			UIImage(UIImage&&) = default;

			UIImage& operator=(const UIImage&) = default;
			UIImage& operator=(UIImage&&) = default;
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