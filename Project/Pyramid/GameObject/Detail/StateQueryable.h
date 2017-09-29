/**
* @file		StateQueryable.h
* @brief	更新・描画の状態保持する
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
		/// 更新・描画の状態保持する.
		/// フックは空実装なので、必要ならオーバーライドして.
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
			/// 更新するか確認.
			/// </summary>
			bool UpdataQuery();

			/// <summary>
			/// 描画するか確認.
			/// </summary>
			bool DrawQuery();

		protected:
			/// <summary>
			/// isActive変更時のフック.
			/// </summary>
			virtual void ModifyisActive();

			/// <summary>
			/// isDestory変更時のフック.
			/// </summary>
			virtual void ModifyisDestory();

			/// <summary>
			/// isUpdata変更時のフック.
			/// </summary>
			virtual void ModifyisUpdata();

			/// <summary>
			/// isDraw変更時のフック.
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
