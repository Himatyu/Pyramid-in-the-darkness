/**
* @file		IUI.h
* @brief	抽象UIコンポーネント
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
		/// 抽象UI
		/// レンダリング、トランスフォーム、
		/// 親子関係を考慮した状態イベント発生のためのパラメータを持つ
		/// イベントの発生は親子の情報に依存するので
		/// Activate直後にOnActiveが発生するとは限らない
		/// IsActiveがフックプロパティじゃないのは自身のIsActiveだけで状態を判断できないから
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
			/// 有効化
			/// </summary>
			virtual void Activate();

			/// <summary>
			/// 無効化
			/// </summary>
			virtual void Deactivate();

			/// <summary>
			/// トランスフォームの更新
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