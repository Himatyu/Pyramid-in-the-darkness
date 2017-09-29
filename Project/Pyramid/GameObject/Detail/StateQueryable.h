/**
* @file		StateQueryable.h
* @brief	�X�V�E�`��̏�ԕێ�����
* @author	S.OIKAWA
* @date		2016.09.20
*/
#pragma once

#pragma region include
//-----------------------------------------------------------
// include
//-----------------------------------------------------------

#pragma endregion

#pragma region define
//-----------------------------------------------------------
// define
//-----------------------------------------------------------
#pragma endregion
namespace Pyramid
{
	namespace GameObject
	{
		/// <summary>
		/// �X�V�E�`��̏�ԕێ�����.
		/// �t�b�N�͋�����Ȃ̂ŁA�K�v�Ȃ�I�[�o�[���C�h����.
		/// </summary>
		class StateQueryable
		{
		public:
#pragma region  defaults
			//-----------------------------------------------------------
			// defaults
			//-----------------------------------------------------------
			StateQueryable() = default;
			~StateQueryable() = default;

			StateQueryable(const StateQueryable&) = default;
			StateQueryable(StateQueryable&&) = default;

			StateQueryable& operator=(const StateQueryable&) = default;
			StateQueryable& operator=(StateQueryable&&) = default;
#pragma endregion

#pragma region function
			//-----------------------------------------------------------
			// function
			//-----------------------------------------------------------
			/// <summary>
			/// �X�V���邩�m�F.
			/// </summary>
			bool UpdataQuery();

			/// <summary>
			/// �`�悷�邩�m�F.
			/// </summary>
			bool DrawQuery();

		protected:
			/// <summary>
			/// isActive�ύX���̃t�b�N.
			/// </summary>
			virtual void ModifyisActive();

			/// <summary>
			/// isDestory�ύX���̃t�b�N.
			/// </summary>
			virtual void ModifyisDestory();

			/// <summary>
			/// isUpdata�ύX���̃t�b�N.
			/// </summary>
			virtual void ModifyisUpdata();

			/// <summary>
			/// isDraw�ύX���̃t�b�N.
			/// </summary>
			virtual void ModifyisDraw();

#pragma endregion

		public:
#pragma region property
			//-----------------------------------------------------------
			// property
			//-----------------------------------------------------------
			PROPERTY_HOOKABLE(m_isActive, isActive, bool, ModifyisActive);
			PROPERTY_HOOKABLE(m_isDestory, isDestory, bool, ModifyisDestory);
			PROPERTY_HOOKABLE(m_isUpdata, isUpdata, bool, ModifyisUpdata);
			PROPERTY_HOOKABLE(m_isDraw, isDraw, bool, ModifyisDraw);

#pragma endregion

		protected:
#pragma region value
			//-----------------------------------------------------------
			// val
			//-----------------------------------------------------------
			bool		m_isActive = true;
			bool		m_isDestory = false;
			bool		m_isUpdata = true;
			bool		m_isDraw = true;
#pragma endregion
		};
	}
}
//-----------------------------------------------------------
// EOF
//-----------------------------------------------------------
