/**
* @file		IUI.h
* @brief	����UI�R���|�[�l���g
* @author	S.OIKAWA
* @date		2017.05.26
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------
#include"../Components/component.h"
#include"../Rendering/ComponentRender/UIRender.h"
#include"UITransform.h"
#include"Event/Listener/IUIChangeState.h"
#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------

#pragma endregion

namespace Pyramid
{
	namespace UI
	{
		/// <summary>
		/// ����UI
		/// �����_�����O�A�g�����X�t�H�[���A
		/// �e�q�֌W���l��������ԃC�x���g�����̂��߂̃p�����[�^������
		/// �C�x���g�̔����͐e�q�̏��Ɉˑ�����̂�
		/// Activate�����OnActive����������Ƃ͌���Ȃ�
		/// IsActive���t�b�N�v���p�e�B����Ȃ��͎̂��g��IsActive�����ŏ�Ԃ𔻒f�ł��Ȃ�����
		/// </summary>
		class IUI :
			public Components::Component
		{
		public:
#pragma region  defaults
			//-----------------------------------------------------------
			// defaults
			//-----------------------------------------------------------
			IUI();
			virtual ~IUI() = default;

			IUI(const IUI&) = default;
			IUI(IUI&&) = default;

			IUI& operator=(const IUI&) = default;
			IUI& operator=(IUI&&) = default;
#pragma endregion

#pragma region function
			//-----------------------------------------------------------
			// function
			//-----------------------------------------------------------

			/// <summary>
			/// �L����
			/// </summary>
			virtual void Activate();

			/// <summary>
			/// ������
			/// </summary>
			virtual void Deactivate();

			/// <summary>
			/// �g�����X�t�H�[���̍X�V
			/// </summary>
			virtual void Updata() override;

#pragma endregion

#pragma region property
			//-----------------------------------------------------------
			// property
			//-----------------------------------------------------------
			PROPERTY_REF_R_ONLY(m_Transform, Transform, UITransform);
			PROPERTY_REF(m_Render.Texture, Texture, Resources::TextureDx);
			PROPERTY_REF(m_Render.Overlap, Overlap, Rendering::Color);

#pragma endregion
		protected:
#pragma region value
			//-----------------------------------------------------------
			// val
			//-----------------------------------------------------------
			Rendering::ComponentRender::UIRender	m_Render;
			UITransform								m_Transform;
#pragma endregion
		};
	}
}

//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------